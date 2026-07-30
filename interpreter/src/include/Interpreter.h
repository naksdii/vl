#pragma once

#include "Thing.h"
#include "VL.h"
#include <any>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

// Exceção de controle de fluxo para o 'return'
struct ReturnException {
  std::string value;
  std::vector<std::string> arrayValues;
};

// Estrutura para transferir argumentos e retornos
struct ResolvedArg {
  std::string value;
  std::vector<std::string> arrayValues;
};

// Tipo estruturado para representar tipos (primitivos, arrays e funções)
struct Type {
  std::string name;
  bool isArray = false;
  bool isFunction = false;
  std::unique_ptr<Type> returnType;
  std::vector<Type> parameters;

  // Enable copying by deep-copying the returnType
  Type() = default;
  explicit Type(std::string n) : name(std::move(n)) {}
  Type(const Type &other)
      : name(other.name), isArray(other.isArray), isFunction(other.isFunction),
        parameters(other.parameters) {
    if (other.returnType)
      returnType = std::make_unique<Type>(*other.returnType);
  }
  Type &operator=(const Type &other) {
    if (this == &other)
      return *this;
    name = other.name;
    isArray = other.isArray;
    isFunction = other.isFunction;
    parameters = other.parameters;
    if (other.returnType)
      returnType = std::make_unique<Type>(*other.returnType);
    else
      returnType.reset();
    return *this;
  }
};

// Helper: extract original source text for a token interval using the
// underlying CharStream
static std::string
getTextFromTokenInterval(antlr4::TokenStream *ts,
                         const antlr4::misc::Interval &intervalTokens) {
  // Prefer extracting from the underlying CharStream (preserves
  // whitespace/comments)
  if (auto common = dynamic_cast<antlr4::CommonTokenStream *>(ts)) {
    if (intervalTokens.a < 0 || intervalTokens.b < 0)
      return std::string();
    antlr4::Token *startTk = common->get(intervalTokens.a);
    antlr4::Token *stopTk = common->get(intervalTokens.b);
    if (startTk && stopTk) {
      if (auto lexer =
              dynamic_cast<antlr4::Lexer *>(startTk->getTokenSource())) {
        if (auto cs = lexer->getInputStream()) {
          antlr4::misc::Interval charInterval(startTk->getStartIndex(),
                                              stopTk->getStopIndex());
          return cs->getText(charInterval);
        }
      }
    }
  }
  // Fallback: token stream getText (may omit hidden channel whitespace)
  return ts->getText(intervalTokens);
}

// Converte um DataTypeContext do parser em um Type estruturado
static Type parseType(VLParser::DataTypeContext *ctx) {
  if (!ctx)
    return Type{"void"};

  if (ctx->primitiveType()) {
    Type t;
    t.name = ctx->primitiveType()->getText();
    return t;
  }

  if (ctx->arrayType()) {
    Type t = parseType(ctx->arrayType()->dataType());
    t.isArray = true;
    return t;
  }

  if (ctx->functionType()) {
    Type t;
    t.isFunction = true;
    t.name = "fn";

    if (ctx->functionType()->dataType())
      t.returnType =
          std::make_unique<Type>(parseType(ctx->functionType()->dataType()));

    if (ctx->functionType()->typeList()) {
      for (auto p : ctx->functionType()->typeList()->dataType())
        t.parameters.push_back(parseType(p));
    }

    return t;
  }

  return Type{"void"};
}

class Interpreter : public VLBaseVisitor {
private:
  bool debugMode = false;
  antlr4::TokenStream *tokenStream = nullptr;
  struct Symbol {
    Thing value;
    bool isConstant;
    Type type;
    bool isInitialized;
    std::vector<std::string> arrayValues;
  };

  struct Parameter {
    std::string name;
    Type type;
  };

  struct FunctionSymbol {
    std::vector<Parameter> params;
    Type returnType;
    std::string bodyText; // store the block source (e.g., "exec { ... }")
    bool isPublic;        // true = opn (public), false = private
  };

  // Built-in functions (name -> implementation)
  std::unordered_map<
      std::string, std::function<ResolvedArg(const std::vector<ResolvedArg> &)>>
      builtins;

  // Tabela Global de Funções
  std::unordered_map<std::string, FunctionSymbol> functionTable;

  // Mantém módulos importados vivos (token streams, parsers, ASTs)
  struct Module {
    std::string name;
    std::unique_ptr<antlr4::ANTLRInputStream> input;
    std::unique_ptr<VLLexer> lexer;
    std::unique_ptr<antlr4::CommonTokenStream> tokens;
    std::unique_ptr<VLParser> parser;
    VLParser::ProgramContext *tree = nullptr;
  };
  std::vector<Module> importedModules;

  // PILHA DE ESCOPOS (Variáveis Locais)
  std::vector<std::unordered_map<std::string, Symbol>> scopes;

  void enterScope() { scopes.push_back({}); }

  void exitScope() {
    if (!scopes.empty()) {
      scopes.pop_back();
    }
  }

  std::string formatType(const Type &type) const {
    std::function<std::string(const Type &)> fmt;
    fmt = [&](const Type &t) -> std::string {
      if (t.isFunction) {
        std::ostringstream oss;
        oss << "fn(";
        for (size_t i = 0; i < t.parameters.size(); ++i) {
          if (i)
            oss << ", ";
          oss << fmt(t.parameters[i]);
        }
        oss << ") -> ";
        if (t.returnType)
          oss << fmt(*t.returnType);
        else
          oss << "void";
        return oss.str();
      }
      std::ostringstream oss;
      oss << t.name;
      if (t.isArray)
        oss << "[]";
      return oss.str();
    };
    return fmt(type);
  }

  std::string formatParams(const std::vector<Parameter> &params) const {
    std::ostringstream oss;
    for (size_t i = 0; i < params.size(); ++i) {
      if (i)
        oss << ", ";
      oss << params[i].name << ":" << formatType(params[i].type);
    }
    return oss.str();
  }

  // Busca do escopo mais interno para o mais externo
  Symbol *findSymbol(const std::string &name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
      auto found = it->find(name);
      if (found != it->end()) {
        return &(found->second);
      }
    }
    return nullptr;
  }

  // Remove aspas de strings caso estejam presentes
  std::string cleanLiteralText(const std::string &text) {
    if (text.size() >= 2 && text.front() == '"' && text.back() == '"') {
      return text.substr(1, text.size() - 2);
    }
    return text;
  }

  // Avalia Nós Primários
  ResolvedArg evaluatePrimary(VLParser::PrimaryContext *ctx) {
    if (ctx->functionCallStmt()) {
    }
    if (ctx->functionCallStmt()) {
      std::any ret = visitFunctionCallStmt(ctx->functionCallStmt());
      return std::any_cast<ResolvedArg>(ret);
    }
    if (ctx->arrayAccess()) {
      std::string arrName = ctx->arrayAccess()->ID()->getText();
      Symbol *sym = findSymbol(arrName);
      if (!sym)
        throw std::runtime_error("Erro: Array '" + arrName +
                                 "' não encontrado.");
      if (!sym->isInitialized)
        throw std::runtime_error("Erro: Array '" + arrName +
                                 "' não inicializado.");

      int index = std::stoi(evaluateExpr(ctx->arrayAccess()->expr()).value);
      if (index < 0 || index >= (int)sym->arrayValues.size()) {
        throw std::runtime_error("Erro: Índice " + std::to_string(index) +
                                 " fora dos limites de '" + arrName + "'.");
      }
      return {sym->arrayValues[index], {}};
    }
    if (ctx->literal()) {
      return {cleanLiteralText(ctx->literal()->getText()), {}};
    }
    if (ctx->ID()) {
      std::string varName = ctx->ID()->getText();
      Symbol *sym = findSymbol(varName);
      if (sym) {
        if (!sym->isInitialized)
          throw std::runtime_error("Erro: Variável '" + varName +
                                   "' não inicializada.");
        if (debugMode)
          std::cerr << "[debug] resolving " << varName << " -> "
                    << sym->value.toString() << std::endl;

        return {sym->value.toString(), sym->arrayValues};
      }

      if (functionTable.find(varName) != functionTable.end()) {
        return {varName, {}};
      }

      throw std::runtime_error("Erro: Variável '" + varName +
                               "' não declarada.");
    }
    return {"", {}};
  }

  // Avaliação de Expressões
  ResolvedArg evaluateExpr(VLParser::ExprContext *ctx) {
    if (!ctx)
      return {"", {}};

    if (auto parenCtx = dynamic_cast<VLParser::ExprParenContext *>(ctx)) {
      return evaluateExpr(parenCtx->expr());
    }

    if (auto primaryCtx = dynamic_cast<VLParser::ExprPrimaryContext *>(ctx)) {
      return evaluatePrimary(primaryCtx->primary());
    }

    if (auto mulCtx = dynamic_cast<VLParser::ExprMulDivContext *>(ctx)) {
      ResolvedArg leftArg = evaluateExpr(mulCtx->left);
      ResolvedArg rightArg = evaluateExpr(mulCtx->right);

      std::string op = mulCtx->op->getText();

      // Try integer arithmetic first
      try {
        int leftVal = std::stoi(leftArg.value);
        int rightVal = std::stoi(rightArg.value);
        int res = 0;
        if (op == "*")
          res = leftVal * rightVal;
        else if (op == "/") {
          if (rightVal == 0)
            throw std::runtime_error("Erro: Divisão por zero.");
          res = leftVal / rightVal;
        } else if (op == "%")
          res = leftVal % rightVal;
        return {std::to_string(res), {}};
      } catch (...) {
        // Non-integer operands: support string repetition e.g. "a" * 3
        if (op == "*") {
          // left string * int
          try {
            int times = std::stoi(rightArg.value);
            std::string result;
            for (int i = 0; i < times; ++i)
              result += leftArg.value;
            return {result, {}};
          } catch (...) {
            // right string * int
            try {
              int times = std::stoi(leftArg.value);
              std::string result;
              for (int i = 0; i < times; ++i)
                result += rightArg.value;
              return {result, {}};
            } catch (...) {
              throw std::runtime_error(
                  "Erro: Operação '*' não aplicável aos operandos fornecidos.");
            }
          }
        }
        throw std::runtime_error(
            "Erro: Operação aritmética aplicada a operandos não numéricos.");
      }
    }

    if (auto addCtx = dynamic_cast<VLParser::ExprAddSubContext *>(ctx)) {
      ResolvedArg leftArg = evaluateExpr(addCtx->left);
      ResolvedArg rightArg = evaluateExpr(addCtx->right);

      std::string op = addCtx->op->getText();

      // Try integer arithmetic
      try {
        int leftVal = std::stoi(leftArg.value);
        int rightVal = std::stoi(rightArg.value);
        int res = 0;
        if (op == "+")
          res = leftVal + rightVal;
        else if (op == "-")
          res = leftVal - rightVal;
        if (debugMode) {
          std::cerr << "[debug] evaluated expr: " << ctx->getText() << "as"
                    << res << std::endl;
        }
        return {std::to_string(res), {}};
      } catch (...) {
        // Fallback: if '+' then perform string concatenation
        if (op == "+") {
          auto result = leftArg.value + rightArg.value;
          if (debugMode) {
            std::cerr << "[debug] evaluated expr: " << ctx->getText() << " as "
                      << result << std::endl;
          }
          return {result, {}};
        }
        throw std::runtime_error("Erro: Operação aritmética '-' não aplicável "
                                 "a operandos não numéricos.");
      }
    }

    return {"", {}};
  }

public:
  void setDebug(bool debug) { debugMode = debug; }
  Interpreter(antlr4::TokenStream *ts) : tokenStream(ts) {
    enterScope(); // global scope
    if (debugMode) {
      std::cerr << "[debug] interpreter initialized with debug mode ON\n";
    }
    // initialize built-ins
    builtins["print"] =
        [&](const std::vector<ResolvedArg> &args) -> ResolvedArg {
      std::ostringstream out;
      for (size_t i = 0; i < args.size(); ++i) {
        if (i)
          out << " ";
        out << args[i].value;
      }
      std::string outStr = out.str();
      // program output goes to stdout only
      std::cout << outStr << std::endl << std::flush;
      // detailed log in English
      return {outStr, {}};
    };

    builtins["input"] =
        [&](const std::vector<ResolvedArg> &args) -> ResolvedArg {
      std::string prompt = "";
      if (!args.empty())
        prompt = args[0].value;
      if (!prompt.empty())
        std::cout << prompt << std::flush;
      std::string line;
      if (!std::getline(std::cin, line))
        line = "";
      return {line, {}};
    };
    if (debugMode) {
      std::cerr << "[debug] declared builtins functions succesfully."
                << std::endl;
    }
  }
  // PROGRAMA E BLOCOS
  virtual std::any visitImportStmt(VLParser::ImportStmtContext *ctx) override {
    // 1. Extrai o caminho do arquivo (removendo as aspas da string)
    std::string rawPath = ctx->STRING()->getText();
    std::string filePath = rawPath.substr(1, rawPath.size() - 2);

    // 2. Define o prefixo/namespace (se usar 'as m', o alias é 'm', senão usa o
    // nome do arquivo)
    std::string namespaceAlias = "";
    if (ctx->ID()) {
      namespaceAlias = ctx->ID()->getText();
    } else {
      // Pega o nome base do arquivo sem a extensão (ex: "math.verb" -> "math")
      size_t lastSlash = filePath.find_last_of("/\\");
      std::string fileName = (lastSlash == std::string::npos)
                                 ? filePath
                                 : filePath.substr(lastSlash + 1);
      size_t lastDot = fileName.find_last_of('.');
      namespaceAlias = (lastDot == std::string::npos)
                           ? fileName
                           : fileName.substr(0, lastDot);
    }

    // 3. Lê o conteúdo do arquivo importado
    std::ifstream file(filePath);
    if (!file.is_open()) {
      throw std::runtime_error(
          "Erro de Importação: Não foi possível abrir o arquivo '" + filePath +
          "'.");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    // 4. Executa o ANTLR no código do arquivo importado
    if (debugMode) {
      std::cerr << "[debug] started importing " << filePath << " as "
                << namespaceAlias << "\n";
    }
    auto importInput = std::make_unique<antlr4::ANTLRInputStream>(fileContent);
    auto importLexer = std::make_unique<VLLexer>(importInput.get());
    auto importTokens =
        std::make_unique<antlr4::CommonTokenStream>(importLexer.get());
    auto importParser = std::make_unique<VLParser>(importTokens.get());

    VLParser::ProgramContext *importTree = importParser->program();

    // Store module to keep token stream and parser alive during execution
    Module mod;
    mod.name = namespaceAlias;
    mod.input = std::move(importInput);
    mod.lexer = std::move(importLexer);
    mod.tokens = std::move(importTokens);
    mod.parser = std::move(importParser);
    mod.tree = importTree;
    importedModules.push_back(std::move(mod));

    // 5. Coleta apenas as funções PÚBLICAS ('opn') do módulo importado
    // Use o parser/tokens armazenados acima para extrair texto precisamente
    Module &stored = importedModules.back();
    for (auto funcCtx : stored.tree->functionDecl()) {
      std::string funcName = funcCtx->ID()->getText();

      // Verifica se a função é pública ('opn')
      bool isPublic = (funcCtx->visibility() != nullptr);
      if (!isPublic)
        continue; // Funções privadas não são exportadas

      Type returnType =
          funcCtx->dataType() ? parseType(funcCtx->dataType()) : Type("void");

      std::vector<Parameter> params;
      if (funcCtx->paramList()) {
        for (auto paramCtx : funcCtx->paramList()->param()) {
          params.push_back(
              {paramCtx->ID()->getText(), parseType(paramCtx->dataType())});
        }
      }

      std::string globalFuncName = namespaceAlias + "." + funcName;
      auto interval = funcCtx->block()->getSourceInterval();
      std::string blockText =
          getTextFromTokenInterval(stored.tokens.get(), interval);
      functionTable[globalFuncName] =
          FunctionSymbol{params, returnType, blockText, true};
      if (debugMode) {
        std::cerr << "[debug] imported function " << funcName << "as"
                  << globalFuncName << " from " << namespaceAlias << "\n";
      }
    }

    return nullptr;
  }
  virtual std::any visitProgram(VLParser::ProgramContext *ctx) override {
    if (debugMode) {
      std::cerr << "[debug] started the program";
    }
    for (auto imp : ctx->importStmt()) {
      visitImportStmt(imp);
    }
    for (auto funcCtx : ctx->functionDecl()) {
      visitFunctionDecl(funcCtx);
    }
    if (ctx->block()) {
      visitBlock(ctx->block());
    }
    return nullptr;
  }

  virtual std::any visitBlock(VLParser::BlockContext *ctx) override {
    enterScope();
    std::any result = visitChildren(ctx);
    exitScope();
    return result;
  }

  // DECLARAÇÕES E VARIÁVEIS
  virtual std::any
  visitCreateDeclStmt(VLParser::CreateDeclStmtContext *ctx) override {
    std::string name = ctx->ID()->getText();
    Type type = parseType(ctx->dataType());

    if (scopes.back().find(name) != scopes.back().end()) {
      throw std::runtime_error("Erro: Variável '" + name +
                               "' já declarada neste escopo.");
    }

    scopes.back()[name] = Symbol{Thing(""), false, type, false, {}};
    return nullptr;
  }

  virtual std::any
  visitCreateInitStmt(VLParser::CreateInitStmtContext *ctx) override {
    std::string name = ctx->ID()->getText();
    bool isConst = ctx->mutability()->getText() == "const";
    Type type = parseType(ctx->dataType());

    if (scopes.back().find(name) != scopes.back().end()) {
      throw std::runtime_error("Erro: Identificador '" + name +
                               "' já declarado.");
    }

    std::vector<std::string> arrVals;
    std::string valStr = "";

    if (ctx->arrayLiteral()) {
      for (auto lit : ctx->arrayLiteral()->literal()) {
        arrVals.push_back(cleanLiteralText(lit->getText()));
      }
    } else if (ctx->expr()) {
      ResolvedArg res = evaluateExpr(ctx->expr());
      valStr = res.value;
      arrVals = res.arrayValues;
    }

    scopes.back()[name] = Symbol{Thing(valStr), isConst, type, true, arrVals};
    return nullptr;
  }

  virtual std::any
  visitSetPropertyStmt(VLParser::SetPropertyStmtContext *ctx) override {
    std::string targetName = ctx->ID()->getText();
    Symbol *sym = findSymbol(targetName);

    if (!sym)
      throw std::runtime_error("Erro: Variável '" + targetName +
                               "' não declarada.");
    if (sym->isConstant)
      throw std::runtime_error("Erro: Constante '" + targetName +
                               "' não pode ser alterada.");

    ResolvedArg res = evaluateExpr(ctx->expr());
    sym->value = Thing(res.value);
    sym->arrayValues = res.arrayValues;
    sym->isInitialized = true;

    return nullptr;
  }

  virtual std::any
  visitSetArrayItemStmt(VLParser::SetArrayItemStmtContext *ctx) override {
    std::string arrName = ctx->ID()->getText();
    Symbol *sym = findSymbol(arrName);

    if (!sym)
      throw std::runtime_error("Erro: Array '" + arrName + "' não encontrado.");

    int index = std::stoi(evaluateExpr(ctx->expr(0)).value);
    ResolvedArg valRes = evaluateExpr(ctx->expr(1));

    if (index < 0 || index >= (int)sym->arrayValues.size()) {
      throw std::runtime_error("Erro: Índice fora dos limites.");
    }

    sym->arrayValues[index] = valRes.value;
    return nullptr;
  }

  virtual std::any visitPrintStmt(VLParser::PrintStmtContext *ctx) override {
    // Delegate to built-in print function
    ResolvedArg res = evaluateExpr(ctx->expr());
    auto it = builtins.find("print");
    if (it != builtins.end()) {
      std::vector<ResolvedArg> args{res};
      it->second(args);
      return nullptr;
    }

    // Fallback behavior
    std::cout << res.value << std::endl << std::flush;
    return nullptr;
  }

  // FUNÇÕES E RETORNO
  virtual std::any
  visitMethodCallStmt(VLParser::MethodCallStmtContext *ctx) override {
    std::string targetName =
        ctx->target->getText(); // Ex: "texto" ou "meu_array"
    std::string methodName =
        ctx->funcName->getText(); // Ex: "to_lower", "push", "len"

    Symbol *sym = findSymbol(targetName);
    if (!sym) {
      throw std::runtime_error("Erro: Variável '" + targetName +
                               "' não encontrada.");
    }

    // -------------------------------------------------------------
    // MÉTODOS PARA STRINGS
    // -------------------------------------------------------------
    if (!sym->type.isArray && sym->type.name == "string") {
      if (methodName == "to_upper") {
        std::string val = sym->value.toString();
        // Transforma em maiúsculas
        for (auto &c : val)
          c = toupper(c);
        return ResolvedArg{val, {}};
      }
      if (methodName == "to_int") {
        return ResolvedArg{sym->value.toString(), {}};
      }
      if (methodName == "to_lower") {
        std::string val = sym->value.toString();
        for (auto &c : val)
          c = tolower(c);
        return ResolvedArg{val, {}};
      }
      if (methodName == "len") {
        return ResolvedArg{std::to_string(sym->value.toString().size()), {}};
      }
      throw std::runtime_error("Erro: O tipo 'string' não possui o método '" +
                               methodName + "'.");
    }

    // -------------------------------------------------------------
    // MÉTODOS PARA INTEIROS (INT)
    // -------------------------------------------------------------
    if (!sym->type.isArray && sym->type.name == "int") {
      // Inteiro não precisa de to_lower nem to_string se ele já é int,
      // mas poderia ter métodos como .to_str() se desejado.
      if (methodName == "to_string") {
        return ResolvedArg{sym->value.toString(), {}};
      }
      throw std::runtime_error("Erro: O tipo 'int' não possui o método '" +
                               methodName + "'.");
    }

    // -------------------------------------------------------------
    // MÉTODOS PARA ARRAYS ([]int, []string, etc.)
    // -------------------------------------------------------------
    if (sym->type.isArray) {
      if (methodName == "len") {
        return ResolvedArg{std::to_string(sym->arrayValues.size()), {}};
      }
      if (methodName == "push") {
        auto args = ctx->argList()->expr();
        ResolvedArg val = evaluateExpr(args[0]);
        sym->arrayValues.push_back(val.value);
        return ResolvedArg{"", {}};
      }
      if (methodName == "pop") {
        if (sym->arrayValues.empty()) {
          throw std::runtime_error("Erro: Tentativa de 'pop' em array vazio.");
        }
        std::string lastVal = sym->arrayValues.back();
        sym->arrayValues.pop_back();
        return ResolvedArg{lastVal, {}};
      }
      throw std::runtime_error("Erro: O tipo 'array' não possui o método '" +
                               methodName + "'.");
    }

    throw std::runtime_error("Erro: Tipo desconhecido para chamada de método.");
  }
  virtual std::any
  visitFunctionDecl(VLParser::FunctionDeclContext *ctx) override {
    std::string funcName = ctx->ID()->getText();
    Type returnType =
        ctx->dataType() ? parseType(ctx->dataType()) : Type{"void"};

    if (functionTable.find(funcName) != functionTable.end()) {
      throw std::runtime_error("Erro: Função '" + funcName + "' já declarada.");
    }

    std::vector<Parameter> params;
    if (ctx->paramList()) {
      for (auto paramCtx : ctx->paramList()->param()) {
        params.push_back(
            {paramCtx->ID()->getText(), parseType(paramCtx->dataType())});
      }
    }

    bool isPublic = (ctx->visibility() != nullptr);
    // Use the main parser's token stream (provided at Interpreter construction)
    if (tokenStream) {
      auto interval = ctx->block()->getSourceInterval();
      std::string blockText = getTextFromTokenInterval(tokenStream, interval);
      functionTable[funcName] =
          FunctionSymbol{params, returnType, blockText, isPublic};
    } else {
      // Fallback to getText() if no token stream is available
      functionTable[funcName] =
          FunctionSymbol{params, returnType, ctx->block()->getText(), isPublic};
    }
    if (debugMode) {
      std::cerr << "[debug] registered function " << funcName
                << " with params (" << formatParams(params)
                << ") and return type " << formatType(returnType) << "\n";
    }
    return nullptr;
  }

  virtual std::any
  visitFunctionCallStmt(VLParser::FunctionCallStmtContext *ctx) override {

    std::string targetName;

    bool isExternalCall = (ctx->namespace_ != nullptr);

    if (!isExternalCall) {
      targetName = ctx->funcName->getText();

      Symbol *sym = findSymbol(targetName);
      if (sym && sym->isInitialized && !sym->value.toString().empty() &&
          functionTable.find(sym->value.toString()) != functionTable.end()) {
        targetName = sym->value.toString();
      }
      if (debugMode) {
        std::cerr << "[debug] call " << ctx->funcName->getText() << " -> "
                  << targetName
                  << " | value=" << (sym ? sym->value.toString() : "<none>")
                  << std::endl;
      }
    } else {
      targetName = ctx->namespace_->getText() + "." + ctx->funcName->getText();
    }

    std::vector<VLParser::ExprContext *> args;
    if (ctx->argList()) {
      args = ctx->argList()->expr();
    }

    // 3. Built-in functions check
    if (!isExternalCall) {
      auto bit = builtins.find(targetName);
      if (bit != builtins.end()) {
        // evaluate args
        std::vector<ResolvedArg> callArgs;
        if (ctx->argList()) {
          for (auto a : ctx->argList()->expr())
            callArgs.push_back(evaluateExpr(a));
        }
        ResolvedArg r = bit->second(callArgs);
        // If built-in returned a value, pack it
        return r;
      }
    }
    // 4. Busca na tabela global de funções
    auto it = functionTable.find(targetName);
    if (it == functionTable.end()) {
      throw std::runtime_error("Erro: Função '" + targetName +
                               "' não encontrada.");
    }

    FunctionSymbol func = it->second;

    if (isExternalCall && !func.isPublic) {
      throw std::runtime_error(
          "Erro de Acesso: A função '" + targetName +
          "' é privada e não pode ser chamada fora do seu módulo.");
    }

    if (args.size() != func.params.size()) {
      throw std::runtime_error(
          "Erro: Quantidade de argumentos incorreta na chamada da função '" +
          targetName + "'.");
    }

    // Avalia os argumentos no escopo atual
    std::vector<ResolvedArg> resolvedArgs;
    for (size_t i = 0; i < args.size(); ++i) {
      ResolvedArg argValue = evaluateExpr(args[i]);
      resolvedArgs.push_back(argValue);
    }

    // Prepara as variáveis dos parâmetros para o bloco que será visitado
    // Nota: O visitBlock vai criar o escopo local, inserimos os parâmetros
    // temporariamente na pilha ajustando o escopo
    enterScope();
    for (size_t i = 0; i < func.params.size(); ++i) {
      scopes.back()[func.params[i].name] =
          Symbol{Thing(resolvedArgs[i].value), false, func.params[i].type, true,
                 resolvedArgs[i].arrayValues};
    }

    ResolvedArg returnArg{"", {}};
    try {
      // Parse the stored bodyText into a fresh parser so the BlockContext is
      // owned by this parser instance (avoids dangling pointers from imports)
      antlr4::ANTLRInputStream input(func.bodyText);
      VLLexer lexer(&input);
      antlr4::CommonTokenStream tokens(&lexer);
      VLParser parser(&tokens);
      VLParser::BlockContext *blockCtx = parser.block();

      // Como já criamos um escopo com os parâmetros acima, visitamos
      // diretamente as crianças do bloco para evitar criar um escopo extra.
      visitChildren(blockCtx);
    } catch (const ReturnException &e) {
      returnArg.value = e.value;
      returnArg.arrayValues = e.arrayValues;
    }

    exitScope();
    return returnArg;
  }

  virtual std::any visitReturnStmt(VLParser::ReturnStmtContext *ctx) override {
    ResolvedArg res{"", {}};
    if (ctx->expr()) {
      res = evaluateExpr(ctx->expr());
    }
    if (debugMode) {
      std::cerr << "[debug] return " << res.value << std::endl;
    }
    throw ReturnException{res.value, res.arrayValues};
  }

  // ESTRUTURAS DE CONTROLE
  virtual std::any visitIfStmt(VLParser::IfStmtContext *ctx) override {
    if (debugMode) {
      std::cerr << "[debug] if condition: " << ctx->condStmt()->getText()
                << std::endl;
    }
    if (std::any_cast<bool>(visit(ctx->condStmt()))) {
      visit(ctx->block());
    }
    return nullptr;
  }

  virtual std::any visitLoopStmt(VLParser::LoopStmtContext *ctx) override {
    if (debugMode) {
      std::cerr << "[debug] loop start" << std::endl;
    }
    int n = 1;
    while (std::any_cast<bool>(visit(ctx->condStmt()))) {
      if (debugMode) {
        std::cerr << "[debug] " << n << " loop iteration" << std::endl;
      }
      visit(ctx->block());
      n++;
    }
    return nullptr;
  }

  virtual std::any visitCondStmt(VLParser::CondStmtContext *ctx) override {
    ResolvedArg leftRes = evaluateExpr(ctx->left);
    ResolvedArg rightRes = evaluateExpr(ctx->right);
    std::string op = ctx->comparisonOp()->getText();

    try {
      int l = std::stoi(leftRes.value);
      int r = std::stoi(rightRes.value);

      if (op == "==") {
        bool returnVal = l == r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      if (op == "!=") {
        bool returnVal = l != r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      if (op == ">=") {
        bool returnVal = l >= r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      if (op == "<=") {
        bool returnVal = l <= r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      if (op == ">") {
        bool returnVal = l > r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return l > r;
      }
      if (op == "<") {
        bool returnVal = l < r;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
    } catch (...) {
      if (op == "==") {
        bool returnVal = leftRes.value == rightRes.value;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      if (op == "!=") {
        bool returnVal = leftRes.value != rightRes.value;
        if (debugMode) {
          std::cerr << "[debug] cond: " << leftRes.value << " " << op << " "
                    << rightRes.value << "returned: " << returnVal << "\n";
        }
        return returnVal;
      }
      throw std::runtime_error(
          "Erro: Operador de comparação incompatível com os tipos fornecidos.");
    }

    return false;
  }

  // Dump interpreter state for debugging/crash reports
  std::string dumpState() const {
    std::ostringstream out;
    out << "Functions:\n";
    for (const auto &kv : functionTable) {
      out << "  " << kv.first << "(";
      const auto &params = kv.second.params;
      for (size_t i = 0; i < params.size(); ++i) {
        out << params[i].name << ":";
        // stringify type (recursive)
        std::function<std::string(const Type &)> t2s;
        t2s = [&](const Type &t) -> std::string {
          std::ostringstream s;
          if (t.isFunction) {
            s << "fn(";
            for (size_t j = 0; j < t.parameters.size(); ++j) {
              if (j)
                s << ",";
              s << t2s(t.parameters[j]);
            }
            s << ") -> ";
            if (t.returnType)
              s << t2s(*t.returnType);
            else
              s << "void";
          } else {
            s << t.name;
            if (t.isArray)
              s << "[]";
          }
          return s.str();
        };
        out << t2s(params[i].type);
        if (i + 1 < params.size())
          out << ", ";
      }
      out << ") -> "
          << (kv.second.returnType.name.empty() ? std::string("void")
                                                : kv.second.returnType.name)
          << "\n";
    }
    out << "Imported modules: " << importedModules.size() << "\n";
    for (const auto &m : importedModules)
      out << "  - " << m.name << "\n";
    out << "Scopes (count): " << scopes.size() << "\n";
    if (!scopes.empty()) {
      out << "Top scope variables:\n";
      const auto &top = scopes.back();
      for (const auto &v : top) {
        out << "  " << v.first << " : " << v.second.type.name;
        if (v.second.type.isArray)
          out << "[]";
        out << (v.second.isInitialized ? " [init]" : " [uninit]") << "\n";
      }
    }
    return out.str();
  }
};
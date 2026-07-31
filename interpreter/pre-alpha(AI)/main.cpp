#include "include/Interpreter.h"
#include "include/VL.h"
#include <antlr4-runtime/antlr4-runtime.h>
#include <fstream>
#include <iostream>

// Função para exibir a ajuda do programa
void printHelp(const char *programName) {
  std::cout << "Uso: " << programName << " [opcoes] <arquivo.verb>\n";
  std::cout << "Opcoes:\n";
  std::cout << "  -h, --help     Mostra esta mensagem de ajuda\n";
  std::cout << "  -d, --debug    Ativa o modo de /debug de estados do "
               "interpretador\n";
}

int main(int argc, const char *argv[]) {
  std::string filename = "";
  bool debugFlag = false;

  // 1. Processamento de argumentos e flags da linha de comando
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "--help" || arg == "-h") {
      printHelp(argv[0]);
      return 0;
    } else if (arg == "--debug" || arg == "-d") {
      debugFlag = true;
    } else {
      // Se não for flag, assumimos que é o arquivo de código fonte
      filename = arg;
    }
  }

  // Se nenhum arquivo foi passado, usa o padrão "script.verb"
  if (filename.empty()) {
    filename = "s.vl";
  }

  std::ifstream stream(filename);
  if (!stream.is_open()) {
    std::cerr << "Erro: Nao foi possivel abrir o arquivo " << filename
              << std::endl;
    return 1;
  }

  // 2. Processa a entrada de texto (ANTLR)
  antlr4::ANTLRInputStream input(stream);
  VLLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  VLParser parser(&tokens);

  // 3. Monta a AST
  VLParser::ProgramContext *tree = parser.program();

  // 4. Inicializa o interpretador repassando os tokens e a flag de debug
  // (Nota: verifique se o construtor do seu Interpreter.h aceita o booleano de
  // debug, ou se você o configura via método, ex: visitor.setDebug(true))
  Interpreter visitor(&tokens);
  visitor.setDebug(debugFlag); // Ativa o modo de debug se a flag estiver setada
  // Se o seu Interpreter.h tiver um método para ativar o debug, chame-o aqui:
  // visitor.setDebug(debugFlag);

  visitor.visit(tree);

  return 0;
}
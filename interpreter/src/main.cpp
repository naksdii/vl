#include <iostream>
#include <fstream>
#include <antlr4-runtime/antlr4-runtime.h>
#include "include/VL.h"
#include "include/Interpreter.h"


int main(int argc, const char* argv[]) {
    // Se o usuário não passar um arquivo, usa "script.verb" como padrão
    std::string filename = "script.verb";
    if (argc > 1) {
        filename = argv[1];
    }

    std::ifstream stream(filename);
    if (!stream.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo " << filename << std::endl;
        return 1;
    }
    
    // 1. Processa a entrada de texto
    antlr4::ANTLRInputStream input(stream);
    VLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    VLParser parser(&tokens);

    // 2. Monta a AST
    VLParser::ProgramContext* tree = parser.program();


    // 3. Execute interpreter
    Interpreter visitor(&tokens);

    visitor.visit(tree);

    return 0;
}

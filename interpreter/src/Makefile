# --- Configuration ---
TARGET        = verbios_lang
CXX           = g++
CXXFLAGS      = -std=c++17 -O3 -I/usr/include/antlr4-runtime -I. -Iinclude -Iparser
LDFLAGS       = -lantlr4-runtime -lpthread

# --- ANTLR Configuration ---
GRAMMAR_FILE  = VL.g4
GRAMMAR_DIR   = parser
GRAMMAR_PATH  = $(GRAMMAR_DIR)/$(GRAMMAR_FILE)

# --- Rules ---
all: antlr build_target

# 1. Garante que o ANTLR roda primeiro e gera os arquivos
antlr: $(GRAMMAR_PATH)
	@echo "--- Executando ANTLR4 ---"
	cd $(GRAMMAR_DIR) && antlr4 -Dlanguage=Cpp -visitor $(GRAMMAR_FILE)

# 2. Avalia os arquivos e compila o binário em um segundo passo protegido
build_target: antlr
	@$(MAKE) --no-print-directory internal_build

# --- Source and Object Files (Avaliados sob demanda) ---
USER_SRCS     = main.cpp
PARSER_SRCS   = $(wildcard $(GRAMMAR_DIR)/*.cpp)
ALL_SRCS      = $(USER_SRCS) $(PARSER_SRCS)
OBJS          = $(ALL_SRCS:.cpp=.o)

internal_build: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "--- Compilação concluída com sucesso! ---"

# Compile root source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile parser source files into object files
$(GRAMMAR_DIR)/%.o: $(GRAMMAR_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	rm -f *.o $(GRAMMAR_DIR)/*.o $(TARGET)

# Clean everything including ANTLR-generated files
clean-all: clean
	rm -f $(GRAMMAR_DIR)/VLBase* $(GRAMMAR_DIR)/VLParser* $(GRAMMAR_DIR)/VLLexer* \
	      $(GRAMMAR_DIR)/VLVisitor* $(GRAMMAR_DIR)/VLListener* \
	      $(GRAMMAR_DIR)/*.interp $(GRAMMAR_DIR)/*.tokens

.PHONY: all antlr build_target internal_build clean clean-all run
run: $(TARGET)
	./$(TARGET)
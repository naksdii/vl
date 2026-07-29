# --- Configuration ---
TARGET        = verbose_lang
CXX           = g++
CXXFLAGS      = -std=c++17 -O3 -I/usr/include/antlr4-runtime -I. -Iinclude -Iparser
LDFLAGS       = -lantlr4-runtime

# --- ANTLR Configuration ---
GRAMMAR_FILE  = VL.g4
GRAMMAR_DIR   = parser
GRAMMAR_PATH  = $(GRAMMAR_DIR)/$(GRAMMAR_FILE)

# Generated files by ANTLR4
ANTLR_GEN_FILES = $(GRAMMAR_DIR)/VLLexer.cpp $(GRAMMAR_DIR)/VLParser.cpp \
                  $(GRAMMAR_DIR)/VLVisitor.cpp $(GRAMMAR_DIR)/VLListener.cpp

# --- Source and Object Files ---
# Find manual source files and add generated parser files
USER_SRCS     = $(wildcard *.cpp)
ALL_SRCS      = $(USER_SRCS) $(wildcard $(GRAMMAR_DIR)/*.cpp)
OBJS          = $(ALL_SRCS:.cpp=.o)

# --- Rules ---
all: antlr $(TARGET)

# Run ANTLR4 to generate C++ files if the grammar file changed
antlr: $(GRAMMAR_PATH)
	@echo "--- Executando ANTLR4 ---"
	cd $(GRAMMAR_DIR) && antlr4 -Dlanguage=Cpp -visitor $(GRAMMAR_FILE)

# Link the final executable (depends on antlr first to ensure files exist)
$(TARGET): antlr $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "--- Compilação concluída com sucesso! ---"

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	rm -f *.o $(GRAMMAR_DIR)/*.o $(TARGET)

# Clean everything including ANTLR-generated files
clean-all: clean
	rm -f $(GRAMMAR_DIR)/VLBase* $(GRAMMAR_DIR)/VLParser* $(GRAMMAR_DIR)/VLLexer* \
	      $(GRAMMAR_DIR)/VLVisitor* $(GRAMMAR_DIR)/VLListener* \
	      $(GRAMMAR_DIR)/*.interp $(GRAMMAR_DIR)/*.tokens

.PHONY: all antlr clean clean-all
run: $(TARGET)
	./$(TARGET)
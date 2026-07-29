
// Generated from VL.g4 by ANTLR 4.13.2


#include "VLListener.h"
#include "VLVisitor.h"

#include "VLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VLParserStaticData final {
  VLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VLParserStaticData(const VLParserStaticData&) = delete;
  VLParserStaticData(VLParserStaticData&&) = delete;
  VLParserStaticData& operator=(const VLParserStaticData&) = delete;
  VLParserStaticData& operator=(VLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag vlParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<VLParserStaticData> vlParserStaticData = nullptr;

void vlParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vlParserStaticData != nullptr) {
    return;
  }
#else
  assert(vlParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VLParserStaticData>(
    std::vector<std::string>{
      "program", "importStmt", "block", "functionDecl", "visibility", "paramList", 
      "param", "statement", "createDeclStmt", "createInitStmt", "mutability", 
      "setPropertyStmt", "setArrayItemStmt", "printStmt", "returnStmt", 
      "expr", "primary", "methodCallStmt", "functionCallStmt", "arrayAccess", 
      "argList", "ifStmt", "loopStmt", "condStmt", "comparisonOp", "dataType", 
      "primitiveType", "arrayType", "functionType", "typeList", "arrayLiteral", 
      "literal"
    },
    std::vector<std::string>{
      "", "'import'", "'as'", "'exec'", "'{'", "'}'", "'fn'", "'=>'", "'('", 
      "')'", "'opn'", "','", "'mut'", "'='", "'const'", "'set'", "'['", 
      "']'", "'print'", "'return'", "'*'", "'/'", "'%'", "'+'", "'-'", "'->'", 
      "'.'", "'if'", "'while'", "'=='", "'!='", "'>='", "'<='", "'>'", "'<'", 
      "'void'", "'[]'", "';'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "SEMI", "BOOL", "FLOAT", "INT", "STRING", "ID", "WS", 
      "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,318,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,1,0,5,0,66,8,0,10,0,12,0,69,9,0,1,0,
  	5,0,72,8,0,10,0,12,0,75,9,0,1,0,3,0,78,8,0,1,0,1,0,1,1,1,1,1,1,1,1,3,
  	1,86,8,1,1,1,1,1,1,2,1,2,1,2,5,2,93,8,2,10,2,12,2,96,9,2,1,2,1,2,1,3,
  	3,3,101,8,3,1,3,1,3,1,3,1,3,3,3,107,8,3,1,3,1,3,3,3,111,8,3,1,3,1,3,1,
  	3,1,4,1,4,1,5,1,5,1,5,5,5,121,8,5,10,5,12,5,124,9,5,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,156,8,7,1,8,1,8,1,8,1,8,1,8,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,3,9,170,8,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,3,14,194,8,14,1,15,1,15,1,15,1,15,1,15,1,15,3,15,202,8,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,5,15,210,8,15,10,15,12,15,213,9,15,1,16,1,16,1,
  	16,1,16,1,16,3,16,220,8,16,1,17,1,17,1,17,1,17,1,17,3,17,227,8,17,1,17,
  	1,17,1,18,1,18,3,18,233,8,18,1,18,1,18,1,18,3,18,238,8,18,1,18,1,18,1,
  	19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,5,20,250,8,20,10,20,12,20,253,9,
  	20,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,
  	23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,25,3,25,277,8,25,1,26,1,26,1,
  	27,1,27,1,27,1,28,1,28,1,28,3,28,287,8,28,1,28,1,28,3,28,291,8,28,1,28,
  	1,28,1,29,1,29,1,29,5,29,298,8,29,10,29,12,29,301,9,29,1,30,1,30,1,30,
  	1,30,5,30,307,8,30,10,30,12,30,310,9,30,3,30,312,8,30,1,30,1,30,1,31,
  	1,31,1,31,0,1,30,32,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,50,52,54,56,58,60,62,0,5,2,0,12,12,14,14,1,0,20,
  	22,1,0,23,24,1,0,29,34,1,0,38,41,324,0,67,1,0,0,0,2,81,1,0,0,0,4,89,1,
  	0,0,0,6,100,1,0,0,0,8,115,1,0,0,0,10,117,1,0,0,0,12,125,1,0,0,0,14,155,
  	1,0,0,0,16,157,1,0,0,0,18,162,1,0,0,0,20,171,1,0,0,0,22,173,1,0,0,0,24,
  	178,1,0,0,0,26,186,1,0,0,0,28,191,1,0,0,0,30,201,1,0,0,0,32,219,1,0,0,
  	0,34,221,1,0,0,0,36,232,1,0,0,0,38,241,1,0,0,0,40,246,1,0,0,0,42,254,
  	1,0,0,0,44,260,1,0,0,0,46,266,1,0,0,0,48,270,1,0,0,0,50,276,1,0,0,0,52,
  	278,1,0,0,0,54,280,1,0,0,0,56,283,1,0,0,0,58,294,1,0,0,0,60,302,1,0,0,
  	0,62,315,1,0,0,0,64,66,3,2,1,0,65,64,1,0,0,0,66,69,1,0,0,0,67,65,1,0,
  	0,0,67,68,1,0,0,0,68,73,1,0,0,0,69,67,1,0,0,0,70,72,3,6,3,0,71,70,1,0,
  	0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,77,1,0,0,0,75,73,1,0,
  	0,0,76,78,3,4,2,0,77,76,1,0,0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,5,0,
  	0,1,80,1,1,0,0,0,81,82,5,1,0,0,82,85,5,41,0,0,83,84,5,2,0,0,84,86,5,42,
  	0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,87,1,0,0,0,87,88,5,37,0,0,88,3,1,0,
  	0,0,89,90,5,3,0,0,90,94,5,4,0,0,91,93,3,14,7,0,92,91,1,0,0,0,93,96,1,
  	0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,1,0,0,0,96,94,1,0,0,0,97,98,5,
  	5,0,0,98,5,1,0,0,0,99,101,3,8,4,0,100,99,1,0,0,0,100,101,1,0,0,0,101,
  	102,1,0,0,0,102,103,5,6,0,0,103,106,5,42,0,0,104,105,5,7,0,0,105,107,
  	3,50,25,0,106,104,1,0,0,0,106,107,1,0,0,0,107,108,1,0,0,0,108,110,5,8,
  	0,0,109,111,3,10,5,0,110,109,1,0,0,0,110,111,1,0,0,0,111,112,1,0,0,0,
  	112,113,5,9,0,0,113,114,3,4,2,0,114,7,1,0,0,0,115,116,5,10,0,0,116,9,
  	1,0,0,0,117,122,3,12,6,0,118,119,5,11,0,0,119,121,3,12,6,0,120,118,1,
  	0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,11,1,0,0,0,
  	124,122,1,0,0,0,125,126,5,42,0,0,126,127,5,7,0,0,127,128,3,50,25,0,128,
  	13,1,0,0,0,129,130,3,16,8,0,130,131,5,37,0,0,131,156,1,0,0,0,132,133,
  	3,18,9,0,133,134,5,37,0,0,134,156,1,0,0,0,135,136,3,22,11,0,136,137,5,
  	37,0,0,137,156,1,0,0,0,138,139,3,24,12,0,139,140,5,37,0,0,140,156,1,0,
  	0,0,141,142,3,26,13,0,142,143,5,37,0,0,143,156,1,0,0,0,144,145,3,36,18,
  	0,145,146,5,37,0,0,146,156,1,0,0,0,147,148,3,34,17,0,148,149,5,37,0,0,
  	149,156,1,0,0,0,150,151,3,28,14,0,151,152,5,37,0,0,152,156,1,0,0,0,153,
  	156,3,42,21,0,154,156,3,44,22,0,155,129,1,0,0,0,155,132,1,0,0,0,155,135,
  	1,0,0,0,155,138,1,0,0,0,155,141,1,0,0,0,155,144,1,0,0,0,155,147,1,0,0,
  	0,155,150,1,0,0,0,155,153,1,0,0,0,155,154,1,0,0,0,156,15,1,0,0,0,157,
  	158,5,12,0,0,158,159,5,42,0,0,159,160,5,7,0,0,160,161,3,50,25,0,161,17,
  	1,0,0,0,162,163,3,20,10,0,163,164,5,42,0,0,164,165,5,7,0,0,165,166,3,
  	50,25,0,166,169,5,13,0,0,167,170,3,60,30,0,168,170,3,30,15,0,169,167,
  	1,0,0,0,169,168,1,0,0,0,170,19,1,0,0,0,171,172,7,0,0,0,172,21,1,0,0,0,
  	173,174,5,15,0,0,174,175,5,42,0,0,175,176,5,13,0,0,176,177,3,30,15,0,
  	177,23,1,0,0,0,178,179,5,15,0,0,179,180,5,42,0,0,180,181,5,16,0,0,181,
  	182,3,30,15,0,182,183,5,17,0,0,183,184,5,13,0,0,184,185,3,30,15,0,185,
  	25,1,0,0,0,186,187,5,18,0,0,187,188,5,8,0,0,188,189,3,30,15,0,189,190,
  	5,9,0,0,190,27,1,0,0,0,191,193,5,19,0,0,192,194,3,30,15,0,193,192,1,0,
  	0,0,193,194,1,0,0,0,194,29,1,0,0,0,195,196,6,15,-1,0,196,197,5,8,0,0,
  	197,198,3,30,15,0,198,199,5,9,0,0,199,202,1,0,0,0,200,202,3,32,16,0,201,
  	195,1,0,0,0,201,200,1,0,0,0,202,211,1,0,0,0,203,204,10,4,0,0,204,205,
  	7,1,0,0,205,210,3,30,15,5,206,207,10,3,0,0,207,208,7,2,0,0,208,210,3,
  	30,15,4,209,203,1,0,0,0,209,206,1,0,0,0,210,213,1,0,0,0,211,209,1,0,0,
  	0,211,212,1,0,0,0,212,31,1,0,0,0,213,211,1,0,0,0,214,220,3,34,17,0,215,
  	220,3,36,18,0,216,220,3,38,19,0,217,220,3,62,31,0,218,220,5,42,0,0,219,
  	214,1,0,0,0,219,215,1,0,0,0,219,216,1,0,0,0,219,217,1,0,0,0,219,218,1,
  	0,0,0,220,33,1,0,0,0,221,222,5,42,0,0,222,223,5,25,0,0,223,224,5,42,0,
  	0,224,226,5,8,0,0,225,227,3,40,20,0,226,225,1,0,0,0,226,227,1,0,0,0,227,
  	228,1,0,0,0,228,229,5,9,0,0,229,35,1,0,0,0,230,231,5,42,0,0,231,233,5,
  	26,0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,234,1,0,0,0,234,235,5,42,0,
  	0,235,237,5,8,0,0,236,238,3,40,20,0,237,236,1,0,0,0,237,238,1,0,0,0,238,
  	239,1,0,0,0,239,240,5,9,0,0,240,37,1,0,0,0,241,242,5,42,0,0,242,243,5,
  	16,0,0,243,244,3,30,15,0,244,245,5,17,0,0,245,39,1,0,0,0,246,251,3,30,
  	15,0,247,248,5,11,0,0,248,250,3,30,15,0,249,247,1,0,0,0,250,253,1,0,0,
  	0,251,249,1,0,0,0,251,252,1,0,0,0,252,41,1,0,0,0,253,251,1,0,0,0,254,
  	255,5,27,0,0,255,256,5,8,0,0,256,257,3,46,23,0,257,258,5,9,0,0,258,259,
  	3,4,2,0,259,43,1,0,0,0,260,261,5,28,0,0,261,262,5,8,0,0,262,263,3,46,
  	23,0,263,264,5,9,0,0,264,265,3,4,2,0,265,45,1,0,0,0,266,267,3,30,15,0,
  	267,268,3,48,24,0,268,269,3,30,15,0,269,47,1,0,0,0,270,271,7,3,0,0,271,
  	49,1,0,0,0,272,277,3,56,28,0,273,277,3,54,27,0,274,277,3,52,26,0,275,
  	277,5,35,0,0,276,272,1,0,0,0,276,273,1,0,0,0,276,274,1,0,0,0,276,275,
  	1,0,0,0,277,51,1,0,0,0,278,279,5,42,0,0,279,53,1,0,0,0,280,281,5,36,0,
  	0,281,282,3,50,25,0,282,55,1,0,0,0,283,286,5,6,0,0,284,285,5,7,0,0,285,
  	287,3,50,25,0,286,284,1,0,0,0,286,287,1,0,0,0,287,288,1,0,0,0,288,290,
  	5,8,0,0,289,291,3,58,29,0,290,289,1,0,0,0,290,291,1,0,0,0,291,292,1,0,
  	0,0,292,293,5,9,0,0,293,57,1,0,0,0,294,299,3,50,25,0,295,296,5,11,0,0,
  	296,298,3,50,25,0,297,295,1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,
  	300,1,0,0,0,300,59,1,0,0,0,301,299,1,0,0,0,302,311,5,16,0,0,303,308,3,
  	62,31,0,304,305,5,11,0,0,305,307,3,62,31,0,306,304,1,0,0,0,307,310,1,
  	0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,
  	311,303,1,0,0,0,311,312,1,0,0,0,312,313,1,0,0,0,313,314,5,17,0,0,314,
  	61,1,0,0,0,315,316,7,4,0,0,316,63,1,0,0,0,26,67,73,77,85,94,100,106,110,
  	122,155,169,193,201,209,211,219,226,232,237,251,276,286,290,299,308,311
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vlParserStaticData = std::move(staticData);
}

}

VLParser::VLParser(TokenStream *input) : VLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VLParser::VLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vlParserStaticData->atn, vlParserStaticData->decisionToDFA, vlParserStaticData->sharedContextCache, options);
}

VLParser::~VLParser() {
  delete _interpreter;
}

const atn::ATN& VLParser::getATN() const {
  return *vlParserStaticData->atn;
}

std::string VLParser::getGrammarFileName() const {
  return "VL.g4";
}

const std::vector<std::string>& VLParser::getRuleNames() const {
  return vlParserStaticData->ruleNames;
}

const dfa::Vocabulary& VLParser::getVocabulary() const {
  return vlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VLParser::getSerializedATN() const {
  return vlParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

VLParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::ProgramContext::EOF() {
  return getToken(VLParser::EOF, 0);
}

std::vector<VLParser::ImportStmtContext *> VLParser::ProgramContext::importStmt() {
  return getRuleContexts<VLParser::ImportStmtContext>();
}

VLParser::ImportStmtContext* VLParser::ProgramContext::importStmt(size_t i) {
  return getRuleContext<VLParser::ImportStmtContext>(i);
}

std::vector<VLParser::FunctionDeclContext *> VLParser::ProgramContext::functionDecl() {
  return getRuleContexts<VLParser::FunctionDeclContext>();
}

VLParser::FunctionDeclContext* VLParser::ProgramContext::functionDecl(size_t i) {
  return getRuleContext<VLParser::FunctionDeclContext>(i);
}

VLParser::BlockContext* VLParser::ProgramContext::block() {
  return getRuleContext<VLParser::BlockContext>(0);
}


size_t VLParser::ProgramContext::getRuleIndex() const {
  return VLParser::RuleProgram;
}

void VLParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void VLParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any VLParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ProgramContext* VLParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, VLParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VLParser::T__0) {
      setState(64);
      importStmt();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VLParser::T__5

    || _la == VLParser::T__9) {
      setState(70);
      functionDecl();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::T__2) {
      setState(76);
      block();
    }
    setState(79);
    match(VLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStmtContext ------------------------------------------------------------------

VLParser::ImportStmtContext::ImportStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::ImportStmtContext::STRING() {
  return getToken(VLParser::STRING, 0);
}

tree::TerminalNode* VLParser::ImportStmtContext::SEMI() {
  return getToken(VLParser::SEMI, 0);
}

tree::TerminalNode* VLParser::ImportStmtContext::ID() {
  return getToken(VLParser::ID, 0);
}


size_t VLParser::ImportStmtContext::getRuleIndex() const {
  return VLParser::RuleImportStmt;
}

void VLParser::ImportStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStmt(this);
}

void VLParser::ImportStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStmt(this);
}


std::any VLParser::ImportStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitImportStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ImportStmtContext* VLParser::importStmt() {
  ImportStmtContext *_localctx = _tracker.createInstance<ImportStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, VLParser::RuleImportStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(VLParser::T__0);
    setState(82);
    match(VLParser::STRING);
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::T__1) {
      setState(83);
      match(VLParser::T__1);
      setState(84);
      match(VLParser::ID);
    }
    setState(87);
    match(VLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

VLParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VLParser::StatementContext *> VLParser::BlockContext::statement() {
  return getRuleContexts<VLParser::StatementContext>();
}

VLParser::StatementContext* VLParser::BlockContext::statement(size_t i) {
  return getRuleContext<VLParser::StatementContext>(i);
}


size_t VLParser::BlockContext::getRuleIndex() const {
  return VLParser::RuleBlock;
}

void VLParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void VLParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any VLParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

VLParser::BlockContext* VLParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, VLParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(VLParser::T__2);
    setState(90);
    match(VLParser::T__3);
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4398450003968) != 0)) {
      setState(91);
      statement();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
    match(VLParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

VLParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::FunctionDeclContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::BlockContext* VLParser::FunctionDeclContext::block() {
  return getRuleContext<VLParser::BlockContext>(0);
}

VLParser::VisibilityContext* VLParser::FunctionDeclContext::visibility() {
  return getRuleContext<VLParser::VisibilityContext>(0);
}

VLParser::DataTypeContext* VLParser::FunctionDeclContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}

VLParser::ParamListContext* VLParser::FunctionDeclContext::paramList() {
  return getRuleContext<VLParser::ParamListContext>(0);
}


size_t VLParser::FunctionDeclContext::getRuleIndex() const {
  return VLParser::RuleFunctionDecl;
}

void VLParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void VLParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


std::any VLParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

VLParser::FunctionDeclContext* VLParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, VLParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::T__9) {
      setState(99);
      visibility();
    }
    setState(102);
    match(VLParser::T__5);
    setState(103);
    match(VLParser::ID);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::T__6) {
      setState(104);
      match(VLParser::T__6);
      setState(105);
      dataType();
    }
    setState(108);
    match(VLParser::T__7);
    setState(110);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::ID) {
      setState(109);
      paramList();
    }
    setState(112);
    match(VLParser::T__8);
    setState(113);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VisibilityContext ------------------------------------------------------------------

VLParser::VisibilityContext::VisibilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VLParser::VisibilityContext::getRuleIndex() const {
  return VLParser::RuleVisibility;
}

void VLParser::VisibilityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVisibility(this);
}

void VLParser::VisibilityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVisibility(this);
}


std::any VLParser::VisibilityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitVisibility(this);
  else
    return visitor->visitChildren(this);
}

VLParser::VisibilityContext* VLParser::visibility() {
  VisibilityContext *_localctx = _tracker.createInstance<VisibilityContext>(_ctx, getState());
  enterRule(_localctx, 8, VLParser::RuleVisibility);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(VLParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

VLParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VLParser::ParamContext *> VLParser::ParamListContext::param() {
  return getRuleContexts<VLParser::ParamContext>();
}

VLParser::ParamContext* VLParser::ParamListContext::param(size_t i) {
  return getRuleContext<VLParser::ParamContext>(i);
}


size_t VLParser::ParamListContext::getRuleIndex() const {
  return VLParser::RuleParamList;
}

void VLParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void VLParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}


std::any VLParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ParamListContext* VLParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 10, VLParser::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    param();
    setState(122);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VLParser::T__10) {
      setState(118);
      match(VLParser::T__10);
      setState(119);
      param();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

VLParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::ParamContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::DataTypeContext* VLParser::ParamContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}


size_t VLParser::ParamContext::getRuleIndex() const {
  return VLParser::RuleParam;
}

void VLParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void VLParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any VLParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ParamContext* VLParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 12, VLParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(VLParser::ID);
    setState(126);
    match(VLParser::T__6);
    setState(127);
    dataType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

VLParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::CreateDeclStmtContext* VLParser::StatementContext::createDeclStmt() {
  return getRuleContext<VLParser::CreateDeclStmtContext>(0);
}

tree::TerminalNode* VLParser::StatementContext::SEMI() {
  return getToken(VLParser::SEMI, 0);
}

VLParser::CreateInitStmtContext* VLParser::StatementContext::createInitStmt() {
  return getRuleContext<VLParser::CreateInitStmtContext>(0);
}

VLParser::SetPropertyStmtContext* VLParser::StatementContext::setPropertyStmt() {
  return getRuleContext<VLParser::SetPropertyStmtContext>(0);
}

VLParser::SetArrayItemStmtContext* VLParser::StatementContext::setArrayItemStmt() {
  return getRuleContext<VLParser::SetArrayItemStmtContext>(0);
}

VLParser::PrintStmtContext* VLParser::StatementContext::printStmt() {
  return getRuleContext<VLParser::PrintStmtContext>(0);
}

VLParser::FunctionCallStmtContext* VLParser::StatementContext::functionCallStmt() {
  return getRuleContext<VLParser::FunctionCallStmtContext>(0);
}

VLParser::MethodCallStmtContext* VLParser::StatementContext::methodCallStmt() {
  return getRuleContext<VLParser::MethodCallStmtContext>(0);
}

VLParser::ReturnStmtContext* VLParser::StatementContext::returnStmt() {
  return getRuleContext<VLParser::ReturnStmtContext>(0);
}

VLParser::IfStmtContext* VLParser::StatementContext::ifStmt() {
  return getRuleContext<VLParser::IfStmtContext>(0);
}

VLParser::LoopStmtContext* VLParser::StatementContext::loopStmt() {
  return getRuleContext<VLParser::LoopStmtContext>(0);
}


size_t VLParser::StatementContext::getRuleIndex() const {
  return VLParser::RuleStatement;
}

void VLParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void VLParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any VLParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

VLParser::StatementContext* VLParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 14, VLParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(129);
      createDeclStmt();
      setState(130);
      match(VLParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(132);
      createInitStmt();
      setState(133);
      match(VLParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(135);
      setPropertyStmt();
      setState(136);
      match(VLParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(138);
      setArrayItemStmt();
      setState(139);
      match(VLParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(141);
      printStmt();
      setState(142);
      match(VLParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(144);
      functionCallStmt();
      setState(145);
      match(VLParser::SEMI);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(147);
      methodCallStmt();
      setState(148);
      match(VLParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(150);
      returnStmt();
      setState(151);
      match(VLParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(153);
      ifStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(154);
      loopStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateDeclStmtContext ------------------------------------------------------------------

VLParser::CreateDeclStmtContext::CreateDeclStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::CreateDeclStmtContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::DataTypeContext* VLParser::CreateDeclStmtContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}


size_t VLParser::CreateDeclStmtContext::getRuleIndex() const {
  return VLParser::RuleCreateDeclStmt;
}

void VLParser::CreateDeclStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateDeclStmt(this);
}

void VLParser::CreateDeclStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateDeclStmt(this);
}


std::any VLParser::CreateDeclStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitCreateDeclStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::CreateDeclStmtContext* VLParser::createDeclStmt() {
  CreateDeclStmtContext *_localctx = _tracker.createInstance<CreateDeclStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, VLParser::RuleCreateDeclStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(VLParser::T__11);
    setState(158);
    match(VLParser::ID);
    setState(159);
    match(VLParser::T__6);
    setState(160);
    dataType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateInitStmtContext ------------------------------------------------------------------

VLParser::CreateInitStmtContext::CreateInitStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::MutabilityContext* VLParser::CreateInitStmtContext::mutability() {
  return getRuleContext<VLParser::MutabilityContext>(0);
}

tree::TerminalNode* VLParser::CreateInitStmtContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::DataTypeContext* VLParser::CreateInitStmtContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}

VLParser::ArrayLiteralContext* VLParser::CreateInitStmtContext::arrayLiteral() {
  return getRuleContext<VLParser::ArrayLiteralContext>(0);
}

VLParser::ExprContext* VLParser::CreateInitStmtContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}


size_t VLParser::CreateInitStmtContext::getRuleIndex() const {
  return VLParser::RuleCreateInitStmt;
}

void VLParser::CreateInitStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateInitStmt(this);
}

void VLParser::CreateInitStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateInitStmt(this);
}


std::any VLParser::CreateInitStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitCreateInitStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::CreateInitStmtContext* VLParser::createInitStmt() {
  CreateInitStmtContext *_localctx = _tracker.createInstance<CreateInitStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, VLParser::RuleCreateInitStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    mutability();
    setState(163);
    match(VLParser::ID);
    setState(164);
    match(VLParser::T__6);
    setState(165);
    dataType();
    setState(166);
    match(VLParser::T__12);
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VLParser::T__15: {
        setState(167);
        arrayLiteral();
        break;
      }

      case VLParser::T__7:
      case VLParser::BOOL:
      case VLParser::FLOAT:
      case VLParser::INT:
      case VLParser::STRING:
      case VLParser::ID: {
        setState(168);
        expr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MutabilityContext ------------------------------------------------------------------

VLParser::MutabilityContext::MutabilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VLParser::MutabilityContext::getRuleIndex() const {
  return VLParser::RuleMutability;
}

void VLParser::MutabilityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMutability(this);
}

void VLParser::MutabilityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMutability(this);
}


std::any VLParser::MutabilityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitMutability(this);
  else
    return visitor->visitChildren(this);
}

VLParser::MutabilityContext* VLParser::mutability() {
  MutabilityContext *_localctx = _tracker.createInstance<MutabilityContext>(_ctx, getState());
  enterRule(_localctx, 20, VLParser::RuleMutability);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    _la = _input->LA(1);
    if (!(_la == VLParser::T__11

    || _la == VLParser::T__13)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetPropertyStmtContext ------------------------------------------------------------------

VLParser::SetPropertyStmtContext::SetPropertyStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::SetPropertyStmtContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::ExprContext* VLParser::SetPropertyStmtContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}


size_t VLParser::SetPropertyStmtContext::getRuleIndex() const {
  return VLParser::RuleSetPropertyStmt;
}

void VLParser::SetPropertyStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetPropertyStmt(this);
}

void VLParser::SetPropertyStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetPropertyStmt(this);
}


std::any VLParser::SetPropertyStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitSetPropertyStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::SetPropertyStmtContext* VLParser::setPropertyStmt() {
  SetPropertyStmtContext *_localctx = _tracker.createInstance<SetPropertyStmtContext>(_ctx, getState());
  enterRule(_localctx, 22, VLParser::RuleSetPropertyStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(VLParser::T__14);
    setState(174);
    match(VLParser::ID);
    setState(175);
    match(VLParser::T__12);
    setState(176);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetArrayItemStmtContext ------------------------------------------------------------------

VLParser::SetArrayItemStmtContext::SetArrayItemStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::SetArrayItemStmtContext::ID() {
  return getToken(VLParser::ID, 0);
}

std::vector<VLParser::ExprContext *> VLParser::SetArrayItemStmtContext::expr() {
  return getRuleContexts<VLParser::ExprContext>();
}

VLParser::ExprContext* VLParser::SetArrayItemStmtContext::expr(size_t i) {
  return getRuleContext<VLParser::ExprContext>(i);
}


size_t VLParser::SetArrayItemStmtContext::getRuleIndex() const {
  return VLParser::RuleSetArrayItemStmt;
}

void VLParser::SetArrayItemStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetArrayItemStmt(this);
}

void VLParser::SetArrayItemStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetArrayItemStmt(this);
}


std::any VLParser::SetArrayItemStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitSetArrayItemStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::SetArrayItemStmtContext* VLParser::setArrayItemStmt() {
  SetArrayItemStmtContext *_localctx = _tracker.createInstance<SetArrayItemStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, VLParser::RuleSetArrayItemStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(VLParser::T__14);
    setState(179);
    match(VLParser::ID);
    setState(180);
    match(VLParser::T__15);
    setState(181);
    expr(0);
    setState(182);
    match(VLParser::T__16);
    setState(183);
    match(VLParser::T__12);
    setState(184);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStmtContext ------------------------------------------------------------------

VLParser::PrintStmtContext::PrintStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::ExprContext* VLParser::PrintStmtContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}


size_t VLParser::PrintStmtContext::getRuleIndex() const {
  return VLParser::RulePrintStmt;
}

void VLParser::PrintStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStmt(this);
}

void VLParser::PrintStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStmt(this);
}


std::any VLParser::PrintStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitPrintStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::PrintStmtContext* VLParser::printStmt() {
  PrintStmtContext *_localctx = _tracker.createInstance<PrintStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, VLParser::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(VLParser::T__17);
    setState(187);
    match(VLParser::T__7);
    setState(188);
    expr(0);
    setState(189);
    match(VLParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

VLParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::ExprContext* VLParser::ReturnStmtContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}


size_t VLParser::ReturnStmtContext::getRuleIndex() const {
  return VLParser::RuleReturnStmt;
}

void VLParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void VLParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


std::any VLParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ReturnStmtContext* VLParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, VLParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(VLParser::T__18);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8521215115520) != 0)) {
      setState(192);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

VLParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VLParser::ExprContext::getRuleIndex() const {
  return VLParser::RuleExpr;
}

void VLParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprPrimaryContext ------------------------------------------------------------------

VLParser::PrimaryContext* VLParser::ExprPrimaryContext::primary() {
  return getRuleContext<VLParser::PrimaryContext>(0);
}

VLParser::ExprPrimaryContext::ExprPrimaryContext(ExprContext *ctx) { copyFrom(ctx); }

void VLParser::ExprPrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprPrimary(this);
}
void VLParser::ExprPrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprPrimary(this);
}

std::any VLParser::ExprPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitExprPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<VLParser::ExprContext *> VLParser::ExprAddSubContext::expr() {
  return getRuleContexts<VLParser::ExprContext>();
}

VLParser::ExprContext* VLParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<VLParser::ExprContext>(i);
}

VLParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }

void VLParser::ExprAddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAddSub(this);
}
void VLParser::ExprAddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAddSub(this);
}

std::any VLParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenContext ------------------------------------------------------------------

VLParser::ExprContext* VLParser::ExprParenContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}

VLParser::ExprParenContext::ExprParenContext(ExprContext *ctx) { copyFrom(ctx); }

void VLParser::ExprParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprParen(this);
}
void VLParser::ExprParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprParen(this);
}

std::any VLParser::ExprParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitExprParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMulDivContext ------------------------------------------------------------------

std::vector<VLParser::ExprContext *> VLParser::ExprMulDivContext::expr() {
  return getRuleContexts<VLParser::ExprContext>();
}

VLParser::ExprContext* VLParser::ExprMulDivContext::expr(size_t i) {
  return getRuleContext<VLParser::ExprContext>(i);
}

VLParser::ExprMulDivContext::ExprMulDivContext(ExprContext *ctx) { copyFrom(ctx); }

void VLParser::ExprMulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprMulDiv(this);
}
void VLParser::ExprMulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprMulDiv(this);
}

std::any VLParser::ExprMulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitExprMulDiv(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ExprContext* VLParser::expr() {
   return expr(0);
}

VLParser::ExprContext* VLParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  VLParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  VLParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, VLParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VLParser::T__7: {
        _localctx = _tracker.createInstance<ExprParenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(196);
        match(VLParser::T__7);
        setState(197);
        expr(0);
        setState(198);
        match(VLParser::T__8);
        break;
      }

      case VLParser::BOOL:
      case VLParser::FLOAT:
      case VLParser::INT:
      case VLParser::STRING:
      case VLParser::ID: {
        _localctx = _tracker.createInstance<ExprPrimaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(200);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(211);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(209);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(203);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(204);
          antlrcpp::downCast<ExprMulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7340032) != 0))) {
            antlrcpp::downCast<ExprMulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(205);
          antlrcpp::downCast<ExprMulDivContext *>(_localctx)->right = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(206);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(207);
          antlrcpp::downCast<ExprAddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == VLParser::T__22

          || _la == VLParser::T__23)) {
            antlrcpp::downCast<ExprAddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(208);
          antlrcpp::downCast<ExprAddSubContext *>(_localctx)->right = expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(213);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

VLParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::MethodCallStmtContext* VLParser::PrimaryContext::methodCallStmt() {
  return getRuleContext<VLParser::MethodCallStmtContext>(0);
}

VLParser::FunctionCallStmtContext* VLParser::PrimaryContext::functionCallStmt() {
  return getRuleContext<VLParser::FunctionCallStmtContext>(0);
}

VLParser::ArrayAccessContext* VLParser::PrimaryContext::arrayAccess() {
  return getRuleContext<VLParser::ArrayAccessContext>(0);
}

VLParser::LiteralContext* VLParser::PrimaryContext::literal() {
  return getRuleContext<VLParser::LiteralContext>(0);
}

tree::TerminalNode* VLParser::PrimaryContext::ID() {
  return getToken(VLParser::ID, 0);
}


size_t VLParser::PrimaryContext::getRuleIndex() const {
  return VLParser::RulePrimary;
}

void VLParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void VLParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any VLParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

VLParser::PrimaryContext* VLParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 32, VLParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(214);
      methodCallStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(215);
      functionCallStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(216);
      arrayAccess();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(217);
      literal();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(218);
      match(VLParser::ID);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallStmtContext ------------------------------------------------------------------

VLParser::MethodCallStmtContext::MethodCallStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VLParser::MethodCallStmtContext::ID() {
  return getTokens(VLParser::ID);
}

tree::TerminalNode* VLParser::MethodCallStmtContext::ID(size_t i) {
  return getToken(VLParser::ID, i);
}

VLParser::ArgListContext* VLParser::MethodCallStmtContext::argList() {
  return getRuleContext<VLParser::ArgListContext>(0);
}


size_t VLParser::MethodCallStmtContext::getRuleIndex() const {
  return VLParser::RuleMethodCallStmt;
}

void VLParser::MethodCallStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCallStmt(this);
}

void VLParser::MethodCallStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCallStmt(this);
}


std::any VLParser::MethodCallStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitMethodCallStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::MethodCallStmtContext* VLParser::methodCallStmt() {
  MethodCallStmtContext *_localctx = _tracker.createInstance<MethodCallStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, VLParser::RuleMethodCallStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    antlrcpp::downCast<MethodCallStmtContext *>(_localctx)->target = match(VLParser::ID);
    setState(222);
    match(VLParser::T__24);
    setState(223);
    antlrcpp::downCast<MethodCallStmtContext *>(_localctx)->funcName = match(VLParser::ID);
    setState(224);
    match(VLParser::T__7);
    setState(226);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8521215115520) != 0)) {
      setState(225);
      argList();
    }
    setState(228);
    match(VLParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallStmtContext ------------------------------------------------------------------

VLParser::FunctionCallStmtContext::FunctionCallStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VLParser::FunctionCallStmtContext::ID() {
  return getTokens(VLParser::ID);
}

tree::TerminalNode* VLParser::FunctionCallStmtContext::ID(size_t i) {
  return getToken(VLParser::ID, i);
}

VLParser::ArgListContext* VLParser::FunctionCallStmtContext::argList() {
  return getRuleContext<VLParser::ArgListContext>(0);
}


size_t VLParser::FunctionCallStmtContext::getRuleIndex() const {
  return VLParser::RuleFunctionCallStmt;
}

void VLParser::FunctionCallStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStmt(this);
}

void VLParser::FunctionCallStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStmt(this);
}


std::any VLParser::FunctionCallStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitFunctionCallStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::FunctionCallStmtContext* VLParser::functionCallStmt() {
  FunctionCallStmtContext *_localctx = _tracker.createInstance<FunctionCallStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, VLParser::RuleFunctionCallStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(230);
      antlrcpp::downCast<FunctionCallStmtContext *>(_localctx)->namespace_ = match(VLParser::ID);
      setState(231);
      match(VLParser::T__25);
      break;
    }

    default:
      break;
    }
    setState(234);
    antlrcpp::downCast<FunctionCallStmtContext *>(_localctx)->funcName = match(VLParser::ID);
    setState(235);
    match(VLParser::T__7);
    setState(237);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8521215115520) != 0)) {
      setState(236);
      argList();
    }
    setState(239);
    match(VLParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

VLParser::ArrayAccessContext::ArrayAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::ArrayAccessContext::ID() {
  return getToken(VLParser::ID, 0);
}

VLParser::ExprContext* VLParser::ArrayAccessContext::expr() {
  return getRuleContext<VLParser::ExprContext>(0);
}


size_t VLParser::ArrayAccessContext::getRuleIndex() const {
  return VLParser::RuleArrayAccess;
}

void VLParser::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}

void VLParser::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}


std::any VLParser::ArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitArrayAccess(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ArrayAccessContext* VLParser::arrayAccess() {
  ArrayAccessContext *_localctx = _tracker.createInstance<ArrayAccessContext>(_ctx, getState());
  enterRule(_localctx, 38, VLParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(VLParser::ID);
    setState(242);
    match(VLParser::T__15);
    setState(243);
    expr(0);
    setState(244);
    match(VLParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

VLParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VLParser::ExprContext *> VLParser::ArgListContext::expr() {
  return getRuleContexts<VLParser::ExprContext>();
}

VLParser::ExprContext* VLParser::ArgListContext::expr(size_t i) {
  return getRuleContext<VLParser::ExprContext>(i);
}


size_t VLParser::ArgListContext::getRuleIndex() const {
  return VLParser::RuleArgList;
}

void VLParser::ArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgList(this);
}

void VLParser::ArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgList(this);
}


std::any VLParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ArgListContext* VLParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 40, VLParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    expr(0);
    setState(251);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VLParser::T__10) {
      setState(247);
      match(VLParser::T__10);
      setState(248);
      expr(0);
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

VLParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::CondStmtContext* VLParser::IfStmtContext::condStmt() {
  return getRuleContext<VLParser::CondStmtContext>(0);
}

VLParser::BlockContext* VLParser::IfStmtContext::block() {
  return getRuleContext<VLParser::BlockContext>(0);
}


size_t VLParser::IfStmtContext::getRuleIndex() const {
  return VLParser::RuleIfStmt;
}

void VLParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void VLParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


std::any VLParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::IfStmtContext* VLParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, VLParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(VLParser::T__26);
    setState(255);
    match(VLParser::T__7);
    setState(256);
    condStmt();
    setState(257);
    match(VLParser::T__8);
    setState(258);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStmtContext ------------------------------------------------------------------

VLParser::LoopStmtContext::LoopStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::CondStmtContext* VLParser::LoopStmtContext::condStmt() {
  return getRuleContext<VLParser::CondStmtContext>(0);
}

VLParser::BlockContext* VLParser::LoopStmtContext::block() {
  return getRuleContext<VLParser::BlockContext>(0);
}


size_t VLParser::LoopStmtContext::getRuleIndex() const {
  return VLParser::RuleLoopStmt;
}

void VLParser::LoopStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStmt(this);
}

void VLParser::LoopStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStmt(this);
}


std::any VLParser::LoopStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitLoopStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::LoopStmtContext* VLParser::loopStmt() {
  LoopStmtContext *_localctx = _tracker.createInstance<LoopStmtContext>(_ctx, getState());
  enterRule(_localctx, 44, VLParser::RuleLoopStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(VLParser::T__27);
    setState(261);
    match(VLParser::T__7);
    setState(262);
    condStmt();
    setState(263);
    match(VLParser::T__8);
    setState(264);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondStmtContext ------------------------------------------------------------------

VLParser::CondStmtContext::CondStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::ComparisonOpContext* VLParser::CondStmtContext::comparisonOp() {
  return getRuleContext<VLParser::ComparisonOpContext>(0);
}

std::vector<VLParser::ExprContext *> VLParser::CondStmtContext::expr() {
  return getRuleContexts<VLParser::ExprContext>();
}

VLParser::ExprContext* VLParser::CondStmtContext::expr(size_t i) {
  return getRuleContext<VLParser::ExprContext>(i);
}


size_t VLParser::CondStmtContext::getRuleIndex() const {
  return VLParser::RuleCondStmt;
}

void VLParser::CondStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondStmt(this);
}

void VLParser::CondStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondStmt(this);
}


std::any VLParser::CondStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitCondStmt(this);
  else
    return visitor->visitChildren(this);
}

VLParser::CondStmtContext* VLParser::condStmt() {
  CondStmtContext *_localctx = _tracker.createInstance<CondStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, VLParser::RuleCondStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    antlrcpp::downCast<CondStmtContext *>(_localctx)->left = expr(0);
    setState(267);
    comparisonOp();
    setState(268);
    antlrcpp::downCast<CondStmtContext *>(_localctx)->right = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonOpContext ------------------------------------------------------------------

VLParser::ComparisonOpContext::ComparisonOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VLParser::ComparisonOpContext::getRuleIndex() const {
  return VLParser::RuleComparisonOp;
}

void VLParser::ComparisonOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonOp(this);
}

void VLParser::ComparisonOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonOp(this);
}


std::any VLParser::ComparisonOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitComparisonOp(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ComparisonOpContext* VLParser::comparisonOp() {
  ComparisonOpContext *_localctx = _tracker.createInstance<ComparisonOpContext>(_ctx, getState());
  enterRule(_localctx, 48, VLParser::RuleComparisonOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33822867456) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataTypeContext ------------------------------------------------------------------

VLParser::DataTypeContext::DataTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::FunctionTypeContext* VLParser::DataTypeContext::functionType() {
  return getRuleContext<VLParser::FunctionTypeContext>(0);
}

VLParser::ArrayTypeContext* VLParser::DataTypeContext::arrayType() {
  return getRuleContext<VLParser::ArrayTypeContext>(0);
}

VLParser::PrimitiveTypeContext* VLParser::DataTypeContext::primitiveType() {
  return getRuleContext<VLParser::PrimitiveTypeContext>(0);
}


size_t VLParser::DataTypeContext::getRuleIndex() const {
  return VLParser::RuleDataType;
}

void VLParser::DataTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDataType(this);
}

void VLParser::DataTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDataType(this);
}


std::any VLParser::DataTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitDataType(this);
  else
    return visitor->visitChildren(this);
}

VLParser::DataTypeContext* VLParser::dataType() {
  DataTypeContext *_localctx = _tracker.createInstance<DataTypeContext>(_ctx, getState());
  enterRule(_localctx, 50, VLParser::RuleDataType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VLParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(272);
        functionType();
        break;
      }

      case VLParser::T__35: {
        enterOuterAlt(_localctx, 2);
        setState(273);
        arrayType();
        break;
      }

      case VLParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(274);
        primitiveType();
        break;
      }

      case VLParser::T__34: {
        enterOuterAlt(_localctx, 4);
        setState(275);
        match(VLParser::T__34);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

VLParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::PrimitiveTypeContext::ID() {
  return getToken(VLParser::ID, 0);
}


size_t VLParser::PrimitiveTypeContext::getRuleIndex() const {
  return VLParser::RulePrimitiveType;
}

void VLParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void VLParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}


std::any VLParser::PrimitiveTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitPrimitiveType(this);
  else
    return visitor->visitChildren(this);
}

VLParser::PrimitiveTypeContext* VLParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, VLParser::RulePrimitiveType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(VLParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

VLParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::DataTypeContext* VLParser::ArrayTypeContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}


size_t VLParser::ArrayTypeContext::getRuleIndex() const {
  return VLParser::RuleArrayType;
}

void VLParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void VLParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


std::any VLParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ArrayTypeContext* VLParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 54, VLParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(VLParser::T__35);
    setState(281);
    dataType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

VLParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VLParser::DataTypeContext* VLParser::FunctionTypeContext::dataType() {
  return getRuleContext<VLParser::DataTypeContext>(0);
}

VLParser::TypeListContext* VLParser::FunctionTypeContext::typeList() {
  return getRuleContext<VLParser::TypeListContext>(0);
}


size_t VLParser::FunctionTypeContext::getRuleIndex() const {
  return VLParser::RuleFunctionType;
}

void VLParser::FunctionTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionType(this);
}

void VLParser::FunctionTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionType(this);
}


std::any VLParser::FunctionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitFunctionType(this);
  else
    return visitor->visitChildren(this);
}

VLParser::FunctionTypeContext* VLParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 56, VLParser::RuleFunctionType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(VLParser::T__5);
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VLParser::T__6) {
      setState(284);
      match(VLParser::T__6);
      setState(285);
      dataType();
    }
    setState(288);
    match(VLParser::T__7);
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4501125726272) != 0)) {
      setState(289);
      typeList();
    }
    setState(292);
    match(VLParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

VLParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VLParser::DataTypeContext *> VLParser::TypeListContext::dataType() {
  return getRuleContexts<VLParser::DataTypeContext>();
}

VLParser::DataTypeContext* VLParser::TypeListContext::dataType(size_t i) {
  return getRuleContext<VLParser::DataTypeContext>(i);
}


size_t VLParser::TypeListContext::getRuleIndex() const {
  return VLParser::RuleTypeList;
}

void VLParser::TypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeList(this);
}

void VLParser::TypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeList(this);
}


std::any VLParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

VLParser::TypeListContext* VLParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 58, VLParser::RuleTypeList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    dataType();
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VLParser::T__10) {
      setState(295);
      match(VLParser::T__10);
      setState(296);
      dataType();
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

VLParser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<VLParser::LiteralContext *> VLParser::ArrayLiteralContext::literal() {
  return getRuleContexts<VLParser::LiteralContext>();
}

VLParser::LiteralContext* VLParser::ArrayLiteralContext::literal(size_t i) {
  return getRuleContext<VLParser::LiteralContext>(i);
}


size_t VLParser::ArrayLiteralContext::getRuleIndex() const {
  return VLParser::RuleArrayLiteral;
}

void VLParser::ArrayLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteral(this);
}

void VLParser::ArrayLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteral(this);
}


std::any VLParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

VLParser::ArrayLiteralContext* VLParser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 60, VLParser::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(VLParser::T__15);
    setState(311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4123168604160) != 0)) {
      setState(303);
      literal();
      setState(308);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == VLParser::T__10) {
        setState(304);
        match(VLParser::T__10);
        setState(305);
        literal();
        setState(310);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(313);
    match(VLParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

VLParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VLParser::LiteralContext::INT() {
  return getToken(VLParser::INT, 0);
}

tree::TerminalNode* VLParser::LiteralContext::FLOAT() {
  return getToken(VLParser::FLOAT, 0);
}

tree::TerminalNode* VLParser::LiteralContext::STRING() {
  return getToken(VLParser::STRING, 0);
}

tree::TerminalNode* VLParser::LiteralContext::BOOL() {
  return getToken(VLParser::BOOL, 0);
}


size_t VLParser::LiteralContext::getRuleIndex() const {
  return VLParser::RuleLiteral;
}

void VLParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void VLParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any VLParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VLVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

VLParser::LiteralContext* VLParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 62, VLParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4123168604160) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool VLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool VLParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void VLParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vlParserInitialize();
#else
  ::antlr4::internal::call_once(vlParserOnceFlag, vlParserInitialize);
#endif
}

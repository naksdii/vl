
// Generated from VL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VLListener.h"


/**
 * This class provides an empty implementation of VLListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VLBaseListener : public VLListener {
public:

  virtual void enterProgram(VLParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(VLParser::ProgramContext * /*ctx*/) override { }

  virtual void enterImportStmt(VLParser::ImportStmtContext * /*ctx*/) override { }
  virtual void exitImportStmt(VLParser::ImportStmtContext * /*ctx*/) override { }

  virtual void enterBlock(VLParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(VLParser::BlockContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(VLParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(VLParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterVisibility(VLParser::VisibilityContext * /*ctx*/) override { }
  virtual void exitVisibility(VLParser::VisibilityContext * /*ctx*/) override { }

  virtual void enterParamList(VLParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(VLParser::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(VLParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(VLParser::ParamContext * /*ctx*/) override { }

  virtual void enterStatement(VLParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(VLParser::StatementContext * /*ctx*/) override { }

  virtual void enterCreateDeclStmt(VLParser::CreateDeclStmtContext * /*ctx*/) override { }
  virtual void exitCreateDeclStmt(VLParser::CreateDeclStmtContext * /*ctx*/) override { }

  virtual void enterCreateInitStmt(VLParser::CreateInitStmtContext * /*ctx*/) override { }
  virtual void exitCreateInitStmt(VLParser::CreateInitStmtContext * /*ctx*/) override { }

  virtual void enterMutability(VLParser::MutabilityContext * /*ctx*/) override { }
  virtual void exitMutability(VLParser::MutabilityContext * /*ctx*/) override { }

  virtual void enterSetPropertyStmt(VLParser::SetPropertyStmtContext * /*ctx*/) override { }
  virtual void exitSetPropertyStmt(VLParser::SetPropertyStmtContext * /*ctx*/) override { }

  virtual void enterSetArrayItemStmt(VLParser::SetArrayItemStmtContext * /*ctx*/) override { }
  virtual void exitSetArrayItemStmt(VLParser::SetArrayItemStmtContext * /*ctx*/) override { }

  virtual void enterPrintStmt(VLParser::PrintStmtContext * /*ctx*/) override { }
  virtual void exitPrintStmt(VLParser::PrintStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(VLParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(VLParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterExprPrimary(VLParser::ExprPrimaryContext * /*ctx*/) override { }
  virtual void exitExprPrimary(VLParser::ExprPrimaryContext * /*ctx*/) override { }

  virtual void enterExprAddSub(VLParser::ExprAddSubContext * /*ctx*/) override { }
  virtual void exitExprAddSub(VLParser::ExprAddSubContext * /*ctx*/) override { }

  virtual void enterExprParen(VLParser::ExprParenContext * /*ctx*/) override { }
  virtual void exitExprParen(VLParser::ExprParenContext * /*ctx*/) override { }

  virtual void enterExprMulDiv(VLParser::ExprMulDivContext * /*ctx*/) override { }
  virtual void exitExprMulDiv(VLParser::ExprMulDivContext * /*ctx*/) override { }

  virtual void enterPrimary(VLParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(VLParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterMethodCallStmt(VLParser::MethodCallStmtContext * /*ctx*/) override { }
  virtual void exitMethodCallStmt(VLParser::MethodCallStmtContext * /*ctx*/) override { }

  virtual void enterFunctionCallStmt(VLParser::FunctionCallStmtContext * /*ctx*/) override { }
  virtual void exitFunctionCallStmt(VLParser::FunctionCallStmtContext * /*ctx*/) override { }

  virtual void enterArrayAccess(VLParser::ArrayAccessContext * /*ctx*/) override { }
  virtual void exitArrayAccess(VLParser::ArrayAccessContext * /*ctx*/) override { }

  virtual void enterArgList(VLParser::ArgListContext * /*ctx*/) override { }
  virtual void exitArgList(VLParser::ArgListContext * /*ctx*/) override { }

  virtual void enterIfStmt(VLParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(VLParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterLoopStmt(VLParser::LoopStmtContext * /*ctx*/) override { }
  virtual void exitLoopStmt(VLParser::LoopStmtContext * /*ctx*/) override { }

  virtual void enterCondStmt(VLParser::CondStmtContext * /*ctx*/) override { }
  virtual void exitCondStmt(VLParser::CondStmtContext * /*ctx*/) override { }

  virtual void enterComparisonOp(VLParser::ComparisonOpContext * /*ctx*/) override { }
  virtual void exitComparisonOp(VLParser::ComparisonOpContext * /*ctx*/) override { }

  virtual void enterDataType(VLParser::DataTypeContext * /*ctx*/) override { }
  virtual void exitDataType(VLParser::DataTypeContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(VLParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(VLParser::PrimitiveTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(VLParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(VLParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterFunctionType(VLParser::FunctionTypeContext * /*ctx*/) override { }
  virtual void exitFunctionType(VLParser::FunctionTypeContext * /*ctx*/) override { }

  virtual void enterTypeList(VLParser::TypeListContext * /*ctx*/) override { }
  virtual void exitTypeList(VLParser::TypeListContext * /*ctx*/) override { }

  virtual void enterArrayLiteral(VLParser::ArrayLiteralContext * /*ctx*/) override { }
  virtual void exitArrayLiteral(VLParser::ArrayLiteralContext * /*ctx*/) override { }

  virtual void enterLiteral(VLParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(VLParser::LiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


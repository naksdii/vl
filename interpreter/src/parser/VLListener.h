
// Generated from VL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VLParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by VLParser.
 */
class  VLListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(VLParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(VLParser::ProgramContext *ctx) = 0;

  virtual void enterImportStmt(VLParser::ImportStmtContext *ctx) = 0;
  virtual void exitImportStmt(VLParser::ImportStmtContext *ctx) = 0;

  virtual void enterBlock(VLParser::BlockContext *ctx) = 0;
  virtual void exitBlock(VLParser::BlockContext *ctx) = 0;

  virtual void enterFunctionDecl(VLParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(VLParser::FunctionDeclContext *ctx) = 0;

  virtual void enterVisibility(VLParser::VisibilityContext *ctx) = 0;
  virtual void exitVisibility(VLParser::VisibilityContext *ctx) = 0;

  virtual void enterParamList(VLParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(VLParser::ParamListContext *ctx) = 0;

  virtual void enterParam(VLParser::ParamContext *ctx) = 0;
  virtual void exitParam(VLParser::ParamContext *ctx) = 0;

  virtual void enterStatement(VLParser::StatementContext *ctx) = 0;
  virtual void exitStatement(VLParser::StatementContext *ctx) = 0;

  virtual void enterCreateDeclStmt(VLParser::CreateDeclStmtContext *ctx) = 0;
  virtual void exitCreateDeclStmt(VLParser::CreateDeclStmtContext *ctx) = 0;

  virtual void enterCreateInitStmt(VLParser::CreateInitStmtContext *ctx) = 0;
  virtual void exitCreateInitStmt(VLParser::CreateInitStmtContext *ctx) = 0;

  virtual void enterMutability(VLParser::MutabilityContext *ctx) = 0;
  virtual void exitMutability(VLParser::MutabilityContext *ctx) = 0;

  virtual void enterSetPropertyStmt(VLParser::SetPropertyStmtContext *ctx) = 0;
  virtual void exitSetPropertyStmt(VLParser::SetPropertyStmtContext *ctx) = 0;

  virtual void enterSetArrayItemStmt(VLParser::SetArrayItemStmtContext *ctx) = 0;
  virtual void exitSetArrayItemStmt(VLParser::SetArrayItemStmtContext *ctx) = 0;

  virtual void enterPrintStmt(VLParser::PrintStmtContext *ctx) = 0;
  virtual void exitPrintStmt(VLParser::PrintStmtContext *ctx) = 0;

  virtual void enterReturnStmt(VLParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(VLParser::ReturnStmtContext *ctx) = 0;

  virtual void enterExprPrimary(VLParser::ExprPrimaryContext *ctx) = 0;
  virtual void exitExprPrimary(VLParser::ExprPrimaryContext *ctx) = 0;

  virtual void enterExprAddSub(VLParser::ExprAddSubContext *ctx) = 0;
  virtual void exitExprAddSub(VLParser::ExprAddSubContext *ctx) = 0;

  virtual void enterExprParen(VLParser::ExprParenContext *ctx) = 0;
  virtual void exitExprParen(VLParser::ExprParenContext *ctx) = 0;

  virtual void enterExprMulDiv(VLParser::ExprMulDivContext *ctx) = 0;
  virtual void exitExprMulDiv(VLParser::ExprMulDivContext *ctx) = 0;

  virtual void enterPrimary(VLParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(VLParser::PrimaryContext *ctx) = 0;

  virtual void enterMethodCallStmt(VLParser::MethodCallStmtContext *ctx) = 0;
  virtual void exitMethodCallStmt(VLParser::MethodCallStmtContext *ctx) = 0;

  virtual void enterFunctionCallStmt(VLParser::FunctionCallStmtContext *ctx) = 0;
  virtual void exitFunctionCallStmt(VLParser::FunctionCallStmtContext *ctx) = 0;

  virtual void enterArrayAccess(VLParser::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(VLParser::ArrayAccessContext *ctx) = 0;

  virtual void enterArgList(VLParser::ArgListContext *ctx) = 0;
  virtual void exitArgList(VLParser::ArgListContext *ctx) = 0;

  virtual void enterIfStmt(VLParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(VLParser::IfStmtContext *ctx) = 0;

  virtual void enterLoopStmt(VLParser::LoopStmtContext *ctx) = 0;
  virtual void exitLoopStmt(VLParser::LoopStmtContext *ctx) = 0;

  virtual void enterCondStmt(VLParser::CondStmtContext *ctx) = 0;
  virtual void exitCondStmt(VLParser::CondStmtContext *ctx) = 0;

  virtual void enterComparisonOp(VLParser::ComparisonOpContext *ctx) = 0;
  virtual void exitComparisonOp(VLParser::ComparisonOpContext *ctx) = 0;

  virtual void enterDataType(VLParser::DataTypeContext *ctx) = 0;
  virtual void exitDataType(VLParser::DataTypeContext *ctx) = 0;

  virtual void enterPrimitiveType(VLParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(VLParser::PrimitiveTypeContext *ctx) = 0;

  virtual void enterArrayType(VLParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(VLParser::ArrayTypeContext *ctx) = 0;

  virtual void enterFunctionType(VLParser::FunctionTypeContext *ctx) = 0;
  virtual void exitFunctionType(VLParser::FunctionTypeContext *ctx) = 0;

  virtual void enterTypeList(VLParser::TypeListContext *ctx) = 0;
  virtual void exitTypeList(VLParser::TypeListContext *ctx) = 0;

  virtual void enterArrayLiteral(VLParser::ArrayLiteralContext *ctx) = 0;
  virtual void exitArrayLiteral(VLParser::ArrayLiteralContext *ctx) = 0;

  virtual void enterLiteral(VLParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(VLParser::LiteralContext *ctx) = 0;


};


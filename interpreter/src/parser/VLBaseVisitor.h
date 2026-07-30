
// Generated from VL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VLVisitor.h"


/**
 * This class provides an empty implementation of VLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  VLBaseVisitor : public VLVisitor {
public:

  virtual std::any visitProgram(VLParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportStmt(VLParser::ImportStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(VLParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(VLParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVisibility(VLParser::VisibilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(VLParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(VLParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(VLParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateDeclStmt(VLParser::CreateDeclStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateInitStmt(VLParser::CreateInitStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMutability(VLParser::MutabilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetPropertyStmt(VLParser::SetPropertyStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetArrayItemStmt(VLParser::SetArrayItemStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStmt(VLParser::PrintStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(VLParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPrimary(VLParser::ExprPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAddSub(VLParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprParen(VLParser::ExprParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprMulDiv(VLParser::ExprMulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(VLParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodCallStmt(VLParser::MethodCallStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallStmt(VLParser::FunctionCallStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAccess(VLParser::ArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(VLParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(VLParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStmt(VLParser::LoopStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondStmt(VLParser::CondStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonOp(VLParser::ComparisonOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataType(VLParser::DataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveType(VLParser::PrimitiveTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(VLParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionType(VLParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeList(VLParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLiteral(VLParser::ArrayLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(VLParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};


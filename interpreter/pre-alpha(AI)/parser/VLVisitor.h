
// Generated from VL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by VLParser.
 */
class  VLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by VLParser.
   */
    virtual std::any visitProgram(VLParser::ProgramContext *context) = 0;

    virtual std::any visitImportStmt(VLParser::ImportStmtContext *context) = 0;

    virtual std::any visitBlock(VLParser::BlockContext *context) = 0;

    virtual std::any visitFunctionDecl(VLParser::FunctionDeclContext *context) = 0;

    virtual std::any visitVisibility(VLParser::VisibilityContext *context) = 0;

    virtual std::any visitParamList(VLParser::ParamListContext *context) = 0;

    virtual std::any visitParam(VLParser::ParamContext *context) = 0;

    virtual std::any visitStatement(VLParser::StatementContext *context) = 0;

    virtual std::any visitCreateDeclStmt(VLParser::CreateDeclStmtContext *context) = 0;

    virtual std::any visitCreateInitStmt(VLParser::CreateInitStmtContext *context) = 0;

    virtual std::any visitMutability(VLParser::MutabilityContext *context) = 0;

    virtual std::any visitSetPropertyStmt(VLParser::SetPropertyStmtContext *context) = 0;

    virtual std::any visitSetArrayItemStmt(VLParser::SetArrayItemStmtContext *context) = 0;

    virtual std::any visitPrintStmt(VLParser::PrintStmtContext *context) = 0;

    virtual std::any visitReturnStmt(VLParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExprPrimary(VLParser::ExprPrimaryContext *context) = 0;

    virtual std::any visitExprAddSub(VLParser::ExprAddSubContext *context) = 0;

    virtual std::any visitExprParen(VLParser::ExprParenContext *context) = 0;

    virtual std::any visitExprMulDiv(VLParser::ExprMulDivContext *context) = 0;

    virtual std::any visitPrimary(VLParser::PrimaryContext *context) = 0;

    virtual std::any visitMethodCallStmt(VLParser::MethodCallStmtContext *context) = 0;

    virtual std::any visitFunctionCallStmt(VLParser::FunctionCallStmtContext *context) = 0;

    virtual std::any visitArrayAccess(VLParser::ArrayAccessContext *context) = 0;

    virtual std::any visitArgList(VLParser::ArgListContext *context) = 0;

    virtual std::any visitIfStmt(VLParser::IfStmtContext *context) = 0;

    virtual std::any visitLoopStmt(VLParser::LoopStmtContext *context) = 0;

    virtual std::any visitCondStmt(VLParser::CondStmtContext *context) = 0;

    virtual std::any visitComparisonOp(VLParser::ComparisonOpContext *context) = 0;

    virtual std::any visitDataType(VLParser::DataTypeContext *context) = 0;

    virtual std::any visitPrimitiveType(VLParser::PrimitiveTypeContext *context) = 0;

    virtual std::any visitArrayType(VLParser::ArrayTypeContext *context) = 0;

    virtual std::any visitFunctionType(VLParser::FunctionTypeContext *context) = 0;

    virtual std::any visitTypeList(VLParser::TypeListContext *context) = 0;

    virtual std::any visitArrayLiteral(VLParser::ArrayLiteralContext *context) = 0;

    virtual std::any visitLiteral(VLParser::LiteralContext *context) = 0;


};


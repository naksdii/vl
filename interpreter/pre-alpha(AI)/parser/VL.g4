grammar VL;

// ==========================================
// 1. ESTRUTURA DO PROGRAMA
// ==========================================

program
    : (importStmt)* (functionDecl)* block? EOF
    ;

importStmt
    : 'import' STRING ('as' ID)? SEMI
    ;

block
    : 'exec' '{' statement* '}'
    ;

functionDecl
    : (visibility)? 'fn' ID ('=>' dataType)? '(' (paramList)? ')' block
    ;

visibility
    : 'opn'
    ;

paramList
    : param (',' param)*
    ;

param
    : ID '=>' dataType
    ;


// ==========================================
// 2. DECLARAÇÕES E STATEMENTS
// ==========================================

statement
    : createDeclStmt SEMI          
    | createInitStmt SEMI          
    | setPropertyStmt SEMI        
    | setArrayItemStmt SEMI       
    | printStmt SEMI               
    | functionCallStmt SEMI       
    | methodCallStmt SEMI         
    | returnStmt SEMI              
    | ifStmt                       
    | loopStmt                     
    ;

createDeclStmt
    : 'mut' ID '=>' dataType
    ;

createInitStmt
    : mutability ID '=>' dataType '=' (arrayLiteral | expr)
    ;

mutability
    : 'mut'
    | 'const'
    ;

setPropertyStmt
    : 'set' ID '=' expr
    ;

setArrayItemStmt
    : 'set' ID '[' expr ']' '=' expr
    ;
printStmt
    : 'print' '(' expr ')'
    ;

returnStmt
    : 'return' (expr)?
    ;


// ==========================================
// 3. EXPRESSÕES E PRECEDÊNCIA
// ==========================================

expr
    : left=expr op=('*'|'/'|'%') right=expr  # ExprMulDiv
    | left=expr op=('+'|'-') right=expr        # ExprAddSub
    | '(' expr ')'                           # ExprParen
    | primary                                # ExprPrimary
    ;

primary
    : methodCallStmt
    | functionCallStmt
    | arrayAccess
    | literal
    | ID
    ;

methodCallStmt
    : target=ID '->' funcName=ID '(' (argList)? ')'
    ;

functionCallStmt
    : (namespace=ID '.')? funcName=ID '(' (argList)? ')'
    ;

arrayAccess
    : ID '[' expr ']'
    ;

argList
    : expr (',' expr)*
    ;


// ==========================================
// 4. CONTROLE DE FLUXO
// ==========================================

ifStmt
    : 'if' '(' condStmt ')' block
    ;

loopStmt
    : 'while' '(' condStmt ')' block
    ;

condStmt
    : left=expr comparisonOp right=expr
    ;

comparisonOp
    : '==' | '!=' | '>=' | '<=' | '>' | '<'
    ;

// ==========================================
// TIPOS
// ==========================================

dataType
    : functionType
    | arrayType
    | primitiveType
    | 'void'
    ;

primitiveType
    : ID
    ;

arrayType
    : '[]' dataType
    ;

functionType
    : 'fn' ('=>' dataType)? '(' typeList? ')'
    ;

typeList
    : dataType (',' dataType)*
    ;

arrayLiteral
    : ('[' (literal (',' literal)*)? ']'|'[]')
    ;

literal
    : INT
    | FLOAT
    | STRING
    | BOOL
    ;


// ==========================================
// 6. LEXER (TOKENS)
// ==========================================

SEMI        : ';' ;

BOOL
    : 'TRUE'
    | 'FALSE'
    ;

FLOAT
    : [0-9]+ '.' [0-9]+
    ;

INT
    : [0-9]+
    ;

STRING
    : '"' .*? '"'
    ;

ID
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

WS          : [ \t\r\n]+ -> skip ;
BLOCK_COMMENT : ';<' .*? '>;' -> skip ;
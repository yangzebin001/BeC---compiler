%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "ast.h"
extern int yylineno;
extern char* yytext;
extern int yylex();
void yyerror(std::string s) {
	printf("%d : %s %s\n", yylineno, s.c_str(), yytext );
}
%}


%union {
	Program *program;
	std::string *string;
	int token;
}

%token <string> ID HEXNUM OCTNUM DECNUM 

%token <token> IF ELSE WHILE PRINTF CONTINUE BREAK RETURN
%token <token> INT VOID CONST 
%token <token> AND OR
%token <token> LE GE EQ NE LT GT
%token <token> '=' '[' ']' '{' '}' ';'



%type <program> Program

%start Program

%%

Program: 
	FuncDef {$$= new Program(); $$->addFuncDef($1);}
	| VarDef {$$= new Program(); $$->addVarDef($1);}
	| ConstVarDef {$$= new Program(); $$->addConstVarDef($1);}
	| Program FuncDef {$$->addFuncDef($2);}
	| Program VarDef {$$->addVarDef($2);}
	| Program ConstVarDef {$$->addConstVarDef($2);}
	;

ConstVarDef: CONST BType ConstDef ';'
	;

BType: INT
	;

ConstDef: DirectDecl '=' ConstInitVal
	| ConstDef ',' DirectDecl '=' ConstInitVal
	;


ConstInitVal: ConstExp
	| '{' REPConstInitVal '}'
	;

REPConstInitVal: 
	| ConstInitVal
	|  REPConstInitVal ',' ConstInitVal
	;

VarDef: BType VarDefList ';'  
	;


VarDefList: InitDecl
	| VarDefList ',' InitDecl
	;

InitDecl: DirectDecl
	| DirectDecl '=' InitVal
	;

DirectDecl: ID
	| DirectDecl '[' ']'
	| DirectDecl '[' ConstExp ']'
	;


InitVal: Exp
	| '{' REPInitVal '}'
	;

REPInitVal: 
	| InitVal
	| REPInitVal ',' InitVal
	;

FuncDef: BType DirectFuncDecl Block
	| VOID DirectFuncDecl Block
	;


DirectFuncDecl: ID
	| DirectFuncDecl '(' FuncFParams ')'
	;

FuncFParams: 
	| FuncFParam
	| FuncFParams ',' FuncFParam
	;

FuncFParam: BType DirectDecl
	; 

Block: '{'BlockItem'}'
	;

BlockItem: 
	| Decl
	| Stmt
	| BlockItem Decl
	| BlockItem Stmt
	;

Stmt: Lval '=' Exp ';'
	| OPTExp ';'
	| Block
	| IF '(' Cond ')' Stmt OPTElseStmt
	| WHILE '(' Cond ')' Stmt
	| BREAK ';'
	| CONTINUE ';'
	| RETURN OPTExp ';'
	;

OPTExp: 
	| Exp
	;

OPTElseStmt: 
	| ELSE Stmt
	;

Exp: AddExp
	;

Cond: LOrExp
	;

Lval: DirectDecl
	;


PrimaryExp: Number
	| Lval
	| '('Exp')'
	;

Number: IntConst
	;

IntConst: HEXNUM
	| OCTNUM
	| DECNUM
	;

UnaryExp: PrimaryExp
	| ID '(' OPTFuncRParams ')'
	| UnaryOp UnaryExp
	;

OPTFuncRParams: 
	| FuncRParams
	;

UnaryOp: '+'
	| '-'
	| '!'
	;

FuncRParams: Exp
	| FuncRParams ',' Exp
	;

MulExp: UnaryExp
	| MulExp '*' UnaryExp
	| MulExp '/' UnaryExp
	| MulExp '%' UnaryExp
	;

AddExp: MulExp
	| AddExp '+' MulExp
	| AddExp '-' MulExp
	;

RelExp: AddExp
	| RelExp GT AddExp
	| RelExp LT AddExp
	| RelExp GE AddExp
	| RelExp LE AddExp
	;

EqExp: RelExp
	| EqExp EQ  RelExp
	| EqExp NE RelExp
	;

LAndExp: EqExp
	| LAndExp AND EqExp
	;

LOrExp: LAndExp
	| LOrExp OR LAndExp
	;

ConstExp: AddExp
	;


%%

         

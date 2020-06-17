%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "ast.h"

extern int yylineno;
extern char* yytext;
extern int yylex();

extern Program *program;

void yyerror(std::string s) {
	printf("%d : %s %s\n", yylineno, s.c_str(), yytext );
}
%}


%union {
	std::string *string;
	int token;
	
	Program *program;
	FunctionDef *functionDef;
	ConstVarDecl *constVarDecl;
	VarDecl *varDecl;
}


%token <string> ID HEXNUM OCTNUM DECNUM 

%token <token> IF ELSE WHILE PRINTF CONTINUE BREAK RETURN
%token <token> INT VOID CONST 
%token <token> AND OR
%token <token> LE GE EQ NE LT GT
%token <token> '=' '[' ']' '{' '}' ';'


%type <program> Program
%type <functionDef> FuncDef
%type <constVarDecl> ConstVarDecl
%type <varDecl> VarDecl


%start Program

%%

Program: FuncDef {$$ = new Program(); $$->addFuncDef($1);}
	| VarDecl {$$ = new Program(); $$->addVarDecl($1);}
	| ConstVarDecl {$$ = new Program(); $$->addConstVarDecl($1);}
	| Program FuncDef {$$->addFuncDef($2);}
	| Program VarDecl {$$->addVarDecl($2);}
	| Program ConstVarDecl {$$->addConstVarDecl($2);}
	;

ConstVarDecl: CONST BType ConstVarDefList ';'
	;

BType: INT
	;

ConstVarDefList: ConstVarDef
	| ConstVarDefList ',' ConstVarDef
	;

ConstVarDef: Lval '=' InitVal
	;

VarDecl: BType VarDefList ';'  
	;


VarDefList: VarDef
	| VarDefList ',' VarDef
	;

Lval: ID
	| ArrayEle
	;

VarDef: DirectDecl
	| ArrayDecl
	;

DirectDecl: ID
	| ID '=' Exp
	;

ArrayDecl: ArrayEle
	| ArrayEle '=' InitVal
	;

ArrayEle: ID '[' ']'
	| ID '[' ConstExp ']'
	| ArrayEle '[' ConstExp ']'
	;

InitVal: Exp
	| ArrayInit
	;

ArrayInit: '{' REPInitVal '}'
	;

REPInitVal: 
	| InitVal
	| REPInitVal ',' InitVal
	;

FuncDef: FuncDecl Block
	;

FuncDecl: BType ID '(' FuncFParams ')'
	| VOID ID '(' FuncFParams ')'
	;

FuncFParams: 
	| FuncFParam
	| FuncFParams ',' FuncFParam
	;

FuncFParam: BType Lval
	; 

Block: '{' Stmts '}'
	;

Stmts: 
	| Stmt
	| Stmts Stmt
	;

Stmt: VarDecl 
	| ConstVarDecl
	| Lval '=' Exp ';'
	| ';'
	| Exp ';'
	| Block
	| IFStmt
	| WHILEStmt
	| BREAK ';'
	| CONTINUE ';'
	| RETURNStmt
	;

IFStmt: IF '(' Cond ')' Stmt
	| IF '(' Cond ')' Stmt ELSE Stmt
	;

WHILEStmt: WHILE '(' Cond ')' Stmt
	;

RETURNStmt: RETURN ';'
	| RETURN Exp ';'
	;


Exp: AddExp
	;

Cond: LOrExp
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
	| FuncCall
	| UnaryOp UnaryExp
	;

FuncCall: ID '(' OPTFuncRParams ')'
	;

OPTFuncRParams: 
	| FuncRParams
	;

FuncRParams: Exp
	| FuncRParams ',' Exp
	;

UnaryOp: '+'
	| '-'
	| '!'
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

         

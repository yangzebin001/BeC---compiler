%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *fp;

%}

%token VOID INT CHAR CONST 
%token FOR WHILE 
%token IF ELSE PRINTF CONTINUE BREAK RETURN
%token STRUCT 
%token HEXNUM OCTNUM DECNUM ID NUM
%token INCLUDE
%token DOT

%token '='
%token AND OR
%token LE GE EQ NE LT GT
%%

start:	CompUnit
	;

CompUnit: 
	| FuncDef CompUnit
	| Decl CompUnit
	;

Decl: VarDecl
	| ConstDecl
	;

ConstDecl: {printf("this is constdecl\n");} CONST BType ConstDef REPConstDef ';'
	;

REPConstDef: 
	| ',' ConstDef REPConstDef
	;

BType: INT
	;

ConstDef: ID REPConstExp '=' ConstInitVal
	;

REPConstExp: 
	| '['ConstExp']' REPConstExp
	;

ConstInitVal: ConstExp
	| '{' OPTConstInitVal '}'
	;

OPTConstInitVal: 
	| ConstInitVal REPConstInitVal
	;

REPConstInitVal: 
	| ',' ConstInitVal REPConstInitVal
	;

VarDecl: {printf("this is vardecl\n");} BType VarDef REPVarDef ';'  
	;

REPVarDef: 
	| ',' VarDef REPVarDef
	;

VarDef: ID REPConstExp
	| ID REPConstExp '=' InitVal
	;

InitVal: Exp
	| '{' OPTInitVal '}'
	;

OPTInitVal: 
	| InitVal
	| InitVal REPInitVal
	;

REPInitVal: 
	| ',' InitVal REPInitVal
	;

FuncDef: 
	| INT ID '('OPTFuncFParams')' Block
	| VOID ID '('OPTFuncFParams')' Block
	;


OPTFuncFParams: 
	| FuncFParams
	;

FuncFParams: FuncFParam
	| FuncFParam REPFuncFParam
	;

REPFuncFParam: 
	| ',' FuncFParam REPFuncFParam
	; 

FuncFParam: BType ID OPTArrayExp
	;

OPTArrayExp: 
	| '['']' REPArrayExp
	;

REPArrayExp: 
	| '['Exp']' REPArrayExp
	; 

Block: '{'REPBlockItem'}'
	;

REPBlockItem: 
	| BlockItem REPBlockItem
	;

BlockItem: Decl
	| Stmt
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

OPTExp: Exp
	| 
	;

OPTElseStmt: 
	| ELSE Stmt
	;

Exp: AddExp
	;

Cond: LOrExp
	;

Lval: ID REPArrayExp
	;


PrimaryExp: '('Exp')'
	| Lval
	| Number
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

FuncRParams: Exp REPExp
	;

REPExp: 
	| ',' Exp REPExp
	;

MulExp: UnaryExp
	| UnaryExp '*' MulExp
	| UnaryExp '/' MulExp
	| UnaryExp '%' MulExp
	;

AddExp:  MulExp
	| MulExp '+' AddExp
	| MulExp '-' AddExp
	;

RelExp: AddExp
	| AddExp GT RelExp
	| AddExp LT RelExp
	| AddExp GE RelExp
	| AddExp LE RelExp
	;

EqExp: RelExp
	| RelExp EQ EqExp 
	| RelExp NE EqExp 
	;

LAndExp: EqExp
	| LAndExp AND EqExp
	;

LOrExp: LAndExp
	| LAndExp OR LOrExp
	;

ConstExp: AddExp
	;


%%
#include"lex.yy.c"
#include<ctype.h>
int count=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");
	
	fclose(yyin);
    return 0;
}
         
yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         
%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *fp;

int yylex();
void yyerror(char *s);


%}

%token VOID INT CONST 
%token WHILE 
%token IF ELSE PRINTF CONTINUE BREAK RETURN
%token HEXNUM OCTNUM DECNUM ID
%token INCLUDE

%token '='
%token AND OR
%token LE GE EQ NE LT GT
%start CompUnit

%%

CompUnit: 
	| CompUnit FuncDef
	| CompUnit Decl
	;

Decl: VarDecl
	| ConstDecl
	;

ConstDecl: CONST BType ConstDef ';'
	;

BType: INT
	;

ConstDef: DirectDecl '=' ConstInitVal
	| ConstDef ',' DirectDecl '=' ConstInitVal
	;


ConstInitVal: ConstExp
	| '{' OPTConstInitVal '}'
	;

OPTConstInitVal: 
	| REPConstInitVal
	;

REPConstInitVal: ConstInitVal
	|  REPConstInitVal ',' ConstInitVal
	;

VarDecl: BType VarDefList ';'  
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
	| '{' OPTInitVal '}'
	;

OPTInitVal: 
	| REPInitVal
	;

REPInitVal: 
	| InitVal
	| REPInitVal ',' InitVal
	;

FuncDef: BType DirectFuncDecl Block
	| VOID DirectFuncDecl Block
	;


DirectFuncDecl: ID
	| DirectFuncDecl '(' OPTFuncFParams ')'
	;


OPTFuncFParams: 
	| FuncFParams
	;

FuncFParams: FuncFParam
	| FuncFParam ',' FuncFParams
	;

FuncFParam: BType DirectDecl
	; 

Block: '{'REPBlockItem'}'
	;

REPBlockItem: 
	| REPBlockItem BlockItem 
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
	| UnaryExp '*' MulExp
	| UnaryExp '/' MulExp
	| UnaryExp '%' MulExp
	;

AddExp: MulExp
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
         
void yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         
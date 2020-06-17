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
	TypeDecl *typeDecl;
	ConstVarDef *constVarDef;
	Lval* lval;
	Ident *ident;
	ArrayElement *arrayEle;
	VarDef *varDef;
	DirectDecl *directDecl;
	Expression *exp;
	Operation *operation;
	AddExpression *addExp;
	MulExpression *mulExp;
	UnaryExp *unaryExp;
	PrimaryExpression *primaryExp;
	FuncParam *funcParam;
	FunctionCall *funcCall;

	vector<ConstVarDef*> *constVarDefList;
	vector<VarDef*> *varDefList;
	vector<Expression*> *paramList;
}


%token <string> ID HEXNUM OCTNUM DECNUM PLUS MINUS TIMES DIV MOD NOT

%token <token> IF ELSE WHILE PRINTF CONTINUE BREAK RETURN
%token <token> INT VOID CONST 
%token <token> AND OR
%token <token> LE GE EQ NE LT GT
%token <token> '=' '[' ']' '{' '}' ';'


%type <string>  IntConst Number
%type <program> Program
%type <functionDef> FuncDef
%type <constVarDecl> ConstVarDecl
%type <varDecl> VarDecl
%type <typeDecl> BType
%type <constVarDef> ConstVarDef
%type <constVarDefList> ConstVarDefList
%type <varDefList> VarDefList
%type <lval> Lval
%type <arrayEle> ArrayEle
%type <varDef> VarDef
%type <directDecl> DirectDecl
%type <operation> UnaryOp
%type <exp> Exp InitVal
%type <addExp> AddExp
%type <mulExp> MulExp
%type <unaryExp> UnaryExp
%type <primaryExp> PrimaryExp
%type <paramList> ParamList FuncRParams
%type <funcCall> FuncCall

%start Program

%%

Program: FuncDef {$$ = new Program(); $$->addFuncDef($1);}
	| VarDecl {$$ = new Program(); $$->addVarDecl($1);}
	| ConstVarDecl {$$ = new Program(); $$->addConstVarDecl($1);}
	| Program FuncDef {$$->addFuncDef($2);}
	| Program VarDecl {$$->addVarDecl($2);}
	| Program ConstVarDecl {$$->addConstVarDecl($2);}
	;

ConstVarDecl: CONST BType ConstVarDefList ';'  {$$ = new ConstVarDecl($2,*$3);}
	;

BType: INT {$$ = new TypeDecl("int");}
	;

ConstVarDefList: ConstVarDef {$$ = new vector<ConstVarDef*>(); $$->push_back($1);}
	| ConstVarDefList ',' ConstVarDef {$$->push_back($3);}
	;

ConstVarDef: Lval '=' InitVal {$$ = new ConstVarDef($1,$3);}
	;

VarDecl: BType VarDefList ';'  {$$ = new VarDecl($1, *$2);}
	;


VarDefList: VarDef {$$ = new vector<VarDef*>(); $$->push_back($1);}
	| VarDefList ',' VarDef {$$->push_back($3);}
	;

Lval: ID {$$ = new Ident(*$1);  delete $1;}
	| ArrayEle
	;

VarDef: DirectDecl {$$ = $1;}
	| ArrayDecl 
	;

DirectDecl: ID {$$ = new DirectDecl(new Ident(*$1), NULL); }
	| ID '=' Exp {$$ = new DirectDecl(new Ident(*$1), $3); }
	;

ArrayDecl: ArrayEle
	| ArrayEle '=' InitVal
	;

ArrayEle: ID '[' ']' 
	| ID '[' ConstExp ']'
	| ArrayEle '[' ConstExp ']'
	;

InitVal: Exp {$$ = $1;}
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


Exp: AddExp {$$ = $1;}
	;

Cond: LOrExp
	;



PrimaryExp: Number {$$ = new PrimaryExpression(*$1, NULL, NULL);}
	| Lval {$$ = new PrimaryExpression(*new string(), $1, NULL);}
	| '(' Exp ')' {$$ = new PrimaryExpression(*new string(), NULL, $2);}
	;

Number: IntConst {$$ = $1;}
	;

IntConst: HEXNUM {$$ = $1;}
	| OCTNUM {$$ = $1;}
	| DECNUM {$$ = $1;}
	;

UnaryExp: PrimaryExp {$$ = new UnaryExp($1, NULL, NULL, NULL);}
	| FuncCall {$$ = new UnaryExp(NULL, $1, NULL, NULL);}
	| UnaryOp UnaryExp {$$ = new UnaryExp(NULL, NULL, $1, $2);}
	;

FuncCall: ID '(' ParamList ')' { $$ = new FunctionCall(new Ident(*$1), *$3);  delete $1;}
	;

ParamList: {$$ = new vector<Expression*>();}
	| FuncRParams {$$ = $1;}
	;

FuncRParams: Exp {$$ = new vector<Expression*>(); $$->push_back($1);}
	| FuncRParams ',' Exp {$$->push_back($3);}
	;

UnaryOp: PLUS {$$ = new Operation(*$1);}
	| MINUS {$$ = new Operation(*$1);}
	| NOT {$$ = new Operation(*$1);}
	;

MulExp: UnaryExp {$$ = new MulExpression($1);}
	| MulExp TIMES UnaryExp {$$ = new MulExpression($1,new Operation(*$2),$3);}
	| MulExp DIV UnaryExp {$$ = new MulExpression($1,new Operation(*$2),$3);}
	| MulExp MOD UnaryExp {$$ = new MulExpression($1,new Operation(*$2),$3);}
	;

AddExp: MulExp {$$ = new AddExpression($1);}
	| AddExp PLUS MulExp {$$ = new AddExpression($1,new Operation(*$2),$3);}
	| AddExp MINUS MulExp {$$ = new AddExpression($1,new Operation(*$2),$3);}
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

         

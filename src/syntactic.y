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
	Lval *lval;
	Ident *ident;
	ArrayElement *arrayEle;
	VarDef *varDef;
	DirectDecl *directDecl;
	Expression *exp;
	Operation *operation;
	AddExpression *addExp;
	MulExpression *mulExp;
	LOrExpression *lorExp;
	LAndExpression *landExp;
	EqExpression *eqExp;
	RelExpression *relExp;
	UnaryExp *unaryExp;
	PrimaryExpression *primaryExp;
	FuncParam *funcParam;
	FunctionCall *funcCall;
	Block *block;
	Statement *statement;
	IFStatement *ifStatement;
	WHILEStatement *whileStatement;
	RETURNStatement *returnStatement;
	CONTINUEStatement *continueStatement;
	BREAKStatement *breakStatement;


	vector<ConstVarDef*> *constVarDefList;
	vector<VarDef*> *varDefList;
	vector<Expression*> *paramList;
	vector<FuncParam*> *funcFParams;
	vector<Statement*> *stmtList;
}


%token <string> ID HEXNUM OCTNUM DECNUM PLUS MINUS TIMES DIV MOD NOT LE GE EQ NE LT GT

%token <token> IF ELSE WHILE PRINTF CONTINUE BREAK RETURN
%token <token> INT VOID CONST 
%token <token> AND OR
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
%type <lorExp> LOrExp Cond
%type <landExp> LAndExp
%type <eqExp> EqExp
%type <relExp> RelExp
%type <addExp> AddExp ConstExp
%type <mulExp> MulExp
%type <unaryExp> UnaryExp
%type <primaryExp> PrimaryExp
%type <paramList> ParamList FuncRParams
%type <funcCall> FuncCall
%type <funcParam> FuncFParam
%type <funcFParams> FuncFParams
%type <block> Block
%type <statement> Stmt
%type <stmtList> Stmts
%type <ifStatement> IFStmt
%type <whileStatement> WHILEStmt
%type <returnStatement> RETURNStmt
%type <continueStatement> CONTINUEStmt
%type <breakStatement> BREAKStmt


%start Program

%%

Program: FuncDef {$$ = new Program(); $$->addFuncDef($1); program = $$; }
	| VarDecl {$$ = new Program(); $$->addVarDecl($1);  program = $$;}
	| ConstVarDecl {$$ = new Program(); $$->addConstVarDecl($1);  program = $$;}
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

FuncDef: BType ID '(' FuncFParams ')' Block {$$ = new FunctionDef($1,new Ident(*$2),*$4,$6);}
	| VOID ID '(' FuncFParams ')' Block {$$ = new FunctionDef(new TypeDecl("void"),new Ident(*$2),*$4,$6);}
	;

FuncFParams: {$$ = new vector<FuncParam*>();}
	| FuncFParam {$$ = new vector<FuncParam*>(); $$->push_back($1);}
	| FuncFParams ',' FuncFParam  {$$->push_back($3);}
	;

FuncFParam: BType Lval {$$ = new FuncParam($1,$2);}
	; 

Block: '{' Stmts '}' {$$ = new Block(*$2);}
	;

Stmts:  {$$ = new vector<Statement*>();}
	| Stmt {$$ = new vector<Statement*>(); $$->push_back($1);}
	| Stmts Stmt {$$->push_back($2);}
	;

Stmt: VarDecl {$$ = $1;}
	| ConstVarDecl {$$ = $1;}
	| Lval '=' Exp ';' {$$ = new Assignment($1,$3);}
	| ';'
	| Exp ';' {$$ = new ExpressionStatement($1);}
	| Block {$$ = new BlockStatement($1);}
	| IFStmt {$$ = $1;}
	| WHILEStmt {$$ = $1;}
	| BREAKStmt ';' {$$ = new BREAKStatement();}
	| CONTINUEStmt ';' {$$ = new CONTINUEStatement();}
	| RETURNStmt {$$ = $1;}
	;


IFStmt: IF '(' Cond ')' Stmt {$$ = new IFStatement($3,$5,NULL);}
	| IF '(' Cond ')' Stmt ELSE Stmt {$$ = new IFStatement($3,$5,$7);}
	;

WHILEStmt: WHILE '(' Cond ')' Stmt {$$ = new WHILEStatement($3,$5);}
	;

BREAKStmt: BREAK
	;

CONTINUEStmt: CONTINUE
	;


RETURNStmt: RETURN ';' {$$ = new RETURNStatement(NULL);}
	| RETURN Exp ';' {$$ = new RETURNStatement($2);}
	;


Exp: AddExp {$$ = $1;}
	;

Cond: LOrExp {$$ = $1;}
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

RelExp: AddExp {$$ = new RelExpression($1);}
	| RelExp GT AddExp {$$ = new RelExpression($1, new Operation(*$2), $3);}
	| RelExp LT AddExp {$$ = new RelExpression($1, new Operation(*$2), $3);}
	| RelExp GE AddExp {$$ = new RelExpression($1, new Operation(*$2), $3);}
	| RelExp LE AddExp {$$ = new RelExpression($1, new Operation(*$2), $3);}
	;

EqExp: RelExp {$$ = new EqExpression($1);}
	| EqExp EQ RelExp {$$ = new EqExpression($1, new Operation(*$2), $3);}
	| EqExp NE RelExp {$$ = new EqExpression($1, new Operation(*$2), $3);}
	;

LAndExp: EqExp {$$ = new LAndExpression($1);}
	| LAndExp AND EqExp {$$ = new LAndExpression($1, $3);}
	;

LOrExp: LAndExp {$$ = new LOrExpression($1);}
	| LOrExp OR LAndExp {$$ = new LOrExpression($1, $3);}
	;

ConstExp: AddExp
	;


%%

         

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include "context.hpp"

using namespace std;

typedef enum {
    NODE,
	PROGRAM,
	STATEMENT,
	EXPRESSION,
	TYPEDECL,
	CONSTVARDECL,
	CONSTVARDEF,
	LVAL,
	IDENT,
	ARRAYELEMENT,
	ARRAYINIT,
	VARDECL,
	VARDEF,
	DIRECTDECL,
	ARRAYDECL,
	BLOCK,
	FUNCPARAM,
	FUNCTIONDEF,
	FUNCTIONCALL,
	STMTS,
	ASSIGNMENT,
	EXPRESSIONSTATEMENT,
	BLOCKSTATEMENT,
	OPERATION,
	BINARYOPEXPRESSION,
	LOREXPRESSION,
	LANDEXPRESSION,
	EQEXPRESSION,
	RELEXPRESSION,
	ADDEXPRESSION,
	MULEXPRESSION,
	PRIMARYEXPRESSION,
	UNARYEXP,
	IFSTATEMENT,
	WHILESTATEMENT,
	RETURNSTATEMENT,
	BREAKSTATEMENT,
	CONTINUESTATEMENT,

} node_t;


class Node;
class Program;
class Statement;
class Expression;
class TypeDecl;
class ConstVarDecl;
class ConstVarDef;
class Lval;
class Ident;
class ArrayElement;
class ArrayInit;
class VarDecl;
class VarDef;
class DirectDecl;
class ArrayDecl;
class Block;
class FuncParam;
class FunctionDef;
class FunctionCall;
class Stmts;
class Assignment;
class ExpressionStatement;
class BlockStatement;
class Operation;
class BinaryOpExpression;
class LOrExpression;
class LAndExpression;
class EqExpression;
class RelExpression;
class AddExpression;
class MulExpression;
class PrimaryExpression;
class UnaryExp;
class IFStatement;
class WHILEStatement;
class RETURNStatement;
class BREAKStatement;
class CONTINUEStatement;





class Node {
public:
	node_t type;
};

class Program : public Node{
public:
	Program(){
		this->type = PROGRAM;
	}
	vector<VarDecl*> varDecls;
    vector<ConstVarDecl*> constVarDecls;
	vector<FunctionDef*> funcDefs;

	void addConstVarDecl(ConstVarDecl *constVarDecl) {
		constVarDecls.push_back(constVarDecl);
	}

	void addVarDecl(VarDecl *varDecl) {
		varDecls.push_back(varDecl);
	}

	void addFuncDef(FunctionDef *funcDef) {
		
		funcDefs.push_back(funcDef);
	}
	void codeGen(const char* in_file_name, const char* out_file_name);
};

class Statement: public Node {
public:
	Statement(){
		this->type = STATEMENT;

	}
	virtual void codeGen(Context &ctx);
};

class Expression: public Node {
public:
	Expression(){
		this->type = EXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class TypeDecl: public Node {
public:
	string typeName;

	TypeDecl(string typeName) {
		this->typeName = typeName;
		this->type = TYPEDECL;
	}
	virtual void codeGen(Context &ctx){}
};

class ConstVarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<ConstVarDef*> constVarDefList;

	ConstVarDecl(TypeDecl *typeDecl, vector<ConstVarDef*> &constVarDefList) {
		this->typeDecl = typeDecl;
		this->constVarDefList = constVarDefList;
		this->type = CONSTVARDECL;
	}

	virtual void codeGen(Context &ctx){}
};


class ConstVarDef: public Statement {
public:
	Lval *lval;
	Expression *initVal;

	ConstVarDef(Lval *lval, Expression *initVal) {
		this->lval = lval;
		this->initVal = initVal;
		this->type = CONSTVARDEF;
	}
	virtual void codeGen(Context &ctx){}
};

class Lval: public Expression {
public:
	virtual void codeGen(Context &ctx);
	Lval(){
		this->type = LVAL;
	}
};

class Ident: public Lval {
public:
	string id;
	Ident(string &id){
		this->id = id;
		this->type = IDENT;
	}

	virtual void codeGen(Context &ctx);
};

class ArrayElement: public Lval {
public:
	Expression *array;
	Expression *index;

	ArrayElement(Expression *array, Expression *index) {
		this->array = array;
		this->index = index;
		this->type = ARRAYELEMENT;
	}

	virtual void codeGen(Context &ctx){}
};

class ArrayInit: public Expression {
public:
	vector<Expression*> exprList;

	ArrayInit(vector<Expression*> &exprList) {
		this->exprList = exprList;
		this->type = ARRAYINIT;
	}

	virtual void codeGen(Context &ctx){}
};

class VarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<VarDef*> VarDefList;

	VarDecl(TypeDecl *typeDecl, vector<VarDef*> &VarDefList) {
		this->typeDecl = typeDecl;
		this->VarDefList = VarDefList;
		this->type = VARDECL;
	}

	virtual void codeGen(Context &ctx);
};


class VarDef: public Expression {
public:
	virtual void codeGen(Context &ctx);
	VarDef(){
		this->type = VARDEF;
	}
};

class DirectDecl: public VarDef {
public:
	Ident *ident;
	Expression* exp;
	DirectDecl(Ident *ident, Expression* exp){
		this->ident = ident;
		this->exp = exp;
		this->type = DIRECTDECL;
	}
	virtual void codeGen(Context &ctx);
};

class ArrayDecl: public VarDef {
public:
	ArrayElement *arrayElement;
	Expression* initVal;
	ArrayDecl(ArrayElement *arrayElement, Expression* initVal){
		this->arrayElement = arrayElement;
		this->initVal = initVal;
		this->type = ARRAYDECL;
	}
	virtual void codeGen(Context &ctx){}
};


class Block: public Node {
public:
	vector<Statement*> statementList;
	Block(){}
	Block(vector<Statement*> &statementList){
		this->statementList = statementList;
		this->type = BLOCK;
	}
	virtual void codeGen(Context &ctx);
};

class FuncParam: public Node{
public: 
	TypeDecl *typeDecl;
	Lval *lval;
	FuncParam(TypeDecl *typeDecl, Lval *lval){
		this->typeDecl = typeDecl;
		this->lval = lval;
		this->type = FUNCPARAM;
	}
	virtual void codeGen(Context &ctx){}
};

class FunctionDef: public Node {
public:
	TypeDecl *returnType;
	Ident *id;
	vector<FuncParam*> ParamList;
	Block *block;
	FunctionDef(TypeDecl* returnType, Ident *id, vector<FuncParam*> &ParamList, Block *block){
		this->returnType = returnType;
		this->id = id;
		this->ParamList = ParamList;
		this->block = block;
		this->type = FUNCTIONDEF;
	}
	virtual void codeGen(Context &ctx);
};


class FunctionCall: public Expression {
public:
	Ident* id;
	vector<Expression*> ParamList;
	FunctionCall(Ident *id, vector<Expression*> &ParamList){
		this->id = id;
		this->ParamList = ParamList;
		this->type = FUNCTIONCALL;
	}
	virtual void codeGen(Context &ctx);
};






class Assignment: public Statement {
public:
	Lval *lval;
	Expression *exp;
	Assignment(Lval *lval, Expression *exp){
		this->lval = lval;
		this->exp = exp;
		this->type = ASSIGNMENT;
	}
	virtual void codeGen(Context &ctx){}
};

class ExpressionStatement: public Statement {
public:
	Expression *exp;
	ExpressionStatement(Expression *exp){
		this->exp = exp;
		this->type = EXPRESSIONSTATEMENT;
	}
	virtual void codeGen(Context &ctx);
};

class BlockStatement: public Statement {
public:
	Block *block;
	BlockStatement(Block *block){
		this->block = block;
		this->type = BLOCKSTATEMENT;
	}
	virtual void codeGen(Context &ctx){}
};


class Operation: public Expression {
public:
	string op;
	Operation(string op){
		this->op = op;
		this->type = OPERATION;
	}
	virtual void codeGen(Context &ctx){}
};


class BinaryOpExpression: public Expression {
public:
	Expression *lhs;
	Expression *rhs;
	Expression *unaryExp;
	Operation* op;
	BinaryOpExpression(){}
	BinaryOpExpression(Expression *unaryExp){
		this->unaryExp = unaryExp;
		this->type = BINARYOPEXPRESSION;
	}
	BinaryOpExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
		this->type = BINARYOPEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class LOrExpression: public BinaryOpExpression {
public:
	LOrExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = LOREXPRESSION;
	}
	LOrExpression(Expression *lhs, Expression *rhs){
		this->op = new Operation("or");
		this->lhs = lhs;
		this->rhs = rhs;
		this->type = LOREXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class LAndExpression: public BinaryOpExpression {
public:
	LAndExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = LANDEXPRESSION;
	}
	LAndExpression(Expression *lhs, Expression *rhs){
		this->op = new Operation("and");
		this->lhs = lhs;
		this->rhs = rhs;
		this->type = LANDEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};


class EqExpression: public BinaryOpExpression {
public:
	EqExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = EQEXPRESSION;
	}
	EqExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
		this->type = EQEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class RelExpression: public BinaryOpExpression {
public:
	RelExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = RELEXPRESSION;
	}
	RelExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
		this->type = RELEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class AddExpression: public BinaryOpExpression {
public:
	AddExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = ADDEXPRESSION;
	}
	AddExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
		this->type = ADDEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class MulExpression: public BinaryOpExpression {
public:
	MulExpression(Expression* exp){
		this->unaryExp = exp;
		this->type = MULEXPRESSION;
	}
	MulExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
		this->type = MULEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class PrimaryExpression: public Expression {
public:
	string number;
	Lval *lval;
	Expression *exp;
	PrimaryExpression(string &number, Lval *lval, Expression *exp){
		this->number = number;
		this->lval = lval;
		this->exp = exp;
		this->type = PRIMARYEXPRESSION;
	}
	virtual void codeGen(Context &ctx);
};

class UnaryExp: public Expression {
public:
	PrimaryExpression *primaryExp;
	FunctionCall *funcCall;
	Operation *unaryOp;
	UnaryExp *unaryExp;
	UnaryExp(PrimaryExpression *primaryExp,FunctionCall* funcCall,Operation *unaryOp,UnaryExp* unaryExp){
		this->primaryExp = primaryExp;
		this->funcCall = funcCall;
		this->unaryOp = unaryOp;
		this->unaryExp = unaryExp;
		this->type = UNARYEXP;
	}
	virtual void codeGen(Context &ctx);
};

class IFStatement: public Statement {
public:
	Expression *exp;
	Statement *TRUEStmt;
	Statement *FALSEStmt;
	IFStatement(Expression *exp,Statement *TRUEStmt,Statement *FALSEStmt){
		this->exp = exp;
		this->TRUEStmt = TRUEStmt;
		this->FALSEStmt = FALSEStmt;
		this->type = IFSTATEMENT;
	}
	virtual void codeGen(Context &ctx){}
};


class WHILEStatement: public Statement {
public:
	Expression *exp;
	Statement *stmt;
	WHILEStatement(Expression *exp,Statement *stmt){
		this->exp = exp;
		this->stmt = stmt;
		this->type = WHILESTATEMENT;
	}
	virtual void codeGen(Context &ctx){}
};

class RETURNStatement: public Statement {
public:
	Expression *exp;
	RETURNStatement(Expression *exp){
		this->exp = exp;
		this->type = RETURNSTATEMENT;
	}
	virtual void codeGen(Context &ctx);
};

class BREAKStatement: public Statement {
public:
	BREAKStatement(){
		this->type = BREAKSTATEMENT;
	}
	virtual void codeGen(Context &ctx){}
};

class CONTINUEStatement: public Statement {
public:
	CONTINUEStatement(){
		this->type = CONTINUESTATEMENT;
	}
	virtual void codeGen(Context &ctx){}
};
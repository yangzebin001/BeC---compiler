#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include "context.hpp"

using namespace std;


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
};

class Program{
public:
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
	virtual void codeGen(Context &ctx);
};

class Expression: public Node {
public:
	virtual void codeGen(Context &ctx);
};

class TypeDecl: public Node {
public:
	string typeName;

	TypeDecl(string typeName) {
		this->typeName = typeName;
	}
	virtual void codeGen(Context &ctx){}
};

class ConstVarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<ConstVarDef*> ConstVarDefList;

	ConstVarDecl(TypeDecl *typeDecl, vector<ConstVarDef*> &constVarDefList) {
		this->typeDecl = typeDecl;
		this->ConstVarDefList = constVarDefList;
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
	}
	virtual void codeGen(Context &ctx){}
};

class Lval: public Expression {
public:
	virtual void codeGen(Context &ctx);
};

class Ident: public Lval {
public:
	string id;
	Ident(string &id){
		this->id = id;
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
	}

	virtual void codeGen(Context &ctx){}
};

class ArrayInit: public Expression {
public:
	vector<Expression*> exprList;

	ArrayInit(vector<Expression*> &exprList) {
		this->exprList = exprList;
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
	}

	virtual void codeGen(Context &ctx);
};


class VarDef: public Expression {
public:
	virtual void codeGen(Context &ctx);
};

class DirectDecl: public VarDef {
public:
	Ident *ident;
	Expression* exp;
	DirectDecl(Ident *ident, Expression* exp){
		this->ident = ident;
		this->exp = exp;
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
	}
	virtual void codeGen(Context &ctx){}
};

//todo: FuncDef,Block,Stmts,AddExp

class Block: public Node {
public:
	vector<Statement*> statementList;
	Block(){}
	Block(vector<Statement*> &statementList){
		this->statementList = statementList;
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
	}
	virtual void codeGen(Context &ctx){}
};

class ExpressionStatement: public Statement {
public:
	Expression *exp;
	ExpressionStatement(Expression *exp){
		this->exp = exp;
	}
	virtual void codeGen(Context &ctx);
};

class BlockStatement: public Statement {
public:
	Block *block;
	BlockStatement(Block *block){
		this->block = block;
	}
	virtual void codeGen(Context &ctx){}
};


class Operation: public Expression {
public:
	string op;
	Operation(string op){
		this->op = op;
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
	}
	BinaryOpExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};

class LOrExpression: public BinaryOpExpression {
public:
	LOrExpression(Expression* exp){
		this->unaryExp = exp;
	}
	LOrExpression(Expression *lhs, Expression *rhs){
		this->op = new Operation("or");
		this->lhs = lhs;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};

class LAndExpression: public BinaryOpExpression {
public:
	LAndExpression(Expression* exp){
		this->unaryExp = exp;
	}
	LAndExpression(Expression *lhs, Expression *rhs){
		this->op = new Operation("and");
		this->lhs = lhs;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};


class EqExpression: public BinaryOpExpression {
public:
	EqExpression(Expression* exp){
		this->unaryExp = exp;
	}
	EqExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};

class RelExpression: public BinaryOpExpression {
public:
	RelExpression(Expression* exp){
		this->unaryExp = exp;
	}
	RelExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};

class AddExpression: public BinaryOpExpression {
public:
	AddExpression(Expression* exp){
		this->unaryExp = exp;
	}
	AddExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	virtual void codeGen(Context &ctx);
};

class MulExpression: public BinaryOpExpression {
public:
	MulExpression(Expression* exp){
		this->unaryExp = exp;
	}
	MulExpression(Expression *lhs, Operation* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
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
	}
	virtual void codeGen(Context &ctx){}
};

class RETURNStatement: public Statement {
public:
	Expression *exp;
	RETURNStatement(Expression *exp){
		this->exp = exp;
	}
	virtual void codeGen(Context &ctx);
};

class BREAKStatement: public Statement {
public:
	BREAKStatement(){
	}
	virtual void codeGen(Context &ctx){}
};

class CONTINUEStatement: public Statement {
public:
	CONTINUEStatement(){
	}
	virtual void codeGen(Context &ctx){}
};
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>

using namespace std;
using namespace llvm;


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
class FuncCall;
class Stmts;
class Assignment;
class ExpressionStatement;
class BlockStatement;
class Operator;
class BinaryOpExpression;
class LOrExpression;
class LAndExpression;
class EqExpression;
class RelExpression;
class AddExpression;
class MulExpression;
class PrimaryExp;
class UnaryExp;
class IFStatement;
class WHILEStatement;
class RETURNStatement;
class BREAKStatement;
class CONTINUEStatement;

class Node {
public:
	void codeGen();
};

class Program : public Node{
public:
	vector<VarDecl*> VarDecls;
    vector<ConstVarDecl*> constVarDecls;
	vector<FunctionDef*> funcDefs;

	void addConstVarDecl(ConstVarDecl *constVarDecl) {
		constVarDecls.push_back(constVarDecl);
	}

	void addVarDecl(VarDecl *varDecl) {
		VarDecls.push_back(varDecl);
	}

	void addFuncDef(FunctionDef *funcDef) {
		funcDefs.push_back(funcDef);
	}
	void codeGen();
};

class Statement: public Node {
public:
	virtual ~Statement() {
	}
	void codeGen();
};

class Expression: public Node {
public:
	virtual ~Expression() {
	}
	void codeGen();
};

class TypeDecl: public Node {
public:
	string typeName;

	TypeDecl(string &typeName) {
		this->typeName = typeName;
	}
	void codeGen();
};

class ConstVarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<ConstVarDef*> ConstVarDefList;

	ConstVarDecl(TypeDecl *typeDecl, vector<ConstVarDef*> &constVarDefList) {
		this->typeDecl = typeDecl;
		this->ConstVarDefList = constVarDefList;
	}

	void codeGen();
};


class ConstVarDef: public Statement {
public:
	Lval *lval;
	Expression *initVal;

	ConstVarDef(Lval *lval, Expression *initVal) {
		this->lval = lval;
		this->initVal = initVal;
	}
	void codeGen();
};

class Lval: public Expression {
public:
	void codeGen();
};

class Ident: public Lval {
public:
	string id;
	Ident(string &id){
		this->id = id;
	}
	void codeGen();
};

class ArrayElement: public Lval {
public:
	Expression *array;
	Expression *index;

	ArrayElement(Expression *array, Expression *index) {
		this->array = array;
		this->index = index;
	}

	void codeGen();
};

class ArrayInit: public Expression {
public:
	vector<Expression*> exprList;

	ArrayInit(vector<Expression*> exprList) {
		this->exprList = exprList;
	}

	void codeGen();
};

class VarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<VarDef*> VarDefList;

	VarDecl(TypeDecl *typeDecl, vector<VarDef*> &VarDefList) {
		this->typeDecl = typeDecl;
		this->VarDefList = VarDefList;
	}

	void codeGen();
};


class VarDef: public Expression {
public:
	void codeGen();
};

class DirectDecl: public VarDef {
public:
	Ident *ident;
	Expression* exp;
	DirectDecl(Ident *ident, Expression* exp){
		this->ident = ident;
		this->exp = exp;
	}
	void codeGen();
};

class ArrayDecl: public VarDef {
public:
	ArrayElement *arrayElement;
	Expression* initVal;
	ArrayDecl(ArrayElement *arrayElement, Expression* initVal){
		this->arrayElement = arrayElement;
		this->initVal = initVal;
	}
	void codeGen();
};

//todo: FuncDef,Block,Stmts,AddExp

class Block: public Node {
public:
	void codeGen();
};

class FuncParam: public Node{
public: 
	TypeDecl *typeDecl;
	Lval *lval;
	FuncParam(TypeDecl *typeDecl, Lval *lval){
		this->typeDecl = typeDecl;
		this->lval = lval;
	}
	void codeGen();
};

class FunctionDef: public Node {
public:
	TypeDecl *returnType;
	Ident *id;
	vector<FuncParam*> ParamList;
	Block *block;
	FunctionDef(TypeDecl* returnType, Ident *id, vector<FuncParam*> ParamList, Block* block){
		this->returnType = returnType;
		this->id = id;
		this->ParamList = ParamList;
		this->block = block;
	}
	void codeGen();
};


class FuncCall: public Expression {
public:
	Ident* id;
	vector<FuncParam*> ParamList;
	FuncCall(Ident *id, vector<FuncParam*> ParamList){
		this->id = id;
		this->ParamList = ParamList;
	}
	void codeGen();
};


class Stmts: public Statement {
public:
	vector<Statement*> statementList;
	Stmts(vector<Statement*> statementList){
		this->statementList = statementList;
	}
	void addStatement(Statement* stmt){
		this->statementList.push_back(stmt);
	}
	void codeGen();
};





class Assignment: public Statement {
public:
	Lval *lval;
	Expression *exp;
	Assignment(Lval *lval, Expression *exp){
		this->lval = lval;
		this->exp = exp;
	}
	void codeGen();
};

class ExpressionStatement: public Expression {
public:
	Expression *exp;
	ExpressionStatement(Expression *exp){
		this->exp = exp;
	}
	void codeGen();
};

class BlockStatement: public Block {
public:
	Block *block;
	BlockStatement(Block *block){
		this->block = block;
	}
	void codeGen();
};


class Operator: public Expression {
public:
	string op;
	Operator(string op){
		this->op = op;
	}
	void codeGen();
};


class BinaryOpExpression: public Expression {
public:
	Expression *lhs;
	Expression *rhs;
	Operator* op;
	BinaryOpExpression(){}
	BinaryOpExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen();
};

class LOrExpression: public BinaryOpExpression {
public:
	LOrExpression(Expression *lhs, Expression *rhs){
		this->op = new Operator("or");
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen();
};

class LAndExpression: public BinaryOpExpression {
public:
	LAndExpression(Expression *lhs, Expression *rhs){
		this->op = new Operator("and");
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen();
};


class EqExpression: public BinaryOpExpression {
public:
	EqExpression(Expression *lhs, Expression *rhs){
		this->op = new Operator("eq");
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen();
};

class RelExpression: public BinaryOpExpression {
public:
	RelExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen();
};

class AddExpression: public BinaryOpExpression {
public:
	AddExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen();
};

class MulExpression: public BinaryOpExpression {
public:
	MulExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen();
};

class PrimaryExp: public Expression {
public:
	int number;
	Lval *lval;
	Expression *exp;
	PrimaryExp(int number, Lval *lval, Expression *exp){
		this->number = number;
		this->lval = lval;
		this->exp = exp;
	}
	void codeGen();
};

class UnaryExp: public Expression {
public:
	PrimaryExp *primaryExp;
	FuncCall *funcCall;
	string unaryOp;
	UnaryExp *unaryExp;
	UnaryExp(PrimaryExp *primaryExp,FuncCall* funcCall,string unaryOp,UnaryExp* unaryExp){
		this->primaryExp = primaryExp;
		this->funcCall = funcCall;
		this->unaryOp = unaryOp;
		this->unaryExp = unaryExp;
	}
	void codeGen();
};

class IFStatement: public Statement {
public:
	Expression *exp;
	Stmts *TRUEStmts;
	Stmts *FALSEStmts;
	IFStatement(Expression *exp,Stmts *TRUEStmts,Stmts *FALSEStmts){
		this->exp = exp;
		this->TRUEStmts = TRUEStmts;
		this->FALSEStmts = FALSEStmts;
	}
	void codeGen();
};


class WHILEStatement: public Statement {
public:
	Expression *exp;
	Stmts *stmts;
	WHILEStatement(Expression *exp,Stmts *stmts){
		this->exp = exp;
		this->stmts = stmts;
	}
	void codeGen();
};

class RETURNStatement: public Statement {
public:
	Expression *exp;
	RETURNStatement(Expression *exp){
		this->exp = exp;
	}
	void codeGen();
};

class BREAKStatement: public Statement {
public:
	BREAKStatement(){
	}
	void codeGen();
};

class CONTINUEStatement: public Statement {
public:
	CONTINUEStatement(){
	}
	void codeGen();
};
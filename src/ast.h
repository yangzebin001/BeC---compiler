#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>

using namespace std;
using namespace llvm;


class AstContext;
class Node;
class Statement;
class Expression;
class Program;
class ConstVarDecl;
class ConstVarDef;
class VarDecl;


class Node {
public:
};

class Program : public Node{
public:
	vector<VarDecl*> VarDecls;
    vector<ConstVarDecl*> constVarDecls;
	vector<FuncDef*> funcDefs;

	void addConstVarDecl(ConstVarDecl *constVarDecl) {
		constVarDecls.push_back(constVarDecl);
	}

	void addVarDecl(VarDecl *VarDecl) {
		VarDecls.push_back(VarDecl);
	}

	void addFuncDef(FuncDef *funcDef) {
		funcDefs.push_back(funcDef);
	}
	void codeGen(AstContext &astContext);
};

class Statement: public Node {
public:
	virtual ~Statement() {
	}
	void codeGen(AstContext &astContext);
};

class Expression: public Node {
public:
	virtual ~Expression() {
	}
	void codeGen(AstContext &astContext);
};

class TypeDecl: public Node {
public:
	string typeName;

	TypeDecl(string &typeName) {
		this->typeName = typeName;
	}
};

class ConstVarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<ConstVarDef*> ConstVarDefList;

	ConstVarDecl(TypeDecl *typeDecl, vector<ConstVarDecl*> &ConstVarDefList) {
		this->typeDecl = typeDecl;
		this->ConstVarDefList = ConstVarDefList;
	}

	void codeGen(AstContext &astContext);
};


class ConstVarDef: public Statement {
public:
	Lval *lval;
	Expression *initVal;

	ConstVarDecl(Lval *lval, Expression *initVal) {
		this->lval = lval;
		this->initVal = initVal;
	}
	void codeGen(AstContext &astContext);
};

class Lval: public Expression {
public:
	void codeGen(AstContext &astContext);
};

class Ident: public Lval {
public:
	string id;
	Ident(string &id){
		this->id = id;
	}
	AValue gen(AstContext &astContext);
	AValue lvalueGen(AstContext &astContext);
}

class ArrayElement: public Lval {
public:
	Expression *array;
	Expression *index;

	ArrayElement(Expression *array, Expression *index) {
		this->array = array;
		this->index = index;
	}

	AValue gen(AstContext &astContext);
	AValue lvalueGen(AstContext &astContext);
};

class ArrayInit: public Expression {
public:
	vector<Expression*> exprList;

	ArrayInit(vector<Expression*> exprList) {
		this->exprList = exprList;
	}

	AValue gen(AstContext &astContext);
};

class ArrayDecl: public Expression {
public:
	ArrayElement *arrayElement;
	ArrayInit *arrayInit;

	ArrayDecl(ArrayElement *arrayElement, ArrayInit *arrayInit){
		this->arrayElement = arrayElement;
		this->arrayInit = arrayInit;
	}

	AValue gen(AstContext &astContext);
}

class VarDecl: public Statement {
public:
	TypeDecl *typeDecl;
	vector<VarDef*> VarDefList;

	VarDecl(TypeDecl *typeDecl, vector<VarDef*> &VarDefList) {
		this->typeDecl = typeDecl;
		this->VarDefList = VarDefList;
	}

	void globalGen();
	void fieldGen(AstContext &astContext);
	void codeGen(AstContext &astContext);
};


class VarDef: public Expression {
public:
	void codeGen(AstContext &astContext);
}

class DirectDecl: public VarDef {
public:
	Ident *ident;
	Expression* exp;
	DirectDecl(Ident *ident, Expression* exp){
		this->ident = ident;
		this->exp = exp;
	}
	void codeGen(AstContext &astContext);
}

class ArrayDecl: public VarDef {
public:
	ArrayElement *arrayElement;
	Expression* initVal;
	ArrayDecl(ArrayElement *arrayElement, Expression* initVal){
		this->arrayElement = arrayElement;
		this->initVal = initVal;
	}
	void codeGen(AstContext &astContext);
}

//todo: FuncDef,Block,Stmts,AddExp

class Block: public Node {
public:
	void codeGen(AstContext &astContext);
}

class FuncParam: public Node{
public: 
	TypeDecl *typeDecl;
	Lval *lval;
	FuncParam(TypeDecl *typeDecl, Lval *lval){
		this->typeDecl = typeDecl;
		this->lval = lval;
	}
}

class FunctionDef: public Node {
public:
	TypeDecl *returnType;
	Ident id;
	vector<FuncParam*> ParamList;
	Block *block;
	FunctionDef(TypeDecl* returnType, Ident id, vector<FuncParam*> ParamList, Block* block){
		this->returnType = returnType;
		this->id = id;
		this->ParamList = ParamList;
		this->block = block;
	}
	void codeGen(AstContext &astContext);
}


class FuncCall: public Expression {
	Ident id;
	vector<FuncParam*> ParamList;
	FuncCall(Ident id, vector<FuncParam*> ParamList){
		this->id = id;
		this->ParamList = ParamList;
	}
	void codeGen(AstContext &astContext);
}


class Stmts: public Node {
public:
	vector<Statement*> statementList;
	Stmts(vector<Statement*> statementList){
		this->statementList = statementList;
	}
	void codeGen(AstContext &astContext);
}





class Assignment: public Statement {
public:
	Lval *lval;
	Expression *exp;
	Assignment(Lval *lval, Expression *exp){
		this->lval = lval;
		this->exp = exp;
	}
	void codeGen(AstContext &astContext);
}

class ExpressionStatement: public Expression {
	Expression *exp;
	Assignment(Expression *exp){
		this->exp = exp;
	}
	void codeGen(AstContext &astContext);
}

class BlockStatement: public Block {
	Block *block;
	BlockStatement(Block *block){
		this->block = block;
	}
	void codeGen(AstContext &astContext);
}


class Operator: public Expression {
public:
	string op;
	Operator(string op){
		this->op = op;
	}
	void codeGen(AstContext &astContext);
}


class BinaryOpExpression: public Expression {
public:
	Expression *lhs;
	Expression *rhs;
	Operator* op;
	BinaryOpExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class LOrExpression: public BinaryOpExpression {
public:
	LOrExpression(Expression *lhs, Expression *rhs){
		this->op = "or";
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class LAndExpression: public BinaryOpExpression {
public:
	LAndExpression(Expression *lhs, Expression *rhs){
		this->op = "and";
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}


class EqExpression: public BinaryOpExpression {
public:
	EqExpression(Expression *lhs, Expression *rhs){
		this->op = "eq";
		this->lhs = lhs;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class RelExpression: public BinaryOpExpression {
public:
	RelExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class AddExpression: public BinaryOpExpression {
public:
	AddExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class MulExpression: public BinaryOpExpression {
public:
	MulExpression(Expression *lhs, Operator* op, Expression *rhs){
		this->lhs = lhs;
		this->op = op;
		this->rhs = rhs;
	}
	void codeGen(AstContext &astContext);
}

class PrimaryExp: public Expression {
public:
	int Number;
	Lval *lval;
	Expression *exp;
	UnaryExp(int Number, Lval *lval, Expression *exp){
		this->Number = Number;
		this->lval = lval;
		this->exp = exp;
	}
	void codeGen(AstContext &astContext);
}

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
	void codeGen(AstContext &astContext);
}

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
	void codeGen(AstContext &astContext);
}


class WHILEStatement: public Statement {
public:
	Expression *exp;
	Stmts *stmts;
	WHILEStatement(Expression *exp,Stmts *stmts){
		this->exp = exp;
		this->stmts = stmts;
	}
	void codeGen(AstContext &astContext);
}

class RETURNStatement: public Statement {
public:
	Expression *exp;
	RETURNStatement(Expression *exp){
		this->exp = exp;
	}
	void codeGen(AstContext &astContext);
}

class BREAKStatement: public Statement {
public:
	BREAKStatement(){
	}
	void codeGen(AstContext &astContext);
}

class CONTINUEStatement: public Statement {
public:
	CONTINUEStatement(){
	}
	void codeGen(AstContext &astContext);
}
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


class VarDef: public Statement {
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




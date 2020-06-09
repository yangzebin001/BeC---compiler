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
class Program;
class VarDef;
class ConstVarDef;
class Statement;


class Node {
public:
};

class Program : public Node{
public:
	vector<VarDef*> varDefs;
    vector<ConstVarDef*> constVarDefs;
	vector<FuncDef*> funcDefs;

	void addConstVarDef(ConstVarDef *constVarDef) {
		constVarDefs.push_back(constVarDef);
	}

	void addVarDef(VarDef *varDef) {
		varDefs.push_back(varDef);
	}

	void addFuncDef(FuncDef *funcDef) {
		funcDefs.push_back(funcDef);
	}
	void codeGen(AstContext &astContext);
};


class Statement: public Node {
public:
	StmtType type;
	virtual void codeGen(AstContext &astContext)=0;
	virtual ~Statement() {
	}
};


class VarDef: public Statement {
public:
	TypeDecl *typeDecl;
	vector<VarInit*> varInitList;

	VarDef(TypeDecl *typeDecl, vector<VarInit*> &varInitList) {
		this->typeDecl = typeDecl;
		this->varInitList = varInitList;
	}

	void globalGen();
	void fieldGen(AstContext &astContext);
	void codeGen(AstContext &astContext);
};

class ConstVarDef: public Statement {
public:
	TypeDecl *typeDecl;
	vector<VarInit*> varInitList;

	ConstVarDef(TypeDecl *typeDecl, vector<VarInit*> &varInitList) {
		this->typeDecl = typeDecl;
		this->varInitList = varInitList;
	}

	void globalGen();
	void fieldGen(AstContext &astContext);
	void codeGen(AstContext &astContext);
};
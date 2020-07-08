#include <cstdio>
#include <assert.h>
#include "ast.h"
#include "assembly.hpp"

void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);

    for(int i = 0; i < funcDefs.size(); i++){
        funcDefs[i]->codeGen();
    }
}

void FunctionDef::codeGen(){
    emit_function_prologue2(id->id.c_str());
    block->codeGen();

    emit_function_epilogue2(id->id.c_str());
}

void Expression::codeGen(){
    printf("EEE\n");
}

void Block::codeGen(){
    for(int i = 0; i < statementList.size(); i++){
        statementList[i]->codeGen();
    }
}

void BinaryOpExpression::codeGen(){
    printf("hhh\n");
}

void RETURNStatement::codeGen(){
    printf("gen returnstatement\n");
    if(exp != NULL){
        exp->codeGen();
    }
}

void Statement::codeGen(){
    printf("SSS\n");
}

void AddExpression::codeGen(){
    printf("gen AddExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void MulExpression::codeGen(){
    printf("gen MulExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void PrimaryExpression::codeGen(){
    printf("gen PrimaryExpression\n");
    if(lval != NULL){
        lval->codeGen();
    }else if(exp != NULL){
        exp->codeGen();
    }else{
        emit_instr_format("mov","r0, #%s",number.c_str());
    }
}

void UnaryExp::codeGen(){
    printf("gen UnaryExp\n");
    if(primaryExp != NULL){
        primaryExp->codeGen();
    }else if(funcCall != NULL){
        funcCall->codeGen();
    }
}

void FunctionCall::codeGen(){
    printf("gen FunctionCall\n");
    emit_instr_format("bl","%s",id->id.c_str());
}

void RelExpression::codeGen(){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void EqExpression::codeGen(){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void LAndExpression::codeGen(){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void LOrExpression::codeGen(){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen();
    }
}

void ExpressionStatement::codeGen(){
    printf("ExpressionStatement\n");
    assert(exp != NULL);
    exp->codeGen();
}
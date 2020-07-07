#include<cstdio>
#include"ast.h"
#include"assembly.hpp"

void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);

    for(int i = 0; i < funcDefs.size(); i++){
        funcDefs[i]->codeGen();
    }
}

void FunctionDef::codeGen(){
    emit_lable(id->id.c_str());
    emit_function_prologue();

    block->codeGen();

    emit_function_epilogue();
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
    }
}


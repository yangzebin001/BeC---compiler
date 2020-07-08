#include <cstdio>
#include <assert.h>
#include "ast.h"
#include "assembly.hpp"

void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);
    Context* topctx = new Context();
    for(int i = 0; i < funcDefs.size(); i++){
        funcDefs[i]->codeGen(*topctx);
    }
}

void FunctionDef::codeGen(Context &ctx){
    emit_function_prologue2(id->id.c_str());
    block->codeGen(ctx);

    emit_function_epilogue2(id->id.c_str());
}

void Expression::codeGen(Context &ctx){
    printf("EEE\n");
}

void Block::codeGen(Context &ctx){
    for(int i = 0; i < statementList.size(); i++){
        statementList[i]->codeGen(ctx);
    }
}

void BinaryOpExpression::codeGen(Context &ctx){
    printf("hhh\n");
}

void RETURNStatement::codeGen(Context &ctx){
    printf("gen returnstatement\n");
    if(exp != NULL){
        exp->codeGen(ctx);
    }
}

void Statement::codeGen(Context &ctx){
    printf("SSS\n");
}

void AddExpression::codeGen(Context &ctx){
    printf("gen AddExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void MulExpression::codeGen(Context &ctx){
    printf("gen MulExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void PrimaryExpression::codeGen(Context &ctx){
    printf("gen PrimaryExpression\n");
    if(lval != NULL){
        lval->codeGen(ctx);
    }else if(exp != NULL){
        exp->codeGen(ctx);
    }else{
        emit_instr_format("mov","r0, #%s",number.c_str());
    }
}

void UnaryExp::codeGen(Context &ctx){
    printf("gen UnaryExp\n");
    if(primaryExp != NULL){
        primaryExp->codeGen(ctx);
    }else if(funcCall != NULL){
        funcCall->codeGen(ctx);
    }
}

void FunctionCall::codeGen(Context &ctx){
    printf("gen FunctionCall\n");
    emit_instr_format("bl","%s",id->id.c_str());
}

void RelExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void EqExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void LAndExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void LOrExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }
}

void ExpressionStatement::codeGen(Context &ctx){
    printf("ExpressionStatement\n");
    assert(exp != NULL);
    exp->codeGen(ctx);
}
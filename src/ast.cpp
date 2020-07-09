#include <cstdio>
#include <assert.h>
#include "ast.h"
#include "assembly.hpp"

static GobalContext* gobalctx = new GobalContext();


const char* get_expression_value(Expression* top){
    return "a";
} 

void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);
    
    // for(int i = 0; i < varDecls.size(); i++){
    //     if(i == 0){
    //         emit_data();
    //     }
    //     if(varDecls[i]->typeDecl->typeName == "int"){
    //         for(int j = 0; j < varDecls[i]->VarDefList.size(); j++){
    //             DirectDecl* now_varDecls = (DirectDecl*)varDecls[i]->VarDefList[j];
    //             if(now_varDecls->exp != NULL){
    //                 emit_gobal_var_def(now_varDecls->ident->id.c_str(), get_expression_value(now_varDecls->exp));
    //             }else{
    //                 emit_gobal_var_decl(now_varDecls->ident->id.c_str());
    //             }
    //         }
    //     }
    // }



    for(int i = 0; i < funcDefs.size(); i++){
        if(i == 0){
            emit_data();
        }
        Context* funcxt = new Context();
        funcDefs[i]->codeGen(*funcxt);
        delete funcxt;
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
        emit_instr_format("mov","r0, r3");
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
        emit_instr_format("mov","r3, #%s",number.c_str());
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
    printf("gen ExpressionStatement\n");
    assert(exp != NULL);
    exp->codeGen(ctx);
}

void VarDecl::codeGen(Context &ctx){
    for(int i = 0; i < VarDefList.size(); i++){
        VarDefList[i]->codeGen(ctx);
    }
}

void VarDef::codeGen(Context &ctx){
    printf("gen VarDef\n");
}

void DirectDecl::codeGen(Context &ctx){
    printf("gen DirectDecl\n");
    assert(ident != NULL);
    bool offset_result = ctx.set_offset(ident->id);
    if(offset_result) {
        emit_instr_format("sub", "sp, sp, #4");
    }
    if(exp != NULL){
        exp->codeGen(ctx);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(ident->id));
    }
}

void Lval::codeGen(Context &ctx){
    printf("gen Lval\n");
}


void Ident::codeGen(Context &ctx){
    printf("gen Ident\n");
    emit_instr_format("ldr", "r3, [fp, #%d]", ctx.get_offset(id));
}


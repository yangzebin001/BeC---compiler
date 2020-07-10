#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#include "ast.h"
#include "assembly.hpp"

static GobalContext* gobal_ctx = new GobalContext();

string get_gobal_label(int label){
    return ".L" + to_string(label);
}


/*just support immediate number*/
string get_var_value(AddExpression* top){
    return ((UnaryExp*)((MulExpression*)top->unaryExp)->unaryExp)->primaryExp->number;
} 

string get_lval_name(Lval* lval){
    if(lval->type == IDENT){
        return ((Ident*)lval)->id;
    }
}

string make_array_ele_name(string array,int index){
    return array + "__" + to_string(index);
}

void get_array_def_number(InitVal* initVal, vector<int> &array_layer, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(array_layer[cur_layer] == 0){
        array_layer[cur_layer] = cur_number > array_layer[cur_layer] ? cur_number : array_layer[cur_layer];
    }
    for(int i = 0; i < cur_number; i++){
        get_array_def_number(initVal->initValList[i], array_layer, cur_layer+1);
    }
}


int get_array_element_number(ArrayDecl* nowarray){
    ArrayElement* ae = (ArrayElement*)nowarray->arrayElement;
    int number = 1;
    vector<int> array_layer;

    //decl
    while(ae->type != IDENT){
        if(ae->index != NULL){
            string cur_ele_number = get_var_value((AddExpression*)ae->index);
            array_layer.push_back(stoi(cur_ele_number));
        }else{
            array_layer.push_back(0);
        }
        ae = (ArrayElement*)ae->array;
    }
    // because array decl is back to front
    reverse(array_layer.begin(),array_layer.end());

    // //def
    if(nowarray->initVal != NULL){
        get_array_def_number((InitVal*)nowarray->initVal,array_layer,0);
    }

    for(int i = 0; i < array_layer.size(); i++){
        number = number * array_layer[i];
    }
    
    return number;
}


string get_array_name(ArrayElement* ae){
    int number = 1;
    while(ae->type != IDENT){
        ae = (ArrayElement*)ae->array;
    }
    return ((Ident*)ae)->id;
}

void get_array_initval_from_index_1(InitVal* initVal, vector<int> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        int val = stoi(get_var_value((AddExpression*)initVal->exp));
        array_eles.push_back(val);
    }
    for(int i = 0; i < cur_number; i++){
        get_array_initval_from_index_1(initVal->initValList[i], array_eles, cur_layer+1);
    }
}


int gen_array_initval_from_index(InitVal* initVal, int index){
    vector<int> flat_array_eles;
    get_array_initval_from_index_1(initVal,flat_array_eles, 0);
    return flat_array_eles[index];
}

// suppose that element is side by side
void get_gobal_array_initval_from_vec(InitVal* initVal, vector<string> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        array_eles.push_back(get_var_value((AddExpression*)initVal->exp));
    }
    for(int i = 0; i < cur_number; i++){
        get_gobal_array_initval_from_vec(initVal->initValList[i], array_eles, cur_layer+1);
    }
}



void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);
    
    // store gobal const var and array
    for(int i = 0; i < constVarDecls.size(); i++){
        for(int j = 0; j < constVarDecls[i]->constVarDefList.size(); j++){
            //const var
            if(constVarDecls[i]->constVarDefList[j]->lval->type != ARRAYELEMENT){
                string var_name = get_lval_name(constVarDecls[i]->constVarDefList[j]->lval);
                string var_val = get_var_value((AddExpression*)constVarDecls[i]->constVarDefList[j]->initVal->exp);
                // cout << var_name << ":" << var_val << endl;
                gobal_ctx->set_const_value(var_name, var_val);

            }else{
            //const array
                cout << "111" << endl;
                ArrayElement* now_arr = (ArrayElement*)constVarDecls[i]->constVarDefList[j]->lval;
                InitVal* initVal = (InitVal*)constVarDecls[i]->constVarDefList[j]->initVal;
                string array_name = get_array_name(now_arr);

                cout << array_name << endl;
                
                vector<string> flat_array_eles;
                get_gobal_array_initval_from_vec(initVal, flat_array_eles, 0);
                for(int i = 0; i < flat_array_eles.size(); i++){
                    string array_ele_name = make_array_ele_name(array_name,i);
                    cout << array_ele_name << " : " << flat_array_eles[i] << endl;
                    gobal_ctx->set_const_value(array_ele_name, flat_array_eles[i]);
                }
            }
        }
    }



    // gen gobal var and array
    for(int i = 0; i < varDecls.size(); i++){
        if(i == 0){
            emit_text();
            emit_data();
        }
        for(int j = 0; j < varDecls[i]->VarDefList.size(); j++){
            if(varDecls[i]->VarDefList[j]->type == DIRECTDECL){
                DirectDecl* now_varDecls = (DirectDecl*)varDecls[i]->VarDefList[j];
                
                // now just support immediate number
                if(now_varDecls->exp != NULL){
                    emit_gobal_var_def(now_varDecls->ident->id.c_str(), get_var_value((AddExpression*)now_varDecls->exp).c_str());
                }
                else{
                    emit_gobal_var_decl(now_varDecls->ident->id.c_str(), 4);
                }
                
                // cout << now_varDecls->ident->id << ":" << endl; 
                
                gobal_ctx->set_label(now_varDecls->ident->id);

            }else if(varDecls[i]->VarDefList[j]->type == ARRAYDECL){
                ArrayDecl* now_arrDecls = (ArrayDecl*)varDecls[i]->VarDefList[j];
                int ele_number = get_array_element_number(now_arrDecls);
                string array_name = get_array_name(now_arrDecls->arrayElement);
                
                // cout << "ele number is: " << ele_number  << " name is :" << array_name<< endl; 

                if(now_arrDecls->initVal != NULL){
                    
                    emit_part_gobal_var_def(array_name.c_str(), ele_number*WORD_SIZE);
                    
                    vector<string> flat_array_eles;
                    get_gobal_array_initval_from_vec(now_arrDecls->initVal, flat_array_eles, 0);
                    for(int i = 0; i < flat_array_eles.size(); i++){
                        emit_word(flat_array_eles[i].c_str());
                    }

                }else{
                    emit_gobal_var_decl(array_name.c_str(), ele_number*WORD_SIZE);
                }
                gobal_ctx->set_label(array_name);

            }
        }
    }

    // gen function
    for(int i = 0; i < funcDefs.size(); i++){
        if(i == 0){
            emit_text();
        }
        Context* funcxt = new Context();
        funcxt->new_scope();
        funcDefs[i]->codeGen(*funcxt);
        delete funcxt;
    }


    //gen var and array lable
    string tmp = "";
	int label_idx = 1;
	gobal_ctx->init_label_for();
	while(gobal_ctx->get_next_label(tmp,label_idx)){
		emit_gobal_var_lable(get_gobal_label(label_idx).c_str(), tmp.c_str());
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
    ctx.cur_type = CFUNCTIONCALL;
    emit_instr_format("bl","%s",id->id.c_str());
    emit_instr_format("mov", "r3, r0");
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

void ArrayDecl::codeGen(Context &ctx){
    printf("gen ArrayDecl\n");
}

void Lval::codeGen(Context &ctx){
    printf("gen Lval\n");
}

void Ident::codeGen(Context &ctx){
    printf("gen Ident\n");

    ctx.cur_var_name = id;

    int offset = ctx.get_offset(id);
    //local var
    if(offset != -1){
        ctx.cur_type = CLOCAL_VAR;
        emit_instr_format("ldr", "r3, [fp, #%d]", offset);
    }else{
        int label = gobal_ctx->get_label(id);
        
        if(label != -1){
            ctx.cur_type = CGOBAL_VAR;
            emit_instr_format("ldr", "r2, %s", get_gobal_label(label).c_str());
        }else{
            string gobal_const_var = gobal_ctx->get_const_value(id);
            if(gobal_const_var != ""){
                emit_instr_format("mov","r3, #%s",gobal_const_var.c_str());
            }else {
                fprintf(stderr,"cannot find : %s not def\n", id.c_str());
                exit(-1);
            }
        }
    }
}

void Assignment::codeGen(Context &ctx){
    exp->codeGen(ctx);  //in r3
    ctx_t exp_type = ctx.cur_type;

    lval->codeGen(ctx); //in r2
    ctx_t lval_type = ctx.cur_type;
    string lval_name = ctx.cur_var_name;



    if(lval_type == CGOBAL_VAR){
        emit_instr_format("str", "r3, [r2]");
    }else if(lval_type == CLOCAL_VAR){
        // str        r3, [fp, #-4]
        emit_instr_format("str", "r3, [fp, #%d]",  ctx.get_offset(lval_name));
    }
}


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#include <map>
#include "ast.h"
#include "assembly.hpp"

static GobalContext* gobal_ctx = new GobalContext();

static const int WORD_SIZE_WIDTH = 2;

string get_gobal_label(int label){
    return ".L" + to_string(label);
}

string get_array_name(ArrayElement* ae){
    int number = 1;
    while(ae->type != IDENT){
        ae = (ArrayElement*)ae->array;
    }
    return ((Ident*)ae)->id;
}

string get_lval_name(Expression* lval){
    if(lval->type == IDENT){
        return ((Ident*)lval)->id;
    }else if(lval->type == DIRECTDECL){
        return get_lval_name(((DirectDecl*)lval)->ident);
    }else if(lval->type == ARRAYELEMENT){
        return get_array_name((ArrayElement*) lval);
    }
}

/*just support immediate number and gobal const var*/
string get_var_value(AddExpression* top){
    PrimaryExpression* pe = ((UnaryExp*)((MulExpression*)top->unaryExp)->unaryExp)->primaryExp;
    if(pe->lval != NULL){
        cout << "const var is : " << gobal_ctx->get_const_value(get_lval_name(pe->lval)) << endl;
        return gobal_ctx->get_const_value(get_lval_name(pe->lval));
    }
    return pe->number;
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

int get_array_element_number_vec(ArrayDecl* nowarray, vector<int> &array_layer){
    ArrayElement* ae = (ArrayElement*)nowarray->arrayElement;
    int number = 1;
    array_layer.resize(0);

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

void get_gobal_array_initval(InitVal* initVal, vector<Expression*> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        array_eles.push_back(initVal->exp);
    }
    for(int i = 0; i < cur_number; i++){
        get_gobal_array_initval(initVal->initValList[i], array_eles, cur_layer+1);
    }
}



void write_rel_instr(ctx_t type, string label){
    if(type == CGT){
        emit_instr_format("ble", "%s", label.c_str());
    }else if(type == CLT){
        emit_instr_format("bge", "%s", label.c_str());
    }else if(type == CGE){
        emit_instr_format("blt", "%s", label.c_str());
    }else if(type == CLE){
        emit_instr_format("bgt", "%s", label.c_str());
    }else if(type == CEQ){
        emit_instr_format("bne", "%s", label.c_str());
    }else if(type == CNE){
        emit_instr_format("beq", "%s", label.c_str());
    }else if(type == CSINGLE){
        emit_instr_format("beq", "%s", label.c_str());
    }
}


void write_rel_instr_forward(ctx_t type, string label){
    if(type == CGT){
    }else if(type == CLT){
        emit_instr_format("blt", "%s", label.c_str());
    }else if(type == CGE){
        emit_instr_format("bgt", "%s", label.c_str());
        emit_instr_format("bge", "%s", label.c_str());
    }else if(type == CLE){
        emit_instr_format("ble", "%s", label.c_str());
    }else if(type == CEQ){
        emit_instr_format("beq", "%s", label.c_str());
    }else if(type == CNE){
        emit_instr_format("bne", "%s", label.c_str());
    }else if(type == CSINGLE){
        emit_instr_format("bne", "%s", label.c_str());
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
            //const array treat as gobal array
                if(i == 0 && j == 0){
                    emit_text();
                    emit_data();
                }
                cout << "111" << endl;
                ArrayElement* now_arr_ele = (ArrayElement*)constVarDecls[i]->constVarDefList[j]->lval;
                InitVal* initVal = (InitVal*)constVarDecls[i]->constVarDefList[j]->initVal;
                // string array_name = get_array_name(now_arr);

                // cout << array_name << endl;
                
                // vector<string> flat_array_eles;
                // get_gobal_array_initval_from_vec(initVal, flat_array_eles, 0);
                // for(int i = 0; i < flat_array_eles.size(); i++){
                //     string array_ele_name = make_array_ele_name(array_name,i);
                //     cout << array_ele_name << " : " << flat_array_eles[i] << endl;
                //     gobal_ctx->set_const_value(array_ele_name, flat_array_eles[i]);
                // }

                ArrayDecl* now_arrDecls = new ArrayDecl(now_arr_ele, initVal);

                int ele_number = get_array_element_number(now_arrDecls);
                string array_name = get_array_name(now_arrDecls->arrayElement);
                

                vector<int> array_layers;
                get_array_element_number_vec(now_arrDecls,array_layers);
                gobal_ctx->set_array_layers(array_name, array_layers);
                // cout << "ele number is: " << ele_number  << " name is :" << array_name<< endl; 
                
                emit_part_gobal_var_def(array_name.c_str(), ele_number*WORD_SIZE);
                
                vector<string> flat_array_eles;
                get_gobal_array_initval_from_vec(now_arrDecls->initVal, flat_array_eles, 0);
                for(int i = 0; i < flat_array_eles.size(); i++){
                    emit_word(flat_array_eles[i].c_str());
                }
                gobal_ctx->set_label(array_name);
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
                

                vector<int> array_layers;
                get_array_element_number_vec(now_arrDecls,array_layers);
                gobal_ctx->set_array_layers(array_name, array_layers);
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
        funcxt->delete_scope();
        delete funcxt;
    }


    //gen var and array lable
    string tmp = "";
	int label_idx = 1;
	gobal_ctx->init_label_for();
	while(gobal_ctx->get_next_label(tmp,label_idx)){
        if(tmp.find("label_") != 0)
		    emit_gobal_var_lable(get_gobal_label(label_idx).c_str(), tmp.c_str());
	}
}

void FunctionDef::codeGen(Context &ctx){
    printf("gen FunctionDef\n");
    emit_function_prologue2(id->id.c_str());
    int end_label = gobal_ctx->set_if_label("label_RETURN");
    ctx.cur_return_label = end_label;

    // support 4 param at most
    for(int i = 0; i < ParamList.size() && i < 4; i++){
        if(ParamList[i]->lval->type == IDENT){
            DirectDecl *d = new DirectDecl((Ident*)ParamList[i]->lval, NULL);
            string ident = get_lval_name(ParamList[i]->lval);

            d->codeGen(ctx);

            emit_instr_format("str", "r%d, [fp, #%d]", i, ctx.get_offset(ident));

        }
        else{
            vector<int> array_layers;
            string ident = get_lval_name(ParamList[i]->lval);
            ArrayDecl* now_arrDecls = new ArrayDecl((ArrayElement*)ParamList[i]->lval, NULL);
            get_array_element_number_vec(now_arrDecls,array_layers);
            ctx.set_array_layers(ident, array_layers);
            ctx.set_offset(ident);
            // ctx.set_def_array(ident);
            emit_instr_format("str", "r%d, [fp, #%d]", i, ctx.get_offset(ident));
        }
    }

    block->codeGen(ctx);
    
    
    emit_label(gobal_ctx->get_if_label("label_RETURN", end_label).c_str());
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
        ctx.cur_type = CRETURN;
        exp->codeGen(ctx);
        emit_instr_format("mov","r0, r3");
    }
    
    emit_instr_format("b","%s", gobal_ctx->get_if_label("label_RETURN", ctx.cur_return_label).c_str());
}

void Statement::codeGen(Context &ctx){
    printf("SSS\n");
}

void AddExpression::codeGen(Context &ctx){
    printf("gen AddExpression\n");

    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        lhs->codeGen(ctx);
        string new_tmp = ctx.get_unique_temp_stack_name("add");

        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        rhs->codeGen(ctx);
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        if(op->op == "+"){
            emit_instr_format("add", "r3, r7");
        }else if(op->op == "-"){
            emit_instr_format("sub", "r3, r7, r3");
        }
    }
}

void MulExpression::codeGen(Context &ctx){
    printf("gen MulExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        lhs->codeGen(ctx);
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        rhs->codeGen(ctx);
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        if(op->op == "*"){
            emit_instr_format("mul", "r3, r7");
        }
        else if(op->op == "/"){
            emit_instr_format("mov", "r1, r3");
            emit_instr_format("mov", "r0, r7");
            emit_instr_format("bl", "__aeabi_idiv");
            emit_instr_format("mov", "r3, r0");
        }else if(op->op == "%"){
            emit_instr_format("mov", "r1, r3");
            emit_instr_format("mov", "r0, r7");
            emit_instr_format("bl", "__aeabi_idivmod");
            emit_instr_format("mov", "r3, r1");
        }
    }
}

void PrimaryExpression::codeGen(Context &ctx){
    printf("gen PrimaryExpression\n");
    if(lval != NULL){
        ctx.cur_type = CLVAL;
        lval->codeGen(ctx);
        // cout << ctx.cur_type << endl;
        if(ctx.cur_type == CARRAY_ELE){
            bool is_const_array = false;
            string lval_name = ctx.cur_var_name;
            int array_offset = ctx.get_offset(lval_name);
            
            if(array_offset != 0){
                bool is_def_arr = ctx.get_def_array(lval_name);
                if(is_def_arr){
                    // emit_instr_format("111", "r1, fp, #%d", -array_offset);
                    emit_instr_format("sub", "r1, fp, #%d", -array_offset);
                }else{
                    // emit_instr_format("222", "r1, fp, #%d", -array_offset);
                    emit_instr_format("ldr", "r1, [fp, #%d]", array_offset);
                }

            }else{
                int label  = gobal_ctx->get_label(lval_name);
                //gobal array
                if(label != -1){
                    emit_instr_format("ldr", "r1, %s", get_gobal_label(label).c_str());
                }else{
                //gobal const array
                    // is_const_array = true;
                    // emit_instr_format("mov", "r1, %s", get_gobal_label().c_str());
                }
            }
            if(ctx.cur_var_disload == false && is_const_array == false){
                emit_instr_format("ldr", "r3, [r1, r9]");
            }
        }

        

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
    }else if(unaryOp != NULL){
        unaryExp->codeGen(ctx);
        if(unaryOp->op == "-"){
            emit_instr_format("rsb", "r3, r3, #0");
        }else if(unaryOp->op == "!"){
            emit_instr_format("cmp", "r3, #0");
            emit_instr_format("moveq", "r3, #1");
            emit_instr_format("movne", "r3, #0");
            emit_instr_format("uxtb", "r3, r3");
        }
    }
}

void FunctionCall::codeGen(Context &ctx){
    printf("gen FunctionCall\n");
    ctx.cur_type = CFUNCTIONCALL;
    for(int i = 0; i < ParamList.size() && i < 3; i++){
        ParamList[i]->codeGen(ctx);
        emit_instr_format("mov", "r%d, r3",i);
    }
    emit_instr_format("bl","%s",id->id.c_str());
    emit_instr_format("mov", "r3, r0");
}


// void FuncParam::codeGen(Context &ctx){
//     printf("gen FuncParam\n");
//     if(lval->type == DIRECTDECL){

//     }
// }

void RelExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
        ctx.cur_type = CSINGLE;
    }else{
        lhs->codeGen(ctx);
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        rhs->codeGen(ctx);
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        emit_instr_format("cmp", "r7, r3");
        if(op->op == ">"){
            ctx.cur_type = CGT;
        }else if(op->op == "<"){
            ctx.cur_type = CLT;
        }else if(op->op == ">="){
            ctx.cur_type = CGE;
        }else if(op->op == "<="){
            ctx.cur_type = CLE;
        }
        
    }
}

void EqExpression::codeGen(Context &ctx){
    printf("gen EqExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        lhs->codeGen(ctx);
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        rhs->codeGen(ctx);
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        emit_instr_format("cmp", "r7, r3");
        if(op->op == "=="){
            ctx.cur_type = CEQ;
        }else if(op->op == "!="){
            ctx.cur_type = CNE;
        }
    }
}

void LAndExpression::codeGen(Context &ctx){
    printf("gen LAndExpression\n");
    ctx_t cur_type = ctx.cur_type;
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);

        
    }else{
        if(cur_type == CIF){

            string end_label_name =(gobal_ctx->if_false_labels).back().first;
            int end_label = (gobal_ctx->if_false_labels).back().second;
            lhs->codeGen(ctx);
            //will print many time when LAndExpression's son also is LAndExpression
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
            
            rhs->codeGen(ctx);
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
            ctx.cur_type = CAND;
        }else if(cur_type == CWHILE){
            string end_label_name =(gobal_ctx->while_false_labels).back().first;
            int end_label = (gobal_ctx->while_false_labels).back().second;
            lhs->codeGen(ctx);
            //will print many time when LAndExpression's son also is LAndExpression
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
            
            rhs->codeGen(ctx);
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
            ctx.cur_type = CAND;
        }
    }
}


void LOrExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");
    ctx_t cur_type = ctx.cur_type;

    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
        if(ctx.cur_type == CSINGLE){
            emit_instr_format("cmp", "r3, #0");
        }

        if(cur_type == CIF){
            string end_label_name = gobal_ctx->if_false_labels.back().first;
            int end_label = gobal_ctx->if_false_labels.back().second;
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
        }else if(cur_type == CWHILE){
            string end_label_name = gobal_ctx->while_false_labels.back().first;
            int end_label = gobal_ctx->while_false_labels.back().second;
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
        }

    }else{
        if(cur_type == CIF){

            string end_label_name =(gobal_ctx->if_false_labels).back().first;
            int end_label = (gobal_ctx->if_false_labels).back().second;
            string true_label_name =(gobal_ctx->if_true_labels).back().first;
            int true_label = (gobal_ctx->if_true_labels).back().second;
            
            lhs->codeGen(ctx);
            write_rel_instr_forward(ctx.cur_type, gobal_ctx->get_if_label(true_label_name, true_label));
            
            rhs->codeGen(ctx);
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
        }else if(cur_type == CWHILE){
            string end_label_name =(gobal_ctx->while_false_labels).back().first;
            int end_label = (gobal_ctx->while_false_labels).back().second;
            string true_label_name =(gobal_ctx->while_start_labels).back().first;
            int true_label = (gobal_ctx->while_start_labels).back().second;
            
            lhs->codeGen(ctx);
            write_rel_instr_forward(ctx.cur_type, gobal_ctx->get_if_label(true_label_name, true_label));
            
            rhs->codeGen(ctx);
            write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label(end_label_name, end_label));
        }

    }
}

void ExpressionStatement::codeGen(Context &ctx){
    printf("gen ExpressionStatement\n");
    assert(exp != NULL);
    exp->codeGen(ctx);
}

void VarDecl::codeGen(Context &ctx){
    printf("gen VarDecl\n");
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
    ctx.cur_type = CDIRECTDECL;
    bool offset_result = ctx.set_offset(ident->id);
    if(offset_result) {
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
    }
    if(exp != NULL){
        exp->codeGen(ctx);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(ident->id));
    }
}

void ArrayDecl::codeGen(Context &ctx){
    ctx.cur_type = CARRAY_DECL;

    int number = get_array_element_number(this);
    string array_name = get_array_name(arrayElement);

    ctx.set_def_array(array_name);

    cout << "array size is:" <<number << endl;
    bool offset_result = ctx.set_assign_offset(array_name,number);

    vector<int> array_layers;
    get_array_element_number_vec(this,array_layers);
    ctx.set_array_layers(array_name, array_layers);


    if(offset_result) {
        emit_instr_format("sub", "sp, sp, #%d", number*WORD_SIZE);
    }
    emit_instr_format("sub", "r2, fp, #%d", -ctx.get_offset(array_name));
    emit_instr_format("mov", "r3, #0");
    for(int i = 0; i < number; i++){
        emit_instr_format("str", "r3, [r2, #%d]", i*WORD_SIZE);
    }
    if(initVal != NULL){

        vector<Expression*> expList;
        get_gobal_array_initval(initVal, expList, 0);
        for(int i = 0; i < expList.size(); i++){
            expList[i]->codeGen(ctx);
            emit_instr_format("str", "r3, [r2, #%d]", i*WORD_SIZE);
        }
    }
}

void ConstVarDecl::codeGen(Context &ctx){
    printf("gen ConstVarDecl\n");
    for(int i = 0; i < constVarDefList.size(); i++){
        constVarDefList[i]->codeGen(ctx);
    }
}


void ConstVarDef::codeGen(Context &ctx){
    printf("gen ConstVarDef\n");
    if(lval->type == ARRAYELEMENT){
        ArrayDecl* constArrayDecl = new ArrayDecl((ArrayElement*)lval, initVal);
        constArrayDecl->codeGen(ctx);
    }else{

    }
}


void Lval::codeGen(Context &ctx){
    printf("gen Lval\n");
}

void Ident::codeGen(Context &ctx){
    printf("gen Ident\n");

    ctx.cur_var_name = id;

    int offset = ctx.get_offset(id);
    //local var
    if(offset != 0){
        if(ctx.cur_var_disload == false){
            if(ctx.get_def_array(id)){
                emit_instr_format("sub", "r3, fp, #%d", -offset);
            }else{
                emit_instr_format("ldr", "r3, [fp, #%d]", offset);
                // emit_instr_format("111", "r3, fp, #%d", -offset);
                //
            }
        }
        ctx.cur_type = CLOCAL_VAR;
    }else{
    //gobal var
        int label = gobal_ctx->get_label(id);
        if(label != -1){
            ctx.cur_type = CGOBAL_VAR;
            emit_instr_format("ldr", "r2, %s", get_gobal_label(label).c_str());
            if(ctx.cur_var_disload == false)
                emit_instr_format("ldr", "r3, [r2]");
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

void ArrayElement::codeGen(Context &ctx){
    // array direct needn't reach here
    printf("gen arrayElement\n");
    if(ctx.cur_type != CLVAL) return;

    bool cur_var_disload = ctx.cur_var_disload;
    ctx.cur_var_disload = false;

    string array_name = get_array_name(this);
    cout << "assign array name is " << array_name << endl;
    if(ctx.cur_array_layers.size() == 0){
        ctx.cur_var_name = array_name;
        ctx.get_array_layers(array_name, ctx.cur_array_layers);

        if(ctx.cur_array_layers.size() == 0){
            gobal_ctx->get_array_layers(array_name, ctx.cur_array_layers);
        }

        ctx.cur_array_index = ctx.cur_array_layers.size()-1;
        cout << "array size is " << ctx.cur_array_layers.size() << endl;
        
        
        index->codeGen(ctx);

        ctx.cur_var_name = array_name;
        ctx.cur_type = CLVAL;
        emit_instr_format("mov","r9, r3");
        emit_instr_format("lsl","r9, r9, #%d", WORD_SIZE_WIDTH);
        // cout << "now layer is" << ctx.cur_array_layers[ctx.cur_array_index] << endl;
    }else{
        ctx.cur_var_name = array_name;
        index->codeGen(ctx);
        ctx.cur_var_name = array_name;
        ctx.cur_type = CLVAL;
        emit_instr_format("mov","r7, #%d",ctx.cur_array_layers[ctx.cur_array_index]);
        emit_instr_format("lsl","r7, r7, #%d", WORD_SIZE_WIDTH);
        emit_instr_format("mul","r3, r7");
        emit_instr_format("add","r9, r3");
        
        // cout << "now layer is" << ctx.cur_array_layers[ctx.cur_array_index] << endl;
        ctx.cur_array_index--;
    }
    
    // out this type ArrayElement node
    if(ctx.cur_array_index == 0){
        ctx.cur_array_layers.resize(0);
        ctx.cur_var_disload = cur_var_disload;
    }


    //get scale
    if(array->type == IDENT) {
        ctx.cur_type = CARRAY_ELE;
        return;
    }
    array->codeGen(ctx);
    ctx.cur_type = CARRAY_ELE;
}

void Assignment::codeGen(Context &ctx){
    printf("gen Assignment\n");
    // exp after lval gen if type is arrayElement

    exp->codeGen(ctx);  //in r3

    emit_instr_format("mov", "r8, r3");

    ctx.cur_type = CLVAL;

    ctx.cur_var_disload = true;
    lval->codeGen(ctx); //in r2 or arrayElement scale in r1
    ctx.cur_var_disload = false;

    ctx_t lval_type = ctx.cur_type;
    string lval_name = ctx.cur_var_name;

    cout << ctx.cur_type << endl;

    if(lval_type == CGOBAL_VAR){
        emit_instr_format("str", "r8, [r2]");
    }else if(lval_type == CLOCAL_VAR){
        emit_instr_format("str", "r8, [fp, #%d]",  ctx.get_offset(lval_name));
    }else if(lval_type == CARRAY_ELE){
        int array_offset = ctx.get_offset(lval_name);

        if(array_offset != 0){
            bool is_def_arr = ctx.get_def_array(lval_name);
                if(is_def_arr){
                    // emit_instr_format("111", "r1, [fp, #%d]", array_offset);
                    emit_instr_format("sub", "r1, fp, #%d", -array_offset);
                }else{
                    // emit_instr_format("222", "r1, [fp, #%d]", array_offset);
                    emit_instr_format("ldr", "r1, [fp, #%d]", array_offset);
                }
            emit_instr_format("str", "r8, [r1, r9]");
        }else{
        //gobal array
            emit_instr_format("ldr", "r1, %s", get_gobal_label(gobal_ctx->get_label(lval_name)).c_str());
            emit_instr_format("str", "r8, [r1, r9]");
        }
    }
}

void IFStatement::codeGen(Context &ctx){
    printf("gen IFStatement\n");
    
    if(FALSEStmt == NULL){
        int end_label = gobal_ctx->set_if_label("label_IFEND");
        
        (gobal_ctx->if_false_labels).push_back(make_pair("label_IFEND",end_label));

        ctx_t pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        exp->codeGen(ctx);
        ctx.cur_type = pre_type;

        // write_rel_instr(ctx.cur_type, gobal_ctx->get_if_label("label_IFEND", end_label));
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        TRUEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;
        
        emit_label(gobal_ctx->get_if_label("label_IFEND", end_label).c_str());

        (gobal_ctx->if_false_labels).pop_back();

    }else if(FALSEStmt != NULL) {
        int false_label = gobal_ctx->set_if_label("label_IFFALSE");
        int true_label = gobal_ctx->set_if_label("label_IFTRUE");
        int end_label = gobal_ctx->set_if_label("label_IFEND");
        
        //store false label
        (gobal_ctx->if_false_labels).push_back(make_pair("label_IFFALSE",false_label));
        //store true label
        (gobal_ctx->if_true_labels).push_back(make_pair("label_IFTRUE",false_label));
        
        //cond
        ctx_t pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        exp->codeGen(ctx);
        ctx.cur_type = pre_type;

        emit_label(gobal_ctx->get_if_label("label_IFTRUE", false_label).c_str());
        
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        TRUEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;

        // skip false area
        emit_instr_format("b", "%s", gobal_ctx->get_if_label("label_IFEND", end_label).c_str());
        emit_label(gobal_ctx->get_if_label("label_IFFALSE", false_label).c_str());
        
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        FALSEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;
        
        emit_label(gobal_ctx->get_if_label("label_IFEND", end_label).c_str());
    
        (gobal_ctx->if_false_labels).pop_back();
        (gobal_ctx->if_true_labels).pop_back();
    }
    // if false 
    // to  label false
    // label true
    // true->gen
    // to label ifend
    // label false
    // false->gen
    // label ifend
}

void BlockStatement::codeGen(Context &ctx){
    printf("gen BlockStatement\n");
    ctx.new_scope();
    block->codeGen(ctx);
    ctx.delete_scope();
}

void WHILEStatement::codeGen(Context &ctx){
    printf("gen WHILEStatement\n");
    // while_start
    // if false
    // to  label end
    // block 
    // b while_start
    int while_start = gobal_ctx->set_if_label("label_WHILESTART");
    int end_label = gobal_ctx->set_if_label("label_WHILEEND");
    //store label_WHILESTART
    (gobal_ctx->while_start_labels).push_back(make_pair("label_WHILESTART",while_start));
    //store label_WHILEEND
    (gobal_ctx->while_false_labels).push_back(make_pair("label_WHILEEND",end_label));
    //while_start
    emit_label(gobal_ctx->get_if_label("label_WHILESTART", while_start).c_str());
    
    
    //cond
    ctx_t pre_type = ctx.cur_type;
    ctx.cur_type = CWHILE;
    exp->codeGen(ctx);
    ctx.cur_type = pre_type;
    
    pre_type = ctx.cur_type;
    ctx.cur_type = CWHILE;
    ctx.new_scope();
    stmt->codeGen(ctx);
    ctx.delete_scope();
    ctx.cur_type = pre_type;

    // b label_WHILESTART
    emit_instr_format("b", "%s", gobal_ctx->get_if_label("label_WHILESTART", while_start).c_str());
    // label_WHILEEND
    emit_label(gobal_ctx->get_if_label("label_WHILEEND", end_label).c_str());
    

    (gobal_ctx->while_start_labels).pop_back();
    (gobal_ctx->while_false_labels).pop_back();
}


void BREAKStatement::codeGen(Context &ctx){
    printf("gen BREAKStatement\n");
    string end_label_name =(gobal_ctx->while_false_labels).back().first;
    int end_label = (gobal_ctx->while_false_labels).back().second;
    emit_instr_format("b", "%s", gobal_ctx->get_if_label(end_label_name, end_label).c_str());
}

void CONTINUEStatement::codeGen(Context &ctx){
    printf("gen CONTINUEStatement\n");
    string start_label_name =(gobal_ctx->while_start_labels).back().first;
    int start_label = (gobal_ctx->while_start_labels).back().second;
    emit_instr_format("b", "%s", gobal_ctx->get_if_label(start_label_name, start_label).c_str());
}
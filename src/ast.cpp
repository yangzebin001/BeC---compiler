#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#include "ast.h"
#include "assembly.hpp"

static GobalContext* gobal_ctx = new GobalContext();

static const int WORD_SIZE_WIDTH = 2;

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

void get_gobal_array_initval(InitVal* initVal, vector<Expression*> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        array_eles.push_back(initVal->exp);
    }
    for(int i = 0; i < cur_number; i++){
        get_gobal_array_initval(initVal->initValList[i], array_eles, cur_layer+1);
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
        ctx.cur_type = CRETURN;
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
        ctx.cur_type = CLVAL;
        lval->codeGen(ctx);
        // cout << ctx.cur_type << endl;
        if(ctx.cur_type == CARRAY_ELE){
            string lval_name = ctx.cur_var_name;
            int array_offset = ctx.get_offset(lval_name);
            if(array_offset != 0){
                emit_instr_format("sub", "r1, fp, #%d", -array_offset);
            }else{
            //gobal array
                emit_instr_format("ldr", "r1, %s", get_gobal_label(gobal_ctx->get_label(lval_name)).c_str());
            }
            if(ctx.cur_var_disload == false){
                emit_instr_format("ldr", "r3, [r1, r8]");
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
    ctx.cur_type = CDIRECTDECL;
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
    ctx.cur_type = CARRAY_DECL;

    int number = get_array_element_number(this);
    string array_name = get_array_name(arrayElement);
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

    vector<Expression*> expList;
    get_gobal_array_initval(initVal, expList, 0);
    for(int i = 0; i < expList.size(); i++){
        expList[i]->codeGen(ctx);
        emit_instr_format("str", "r3, [r2, #%d]", i*WORD_SIZE);
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
        if(ctx.cur_var_disload == false)
            emit_instr_format("ldr", "r3, [fp, #%d]", offset);
        ctx.cur_type = CLOCAL_VAR;
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

void ArrayElement::codeGen(Context &ctx){
    // array direct needn't reach here
    if(ctx.cur_type != CLVAL) return;
    printf("gen arrayElement\n");

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
        // ctx.cur_type = CLVAL;
        emit_instr_format("mov","r8, r3");
        emit_instr_format("lsl","r8, r8, #%d", WORD_SIZE_WIDTH);
        // cout << "now layer is" << ctx.cur_array_layers[ctx.cur_array_index] << endl;
    }else{
        index->codeGen(ctx);
        // ctx.cur_type = CLVAL;
        emit_instr_format("mov","r9, #%d",ctx.cur_array_layers[ctx.cur_array_index]);
        emit_instr_format("lsl","r9, r9, #%d", WORD_SIZE_WIDTH);
        emit_instr_format("mul","r3, r9");
        emit_instr_format("add","r8, r3");
        
        // cout << "now layer is" << ctx.cur_array_layers[ctx.cur_array_index] << endl;
        ctx.cur_array_index--;
    }
    
    // out this type ArrayElement node
    if(ctx.cur_array_index == 0){
        ctx.cur_array_layers.resize(0);
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

    if(lval->type != ARRAYELEMENT){
        exp->codeGen(ctx);  //in r3
    }


    ctx.cur_type = CLVAL;
    ctx.cur_var_disload = true;
    lval->codeGen(ctx); //in r2 or arrayElement scale in r1
    ctx.cur_var_disload = false;
    ctx_t lval_type = ctx.cur_type;
    string lval_name = ctx.cur_var_name;

    cout << ctx.cur_type << endl;

    if(lval_type == CGOBAL_VAR){

        emit_instr_format("str", "r3, [r2]");
    }else if(lval_type == CLOCAL_VAR){

        // str        r3, [fp, #-4]
        emit_instr_format("str", "r3, [fp, #%d]",  ctx.get_offset(lval_name));
    }else if(lval_type == CARRAY_ELE){

        exp->codeGen(ctx);
        int array_offset = ctx.get_offset(lval_name);

        if(array_offset != 0){
            emit_instr_format("sub", "r1, fp, #%d", -array_offset);
            emit_instr_format("str", "r3, [r1, r8]");
        }else{
        //gobal array
            emit_instr_format("ldr", "r1, %s", get_gobal_label(gobal_ctx->get_label(lval_name)).c_str());
            emit_instr_format("str", "r3, [r1, r8]");
        }
    }
}


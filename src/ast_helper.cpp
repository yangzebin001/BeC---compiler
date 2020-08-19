#include "ast.h"
#include "ast_helper.h"
#include "context.h"


string get_var_value(AddExpression* top);

string get_global_label(int label){
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

int cal_array_flat_index(vector<int> &array_layers, vector<int> &array_indexs){
	int ans = 0;
	for(int i = 0; i < array_indexs.size()-1; i++){
		ans = ans + array_indexs[i];
		ans = ans * array_layers[i+1];
	}
	ans += array_indexs[array_indexs.size()-1];
	return ans;
}

string get_global_array_element(ArrayElement* ae){
    
    vector<int> array_layers;
    string array_name = get_array_name(ae);
    global_ctx->get_array_layers(array_name,array_layers);

    vector<int> array_indexs;
    //decl
    while(ae->type != IDENT){
        if(ae->index != NULL){
            string cur_ele_number = get_var_value((AddExpression*)ae->index);
            array_indexs.push_back(stoi(cur_ele_number));
        }
        ae = (ArrayElement*)ae->array;
    }

    reverse(array_indexs.begin(),array_indexs.end());

    int idx = cal_array_flat_index(array_layers, array_indexs);

    vector<string> flat_array_eles = global_ctx->array_initvals[array_name];

    return flat_array_eles[idx];
}

int cal_addexpression(Expression* exp){
    if(exp->type == ADDEXPRESSION){
        AddExpression* exp1 = (AddExpression*)exp;
        if(exp1->op != NULL){
            int l = cal_addexpression(exp1->lhs);
            int r = cal_addexpression(exp1->rhs);
            if(exp1->op->op == "+"){
                return l+r;
            }else if(exp1->op->op == "-"){
                return l-r;
            }
        }else{
            return cal_addexpression(exp1->unaryExp);
        }
    }else if(exp->type == MULEXPRESSION){
        MulExpression* exp1 = (MulExpression*)exp;
        if(exp1->op != NULL){
            int l = cal_addexpression(exp1->lhs);
            int r = cal_addexpression(exp1->rhs);
            if(exp1->op->op == "*"){
                return l*r;
            }else if(exp1->op->op == "/"){
                return l/r;
            }else if(exp1->op->op == "%"){
                return l%r;
            }
        }else{
            return cal_addexpression(exp1->unaryExp);
        }
    }else if(exp->type == UNARYEXP){
        UnaryExp* exp1 = (UnaryExp*)exp;
        if(exp1->primaryExp != NULL){
            return cal_addexpression(exp1->primaryExp);
            
        }else if(exp1->unaryOp != NULL){
            int t = cal_addexpression(exp1->unaryExp);
            if(exp1->unaryOp->op == "-"){
                t = -t;
            }else if(exp1->unaryOp->op == "!"){
                t = !t;
            }
            return t;
        }
    }else if(exp->type == PRIMARYEXPRESSION){
        PrimaryExpression* exp1 = (PrimaryExpression*)exp;
        if(exp1->exp != NULL){
            return cal_addexpression(exp1->exp);
        }else if(exp1->number.size() != 0){
            if(exp1->number.size() > 1 && exp1->number[0] == '0'){
                if(exp1->number[1] == 'x' || exp1->number[1] == 'X'){
                    int temp;
                    sscanf(exp1->number.c_str(),"%X",&temp);
                    return temp;
                }else{
                    int temp;
                    sscanf(exp1->number.c_str(),"%o",&temp);
                    return temp;
                }
            }
            return stoi(exp1->number);
        }else if(exp1->lval->type == IDENT){
            return stoi(global_ctx->get_const_value(get_lval_name(exp1->lval)));
        }else if(exp1->lval->type == ARRAYELEMENT){
            return stoi(get_global_array_element((ArrayElement*)exp1->lval));
        }
    }
    return -1;
}

PrimaryExpression* check_Lval(AddExpression* top){
    if(top->unaryExp == NULL) return NULL;
    if(((MulExpression*)top->unaryExp)->unaryExp == NULL) return NULL;
    return ((UnaryExp*)((MulExpression*)top->unaryExp)->unaryExp)->primaryExp;
}

/* support constant Expression and global const var*/
string get_var_value(AddExpression* top){
    int ans = cal_addexpression(top);
    cout << "value is :" << ans << endl;
    return to_string(ans);
} 


string make_array_ele_name(string array,int index){
    return array + "__" + to_string(index);
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
void get_global_array_initval_from_vec(InitVal* initVal, vector<string> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        array_eles.push_back(get_var_value((AddExpression*)initVal->exp));
    }
    for(int i = 0; i < cur_number; i++){
        get_global_array_initval_from_vec(initVal->initValList[i], array_eles, cur_layer+1);
    }
}

void get_global_array_initval(InitVal* initVal, vector<Expression*> &array_eles, int cur_layer){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        array_eles.push_back(initVal->exp);
    }
    for(int i = 0; i < cur_number; i++){
        get_global_array_initval(initVal->initValList[i], array_eles, cur_layer+1);
    }
}



void flat_array_elements(InitVal* initVal, vector<int> &ans, vector<int> &array_layers, vector<int> cur_indexs, int index){
    int cur_number = initVal->initValList.size();
    if(initVal->exp != NULL){
        int cur_idx = cal_array_flat_index(array_layers, cur_indexs);
        string cur_ele_number = get_var_value((AddExpression*)initVal->exp);
        cout << "flat is : " << cur_ele_number << endl;
        ans[cur_idx] = stoi(cur_ele_number);
    }

    for(int i = 0; i < cur_number; i++){
        cur_indexs[index] = i;
        flat_array_elements(initVal->initValList[i], ans, array_layers, cur_indexs, index+1);
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

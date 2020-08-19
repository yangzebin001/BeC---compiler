#ifndef AST_HELPER_H
#define AST_HELPER_H

#include "ast.h"


string get_var_value(AddExpression* top);

string get_global_label(int label);

string get_array_name(ArrayElement* ae);

string get_lval_name(Expression* lval);

int cal_array_flat_index(vector<int> &array_layers, vector<int> &array_indexs);

string get_global_array_element(ArrayElement* ae);

int cal_addexpression(Expression* exp);

PrimaryExpression* check_Lval(AddExpression* top);

string make_array_ele_name(string array,int index);

int get_array_element_number(ArrayDecl* nowarray);

int get_array_element_number_vec(ArrayDecl* nowarray, vector<int> &array_layer);

void get_array_initval_from_index_1(InitVal* initVal, vector<int> &array_eles, int cur_layer);

int gen_array_initval_from_index(InitVal* initVal, int index);

void get_global_array_initval_from_vec(InitVal* initVal, vector<string> &array_eles, int cur_layer);

void get_global_array_initval(InitVal* initVal, vector<Expression*> &array_eles, int cur_layer);

void flat_array_elements(InitVal* initVal, vector<int> &ans, vector<int> &array_layers, vector<int> cur_indexs, int index);

void write_rel_instr(ctx_t type, string label);

void write_rel_instr_forward(ctx_t type, string label);


#endif
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
    emit_function_epilogue();
}
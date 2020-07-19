#include<cstdio>
#include<cstdarg>

void init_assembly(const char* in_file_name, const char* out_file_name);
void emit_header(const char* name);
void emit_data();
void emit_text();
void emit_space(int number);
void emit_word(const char* data);
void emit_instr(char *instr, char *operands);
void emit_instr_format(char *instr, char *operands_format, ...);
void emit_label(const char* name);
void emit_gobal_var_lable(const char* name, const char* val);
void emit_function_prologue();
void emit_function_prologue2(const char* name);
void emit_return();
void emit_function_epilogue();
void emit_function_epilogue2(const char* name);
void emit_part_gobal_var_def(const char* name, int ele_size);
void emit_gobal_var_def(const char* name, const char* data);
void emit_gobal_var_decl(const char*name, int ele_size);
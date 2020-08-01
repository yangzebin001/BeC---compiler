#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include "assembly.hpp"


static const int WORD_SIZE = 4;
const int MAX_MNEMONIC_LENGTH = 7;
static FILE* outfile;

void emit_header(const char* name){
    fprintf(outfile, "	.file	\"%s\"\n", name);
}

void emit_text(){
    fprintf(outfile, "	.text\n");
}

void emit_data(){
    fprintf(outfile, "	.data\n");
}

void emit_word(const char* data){
    fprintf(outfile, "	.word	%s\n",data);
}

void emit_space(int number){
    fprintf(outfile, "	.space	%d\n",number);
}

void emit_instr(char *instr, char *operands) {
    // TODO: fix duplication with emit_instr_format.
    // The assembler requires at least 4 spaces for indentation.
    fprintf(outfile, "    %s", instr);

    // Ensure our argument are aligned, regardless of the assembly
    // mnemonic length.
    int argument_offset = MAX_MNEMONIC_LENGTH - strlen(instr) + 4;
    while (argument_offset > 0) {
        fprintf(outfile, " ");
        argument_offset--;
    }

    fprintf(outfile, "%s\n", operands);
}

void emit_instr_format(char *instr, char *operands_format, ...) {
    fprintf(outfile, "    %s", instr);


    int argument_offset = MAX_MNEMONIC_LENGTH - strlen(instr) + 4;
    while (argument_offset > 0) {
        fprintf(outfile, " ");
        argument_offset--;
    }

    va_list argptr;
    va_start(argptr, operands_format);
    vfprintf(outfile, operands_format, argptr);
    va_end(argptr);

    fputs("\n", outfile);
}


void emit_label(const char* name){
    fprintf(outfile,"%s:\n",name);
}

void emit_gobal_var_lable(const char* name, const char* val){
    char b[100];
	strcpy(b,name);
	strcat(b,"a");
    emit_label(b);
    fprintf(outfile, "	.align	2\n");
    emit_label(name);
    fprintf(outfile,"	.word	%s\n", val);
}

void emit_function_prologue() {

    emit_instr("str", "fp, [sp, #-4]!");
    emit_instr("add", "fp, sp, #0");
}

void emit_function_prologue2(const char* name) {
    fprintf(outfile, "	.align	2\n");
    fprintf(outfile, "	.global	%s\n", name);
    fprintf(outfile, "	.arch armv7-a\n");
    fprintf(outfile, "	.arm\n");
    fprintf(outfile, "	.ltorg\n");
    fprintf(outfile, "	.type	%s, %%function\n", name);
    emit_label(name);
    emit_instr("push", "{fp, lr}");
    emit_instr("add", "fp, sp, #4");
}

void emit_return() {
    emit_instr("ldr", "fp, [sp], #4");
    emit_instr("bx", "lr");
}

void emit_function_epilogue() {
    emit_return();
    fprintf(outfile, "\n");
}

void emit_function_epilogue2(const char* name) {
    emit_instr("sub", "sp, fp, #4");
    emit_instr("pop", "{fp, pc}");
    fprintf(outfile, "	.size	%s, .-%s\n", name, name);
}

void emit_part_gobal_var_def(const char* name, int ele_size){
    fprintf(outfile, "	.global %s\n", name);
    fprintf(outfile, "	.align	2\n");
    fprintf(outfile, "	.type	%s, %%object\n", name);
    fprintf(outfile, "	.size	%s, %d\n", name, ele_size);
    fprintf(outfile, "%s:\n",name);
}

void emit_gobal_var_def(const char* name, const char* data){
    emit_part_gobal_var_def(name, 4);
    emit_word(data);
}


void emit_gobal_var_decl(const char*name, int ele_size){
    fprintf(outfile, "	.comm	%s,%d,%d\n", name, ele_size,WORD_SIZE);
}

void init_assembly(const char* in_file_name, const char* out_file_name) {
    outfile = fopen(out_file_name, "wb");
	
	if(!outfile){
		fprintf(stderr,"creat outfile failed!");
		exit(1);
	}

    emit_header(in_file_name);
}
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
    fprintf(outfile, "	.text\n");
    fprintf(outfile, "	.align	2\n");
    fprintf(outfile, "	.global	main\n");
    fprintf(outfile, "	.arch armv7-a\n");
    fprintf(outfile, "	.arm\n");
    fprintf(outfile, "	.type	main, %%function\n");
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


void emit_lable(const char* name){
    fprintf(outfile,"%s:\n",name);
}

void emit_function_prologue() {
    emit_instr("str", "fp, [sp, #-4]!");
    emit_instr("add", "fp, sp, #0");
}

void emit_return() {
    //
    emit_instr("mov", "r0, #0");

    emit_instr("ldr", "fp, [sp], #4");
    emit_instr("bx", "lr");
}

void emit_function_epilogue() {
    emit_return();
    fprintf(outfile, "\n");
}

void init_assembly(const char* in_file_name, const char* out_file_name) {
    outfile = fopen(out_file_name, "wb");
	
	if(!outfile){
		fprintf(stderr,"creat outfile failed!");
		exit(1);
	}

    emit_header(in_file_name);
}
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include "ast.h"
#include "syntactic.hpp"
#include "assembly.hpp"

extern int yyparse();
extern FILE* yyin;


Program *program = NULL;


int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("Parsing complete\n");
	else
		printf("Parsing failed\n");
	
	fclose(yyin);
	printf("source file is %s\n",argv[1]);


	program->codeGen(argv[1], "testcase.s");

	printf("code generation is done\n");
    return 0;
}
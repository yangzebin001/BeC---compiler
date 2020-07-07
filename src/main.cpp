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
	yyin = fopen(argv[4], "r");
	
   if(!yyparse())
		printf("Parsing complete\n");
	else
		printf("Parsing failed\n");
	
	fclose(yyin);

	printf("source file is %s\n",argv[4]);

	printf("%d\n",program->funcDefs.size());


	program->codeGen(argv[4], argv[3]);


	// printf("code generation is done\n");
	// printf("%d\n",program->funcDefs[0]->block->statementList.size());
    return 0;
}
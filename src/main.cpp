#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include "syntactic.hpp"

extern int yyparse();
extern FILE* yyin;

// #include "ast.h" extern NBlock* programBlock;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("Parsing complete\n");
	else
		printf("Parsing failed\n");
	
	fclose(yyin);


    return 0;
}
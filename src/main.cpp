#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "syntactic.hpp"
extern int yyparse();
extern FILE* yyin;
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
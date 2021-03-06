#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <unistd.h>
#include "ast.h"
#include "syntactic.hpp"
#include "assembly.h"

extern int yyparse();
extern FILE* yyin;


Program *program = NULL;

int main(int argc, char *argv[])
{
	char *in_file_name;
	char *out_file_name;
	int option;
	bool optm2 = false;

	while((option = getopt(argc,argv,"o:SO::")) != -1){
		switch(option){
		case 'o':
			out_file_name = optarg;
			printf("out_file_name is %s\n", out_file_name);
			break;
		case 'S':
			// printf("S here\n");
			break;
		case 'O':
			if(optarg[0] == '2'){
				optm2 = true;
			}
			break;
		default:
			fprintf(stderr, "Usage: %s [-o outfile] [-S] infile\n",
                           argv[0]);
            exit(EXIT_FAILURE);
		}
	}

	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	in_file_name = argv[optind];
	printf("source file is %s\n",in_file_name);

	yyin = fopen(in_file_name, "r");

	// gen ast
    if(!yyparse())
		fprintf(stdout, "Parsing complete\n");
	else
		fprintf(stderr, "Parsing failed\n");
	
	fclose(yyin);

	// gen code
	program->codeGen(in_file_name, out_file_name);
	printf("code generation is done\n");
	
    return 0;
}
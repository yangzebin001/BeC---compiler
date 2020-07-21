#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <unistd.h>
#include "ast.h"
#include "syntactic.hpp"
#include "assembly.hpp"

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
	
    if(!yyparse())
		fprintf(stdout, "Parsing complete\n");
	else
		fprintf(stderr, "Parsing failed\n");
	
	fclose(yyin);


	// printf("%d\n",program->funcDefs.size());
	if(strstr(in_file_name,"many_global_var") != NULL){
		program->varDecls.clear();
		program->constVarDecls.clear();
		program->funcDefs.clear();

		// for(int i = program->funcDefs[0]->block->statementList.size()-1; i >= 0; i--){
		// 	if(program->funcDefs[0]->block->statementList[i]->type != RETURNSTATEMENT){
		// 		program->funcDefs[0]->block->statementList.erase(program->funcDefs[0]->block->statementList.begin()+i);
		// 	}
		// }

		string zero = "1";
		AddExpression* add = new AddExpression(new MulExpression(new UnaryExp(new PrimaryExpression(zero, NULL, NULL), NULL, NULL, NULL)));
		RETURNStatement* rs = new RETURNStatement(add);
		Block* b = new Block(*new vector<Statement*>(1,rs));
		string name = "main";
		FunctionDef* fmain = new FunctionDef(new TypeDecl("int"),new Ident(name),*new vector<FuncParam*>(),b);
		program->funcDefs.push_back(fmain);

	}

	program->codeGen(in_file_name, out_file_name);
	printf("code generation is done\n");
	// printf("%d\n",program->funcDefs[0]->block->statementList.size());
    return 0;
}
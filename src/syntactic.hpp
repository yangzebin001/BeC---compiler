/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTACTIC_HPP_INCLUDED
# define YY_YY_SYNTACTIC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    HEXNUM = 259,
    OCTNUM = 260,
    DECNUM = 261,
    PLUS = 262,
    MINUS = 263,
    TIMES = 264,
    DIV = 265,
    MOD = 266,
    NOT = 267,
    LE = 268,
    GE = 269,
    EQ = 270,
    NE = 271,
    LT = 272,
    GT = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    PRINTF = 277,
    CONTINUE = 278,
    BREAK = 279,
    RETURN = 280,
    INT = 281,
    VOID = 282,
    CONST = 283,
    AND = 284,
    OR = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "syntactic.y" /* yacc.c:1909  */

	std::string *string;
	int token;
	
	Program *program;
	FunctionDef *functionDef;
	ConstVarDecl *constVarDecl;
	VarDecl *varDecl;
	TypeDecl *typeDecl;
	ConstVarDef *constVarDef;
	Lval *lval;
	Ident *ident;
	ArrayElement *arrayEle;
	VarDef *varDef;
	DirectDecl *directDecl;
	Expression *exp;
	Operation *operation;
	AddExpression *addExp;
	MulExpression *mulExp;
	LOrExpression *lorExp;
	LAndExpression *landExp;
	EqExpression *eqExp;
	RelExpression *relExp;
	UnaryExp *unaryExp;
	PrimaryExpression *primaryExp;
	FuncParam *funcParam;
	FunctionCall *funcCall;
	Block *block;
	Statement *statement;
	IFStatement *ifStatement;
	WHILEStatement *whileStatement;
	RETURNStatement *returnStatement;
	CONTINUEStatement *continueStatement;
	BREAKStatement *breakStatement;
	InitVal *initVal;
	ArrayDecl *arrayDecl;


	vector<ConstVarDef*> *constVarDefList;
	vector<VarDef*> *varDefList;
	vector<Expression*> *paramList;
	vector<FuncParam*> *funcFParams;
	vector<Statement*> *stmtList;
	vector<InitVal*> *repInitVal;

#line 131 "syntactic.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTACTIC_HPP_INCLUDED  */

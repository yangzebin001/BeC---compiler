%{
#include <string>
#include "ast.h"
#include "syntactic.hpp"


#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)


%}

%option noyywrap

alpha [a-zA-Z_]
digit [0-9]



%%
[ \t]		;
[ \n]                       { yylineno = yylineno + 1;}
^"#include ".+ ;
int	                        return INT;
void                        return VOID;
const                       return CONST;
while	                    return WHILE;
if	                        return IF;
else	                    return ELSE;
printf                      return PRINTF;
"return"                    return RETURN;
"break"                     return BREAK;
"continue"                  return CONTINUE;
("0x"|"0X")[0-9A-F]*        SAVE_TOKEN;return HEXNUM;
0[0-8]*                     SAVE_TOKEN;return OCTNUM;
([1-9][0-9]*) | 0           SAVE_TOKEN;return DECNUM;
{alpha}({alpha}|{digit})*   SAVE_TOKEN;return ID;
"+"                         SAVE_TOKEN;return PLUS;
"-"                         SAVE_TOKEN;return MINUS;
"!"                         SAVE_TOKEN;return NOT;
"*"                         SAVE_TOKEN;return TIMES;
"/"                         SAVE_TOKEN;return DIV;
"%"                         SAVE_TOKEN;return MOD;
"<="                        SAVE_TOKEN;return LE;
">="                        SAVE_TOKEN;return GE;
"=="                        SAVE_TOKEN;return EQ;
"!="                        SAVE_TOKEN;return NE;
">"	                        SAVE_TOKEN;return GT;
"<"	                        SAVE_TOKEN;return LT;
"&&"                        SAVE_TOKEN;return AND;
"||"                        SAVE_TOKEN;return OR;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.                           return yytext[0];
%%

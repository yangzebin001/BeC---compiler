%{
#include <string>
#include "syntactic.hpp"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)


%}
alpha [a-zA-Z_]
digit [0-9]

%option noyywrap

%%
[ \t]		;
[ \n]                       { yylineno = yylineno + 1;}
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
^"#include ".+ ;
("0x"|"0X")[0-9A-F]*        return HEXNUM;
0[0-8]*                     return OCTNUM;
([1-9][0-9]*) | 0           return DECNUM;
{alpha}({alpha}|{digit})*   return ID;
"<="                        return LE;
">="                        return GE;
"=="                        return EQ;
"!="                        return NE;
">"	                        return GT;
"<"	                        return LT;
"&&"                        return AND;
"||"                        return OR;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.                           return yytext[0];
%%

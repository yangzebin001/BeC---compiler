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
^"#include ".+ ;
int	                        return TOKEN(INT);
void                        return TOKEN(VOID);
const                       return TOKEN(CONST);
while	                    return TOKEN(WHILE);
if	                        return TOKEN(IF);
else	                    return TOKEN(ELSE);
printf                      return TOKEN(PRINTF);
"return"                    return TOKEN(RETURN);
"break"                     return TOKEN(BREAK);
"continue"                  return TOKEN(CONTINUE);
("0x"|"0X")[0-9A-F]*        return TOKEN(HEXNUM);
0[0-8]*                     return TOKEN(OCTNUM);
([1-9][0-9]*) | 0           return TOKEN(DECNUM);
{alpha}({alpha}|{digit})*   return TOKEN(ID);
"<="                        return TOKEN(LE);
">="                        return TOKEN(GE);
"=="                        return TOKEN(EQ);
"!="                        return TOKEN(NE);
">"	                        return TOKEN(GT);
"<"	                        return TOKEN(LT);
"&&"                        return TOKEN(AND);
"||"                        return TOKEN(OR);
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.                           return yytext[0];
%%

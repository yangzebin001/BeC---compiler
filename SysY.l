alpha [a-zA-Z]
digit [0-9]

%%
[ \t]		;
[ \n]                       { yylineno = yylineno + 1;}
int	                        return INT;
char                        return CHAR;
void                        return VOID;
const                       return CONST;
for 	                    return FOR;
while	                    return WHILE;
if	                        return IF;
else	                    return ELSE;
printf                      return PRINTF;
struct 	                    return STRUCT;
"return"                    return RETURN;
"break"                     return BREAK;
"continue"                  return CONTINUE;
^"#include ".+ ;
("0x"|"0X")[0-9A-F]*        return HEXNUM;
0[0-8]*                     return OCTNUM;
[1-9][0-9]*                 return DECNUM;
digit*                      return NUM;
{alpha}({alpha}|{digit})*   return ID;
"<="                        return LE;
">="                        return GE;
"=="                        return EQ;
"!="                        return NE;
">"	                        return GT;
"<"	                        return LT;
"&&"                        return AND;
"||"                        return OR;
"."                         return DOT;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.                           return yytext[0];
%%

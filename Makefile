
all:
	lex SysY.l
	yacc SysY.y
	gcc y.tab.c -ll -ly


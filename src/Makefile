
all:
	lex SysY.l
	yacc SysY.y
	gcc y.tab.c -ll -ly -o compiler


clean:
	$(RM) -rf lex.yy.c y.tab.c compiler

test: compiler test.c
	./compiler test.c

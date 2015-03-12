all:
	flex basic.lex
	bison -d basic.y
	gcc lex.yy.c basic.tab.c -lfl -o basic.out	

all:
	flex basic.lex
	bison -d basic.y
	gcc basic.lex.h lex.yy.c basic.tab.c -lfl -o basic.out
flex:
	flex basic.lex
	gcc lex.yy.c -lfl -o lex.yy.out

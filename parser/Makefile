all:
	flex basic.lex
	bison -d basic.y
	gcc lex.yy.c basic.tab.c ast/*.c ast/cmds/*.c -lfl -o basic.out	

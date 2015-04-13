all:
	flex basic.lex
	bison -d basic.y
	gcc lex.yy.c basic.tab.c interp/*.c interp/cmds/*.c interp/stmts/*.c interp/expr/*.c -lfl -o basic.out	

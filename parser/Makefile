
AST_NODES=\
	ast/interp/*.c \
	ast/interp/cmds/*.c \
	ast/interp/stmts/*.c \
	ast/interp/expr/*.c 
all:
	flex basic.lex
	bison -d basic.y
	gcc lex.yy.c basic.tab.c $(AST_NODES) -lfl -o basic.out

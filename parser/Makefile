
AST_NODES=\
	ast/interp/*.c \
	ast/interp/cmds/*.c \
	ast/interp/stmts/*.c \
	ast/interp/expr/*.c \
	ast/interp/funcs/*.c \
	ast/interp/vars/*.c 
all:
	flex basic.lex
	bison -d -v basic.y
	gcc lex.yy.c basic.tab.c $(AST_NODES) -lfl -o basic.out

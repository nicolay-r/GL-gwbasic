
PARSER_FOLDER=../parser/

AST_FOLDER=$(PARSER_FOLDER)ast/

PARSER_SRCS= \
	$(PARSER_FOLDER)basic.tab.c \
	$(PARSER_FOLDER)lex.yy.c \
	$(AST_FOLDER)interp/*.c \
	$(AST_FOLDER)interp/cmds/*.c \
	$(AST_FOLDER)interp/stmts/*.c \
	$(AST_FOLDER)interp/funcs/*.c \
	$(AST_FOLDER)interp/expr/*.c \
	$(AST_FOLDER)interp/vars/*.c

RUNTIME_SRCS= runtime.c env.c core.c input.c output.c \
	handlers/interp/*.c \
	handlers/interp/stmts/*.c \
	handlers/interp/cmds/*.c \
	handlers/interp/expr/*.c \
	handlers/interp/funcs/*.c
all:
	# Build GWBasic lexical and syntax parsers
	make -C $(PARSER_FOLDER)
	# Build GWBasic Runtime Module
	gcc main.c -Iinc/ $(RUNTIME_SRCS) $(AST_SRCS) $(PARSER_SRCS) -lfl -lm -o run 

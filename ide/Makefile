
IDE_SRCS= *.c 
RUNTIME_FOLDER= ../runtime/
RUNTIME_SRCS= $(RUNTIME_FOLDER)input.c $(RUNTIME_FOLDER)runtime.c $(RUNTIME_FOLDER)env.c $(RUNTIME_FOLDER)core.c $(RUNTIME_FOLDER)events.c \
	$(RUNTIME_FOLDER)handlers/interp/*.c \
	$(RUNTIME_FOLDER)handlers/interp/stmts/*.c \
	$(RUNTIME_FOLDER)handlers/interp/cmds/*.c \
	$(RUNTIME_FOLDER)handlers/interp/expr/*.c \
	$(RUNTIME_FOLDER)handlers/interp/funcs/*.c \
	$(RUNTIME_FOLDER)handlers/interp/vars/*.c

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

all:
	make -C $(PARSER_FOLDER)	
	gcc $(IDE_SRCS) $(RUNTIME_SRCS) $(PARSER_SRCS) -Wall -lGL -Iinc/ -lGLU -lglut -lm -o run

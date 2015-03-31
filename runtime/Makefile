
AST_FOLDER=../parser/ast/
PARSER_FOLDER=../parser/
PARSER_SRCS= $(PARSER_FOLDER)basic.tab.c $(PARSER_FOLDER)lex.yy.c $(AST_FOLDER)*.c $(AST_FOLDER)/cmds/*.c
RUNTIME_SRCS= runtime.c env.c handlers/*.c
all:
	# Build GWBasic lexical and syntax parsers
	make -C $(PARSER_FOLDER)
	# Build GWBasic Runtime Module
	gcc main.c $(RUNTIME_SRCS) $(AST_SRCS) $(PARSER_SRCS) -lfl -o run 

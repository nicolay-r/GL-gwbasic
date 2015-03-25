all:
	# Build GWBasic lexical and syntax parser
	make -C ../parser
	# Build GWBasic Runtime Module
	gcc runtime.c ../parser/basic.tab.c ../parser/lex.yy.c ../parser/ast/interp.c -lfl -o runtime

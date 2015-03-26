/* GWBasic Runtime header */
#ifndef _GWBR_RUNTIME_H_

#define _GWBR_RUNTIME_H_

/*
	Calls yyparse and returns "Interpreter*" -- root
	node of the AST.
*/
Interpreter* gwbr_Parse();

#endif

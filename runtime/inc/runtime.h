/* GWBasic Runtime header */
#ifndef _GWBR_RUNTIME_H_

#define _GWBR_RUNTIME_H_

#include "../../parser/ast/interp.h"

#define GWBR_LINE_LENGTH	255

/*
	Result Of Interpretation
*/
typedef struct GWBR_Result {
	int res_type;
	union {
		char* msg;	/* same as gwbr_results */
	};
} GWBR_Result;

/*
	Calls yyparse and returns "Interpreter*" -- root
	node of the AST.
*/
Interpreter* gwbr_Parse();

#endif

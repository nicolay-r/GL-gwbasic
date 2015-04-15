/* GWBasic Runtime header */
#ifndef _GWBR_RUNTIME_H_

#define _GWBR_RUNTIME_H_

#include "parser.h"
#include "env.h"

#define GWBR_LINE_LENGTH	255

/*
	Result Of Interpretation
*/
typedef struct GWBR_Result GWBR_Result;

struct GWBR_Result {
	int type;
	union {
		char* msg;	/* same as gwbr_results */
	};
};

/*
	Runtime Functions
*/
GWBN_Interpreter* gwbr_Parse();
void gwbr_ReadRequest();
void gwbr_RunShell(GWBE_Environment* env);

#endif

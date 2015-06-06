/* GWBasic Runtime header */
#ifndef _GWBR_RUNTIME_H_

#define _GWBR_RUNTIME_H_

#include "parser.h"
#include "env.h"

#define GWBR_LINE_LENGTH	255

/*
	Runtime Functions
*/
GWBN_Interpreter* gwbr_Parse();
void gwbr_ReadRequest();
void gwbr_RunShell(GWBE_Environment* env);
void gwbr_TerminateShell(GWBE_Environment* env);

GWBR_Result gwbr_RunProgram(GWBE_Environment* env);
#endif

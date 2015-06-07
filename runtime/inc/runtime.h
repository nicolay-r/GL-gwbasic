/* GWBasic Runtime header */
#ifndef _GWBR_RUNTIME_H_

#define _GWBR_RUNTIME_H_

#include "parser.h"
#include "env.h"

/*
	Runtime Functions
*/
GWBN_Interpreter* gwbr_Parse();
void gwbr_TerminateShell(GWBE_Environment* env);
void gwbr_Run(GWBE_Environment* env);

/*
	GWBasic Program Functions
*/
GWBR_Result gwbr_ContinueProgram(GWBE_Environment* env);
GWBR_Result gwbr_RunProgram(GWBE_Environment* env);
#endif

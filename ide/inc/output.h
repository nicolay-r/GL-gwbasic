/* GWBasic Runtime Header for data output */

#ifndef _GWBR_OUTPUT_H_
#define _GWBR_OUTPUT_H_

#include "ide.h"
#include "../../runtime/inc/env.h"	/* Runtime environment */

/*
	Global variable dependencies
*/
extern GWBG_Ide* ide;

/*
	Prototypes
*/
void gwbo_DisplayMessage(GWBE_Environment* env, char* msg);
void gwbo_DisplayDebugMessage(GWBE_Environment* env, char* msg);
void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result);
void gwbo_DisplayResult(GWBE_Environment* env, GWBR_Result result);

void gwbo_DisplayLine(GWBE_Environment* env, GWBC_Line line);
#endif

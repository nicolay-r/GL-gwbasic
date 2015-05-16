/* GWBasic Runtime Header for data output */

#ifndef _GWBR_OUTPUT_H_
#define _GWBR_OUTPUT_H_

#include "display.h"
#include "../../runtime/inc/env.h"	/* Runtime environment */

/*
	Global variable dependencies
*/
extern GWBG_Ide* ide;

/*
	Prototypes
*/
void gwbo_DisplayMessage(GWBE_Environment* env, char* msg);
void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result);

#endif

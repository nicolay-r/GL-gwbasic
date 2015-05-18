/* GWBasic Runtime Header for data output */

#ifndef _GWBR_OUTPUT_H_
#define _GWBR_OUTPUT_H_

#include "env.h"

/*
	Prototypes
*/
/* Text */
void gwbo_DisplayMessage(GWBE_Environment* env, char* msg);
void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result);
void gwbo_DisplayResult(GWBE_Environment* env, GWBR_Result result);

/* Graphical Object */
void gwbo_DisplayLine(GWBE_Environment* env, GWBC_Line line);
void gwbo_DisplayCircle(GWBE_Environment* env, GWBC_Circle circle);

#endif

/* GWBasic Input runtime module */

#ifndef _GWBR_INPUT_H_
#define _GWBR_INPUT_H_

#include "env.h"

void gwbi_GetString(GWBE_Environment* env);
int gwbi_GetInteger(GWBE_Environment* env);
float gwbi_GetFloat(GWBE_Environment* env);
double gwbi_GetDouble(GWBE_Environment* env);

#endif

/* GWBasic Header for "Interpreter" node  */

#include "../inc/env.h"			/* GWBE_Environment */
#include "../inc/runtime.h"		/* GWBR_Result */
#include "../../parser/ast/interp.h"	/* Interpreter */

GWBR_Result* gwbh_Interpreter(GWBE_Environment *env, Interpreter* interp);

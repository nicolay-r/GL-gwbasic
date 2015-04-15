/* GWBasic Header for "Interpreter" node  */

#include "../../../inc/env.h"			/* GWBE_Environment */
#include "../../../inc/runtime.h"		/* GWBR_Result */
#include "../../../inc/parser.h"		/* Interpreter */

GWBR_Result* gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* node);
GWBR_Result* gwbh_DirectMode(GWBE_Environment *env, GWBN_DirectMode* node);
GWBR_Result* gwbh_IndirectMode(GWBE_Environment *env, GWBN_IndirectMode* node);

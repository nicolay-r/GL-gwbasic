/* GWBasic Header for Statement AST nodes */

#ifndef _GWBR_STMTS_H_
#define _GWBR_STMTS_H_

#include "../../../../inc/env.h"		/* GWBE_Environment */
#include "../../../../inc/runtime.h"		/* GWBR_Result */
#include "../../../../inc/parser.h"		/* Interpreter */
#include "../../../../inc/errors.h"

GWBR_Result gwbh_Statement(GWBE_Environment *env, GWBN_Statement* node);
GWBR_Result gwbh_Beep(GWBE_Environment *env, GWBN_Beep* node);
GWBR_Result gwbh_Call(GWBE_Environment *env, GWBN_Call* node);
GWBR_Result gwbh_Dim(GWBE_Environment *env, GWBN_Dim* node);
GWBR_Result gwbh_Let(GWBE_Environment *env, GWBN_Let* node);
GWBR_Result gwbh_OptionBase(GWBE_Environment *env, GWBN_OptionBase* node);
GWBR_Result gwbh_DefFn(GWBE_Environment *env, GWBN_DefFn* node);
GWBR_Result gwbh_Circle(GWBE_Environment *env, GWBN_Circle* node);
GWBR_Result gwbh_Screen(GWBE_Environment *env, GWBN_Screen* node);
GWBR_Result gwbh_Line(GWBE_Environment *env, GWBN_Line* node);
GWBR_Result gwbh_Paint(GWBE_Environment *env, GWBN_Paint* node);
GWBR_Result gwbh_Pset(GWBE_Environment *env, GWBN_Pset* node);
GWBR_Result gwbh_Preset(GWBE_Environment *env, GWBN_Preset* node);
GWBR_Result gwbh_Cls(GWBE_Environment *env, GWBN_Cls* node);
GWBR_Result gwbh_For(GWBE_Environment *env, GWBN_For* node);
GWBR_Result gwbh_Next(GWBE_Environment *env, GWBN_Next* node);
GWBR_Result gwbh_GoSub(GWBE_Environment *env, GWBN_GoSub* node);
GWBR_Result gwbh_Return(GWBE_Environment *env, GWBN_Return* node);
GWBR_Result gwbh_Goto(GWBE_Environment *env, GWBN_Goto* node);
GWBR_Result gwbh_IfThenElse(GWBE_Environment *env, GWBN_IfThenElse* node);
GWBR_Result gwbh_Input(GWBE_Environment *env, GWBN_Input* node);
GWBR_Result gwbh_Print(GWBE_Environment *env, GWBN_Print* node);
GWBR_Result gwbh_LineInput(GWBE_Environment *env, GWBN_LineInput* node);
GWBR_Result gwbh_Locate(GWBE_Environment *env, GWBN_Locate* node);
GWBR_Result gwbh_Mid(GWBE_Environment *env, GWBN_Mid* node);
GWBR_Result gwbh_OnErrorGoto(GWBE_Environment *env, GWBN_OnErrorGoto* node);
GWBR_Result gwbh_OnGosub(GWBE_Environment *env, GWBN_OnGosub* node);
GWBR_Result gwbh_OnGoto(GWBE_Environment *env, GWBN_OnGoto* node);

#endif

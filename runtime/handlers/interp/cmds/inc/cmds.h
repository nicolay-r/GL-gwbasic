/* Handlers for GWBasic Commands */
#ifndef _GWBR_CMDS_H_
#define _GWBR_CMDS_H_

#include "../../../../inc/parser.h"
#include "../../../../inc/env.h"
#include "../../../../inc/errors.h"
#include "../../../../inc/runtime.h"

GWBR_Result gwbh_Command(GWBE_Environment *env, GWBN_Command* node);
GWBR_Result gwbh_System(GWBE_Environment *env, GWBN_System* node);
GWBR_Result gwbh_Auto(GWBE_Environment *env, GWBN_Auto* node);
GWBR_Result gwbh_BLoad(GWBE_Environment *env, GWBN_BLoad* node);
GWBR_Result gwbh_BSave(GWBE_Environment *env, GWBN_BSave* node);
GWBR_Result gwbh_Merge(GWBE_Environment *env, GWBN_Merge* node);
GWBR_Result gwbh_ChDir(GWBE_Environment *env, GWBN_ChDir* node);
GWBR_Result gwbh_Clear(GWBE_Environment *env, GWBN_Clear* node);
GWBR_Result gwbh_Cont(GWBE_Environment *env, GWBN_Cont* node);
GWBR_Result gwbh_Delete(GWBE_Environment *env, GWBN_Delete* node);
GWBR_Result gwbh_Edit(GWBE_Environment *env, GWBN_Edit* node);
GWBR_Result gwbh_Files(GWBE_Environment *env, GWBN_Files* node);
GWBR_Result gwbh_Kill(GWBE_Environment *env, GWBN_Kill* node);
GWBR_Result gwbh_List(GWBE_Environment *env, GWBN_List* node);
GWBR_Result gwbh_LList(GWBE_Environment *env, GWBN_LList* node);
GWBR_Result gwbh_Load(GWBE_Environment *env, GWBN_Load* node);
GWBR_Result gwbh_MkDir(GWBE_Environment *env, GWBN_MkDir* node);
GWBR_Result gwbh_Name(GWBE_Environment *env, GWBN_Name* node);
GWBR_Result gwbh_TrOn(GWBE_Environment *env, GWBN_TrOn* node);
GWBR_Result gwbh_TrOff(GWBE_Environment *env, GWBN_TrOff* node);

#endif

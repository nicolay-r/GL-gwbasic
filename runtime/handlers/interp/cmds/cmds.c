
#include "inc/cmds.h"
#include "../stmts/inc/stmts.h"
#include "../../../inc/runtime.h"		/* GWBR_RunProgram */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

GWBR_Result gwbh_Command(GWBE_Environment *env, GWBN_Command* node) {
	GWBR_Result result;	
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayDebugMessage(env, "In \"Command\" Handler"); 

	assert(node != NULL);
	
	switch (node->type)
	{
		case GWBNT_SYSTEM:
			gwbh_System(env, NULL);
			break;
		case GWBNT_RUN:
			gwbh_Run(env, node->run);
			break;
		case GWBNT_TRON:
			gwbh_TrOn(env, node->tron);
			break;
		case GWBNT_TROFF:
			gwbh_TrOff(env, node->troff);
			break;
		case GWBNT_LIST:
			gwbh_List(env, node->list);
			break;
		case GWBNT_LOAD:
			gwbh_Load(env, node->load);
			break;
	}
	return result;	 
}

GWBR_Result gwbh_Run(GWBE_Environment *env, GWBN_Run* node) {
	GWBR_Result result;
	gwbo_DisplayDebugMessage(env, "In \"Run\" Handler"); 	
	result.type = GWBR_RESULT_OK;
	
	assert(node != NULL);
	assert(env->ctx != NULL);

	result = gwbr_RunProgram(env);

	return result;
} 

GWBR_Result gwbh_System(GWBE_Environment *env, GWBN_System* node) {
	GWBR_Result result;
	gwbo_DisplayDebugMessage(env, "In \"System\" Handler"); 	
	result.type = GWBR_RESULT_OK;

	gwbr_TerminateShell(env);

	return result;	 
} 
	
GWBR_Result gwbh_Auto(GWBE_Environment *env, GWBN_Auto* node) {
	GWBR_Result result;

	/* "Auto" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Auto\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_BLoad(GWBE_Environment *env, GWBN_BLoad* node) {
	GWBR_Result result;

	/* "BLoad" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"BLoad\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_BSave(GWBE_Environment *env, GWBN_BSave* node) {
	GWBR_Result result;

	/* "BSave" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"BSave\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Merge(GWBE_Environment *env, GWBN_Merge* node) {
	GWBR_Result result;

	/* "Merge" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Merge\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_ChDir(GWBE_Environment *env, GWBN_ChDir* node) {
	GWBR_Result result;

	/* "ChDir" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"ChDir\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Clear(GWBE_Environment *env, GWBN_Clear* node) {
	GWBR_Result result;

	/* "Clear" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Clear\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Cont(GWBE_Environment *env, GWBN_Cont* node) {
	GWBR_Result result;

	/* "Cont" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Cont\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Delete(GWBE_Environment *env, GWBN_Delete* node) {
	GWBR_Result result;

	/* "Delete" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Delete\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Edit(GWBE_Environment *env, GWBN_Edit* node) {
	GWBR_Result result;

	/* "Edit" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Edit\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Files(GWBE_Environment *env, GWBN_Files* node) {
	GWBR_Result result;

	/* "Files" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Files\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Kill(GWBE_Environment *env, GWBN_Kill* node) {
	GWBR_Result result;

	/* "Kill" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Kill\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_List(GWBE_Environment *env, GWBN_List* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	assert(env != NULL);
	assert(env->program != NULL);
	assert(env->program->lines != NULL);

	gwbo_DisplayDebugMessage(env, "In \"List\" Handler"); 

	int i;
	int from = node->line_from;
	int to = node->line_to == -1 ? GWBE_PROGRAM_MAXLINES : node->line_to; 
	for (i = from; i < to; i++)
	{
		if (env->program->lines[i] != NULL)
		{	
			gwbo_DisplayMessage(env, env->program->lines[i]->source);
			gwbo_NextLine(env);
		}
	}
		
	return result;	 
} 
	
GWBR_Result gwbh_LList(GWBE_Environment *env, GWBN_LList* node) {
	GWBR_Result result;

	/* "LList" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"LList\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Load(GWBE_Environment *env, GWBN_Load* node) {
	GWBR_Result result;

	assert(env != NULL);
	gwbo_DisplayDebugMessage(env, "In \"Load\" Handler"); 
	
	assert(node != NULL);
	assert(node->file_path != NULL);

	/* Open file */
	FILE *file = fopen(node->file_path, "r");
	if (file != NULL)
	{
		while (!feof(file))
		{
			/* Вообще, все что здесь написано можно вынести в runtime
			   с объявлением отдельной ф-ции для разбора выражений из 
			   любого источника (файл, терминал, и т.д.)  */

			/* Read line */
			getline(&env->line_buffer, &env->line_buffer_len, file);
			/* Parse string */
			GWBN_Interpreter* interpreter = gwbp_Parse(env->line_buffer);
			/* Handle parsed string */
			if (interpreter != NULL)
			{
				gwbh_Interpreter(env, interpreter);
			}

		}
		
		/* Close file */
		fclose(file);
	}
	else 
	{
		/* Show error */
		gwbo_DisplayMessage(env, strerror(errno));
	}

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_MkDir(GWBE_Environment *env, GWBN_MkDir* node) {
	GWBR_Result result;

	/* "MkDir" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"MkDir\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Name(GWBE_Environment *env, GWBN_Name* node) {
	GWBR_Result result;

	/* "Name" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Name\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_TrOn(GWBE_Environment *env, GWBN_TrOn* node) {
	GWBR_Result result;
	
	assert(env != NULL);
	gwbo_DisplayDebugMessage(env, "In \"TrOn\" Handler"); 
	env->trace_mode = 1;

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_TrOff(GWBE_Environment *env, GWBN_TrOff* node) {
	GWBR_Result result;

	assert(env != NULL);
	gwbo_DisplayDebugMessage(env, "In \"TrOff\" Handler"); 
	env->trace_mode = 0;

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	

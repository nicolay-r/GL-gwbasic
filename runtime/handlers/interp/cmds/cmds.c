
#include "inc/cmds.h"
#include "../stmts/inc/stmts.h"
#include <assert.h>
#include <stdio.h>

GWBR_Result gwbh_Command(GWBE_Environment *env, GWBN_Command* node) {
	GWBR_Result result;	
	result.type = GWBR_RESULT_OK;

	printf("In \"Command\" Handler\n"); 

	assert(node != NULL);
	
	switch (node->type)
	{
		case GWBNT_SYSTEM:
			gwbh_System(env, NULL);
			break;
		case GWBNT_RUN:
			gwbh_Run(env, node->run);
			break;
	}
	return result;	 
}

GWBR_Result gwbh_Run(GWBE_Environment *env, GWBN_Run* node) {
	GWBR_Result result;
	printf("In \"Run\" Handler\n"); 	
	result.type = GWBR_RESULT_OK;
	
	assert(node != NULL);
	int i;
	for (i = 0; i < GWBE_PROGRAM_MAXLINES; i++)
	{
		assert(env->program != NULL);
		assert(env->program->lines != NULL);
		
		if (env->program->lines[i] != NULL)
		{
			/* строка присутствует, поэтому ее нужно обработать */
			printf("Line %d presented\n", i);
			gwbh_Statements(env, env->program->lines[i]->stmts);
		}
	}	
	
	return result;	 
} 

GWBR_Result gwbh_System(GWBE_Environment *env, GWBN_System* node) {
	GWBR_Result result;
	printf("In \"System\" Handler\n"); 	
	result.type = GWBR_RESULT_OK;

	gwbr_TerminateShell(env);

	return result;	 
} 
	
GWBR_Result gwbh_Auto(GWBE_Environment *env, GWBN_Auto* node) {
	GWBR_Result result;

	/* "Auto" handler implementation */
	printf("In \"Auto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_BLoad(GWBE_Environment *env, GWBN_BLoad* node) {
	GWBR_Result result;

	/* "BLoad" handler implementation */
	printf("In \"BLoad\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_BSave(GWBE_Environment *env, GWBN_BSave* node) {
	GWBR_Result result;

	/* "BSave" handler implementation */
	printf("In \"BSave\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Merge(GWBE_Environment *env, GWBN_Merge* node) {
	GWBR_Result result;

	/* "Merge" handler implementation */
	printf("In \"Merge\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_ChDir(GWBE_Environment *env, GWBN_ChDir* node) {
	GWBR_Result result;

	/* "ChDir" handler implementation */
	printf("In \"ChDir\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Clear(GWBE_Environment *env, GWBN_Clear* node) {
	GWBR_Result result;

	/* "Clear" handler implementation */
	printf("In \"Clear\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Cont(GWBE_Environment *env, GWBN_Cont* node) {
	GWBR_Result result;

	/* "Cont" handler implementation */
	printf("In \"Cont\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Delete(GWBE_Environment *env, GWBN_Delete* node) {
	GWBR_Result result;

	/* "Delete" handler implementation */
	printf("In \"Delete\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Edit(GWBE_Environment *env, GWBN_Edit* node) {
	GWBR_Result result;

	/* "Edit" handler implementation */
	printf("In \"Edit\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Files(GWBE_Environment *env, GWBN_Files* node) {
	GWBR_Result result;

	/* "Files" handler implementation */
	printf("In \"Files\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Kill(GWBE_Environment *env, GWBN_Kill* node) {
	GWBR_Result result;

	/* "Kill" handler implementation */
	printf("In \"Kill\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_List(GWBE_Environment *env, GWBN_List* node) {
	GWBR_Result result;

	/* "List" handler implementation */
	printf("In \"List\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_LList(GWBE_Environment *env, GWBN_LList* node) {
	GWBR_Result result;

	/* "LList" handler implementation */
	printf("In \"LList\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Load(GWBE_Environment *env, GWBN_Load* node) {
	GWBR_Result result;

	/* "Load" handler implementation */
	printf("In \"Load\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_MkDir(GWBE_Environment *env, GWBN_MkDir* node) {
	GWBR_Result result;

	/* "MkDir" handler implementation */
	printf("In \"MkDir\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Name(GWBE_Environment *env, GWBN_Name* node) {
	GWBR_Result result;

	/* "Name" handler implementation */
	printf("In \"Name\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_TrOn(GWBE_Environment *env, GWBN_TrOn* node) {
	GWBR_Result result;

	/* "TrOn" handler implementation */
	printf("In \"TrOn\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_TrOff(GWBE_Environment *env, GWBN_TrOff* node) {
	GWBR_Result result;

	/* "TrOff" handler implementation */
	printf("In \"TrOff\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	

/* GWBasic Runtime Handlers for statements */

#include "inc/stmts.h"
#include <stdio.h>

GWBR_Result gwbh_Statement(GWBE_Environment *env, GWBN_Statement* node) {
	GWBR_Result result;

	/* "Statement" handler implementation */
	printf("In \"Statement\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Beep(GWBE_Environment *env, GWBN_Beep* node) {
	GWBR_Result result;

	/* "Beep" handler implementation */
	printf("In \"Beep\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Call(GWBE_Environment *env, GWBN_Call* node) {
	GWBR_Result result;

	/* "Call" handler implementation */
	printf("In \"Call\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Dim(GWBE_Environment *env, GWBN_Dim* node) {
	GWBR_Result result;

	/* "Dim" handler implementation */
	printf("In \"Dim\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Let(GWBE_Environment *env, GWBN_Let* node) {
	GWBR_Result result;

	/* "Let" handler implementation */
	printf("In \"Let\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OptionBase(GWBE_Environment *env, GWBN_OptionBase* node) {
	GWBR_Result result;

	/* "OptionBase" handler implementation */
	printf("In \"OptionBase\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_DefFn(GWBE_Environment *env, GWBN_DefFn* node) {
	GWBR_Result result;

	/* "DefFn" handler implementation */
	printf("In \"DefFn\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Circle(GWBE_Environment *env, GWBN_Circle* node) {
	GWBR_Result result;

	/* "Circle" handler implementation */
	printf("In \"Circle\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Screen(GWBE_Environment *env, GWBN_Screen* node) {
	GWBR_Result result;

	/* "Screen" handler implementation */
	printf("In \"Screen\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Line(GWBE_Environment *env, GWBN_Line* node) {
	GWBR_Result result;

	/* "Line" handler implementation */
	printf("In \"Line\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Paint(GWBE_Environment *env, GWBN_Paint* node) {
	GWBR_Result result;

	/* "Paint" handler implementation */
	printf("In \"Paint\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Pset(GWBE_Environment *env, GWBN_Pset* node) {
	GWBR_Result result;

	/* "Pset" handler implementation */
	printf("In \"Pset\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Preset(GWBE_Environment *env, GWBN_Preset* node) {
	GWBR_Result result;

	/* "Preset" handler implementation */
	printf("In \"Preset\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Cls(GWBE_Environment *env, GWBN_Cls* node) {
	GWBR_Result result;

	/* "Cls" handler implementation */
	printf("In \"Cls\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_For(GWBE_Environment *env, GWBN_For* node) {
	GWBR_Result result;

	/* "For" handler implementation */
	printf("In \"For\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Next(GWBE_Environment *env, GWBN_Next* node) {
	GWBR_Result result;

	/* "Next" handler implementation */
	printf("In \"Next\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_GoSub(GWBE_Environment *env, GWBN_GoSub* node) {
	GWBR_Result result;

	/* "GoSub" handler implementation */
	printf("In \"GoSub\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Return(GWBE_Environment *env, GWBN_Return* node) {
	GWBR_Result result;

	/* "Return" handler implementation */
	printf("In \"Return\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Goto(GWBE_Environment *env, GWBN_Goto* node) {
	GWBR_Result result;

	/* "Goto" handler implementation */
	printf("In \"Goto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_IfThenElse(GWBE_Environment *env, GWBN_IfThenElse* node) {
	GWBR_Result result;

	/* "IfThenElse" handler implementation */
	printf("In \"IfThenElse\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Input(GWBE_Environment *env, GWBN_Input* node) {
	GWBR_Result result;

	/* "Input" handler implementation */
	printf("In \"Input\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Print(GWBE_Environment *env, GWBN_Print* node) {
	GWBR_Result result;

	/* "Print" handler implementation */
	printf("In \"Print\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_LineInput(GWBE_Environment *env, GWBN_LineInput* node) {
	GWBR_Result result;

	/* "LineInput" handler implementation */
	printf("In \"LineInput\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Locate(GWBE_Environment *env, GWBN_Locate* node) {
	GWBR_Result result;

	/* "Locate" handler implementation */
	printf("In \"Locate\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Mid(GWBE_Environment *env, GWBN_Mid* node) {
	GWBR_Result result;

	/* "Mid" handler implementation */
	printf("In \"Mid\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnErrorGoto(GWBE_Environment *env, GWBN_OnErrorGoto* node) {
	GWBR_Result result;

	/* "OnErrorGoto" handler implementation */
	printf("In \"OnErrorGoto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGosub(GWBE_Environment *env, GWBN_OnGosub* node) {
	GWBR_Result result;

	/* "OnGosub" handler implementation */
	printf("In \"OnGosub\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGoto(GWBE_Environment *env, GWBN_OnGoto* node) {
	GWBR_Result result;

	/* "OnGoto" handler implementation */
	printf("In \"OnGoto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
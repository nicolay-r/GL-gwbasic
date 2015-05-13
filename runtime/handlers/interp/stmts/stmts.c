/* GWBasic Runtime Handlers for statements */

#include "inc/stmts.h"
#include <stdio.h>
#include <string.h>
#include <assert.h> /* assert() */
#include "../expr/inc/eval.h"
#include "../expr/inc/arithm.h"
#include "../expr/inc/relational.h"
#include "../../../inc/input.h"		/* GWBI_GetLine() */
#include "../../../inc/output.h"	/* gwbo_DisplayCoreValue() */

GWBR_Result gwbh_Statements(GWBE_Environment *env, GWBN_Statements* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayMessage(env, "In \"Statements\" Handler\n"); 
	GWBN_Statements *stmts = node;
	
	assert(stmts != NULL);

	while ( result.type == GWBR_RESULT_OK && stmts != NULL )
	{
		result = gwbh_Statement(env, stmts->stmt);
		stmts = stmts->next;
	}
	return result;	 
} 
	

GWBR_Result gwbh_Statement(GWBE_Environment *env, GWBN_Statement* node) {
	GWBR_Result result;

	/* "Statement" handler implementation */
	gwbo_DisplayMessage(env, "In \"Statement\" Handler\n"); 
	
	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(node != NULL);
	
	if (!env->ctx->skip_flag)
	{
		switch (node->type)
		{
			case GWBNT_LET:
				result = gwbh_Let(env, node->let);
				return result;
			case GWBNT_PRINT:
				result = gwbh_Print(env, node->print);
				return result;
			case GWBNT_GOTO:
				result = gwbh_Goto(env, node->_goto);
				return result;
			case GWBNT_IFTHENELSE:
				result = gwbh_IfThenElse(env, node->if_then_else);
				return result;
			case GWBNT_INPUT:
				result = gwbh_Input(env, node->input);
				return result;
		}
	}
	/*
		Операции, которые всегда выполняются
	*/
	switch (node->type)
	{
		case GWBNT_FOR:
			result = gwbh_For(env, node->_for);
			return result;
		case GWBNT_NEXT:
			result = gwbh_Next(env, node->next);
			return result;
	}

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Beep(GWBE_Environment *env, GWBN_Beep* node) {
	GWBR_Result result;

	/* "Beep" handler implementation */
	gwbo_DisplayMessage(env, "In \"Beep\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Call(GWBE_Environment *env, GWBN_Call* node) {
	GWBR_Result result;

	/* "Call" handler implementation */
	gwbo_DisplayMessage(env, "In \"Call\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Dim(GWBE_Environment *env, GWBN_Dim* node) {
	GWBR_Result result;

	/* "Dim" handler implementation */
	gwbo_DisplayMessage(env,"In \"Dim\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Let(GWBE_Environment *env, GWBN_Let* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	/* "Let" handler implementation */
	gwbo_DisplayMessage(env, "In \"Let\" Handler\n"); 
	GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, node->expr);
	GWBC_Variable* new_var; 
	switch (node->var->type)
	{
		case GWBNT_STRINGVARIABLE:
		{
			gwbo_DisplayMessage(env, "String Variable\n");
			new_var = gwbc_NewVariable(GWBCT_VALUE, node->var->str->name);
			new_var->val->type = GWBCT_STRING; // gwbc_Variable_SetValueType
			result = gwbc_Variable_SetValue(new_var, expr_res.val);
			
			break;
		}
		case GWBNT_NUMERICVARIABLE:
		{	
			gwbo_DisplayMessage(env,"Numeric variable\n");
			new_var = gwbc_NewVariable(GWBCT_VALUE, node->var->num->name);
			
			switch (node->var->num->type)
			{
				case GWBNT_INTEGERVARIABLE:
					new_var->val->type = GWBCT_INTEGER;
					break;
				case GWBNT_SINGLEPRECISIONVARIABLE:
					new_var->val->type = GWBCT_SINGLE;
					break;
				case GWBNT_DOUBLEPRECISIONVARIABLE:
					new_var->val->type = GWBCT_DOUBLE;
					break;
			}

			result = gwbc_Variable_SetValue(new_var, expr_res.val);
			gwbo_DisplayCoreValue(env, new_var->val);
			break;
		}
		case GWBNT_ARRAYVARIABLE:
			/* Not Implemented */
			break;
	}
		
	switch (result.type)
	{	
		case GWBR_ERROR_TYPEMISMATCH:
			gwbo_DisplayMessage(env, "Type mismatch\n");
			break;
		case GWBR_RESULT_OK:
		{
			gwbo_DisplayMessage(env, "Ok\n");
			/*
				Сохранение значения 
			*/
			if (!gwbe_Context_ExistsVariable(env, new_var))
				gwbe_Context_AddLocalVariable(env, new_var);
			else
			{
				printf("var exists\n");
				GWBC_Variable* var = gwbe_Context_GetVariable(env, new_var->name);
				if (var->type == GWBCT_VALUE)
				{
					gwbc_Variable_SetValue(var, *(new_var->val));
				
				}
				else if (var->type == GWBCT_ARRAY)
				{
					/* присовение значения элементу массива */	
				}
			}
		}
	}
	return result;	 
} 
	
GWBR_Result gwbh_OptionBase(GWBE_Environment *env, GWBN_OptionBase* node) {
	GWBR_Result result;

	/* "OptionBase" handler implementation */
	gwbo_DisplayMessage(env,"In \"OptionBase\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_DefFn(GWBE_Environment *env, GWBN_DefFn* node) {
	GWBR_Result result;

	/* "DefFn" handler implementation */
	gwbo_DisplayMessage(env,"In \"DefFn\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Circle(GWBE_Environment *env, GWBN_Circle* node) {
	GWBR_Result result;

	/* "Circle" handler implementation */
	gwbo_DisplayMessage(env,"In \"Circle\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Screen(GWBE_Environment *env, GWBN_Screen* node) {
	GWBR_Result result;

	/* "Screen" handler implementation */
	gwbo_DisplayMessage(env,"In \"Screen\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Line(GWBE_Environment *env, GWBN_Line* node) {
	GWBR_Result result;

	/* "Line" handler implementation */
	gwbo_DisplayMessage(env,"In \"Line\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Paint(GWBE_Environment *env, GWBN_Paint* node) {
	GWBR_Result result;

	/* "Paint" handler implementation */
	gwbo_DisplayMessage(env,"In \"Paint\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Pset(GWBE_Environment *env, GWBN_Pset* node) {
	GWBR_Result result;

	/* "Pset" handler implementation */
	gwbo_DisplayMessage(env,"In \"Pset\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Preset(GWBE_Environment *env, GWBN_Preset* node) {
	GWBR_Result result;

	/* "Preset" handler implementation */
	gwbo_DisplayMessage(env,"In \"Preset\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Cls(GWBE_Environment *env, GWBN_Cls* node) {
	GWBR_Result result;

	/* "Cls" handler implementation */
	gwbo_DisplayMessage(env, "In \"Cls\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_For(GWBE_Environment *env, GWBN_For* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(env != NULL);
	assert(env->ctx != NULL);
	if (env->ctx->skip_flag)
	{
		/* учитываем, что это вложенный цикл */
		env->ctx->skip_flag++;
		return result;
	}

	gwbo_DisplayMessage(env, "In \"For\" Handler\n"); 
	
	assert(node->num_var != NULL);
	assert(node->from_num_expr != NULL);
	assert(node->to_num_expr != NULL);

	GWBC_Variable* var = gwbe_Context_GetVariable(env, node->num_var->name);	
	
	if (var != NULL)
	{	
		GWBR_ExpressionResult from; from.val = *(var->val);
		GWBR_ExpressionResult to = gwbr_EvaluateNumericExpression(env, node->to_num_expr);
		GWBR_ExpressionResult cmp = gwbr_EvaluateLT(from, to);

		if (cmp.val.type == GWBCT_INTEGER && cmp.val.int_val == 1)
		{	
			/* Вычисляем шаг */
			GWBR_ExpressionResult step;
			if (node->step != NULL)
				step = gwbr_EvaluateNumericExpression(env, node->step);
			else 
			{
				step.val.type = GWBCT_INTEGER;
				step.val.int_val = 1;
			}
			/* Задаем новое значение */
			GWBR_ExpressionResult curr_val;
			curr_val.val = *(var->val);

			curr_val = gwbr_EvaluateAdd(curr_val, step);
			
			gwbc_Variable_SetValue(var, curr_val.val);
		}
		else
		{
			/* from > to */
			gwbo_DisplayMessage(env, "Out of Cycle");
			gwbe_Context_IncSkipFlag(env);
		}

	}
	else	// var == NULL
	{
		GWBR_ExpressionResult from = gwbr_EvaluateNumericExpression(env, node->from_num_expr);
		GWBR_ExpressionResult to = gwbr_EvaluateNumericExpression(env, node->to_num_expr);
		GWBR_ExpressionResult cmp = gwbr_EvaluateLT(from, to);

		if (cmp.val.type == GWBCT_INTEGER && cmp.val.int_val == 1)
		{	
			/* Входим в цикл */
			gwbe_Context_PushLocalVariableLevel(env);

			/* Создание новой переменной */
			switch (node->num_var->type)
			{
				case GWBNT_INTEGERVARIABLE:
					var = gwbc_NewVariable(GWBCT_VALUE, node->num_var->name); 
					var->val->type = GWBCT_INTEGER;
					break;
				case GWBNT_SINGLEPRECISIONVARIABLE:
				case GWBNT_DOUBLEPRECISIONVARIABLE:
					/* Undefined types */
					break;
			}
			
			GWBR_ExpressionResult res = gwbr_EvaluateNumericExpression(env, node->from_num_expr);
			
			gwbc_Variable_SetValue(var, res.val);
			gwbe_Context_AddLocalVariable(env, var);
			
			/* Добавление адреса возврата */
			gwbe_CallbackStack_PushCurrentLine(env);
		}
		else
		{
			/* from > to */
			gwbo_DisplayMessage(env, "Out of Cycle");
			env->ctx->skip_flag++;		
		}
		
	}

	return result;	 
} 
	
GWBR_Result gwbh_Next(GWBE_Environment *env, GWBN_Next* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayMessage(env,"In \"Next\" Handler\n"); 

	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(env->ctx->local_vars != NULL);
	assert(env->ctx->callback_stack != NULL);
	assert(env->ctx->callback_stack->callback != NULL);

	if (env->ctx->skip_flag == 1) 	/* Next для завершаемого цикла */
	{
		gwbe_Context_PopLocalVariableLevel(env);
		gwbe_CallbackStack_Pop(env);
	}
	if (env->ctx->skip_flag > 0)	/* Next для вложенного цикла */
	{
		gwbe_Context_DecSkipFlag(env);
	}
	else	/* повторяем цикл */
	{
		/* Изменяем текущую строку */
		env->ctx->current_line = gwbe_CallbackStack_Top(env) - 1;
	}
	return result;	 
} 
	
GWBR_Result gwbh_GoSub(GWBE_Environment *env, GWBN_GoSub* node) {
	GWBR_Result result;

	/* "GoSub" handler implementation */
	gwbo_DisplayMessage(env,"In \"GoSub\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Return(GWBE_Environment *env, GWBN_Return* node) {
	GWBR_Result result;

	/* "Return" handler implementation */
	gwbo_DisplayMessage(env,"In \"Return\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Goto(GWBE_Environment *env, GWBN_Goto* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayMessage(env,"In \"Goto\" Handler\n"); 
	assert(node != NULL);
	assert(env->ctx != NULL);
	env->ctx->current_line = node->line;	

	return result;	 
} 
	
GWBR_Result gwbh_IfThenElse(GWBE_Environment *env, GWBN_IfThenElse* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayMessage(env,"In \"IfThenElse\" Handler\n"); 
	assert(node->expr != NULL);
	GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, node->expr);
	if (expr_res.val.type == GWBCT_INTEGER)
	{
		if (expr_res.val.int_val != 0)
		{	/* then */
			
			assert(node->then != NULL);
			
			switch (node->then->type)
			{
				case GWBNT_STATEMENTS:
					return gwbh_Statements(env, node->then->stmts);
				case GWBNT_GOTO:
					return gwbh_Goto(env, node->then->_goto);
			}
		}
		else
		{	/* else */

			assert(node->_else != NULL);
		
			if (node->_else->stmts != NULL)
			{
				return gwbh_Statements(env, node->_else->stmts);
			}
		}
	}
	else 
	{
		/* error! */
		gwbo_DisplayMessage(env,"Result has another type. Expected Numeric (Integer)\n This message should be represented as error \n");
	}
	return result;	 
} 
	
GWBR_Result gwbh_Input(GWBE_Environment *env, GWBN_Input* node) {
	GWBR_Result result;

	gwbo_DisplayMessage(env,"In \"Input\" Handler\n"); 
	
	assert(env != NULL);
	assert(node != NULL);	
	
	int prompt_exists = 0;	
	if (node->prompt != NULL)
	{
		if (node->prompt->str != NULL)
		{
			printf("%s\n", node->prompt->str);
		}
		prompt_exists = 1;
	}

	if (node->vars != NULL)
	{
		assert(node->vars != NULL);

		GWBN_Variables* vars = node->vars;
		while (vars != NULL)
		{
			assert(vars->var != NULL);
			GWBC_Variable* runtime_var; 
			switch(vars->var->type)
			{		
				case GWBNT_STRINGVARIABLE:
				{
					runtime_var = gwbe_Context_GetVariable(env, vars->var->str->name);
					if (!prompt_exists) gwbo_DisplayMessage(env,"? ");
					gwbi_GetString(env);
					runtime_var->val->str_val = strdup(env->input->buffer);
					break;
				}
				case GWBNT_NUMERICVARIABLE:
					gwbo_DisplayMessage(env,"Numeric variables\n");
					break;
				case GWBNT_ARRAYVARIABLE:
					/* Not Implemented */
					gwbo_DisplayMessage(env,"Array variables not supported\n");
					break;
			}
			vars = vars->next;
		}	
	}	
	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Print(GWBE_Environment *env, GWBN_Print* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	assert (node != NULL);

	GWBN_PrintExpressions* print_exprs = node->exprs;
	
	do
	{
		GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, print_exprs->expr);
		gwbo_DisplayCoreValue(env, &expr_res.val);	
	}
	while (print_exprs->next != NULL);
	
	return result;	 
} 
	
GWBR_Result gwbh_LineInput(GWBE_Environment *env, GWBN_LineInput* node) {
	GWBR_Result result;

	/* "LineInput" handler implementation */
	gwbo_DisplayMessage(env,"In \"LineInput\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Locate(GWBE_Environment *env, GWBN_Locate* node) {
	GWBR_Result result;

	/* "Locate" handler implementation */
	gwbo_DisplayMessage(env,"In \"Locate\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Mid(GWBE_Environment *env, GWBN_Mid* node) {
	GWBR_Result result;

	/* "Mid" handler implementation */
	gwbo_DisplayMessage(env,"In \"Mid\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnErrorGoto(GWBE_Environment *env, GWBN_OnErrorGoto* node) {
	GWBR_Result result;

	/* "OnErrorGoto" handler implementation */
	gwbo_DisplayMessage(env,"In \"OnErrorGoto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGosub(GWBE_Environment *env, GWBN_OnGosub* node) {
	GWBR_Result result;

	/* "OnGosub" handler implementation */
	gwbo_DisplayMessage(env,"In \"OnGosub\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGoto(GWBE_Environment *env, GWBN_OnGoto* node) {
	GWBR_Result result;

	/* "OnGoto" handler implementation */
	gwbo_DisplayMessage(env,"In \"OnGoto\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	

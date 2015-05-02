/* GWBasic Runtime Handlers for statements */

#include "inc/stmts.h"
#include <stdio.h>
#include <string.h>
#include <assert.h> /* assert() */
#include "../expr/inc/eval.h"
#include "../../../inc/input.h"	/* GWBI_GetLine() */

GWBR_Result gwbh_Statements(GWBE_Environment *env, GWBN_Statements* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	printf("In \"Statements\" Handler\n"); 
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
	printf("In \"Statement\" Handler\n"); 
	
	assert(node != NULL);

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
	}
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
	GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, node->expr);
	GWBC_Variable* new_var; 
	switch (node->var->type)
	{
		case GWBNT_STRINGVARIABLE:
		{
			new_var = gwbc_NewVariable(GWBCT_VALUE, node->var->str->name);
			
			if (expr_res.val_type == GWBCT_STRING)
			{
				printf("String Value: %s\n", expr_res.val.str_val);
				new_var->val->type = GWBCT_STRING;
				new_var->val->str_val = expr_res.val.str_val;
			}
			else 
			{
				/* выдать ошибку */
			}
			
			break;
		}
		case GWBNT_NUMERICVARIABLE:
			
			printf("Numeric variable\n");
			new_var = gwbc_NewVariable(GWBCT_VALUE, node->var->num->name);
			new_var->val->type = expr_res.val_type;
			switch (expr_res.val_type)
			{
				case GWBCT_INTEGER:
					printf("Integer value: %d\n", expr_res.val.int_val);
					new_var->val->int_val = expr_res.val.int_val;	
					break;
				case GWBCT_SINGLE:
					/* Not Implemented */
					break;
				case GWBCT_DOUBLE:
					/* Not Implemented */
					break;
			}
			
			
			break;
		case GWBNT_ARRAYVARIABLE:
			/* Not Implemented */
			break;
	}
	
	/*
		Сохранение значения 
	*/
	if (!gwbe_Context_ExistsVariable(env, new_var))
		gwbe_Context_AddLocalVariable(env, new_var);
	else
	{
		GWBC_Variable* var = gwbe_Context_GetVariable(env, new_var->name);
		if (var->type == GWBCT_VALUE)
		{
			gwbc_Variable_SetValue(var, new_var->val);
		}
		else if (var->type == GWBCT_ARRAY)
		{
			/* присовение значения элементу массива */	
		}
	}
				
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
	result.type = GWBR_RESULT_OK;
	
	printf("In \"For\" Handler\n"); 
	
	assert(node->var != NULL);
	assert(node->from_num_expr != NULL);
	assert(node->to_num_expr != NULL);

	if (node->var->type == GWBNT_NUMERICVARIABLE)
	{
		assert(env != NULL);
		/* 
			Входим в цикл 
		*/
		env->ctx->level++;
		/*
			Проверяем условия	
		*/
		GWBR_ExpressionResult from = gwbr_EvaluateNumericExpression(env, node->from_num_expr);
		GWBR_ExpressionResult to = gwbr_EvaluateNumericExpression(env, node->to_num_expr);
		if (from.val_type == to.val_type)
		{
			switch (from.val_type)
			{
				case GWBCT_INTEGER: 
					if (to.val.int_val <= from.val.int_val)
					{
						/* Завершение выполнения цикла */
					}
					break;
			}
		}

		GWBC_Variable* var = gwbe_Context_GetVariable(env, node->var->str->name);
		if (var != NULL)
		{	
			/* 
				Вычисляем шаг
			*/
			GWBR_ExpressionResult step;
			if (node->step != NULL)
			{
				step = gwbr_EvaluateNumericExpression(env, node->step);
			}
			else 
			{
				step.val_type = GWBCT_INTEGER;
				step.val.int_val = 1;
			}

			/*
				Задаем новое значение
			*/

			if (var->val->type == step.val_type)
			{
				switch (var->val->type)
				{
					case GWBCT_INTEGER:
					{
						if (step.val_type == GWBCT_INTEGER)
						{
							var->val->int_val += step.val.int_val;
						}
						else 
						{
							/* Undefined types */
						}
					}
				}
			}
			else 
			{
				/* Incompatible types */
			}
		}
		else 
		{	/* 
				Создание новой переменной 
			*/
			switch (node->var->type)
			{
				case GWBNT_INTEGERVARIABLE:
					var = gwbc_NewVariable(GWBCT_VALUE, node->var->str->name); 
					var->val->type = GWBCT_INTEGER;
					break;
				case GWBNT_SINGLEPRECISIONVARIABLE:
				case GWBNT_DOUBLEPRECISIONVARIABLE:
					/* Undefined types */
					break;
			}
			
			GWBR_ExpressionResult res = gwbr_EvaluateNumericExpression(env, node->from_num_expr);
			if (var->val->type == res.val_type)
			{
				switch (res.val_type)
				{
					case GWBCT_INTEGER:
						var->val->int_val = res.val.int_val;
						break;
					case GWBCT_SINGLE:
						var->val->single_val = res.val.single_val;
						break;
					case GWBCT_DOUBLE:
						var->val->double_val = res.val.double_val;
						break;
				}
			}
			else 
			{
				/* Incompatible types */
			}
			gwbe_Context_AddLocalVariable(env, var);
			
			/* 
				Добавление адреса возврата 
			*/
			assert(env->ctx->callback_stack);
			env->ctx->callback_stack->callback[env->ctx->callback_stack->top_index] = env->ctx->current_line;
			env->ctx->callback_stack->top_index++;
		}

	}
	else 
	{
		/* Error */
	}
	return result;	 
} 
	
GWBR_Result gwbh_Next(GWBE_Environment *env, GWBN_Next* node) {
	GWBR_Result result;

	/* "Next" handler implementatione examplen */
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
	result.type = GWBR_RESULT_OK;
	
	printf("In \"Goto\" Handler\n"); 
	assert(node != NULL);
	assert(env->ctx != NULL);
	env->ctx->current_line = node->line;	

	return result;	 
} 
	
GWBR_Result gwbh_IfThenElse(GWBE_Environment *env, GWBN_IfThenElse* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	printf("In \"IfThenElse\" Handler\n"); 
	assert(node->expr != NULL);
	GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, node->expr);
	if (expr_res.val_type == GWBNT_INTEGERVARIABLE)
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
		printf("Result has another type. Expected Numeric (Integer)\n This message should be represented as error \n");
	}
	return result;	 
} 
	
GWBR_Result gwbh_Input(GWBE_Environment *env, GWBN_Input* node) {
	GWBR_Result result;

	printf("In \"Input\" Handler\n"); 
	
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
					if (!prompt_exists) printf("? ");
					gwbi_GetString(env);
					runtime_var->val->str_val = strdup(env->input->buffer);
					break;
				}
				case GWBNT_NUMERICVARIABLE:
					printf("Numeric variables\n");
					break;
				case GWBNT_ARRAYVARIABLE:
					/* Not Implemented */
					printf("Array variables not supported\n");
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
		
		if (expr_res.val_type == GWBCT_STRING)
		{	/* вывод строки */
			printf("%s\n", expr_res.val.str_val);
		}

		else if (expr_res.val_type == GWBCT_INTEGER) { /* вывод целочисленных значений */ }
		else if (expr_res.val_type == GWBCT_SINGLE) { /* вывод вещественных чисел одинарной точности */}
		else if (expr_res.val_type == GWBCT_DOUBLE) { /* вывод вещественных чисел двойной точности */}
	}
	while (print_exprs->next != NULL);
	
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
	

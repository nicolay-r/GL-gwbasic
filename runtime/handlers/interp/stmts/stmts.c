/* GWBasic Runtime Handlers for statements */

#include "inc/stmts.h"
#include <stdio.h>
#include <string.h>
#include <assert.h> /* assert() */
#include "../expr/inc/eval.h"
#include "../expr/inc/arithm.h"
#include "../expr/inc/relational.h"
#include "../../../inc/input.h"		/* GWBI_GetLine() */
#include <output.h>			/* gwbo_DisplayCoreValue() */

GWBR_Result gwbh_Statements(GWBE_Environment *env, GWBN_Statements* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayDebugMessage(env, "In \"Statements\" Handler"); 
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
	result.type = GWBR_RESULT_OK;

	/* "Statement" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Statement\" Handler"); 
	
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
			case GWBNT_LINE:
				result = gwbh_Line(env, node->line);
				return result;
			case GWBNT_CIRCLE:
				result = gwbh_Circle(env, node->circle);
				return result;
			case GWBNT_CLS:
				result = gwbh_Cls(env, node->cls);
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

	return result;	 
} 
	
GWBR_Result gwbh_Beep(GWBE_Environment *env, GWBN_Beep* node) {
	GWBR_Result result;

	/* "Beep" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Beep\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Call(GWBE_Environment *env, GWBN_Call* node) {
	GWBR_Result result;

	/* "Call" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Call\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Dim(GWBE_Environment *env, GWBN_Dim* node) {
	GWBR_Result result;

	/* "Dim" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Dim\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Let(GWBE_Environment *env, GWBN_Let* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	/* "Let" handler implementation */
	gwbo_DisplayDebugMessage(env, "In \"Let\" Handler"); 
	GWBR_ExpressionResult expr_res = gwbr_EvaluateExpression(env, node->expr);
	GWBC_Variable* new_var; 
	switch (node->var->type)
	{
		case GWBNT_STRINGVARIABLE:
		{
			gwbo_DisplayDebugMessage(env, "String Variable");
			new_var = gwbc_NewVariable(GWBCT_VALUE, node->var->str->name);
			new_var->val->type = GWBCT_STRING; // gwbc_Variable_SetValueType
			result = gwbc_Variable_SetValue(new_var, expr_res.val);
			
			break;
		}
		case GWBNT_NUMERICVARIABLE:
		{	
			gwbo_DisplayDebugMessage(env,"Numeric variable");
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
			//gwbo_DisplayCoreValue(env, new_var->val);
			break;
		}
		case GWBNT_ARRAYVARIABLE:
			/* Not Implemented */
			break;
	}
		
	switch (result.type)
	{	
		case GWBR_ERROR_TYPEMISMATCH:
			break;
		case GWBR_RESULT_OK:
		{
			/*
				Сохранение значения 
			*/
			if (!gwbe_Context_ExistsVariable(env, new_var))
				gwbe_Context_AddLocalVariable(env, new_var);
			else
			{
				GWBC_Variable* var = gwbe_Context_GetVariable(env, new_var->name);
				
				assert(var != NULL);

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
	gwbo_DisplayDebugMessage(env,"In \"OptionBase\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_DefFn(GWBE_Environment *env, GWBN_DefFn* node) {
	GWBR_Result result;

	/* "DefFn" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"DefFn\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Circle(GWBE_Environment *env, GWBN_Circle* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	assert(env != NULL);
	assert(node != NULL);
	assert(node->opts != NULL);

	gwbo_DisplayDebugMessage(env,"In \"Circle\" Handler"); 
	
	int type_mismatch = 0;

	GWBC_Circle circle;
	
	GWBC_Value val;
	val = gwbr_EvaluateNumericExpression(env, node->coord->x).val;
	if (val.type == GWBCT_INTEGER) circle.center.x = val.int_val;
	else type_mismatch = 1;
	
	val = gwbr_EvaluateNumericExpression(env, node->coord->y).val;
	if (val.type == GWBCT_INTEGER) circle.center.y = val.int_val;
	else type_mismatch = 1;

	if (node->opts->color != NULL)
	{
		circle.color = malloc(sizeof(GWBC_Value));
		*(circle.color) = gwbr_EvaluateNumericExpression(env, node->opts->color).val;
	}
	else circle.color = NULL;

	val = gwbr_EvaluateNumericExpression(env, node->r).val;
	
	switch (val.type)
	{
		case GWBCT_INTEGER:
			circle.r = (double) val.int_val;
			break;
		case GWBCT_SINGLE:
			circle.r = (double) val.single_val;
			break;
		case GWBCT_DOUBLE:
			circle.r = val.double_val;
			break;
		default:
			type_mismatch = 1;
			break;
	}

	if (!type_mismatch)
	{
		gwbo_DisplayCircle(env, circle);
	}
	else
	{
		result.type = GWBR_ERROR_TYPEMISMATCH;
		return result;
	}
	return result;	 
} 
	
GWBR_Result gwbh_Screen(GWBE_Environment *env, GWBN_Screen* node) {
	GWBR_Result result;

	/* "Screen" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Screen\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Line(GWBE_Environment *env, GWBN_Line* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(env != NULL);
	assert(node != NULL);
	assert(node->coord_b != NULL);
	assert(node->opts != NULL);
	assert(node->opts->color != NULL);
	gwbo_DisplayDebugMessage(env,"In \"Line\" Handler"); 
	
	GWBC_Value val;

	int type_mismatch = 0;

	GWBC_Line line;
	if (node->coord_a != NULL)
	{
		val = gwbr_EvaluateNumericExpression(env, node->coord_a->x).val;
		if (val.type == GWBCT_INTEGER) line.a.x = val.int_val;
		else type_mismatch = 1;

		val = gwbr_EvaluateNumericExpression(env, node->coord_a->y).val;
		if (val.type == GWBCT_INTEGER) line.a.y = val.int_val;
		else type_mismatch = 1;
	}
	else 
	{
		line.a.x = 0;
		line.b.y = 0;
	}

	val = gwbr_EvaluateNumericExpression(env, node->coord_b->x).val;
	if (val.type == GWBCT_INTEGER) line.b.x = val.int_val;
	else type_mismatch = 1;

	val = gwbr_EvaluateNumericExpression(env, node->coord_b->y).val;
	if (val.type == GWBCT_INTEGER) line.b.y = val.int_val;
	else type_mismatch = 1;

	if (node->opts->color != NULL)
	{
		line.color = malloc(sizeof(GWBC_Line));
		*(line.color) = gwbr_EvaluateNumericExpression(env, node->opts->color).val;
	}
	else line.color = NULL;

	if (!type_mismatch)
		gwbo_DisplayLine(env, line);
	else 
	{
		result.type = GWBR_ERROR_TYPEMISMATCH;
	}
	return result;	 
} 
	
GWBR_Result gwbh_Paint(GWBE_Environment *env, GWBN_Paint* node) {
	GWBR_Result result;

	/* "Paint" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Paint\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Pset(GWBE_Environment *env, GWBN_Pset* node) {
	GWBR_Result result;

	/* "Pset" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Pset\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Preset(GWBE_Environment *env, GWBN_Preset* node) {
	GWBR_Result result;

	/* "Preset" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Preset\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Cls(GWBE_Environment *env, GWBN_Cls* node) {
	GWBR_Result result;

	gwbo_DisplayDebugMessage(env, "In \"Cls\" Handler"); 
	gwbo_Cls(env);

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

	gwbo_DisplayDebugMessage(env, "In \"For\" Handler"); 
	
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
			gwbe_Context_PopLocalVariableLevel(env);
			gwbo_DisplayDebugMessage(env, "Out of Cycle");
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
			var = gwbc_NewVariable(GWBCT_VALUE, node->num_var->name); 
			switch (node->num_var->type)
			{
				case GWBNT_INTEGERVARIABLE:
					var->val->type = GWBCT_INTEGER;
					break;
				case GWBNT_SINGLEPRECISIONVARIABLE:
					var->val->type = GWBCT_SINGLE;
					break;
				case GWBNT_DOUBLEPRECISIONVARIABLE:
					var->val->type = GWBCT_DOUBLE;
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
			gwbo_DisplayDebugMessage(env, "Out of Cycle");
			env->ctx->skip_flag++;		
		}
		
	}

	return result;	 
} 
	
GWBR_Result gwbh_Next(GWBE_Environment *env, GWBN_Next* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayDebugMessage(env,"In \"Next\" Handler"); 

	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(env->ctx->local_vars != NULL);
	assert(env->ctx->callback_stack != NULL);
	assert(env->ctx->callback_stack->callback != NULL);

	if (env->ctx->skip_flag == 1) 	/* Next для завершаемого цикла */
	{
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
	gwbo_DisplayDebugMessage(env,"In \"GoSub\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Return(GWBE_Environment *env, GWBN_Return* node) {
	GWBR_Result result;

	/* "Return" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Return\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Goto(GWBE_Environment *env, GWBN_Goto* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayDebugMessage(env,"In \"Goto\" Handler"); 
	assert(node != NULL);
	assert(env->ctx != NULL);
	/* Здесь делается поправка на систему исполнения, которая 
	   Автоматически инкрементирует это значение после выполнения
	   оператора (Statement) */
	env->ctx->current_line = node->line - 1;	

	return result;	 
} 
	
GWBR_Result gwbh_IfThenElse(GWBE_Environment *env, GWBN_IfThenElse* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayDebugMessage(env,"In \"IfThenElse\" Handler"); 
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
		gwbo_DisplayDebugMessage(env,"Result has another type. Expected Numeric (Integer)\n This message should be represented as error ");
	}
	return result;	 
} 

/* Set variable Vaulue from Input */
GWBR_Result gwbi_SetValue(GWBE_Environment *env, GWBN_Variable* node_var)
{
	GWBR_Result result;
	GWBC_Variable* runtime_var;
	switch(node_var->type)
	{		
		case GWBNT_STRINGVARIABLE:
		{
			runtime_var = gwbe_Context_GetVariable(env, node_var->str->name);
			
			assert (runtime_var != NULL);

			gwbi_GetString(env);
			
			GWBC_Value value;
			value.type = GWBCT_STRING;
			value.str_val = strdup(env->input->buffer);

			result = gwbc_Variable_SetValue(runtime_var, value);

			break;
		}
		case GWBNT_NUMERICVARIABLE:
		{
			runtime_var = gwbe_Context_GetVariable(env, node_var->num->name);
			
			assert (runtime_var != NULL);
			
			GWBC_Value value;
			switch (node_var->num->type)
			{
				case GWBNT_INTEGERVARIABLE:
				{
					value.type = GWBCT_INTEGER;
					value.int_val = gwbi_GetInteger(env);
					break;
				}
				case GWBNT_SINGLEPRECISIONVARIABLE:
				{
					value.type = GWBCT_SINGLE;
					value.single_val = gwbi_GetFloat(env);
					break;
				}
				case GWBNT_DOUBLEPRECISIONVARIABLE:
				{
					value.type = GWBCT_DOUBLE;
					value.double_val = gwbi_GetDouble(env);
					break;
				}
			}

			result = gwbc_Variable_SetValue(runtime_var, value);

			break;
		}
		case GWBNT_ARRAYVARIABLE:
			/* Not Implemented */
			gwbo_DisplayDebugMessage(env,"Array variables not supported");
			break;
	}
	return result;
}

GWBR_Result gwbh_Input(GWBE_Environment *env, GWBN_Input* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayDebugMessage(env,"In \"Input\" Handler"); 

	assert(env != NULL);
	assert(node != NULL);	

	if (env->runtime_mode == GWBE_RUNTIMEMODE_INTERPRETER)
	{
		gwbo_DisplayMessage(env, "This statement can't be run in \"Interpter Mode\". Use \"Let\" statement instead.");
		gwbo_NextLine(env);
		return result;
	}
	
	assert(env->input != NULL);
	
	if (env->input->input_request.var_index == 0)
	{
		/* Вывод текстового сообщения */
		if (node->prompt != NULL)
		{
			if (node->prompt->str != NULL) 
			{
				gwbo_DisplayMessage(env, node->prompt->str);
				gwbo_NextLine(env);
			}
			else {
				gwbo_DisplayMessage(env, "?");
				gwbo_NextLine(env);
			}
		}
	}
	
	int var_index = 0;
	GWBN_Variables* vars = node->vars;
	if (node->vars != NULL)
	{
		assert(node->vars != NULL);

		while (vars != NULL && result.type == GWBR_RESULT_OK)
		{
			if (var_index == env->input->input_request.var_index)
			{
				/* leave cycle on next iteration. Wait for value. */
				gwbo_DisplayDebugMessage(env, "Waiting for new value for variable");
				result.type = GWBR_NOTIFICATION_WAITFORVALUE;
			}
			else if (var_index == env->input->input_request.var_index - 1)
			{
				/* set new value to variable */
				assert(vars->var != NULL);
				result = gwbi_SetValue(env, vars->var);
			}

			/* Got to the next variable */
			vars = vars->next;
			var_index++;
		}	
	}	
	
	switch (result.type)
	{
		case GWBR_RESULT_OK:
		{
			gwbo_DisplayDebugMessage(env, "All variables inited");
			
			/* Сбрасываем индекс для оператора Input */
			env->input->input_request.var_index = 0;
			break;
		}
		case GWBR_ERROR_TYPEMISMATCH:
		{
			gwbo_DisplayDebugMessage(env, "Type mismatch occured");
			
			/* Сбрасываем индекс для оператора Input */
			env->input->input_request.var_index = 0;
		}
		case GWBR_NOTIFICATION_WAITFORVALUE:
		{
			gwbo_DisplayDebugMessage(env, "Waiting for value");
			
			/* сохраняем новый индекс */
			env->input->input_request.var_index = var_index;
		}
	}
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

		switch (print_exprs->sep_type)
		{
			case GWBBT_COMMA:
				break;
			case GWBBT_SEMICOLON:
				gwbo_NextLine(env);
				break;
			case GWBBT_NONE:
				gwbo_NextLine(env);
				break;
		};

		print_exprs = print_exprs->next;
	}
	while (print_exprs != NULL);
	
	return result;	 
} 
	
GWBR_Result gwbh_LineInput(GWBE_Environment *env, GWBN_LineInput* node) {
	GWBR_Result result;

	/* "LineInput" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"LineInput\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Locate(GWBE_Environment *env, GWBN_Locate* node) {
	GWBR_Result result;

	/* "Locate" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Locate\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_Mid(GWBE_Environment *env, GWBN_Mid* node) {
	GWBR_Result result;

	/* "Mid" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"Mid\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnErrorGoto(GWBE_Environment *env, GWBN_OnErrorGoto* node) {
	GWBR_Result result;

	/* "OnErrorGoto" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"OnErrorGoto\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGosub(GWBE_Environment *env, GWBN_OnGosub* node) {
	GWBR_Result result;

	/* "OnGosub" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"OnGosub\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_OnGoto(GWBE_Environment *env, GWBN_OnGoto* node) {
	GWBR_Result result;

	/* "OnGoto" handler implementation */
	gwbo_DisplayDebugMessage(env,"In \"OnGoto\" Handler"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	

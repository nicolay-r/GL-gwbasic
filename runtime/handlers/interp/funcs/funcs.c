/* GWBasic Functions implementation */

#include "inc/funcs.h"
#include <assert.h>

#include "../expr/inc/eval.h" 	/* Expression Evaluator */
#include <output.h>		/* GWBO_* */

#include <stdio.h>

GWBR_Result gwbh_Function(GWBE_Environment *env, GWBN_Function* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(env != NULL);
	assert(node != NULL);
	assert(node->math_func != NULL);

	gwbo_DisplayMessage(env, "In \"Function\" Handler"); 
	
	GWBR_ExpressionResult expr_result;
	switch (node->type)
	{
		case GWBNT_MATHFUNCTION:
			/* вычислить математическое выражение */
			expr_result = gwbr_EvaluateMathFunction(env, node->math_func);	
			break;
		case GWBNT_STRINGFUNCTION:
		case GWBNT_SYSTEMFUNCTION:
			break;
	}
	/* 
		можно еще отобразить результат на экран 
		для этого потребуется ф-ция вывода
	*/
	gwbo_DisplayCoreValue(env, &expr_result.val);	
	return result;	 
} 
	

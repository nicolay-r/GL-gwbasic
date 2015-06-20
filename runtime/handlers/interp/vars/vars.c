/* GWBasic Variables handlers Implementations and Auxilary handlers and functions */

#include "../expr/inc/eval.h"		/* gwbr_EvalueateNumericExpression() */
#include "../../../inc/env.h"		/* gwbe_* */
#include "inc/vars.h"

#include <output.h>			/* gwbo_DisplayCoreValue() */

#include <assert.h>			/* assert */

GWBR_Result gwbh_Indexes(GWBE_Environment *env, GWBN_Indexes* indexes, GWBC_Indexes* core_indexes)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(env != NULL);
	assert(core_indexes != NULL);

	int length = 0;
	GWBN_Indexes* curr_index = indexes;
	while (curr_index != NULL)
	{
		/* go to next index */
		curr_index = curr_index->next;
		length++;
	}
	
	/* set initial length */
	core_indexes->count = length;
	core_indexes->indexes = malloc(sizeof(int)* (core_indexes->count));

	/* going again from beginning to end */
	int i = 0;
	curr_index = indexes;
	while (curr_index != NULL)
	{
		GWBR_ExpressionResult res = gwbr_EvaluateNumericExpression(env, curr_index->num);
		
		assert(res.val.type == GWBCT_INTEGER);

		/* set index values */
		core_indexes->indexes[i] = res.val.int_val;

		/* go to next index */
		curr_index = curr_index->next;
		i++;
	}
	
	return result;
}



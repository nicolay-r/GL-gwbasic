/* GWBasic Runtime Output implementation */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <output.h>	/* GWBE_Display */ 
#include "render.h"

void gwbo_DisplayMessage(GWBE_Environment* env, char* msg)
{
	assert(ide != NULL);
	assert(ide->text_buffer != NULL);
	
	gwbg_TextBuffer_PushString(ide->text_buffer, msg);

	// Force Render Ide
	//gwbg_Ide_Render();
}

void gwbo_DisplayDebugMessage(GWBE_Environment* env, char* msg)
{
	assert(ide != NULL);
	assert(ide->text_buffer != NULL);
	
	if (env->trace_mode)
	{
		gwbg_TextBuffer_PushString(ide->text_buffer, msg);
	}

	// Force Render Ide
	//gwbg_Ide_Render();
}

void gwbo_DisplayResult(GWBE_Environment* env, GWBR_Result result)
{
	assert(env != NULL);
	
	switch (result.type)
	{
		case GWBR_RESULT_OK:
			gwbo_DisplayMessage(env, "Ok");
			break;
		case GWBR_ERROR_TYPEMISMATCH:
			gwbo_DisplayMessage(env, "Type Mismatch");
			break;
		default:
			gwbo_DisplayMessage(env, "Uknown Error");
			break;
	}

}

void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result)
{
	assert(env != NULL);
	assert(ide->text_buffer != NULL);

	//assert(env != NULL);
	assert(result != NULL);

	char output[50];
	switch (result->type)
	{
		case GWBCT_INTEGER:
			sprintf(output, "%d", result->int_val);
			gwbg_TextBuffer_PushString(ide->text_buffer, output);
			break;
		case GWBCT_SINGLE:
      			snprintf(output,50,"%f",result->single_val);
			gwbg_TextBuffer_PushString(ide->text_buffer, output);
			break;
		case GWBCT_DOUBLE:
      			snprintf(output,50,"%f",result->double_val);
			gwbg_TextBuffer_PushString(ide->text_buffer, output);
			break;
		case GWBCT_STRING:
			assert(result->str_val != NULL);
			gwbg_TextBuffer_PushString(ide->text_buffer, result->str_val);
			break;
	}
}

void gwbo_DisplayLine(GWBE_Environment* env, GWBC_Line line)
{
	/* Draw line */	
	gwbo_DisplayMessage(env, "DisplayLine is not implemented");
}

void gwbo_DisplayCircle(GWBE_Environment* env, GWBC_Circle circle)
{
	/* Draw Circle */
	gwbo_DisplayMessage(env, "DisplayCircle is not implemented");
}

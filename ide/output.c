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
}
void gwbo_DisplayDebugMessage(GWBE_Environment* env, char* msg)
{
	assert(ide != NULL);
	assert(ide->text_buffer != NULL);
	
	if (env->trace_mode)
	{
		gwbg_TextBuffer_PushString(ide->text_buffer, msg);
		gwbo_NextLine(env);
	}
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
	if (env->graphics_mode == 1)
	{
		/* Draw line */	
		gwbg_Canvas_AddLine(ide->canvas, line);

		/* Force Render */
		gwbg_Ide_Render();
	}
	else
	{
		gwbo_DisplayMessage(env, "Graphics mode disabled. Use \"Screen\" command to enable. ");
		gwbo_NextLine(env);
	}
}

void gwbo_DisplayCircle(GWBE_Environment* env, GWBC_Circle circle)
{
	if (env->graphics_mode == 1)
	{
		/* Draw Circle */
		gwbg_Canvas_AddCircle(ide->canvas, circle);

		/* Force Render */
		gwbg_Ide_Render();
	}
	else
	{
		gwbo_DisplayMessage(env, "Graphics mode disabled. Use \"Screen\" command to enable. ");
		gwbo_NextLine(env);
	}
}
void gwbo_Cls(GWBE_Environment* env)
{
	assert(ide != NULL);

	/* Clean canvas */
	gwbg_Canvas_Clear(ide->canvas);
	gwbg_TextBuffer_Clear(ide->text_buffer);
	
	/* Force Render */
	gwbg_Ide_Render();
}

void gwbo_NextLine(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(ide != NULL);

	gwbg_TextBuffer_CursorNextLine(ide->text_buffer); 	
}

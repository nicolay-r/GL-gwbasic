/* GWBasic Runtime Output implementation */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <output.h>	/* GWBE_Display */ 

void gwbo_DisplayMessage(GWBE_Environment* env, char* msg)
{
	assert(ide != NULL);
	assert(ide->text_buffer != NULL);
	
	gwbg_TextBuffer_PushString(ide->text_buffer, msg);
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

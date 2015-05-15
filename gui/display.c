/* GWBasic display functions implementation */

#include "inc/display.h"
#include <assert.h>
#include <stdlib.h>

void gwbg_Display_CreateTextBuffer(GWBG_Display* display, int height, int width)
{
	assert(display != NULL);
	
	GWBG_TextBuffer *text_buffer = malloc(sizeof(GWBG_TextBuffer));
	
	text_buffer->text_field = malloc(sizeof(char)*height*width);
	text_buffer->width = width;
	text_buffer->height = height;

	GWBC_DisplayPoint *cursor = malloc(sizeof(GWBC_DisplayPoint));
	cursor->x = 0;
	cursor->y = 0;
	
	text_buffer->cursor = cursor;	
	display->text_buffer = text_buffer;
}

void gwbg_Display_DeleteTextBuffer(GWBG_Display* display)
{
	free(display->text_buffer->text_field);
	free(display->text_buffer->cursor);
	free(display->text_buffer);
}

/* GWBasic display functions implementation */

#include "inc/display.h"
#include "inc/settings.h"

#include <assert.h>
#include <stdlib.h>

/* Display */
GWBG_Display* gwbg_NewDisplay()
{
	GWBG_Display* display = malloc(sizeof(GWBG_Display));
	
	display->width = GWBGS_DISPLAYWIDTH;
	display->height = GWBGS_DISPLAYHEIGHT;

	return display;
}

void gwbg_Display_CreateTextBuffer(GWBG_Display* display, int height, int width)
{
	assert(display != NULL);
	
	GWBG_TextBuffer *text_buffer = malloc(sizeof(GWBG_TextBuffer));
	
	text_buffer->text_field = malloc(sizeof(char)*height);
	int i;
	for (i = 0; i < height; i++)
	{
		text_buffer->text_field[i] = calloc(width, sizeof(char));
		int j;
		for (j = 0; j < width; j++)
			text_buffer->text_field[i][j] = '*' + i ;
	}
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

/* TextBuffer */
void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c)
{
	assert(text_buffer != NULL);
	assert(text_buffer->cursor != NULL);

	int x = text_buffer->cursor->x;
	int y = text_buffer->cursor->y;
	text_buffer->text_field[x][y] = c;
	
	/* изменение координат каретки */
	if (y < text_buffer->width - 1)
	{
		/* смещение по строке вправо */
		text_buffer->cursor->y++;
	}
	else if (x < text_buffer->height - 1)
	{
		/* переход на новую строку */	
		text_buffer->cursor->x++;
		text_buffer->cursor->y = 0;
	}
}
void gwbg_TextBuffer_PopChar(GWBG_TextBuffer* text_buffer)
{
	int x = text_buffer->cursor->x;
	int y = text_buffer->cursor->y;
	text_buffer->text_field[x][y] = 0;
	
	/* смещение каретки */
	if (y > 0)
	{
		text_buffer->cursor->y--;
	}
	else if (x > 0)
	{
		text_buffer->cursor->x--;
		text_buffer->cursor->y = text_buffer->width - 1;
	}
}


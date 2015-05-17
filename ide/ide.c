/* GWBasic display functions implementation */

#include "inc/ide.h"
#include "inc/settings.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Ide */
GWBG_Ide* gwbg_NewIde()
{
	GWBG_Ide* ide = malloc(sizeof(GWBG_Ide));
	
	ide->width = GWBGS_DISPLAYWIDTH;
	ide->height = GWBGS_DISPLAYHEIGHT;

	return ide;
}

void gwbg_Ide_CreateTextBuffer(GWBG_Ide* ide, int height, int width)
{
	assert(ide != NULL);
	
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
	ide->text_buffer = text_buffer;
}

void gwbg_Ide_DeleteTextBuffer(GWBG_Ide* ide)
{
	free(ide->text_buffer->text_field);
	free(ide->text_buffer->cursor);
	free(ide->text_buffer);
}

/* TextBuffer */
void gwbg_TextBuffer_PushString(GWBG_TextBuffer* text_buffer, char* string)
{
	assert(text_buffer != NULL);
	assert(text_buffer->cursor != NULL);
	
	int i;
	for (i = 0; i < strlen(string); i++)
	{
		gwbg_TextBuffer_PushChar(text_buffer, string[i]);
	}

	gwbg_TextBuffer_CursorNextLine(text_buffer);	
}

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
	else gwbg_TextBuffer_CursorNextLine(text_buffer); 
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

	/*
	// переход на предыдущую строку 
	else if (x > 0)
	{
		text_buffer->cursor->x--;
		text_buffer->cursor->y = text_buffer->width - 1;
	}*/
}

void gwbg_TextBuffer_CursorNextLine(GWBG_TextBuffer* text_buffer)
{
	int x = text_buffer->cursor->x, y = text_buffer->cursor->y;
	
	text_buffer->text_field[x][y] = 0;

	if (x < text_buffer->height - 1)
	{
		text_buffer->cursor->x++;
		text_buffer->cursor->y = 0;
	}
	else
	{
		/* Выполняем сдвиг текста */
		int i, j;
		free(text_buffer->text_field[0]);
		for (i = 0; i < text_buffer->height - 1; i++)
		{
			text_buffer->text_field[i] = text_buffer->text_field[i+1];
		}

		text_buffer->text_field[x] = calloc(text_buffer->width, sizeof(char));		
		text_buffer->cursor->y = 0;
	}
}
void gwbg_Environment_ClearRequest(GWBE_Environment* env)
{
	assert(env != NULL);

	env->line_buffer_len = 0;
	env->line_buffer[0] = 0;
}
void gwbg_Environment_PushCharToRequest(GWBE_Environment* env, char c)
{
	assert(env != NULL);

	env->line_buffer[env->line_buffer_len] = c;
	env->line_buffer_len++;
	env->line_buffer[env->line_buffer_len] = 0;
}
void gwbg_Environment_PopCharFromRequest(GWBE_Environment* env)
{
	assert(env != NULL);

	if (env->line_buffer_len > 0)
	{
		env->line_buffer_len--;
		env->line_buffer[env->line_buffer_len] = 0;
	}
}

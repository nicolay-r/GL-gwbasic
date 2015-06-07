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

int contents_by_pixelformat(int pixel_format)
{
	int contents = 1;
	switch(pixel_format) {
		case GL_BGR:
		case GL_RGB:
		    contents = 3; break;
		case GL_BGRA:
		case GL_RGBA:
		    contents = 4; break;
		case GL_ALPHA:
		case GL_LUMINANCE:
		    contents = 1; break;
	}
	return contents;
}

void gwbg_Ide_SetCanvas(GWBG_Ide* ide, int pixel_format)
{
	int contents = contents_by_pixelformat(pixel_format);

	ide->canvas = malloc(sizeof(GWBG_Canvas));
	ide->canvas->data = calloc(ide->height*ide->width*contents, sizeof(GLubyte));
	
	ide->canvas->pixel_format = pixel_format;
	ide->canvas->pixel_type = GL_UNSIGNED_BYTE;
	ide->canvas->to_draw_count = 0;			

}

void gwbg_Ide_SetTextBuffer(GWBG_Ide* ide, int rows, int columns)
{
	assert(ide != NULL);
	
	GWBG_TextBuffer *text_buffer = malloc(sizeof(GWBG_TextBuffer));
	
	text_buffer->text_field = malloc(sizeof(char*)*rows);
	int i;
	for (i = 0; i < rows; i++)
	{
		text_buffer->text_field[i] = calloc(columns, sizeof(char));
		/*
		int j;
		for (j = 0; j < width; j++)
			text_buffer->text_field[i][j] = '*' + i ;
		*/
	}
	text_buffer->width = columns;
	text_buffer->height = rows;

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
}

void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c)
{
	assert(text_buffer != NULL);
	assert(text_buffer->cursor != NULL);

	int x = text_buffer->cursor->x;
	int y = text_buffer->cursor->y;
	
	/* изменение координат каретки */
	if (y < text_buffer->width - 1)
	{
		text_buffer->text_field[x][y] = c;
		/* смещение по строке вправо */
		text_buffer->cursor->y++;
	}
	else 
	{
		gwbg_TextBuffer_CursorNextLine(text_buffer);
		text_buffer->text_field[x][y] = c;
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
		int i;
		char* unused_buffer = text_buffer->text_field[0];
		for (i = 0; i < text_buffer->height - 1; i++)
		{
			text_buffer->text_field[i] = text_buffer->text_field[i+1];
		}

		text_buffer->text_field[x] = unused_buffer;
		for (i = 0; i < text_buffer->width; i++)
			text_buffer->text_field[x][i] = 0;

		text_buffer->cursor->y = 0;
	}
}
void gwbg_TextBuffer_Clear(GWBG_TextBuffer* text_buffer)
{
	assert(text_buffer != NULL);
	assert(text_buffer->text_field != NULL);

	/* Очистка текстовой матрицы */
	int i, j;
	for (i = 0; i < text_buffer->height; i++)
		for (j = 0; j < text_buffer->width; j++)
			text_buffer->text_field[i][j] = 0;
	
	/* Устанавливаем начальное положение курсора */
	text_buffer->cursor->x = 0;
	text_buffer->cursor->y = 0;
}
void gwbg_Environment_ClearRequest(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->input != NULL);
	assert(env->input->buffer != NULL);

	env->input->buffer_len = 0;
	env->input->buffer[0] = 0;
}
void gwbg_Environment_PushCharToRequest(GWBE_Environment* env, char c)
{
	assert(env != NULL);
	assert(env->input != NULL);
	assert(env->input->buffer != NULL);
	
	env->input->buffer[env->input->buffer_len] = c;
	env->input->buffer_len++;
	env->input->buffer[env->input->buffer_len] = 0;
}
void gwbg_Environment_PopCharFromRequest(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->input != NULL);
	assert(env->input->buffer != NULL);

	if (env->input->buffer_len > 0)
	{
		env->input->buffer_len--;
		env->input->buffer[env->input->buffer_len] = 0;
	}
}

/* Canvas */
void gwbg_Canvas_AddLine(GWBG_Canvas* canvas, GWBC_Line line)
{
	assert(canvas != NULL);

	int index = canvas->to_draw_count;

	if (index < GWBG_CANVAS_MAXOBJECTS)
	{	
		canvas->objects[index].type = GWBCT_LINE;
		canvas->objects[index].line = line;
		
		canvas->to_draw_count++;
	}
	else
	{
		assert(ide != NULL);
		assert(ide->env != NULL);
		gwbo_DisplayMessage(ide->env, "Error: Can't add more lines in canvas buffer");	
	}
}

void gwbg_Canvas_AddCircle(GWBG_Canvas* canvas, GWBC_Circle circle)
{
	assert(canvas != NULL);

	int index = canvas->to_draw_count;

	if (index < GWBG_CANVAS_MAXOBJECTS)
	{	
		canvas->objects[index].type = GWBCT_CIRCLE;
		canvas->objects[index].circle = circle;

		canvas->to_draw_count++;
	}
	else 
	{
		assert(ide != NULL);
		assert(ide->env != NULL);
		gwbo_DisplayMessage(ide->env, "Error: Can't add more circles in canvas buffer");
	}
}

void gwbg_Canvas_Clear(GWBG_Canvas* canvas)
{
	assert(ide != NULL);
	assert(canvas != NULL);
	assert(canvas->data != NULL);

	int contents = contents_by_pixelformat(canvas->pixel_format);
	
	/* очистка холста */	
	int i, j;
	for (i = 0; i < ide->height; i++)
		for (j = 0; j < ide->width*contents; j++)
			canvas->data[i*ide->width*contents + j] = 0;
}



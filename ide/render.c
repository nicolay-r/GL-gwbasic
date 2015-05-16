/* GWBasic Rendering implementation */

#include "inc/render.h"
#include <GL/glut.h>
#include <assert.h>
#include <stdio.h>

void gwbg_SetTextLinePosition(int x, int y)
{
	glRasterPos2i(x, y);
}
void gwbg_RenderTextLine(char c)
{
	void* font = GLUT_BITMAP_9_BY_15;
	glutBitmapCharacter(font, c);
}

void gwbg_Ide_Render(GWBG_Ide* ide)
{
	assert(ide != NULL);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, ide->width, 0.0, ide->height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Green color
	glColor3f(0.0, 1.0, 0.0); 
		
	/* Используется инвертированная система координат */
	GWBC_DisplayPoint lu_offset;
	lu_offset.x = 10;
	lu_offset.y = ide->height - 20;	
	gwbg_TextBuffer_Render(ide->text_buffer, lu_offset); 

	gwbg_TextBuffer_MarkCursorPosition(ide->text_buffer);

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

}

void gwbg_TextBuffer_Render(
	GWBG_TextBuffer* text_buffer, 
	GWBC_DisplayPoint lu_corner) /* lu_offset -- смещение от верхнего левого угла */
{
	assert(text_buffer != NULL);
	assert(text_buffer->text_field != NULL);

	int i, j;
	
	for (i = 0; i < text_buffer->height; i++)
	{
		gwbg_SetTextLinePosition(lu_corner.x, lu_corner.y);
	
		for (j = 0; j < text_buffer->width; j++)
		{
			gwbg_RenderTextLine(text_buffer->text_field[i][j]);
		}
		
		lu_corner.y -= 10;
	}
}


void gwbg_TextBuffer_MarkCursorPosition(GWBG_TextBuffer* text_buffer)
{
	int x = text_buffer->cursor->x;
	int y = text_buffer->cursor->y;

	text_buffer->text_field[x][y] = GWBGS_CURSORMARKER;
}


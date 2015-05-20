/* GWBasic Rendering implementation */

#include "inc/render.h"
#include <GL/glut.h>
#include <assert.h>
#include <stdio.h>

/*
	Main Rendering Function
*/
int x = 0;
void gwbg_Ide_Render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	assert(ide != NULL);
	assert(ide->canvas != NULL);
	assert(ide->canvas->data != NULL);	


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, ide->width, 0.0, ide->height);

	glRasterPos2i(0, 0);
	glDrawPixels(ide->width, ide->height, ide->canvas->pixel_format, ide->canvas->pixel_type, ide->canvas->data);
	
	if (x == 0)
	{
		glBegin(GL_LINES);
			glColor3f(0.0,1.0,0.0);
			glVertex3f(10.0, 10.0, 0.0);
			glVertex3f(100.0, 100.0, 0.0);
		glEnd();

		// Force draw everything before
		glFlush();

		// save	
		glReadPixels(0,0, ide->width, ide->height, ide->canvas->pixel_format, ide->canvas->pixel_type, ide->canvas->data);
		x = 1;
	}

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

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

        
	glutSwapBuffers();
}

void gwbg_SetTextLinePosition(int x, int y)
{
	glRasterPos2i(x, y);
}

void gwbg_RenderTextLine(char c)
{
	void* font = GLUT_BITMAP_9_BY_15;
	glutBitmapCharacter(font, c);
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
	gwbg_TextBuffer_MarkCursorPosition(text_buffer);
}


void gwbg_TextBuffer_MarkCursorPosition(GWBG_TextBuffer* text_buffer)
{
	int x = text_buffer->cursor->x;
	int y = text_buffer->cursor->y;

	text_buffer->text_field[x][y] = GWBGS_CURSORMARKER;
}


/* GWBasic Rendering implementation */

#include "inc/render.h"
#include <GL/glut.h>
#include <assert.h>
#include <stdio.h>
void gwbg_Display_Render(GWBG_Display* display)
{
	assert(display != NULL);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, display->width, 0.0, display->height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Green color
	glColor3f(0.0, 1.0, 0.0); 
		
	/* Используется инвертированная система координат */
	GWBC_DisplayPoint lu_offset;
	lu_offset.x = 10;
	lu_offset.y = display->height - 20;	
	gwbg_TextBuffer_Render(display->text_buffer, lu_offset); 

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

	void* font = GLUT_BITMAP_9_BY_15;

	int i, j;
	
	for (i = 0; i < text_buffer->height; i++)
	{
		glRasterPos2i(lu_corner.x, lu_corner.y);
	
		for (j = 0; j < text_buffer->width; j++)
		{
			glutBitmapCharacter(font, text_buffer->text_field[i][j]);
		}
		
		lu_corner.y -= 10;
	}
}

/* GWBasic Rendering implementation */

#include "inc/render.h"
#include "inc/runtime.h"		/* GWBCT_CIRCLE, GWBCT_LINE */

#include <GL/glut.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>			/* M_PI */
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

	/* Display current canvas */
	glRasterPos2i(0, 0);
	glDrawPixels(ide->width, ide->height, ide->canvas->pixel_format, ide->canvas->pixel_type, ide->canvas->data);
	
	/* Green color */
	glColor3f(0.0, 1.0, 0.0); 
	
	/* Draw new objects on canvas */
	gwbg_Canvas_RenderObjectsToDraw(ide->canvas);	

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	/* Green color */
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

void gwbg_Canvas_RenderObjectsToDraw(GWBG_Canvas* canvas)
{
	assert(canvas != NULL);	
	assert(canvas->objects != NULL);

	int i = 0;
	for (i = 0; i < canvas->to_draw_count; i++)
	{
		switch (canvas->objects[i].type)
		{
			case GWBCT_LINE:
			{
				GWBC_Line line = canvas->objects[i].line; 	
				
				glBegin(GL_LINES);
					/* нужно задать цвет! */
					glVertex2i(line.a.x, line.a.y);
					glVertex2i(line.b.x, line.b.y);
				glEnd();
				break;
			}
			case GWBCT_CIRCLE:
			{
				/* draw circle */
				GWBC_Circle circle = canvas->objects[i].circle;

				glBegin(GL_LINE_LOOP);	
					/* нужно задать цвет! */
					double alpha;
					for (alpha = 0; alpha < 2*M_PI; alpha += 2*M_PI/50)
					{	
						int x = circle.center.x + round(circle.r*sin(alpha));
						int y = circle.center.y + round(circle.r*cos(alpha));	
						glVertex2i(x, y);
					}
				glEnd();
				break;
			}
		}
	}

	/* clears array */
	canvas->to_draw_count = 0;

	/* Force draw everything before */
	glFlush();

	/* save	*/
	glReadPixels(0,0, ide->width, ide->height, ide->canvas->pixel_format, 
		ide->canvas->pixel_type, ide->canvas->data);
}

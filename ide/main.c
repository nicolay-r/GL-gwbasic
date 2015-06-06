
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

#include "inc/ide.h"
#include "inc/render.h"
#include "inc/settings.h"

GLubyte *data;
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
	h = 1;
	float ratio = 1.0* w / h;
					
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
								
	// Reset Matrix
	glLoadIdentity();
								
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
												
	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);
						
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void fixedSize(int w, int h)
{
	// we ignore the params and do:
	glutReshapeWindow(ide->width, ide->height);
}
void SetData(GLubyte *data)
{
	int i, j;
	for (i = 0; i < ide->height; i++)
	{
		for (j = 0; j < ide->width*3; j++)
		{
			data[i*ide->width*3 + j] = 116;
		}
	}
}
void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 8: /* Backspace */
			gwbg_TextBuffer_PopChar(ide->text_buffer);
			gwbg_Environment_PopCharFromRequest(ide->env);
			break;
		case 13: /* Enter */	
			//glReadPixels(0, 0, ide->width, ide->height, GL_RGB, GL_UNSIGNED_BYTE, data);
			gwbg_TextBuffer_CursorNextLine(ide->text_buffer);
			gwbg_Environment_PushCharToRequest(ide->env, '\n');
			/* Run user request */
			GWBN_Interpreter* interpreter = gwbp_Parse(ide->env->input->buffer);
			if (interpreter != NULL)
			{
				gwbh_Interpreter(ide->env, interpreter);
			}
			/* Clear user request*/
			gwbg_Environment_ClearRequest(ide->env);
			break;
		default:
			//SetData(data);
			gwbg_TextBuffer_PushChar(ide->text_buffer, key);
			gwbg_Environment_PushCharToRequest(ide->env, key);
			break;
	}
}

GWBG_Ide* GWBG_CreateIde()
{
	GWBG_Ide* ide = gwbg_NewIde();
	gwbg_Ide_SetTextBuffer(ide, GWBGS_TEXTBUFFER_LINES, GWBGS_TEXTBUFFER_COLUMNS);
	gwbg_Ide_SetCanvas(ide, GL_RGB);

	ide->env = gwbe_NewEnvironment();

	// setup graphics window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(ide->width, ide->height);
	glutCreateWindow("GWBasic interpreter");
	
	// register callbacks
	glutDisplayFunc(gwbg_Ide_Render);
	glutReshapeFunc(fixedSize);
	glutKeyboardFunc(processNormalKeys);

	return ide;	
}
void GWBG_RunIde()
{
	// enter GLUT event processing cycle
	glutMainLoop();
}
int main(int argc, char **argv) 
{
	
	GWBE_Environment* env;
	
	// init GLUT and create Window
	glutInit(&argc, argv);

	// Create Ide
	ide = GWBG_CreateIde();
	
	// Run Ide
	GWBG_RunIde();

	return 1;

}

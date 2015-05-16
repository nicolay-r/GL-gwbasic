
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

#include "inc/settings.h"
#include "inc/display.h"
#include "inc/runtime.h"

GWBG_Display* display;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw a line
	
	/*glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);
	glEnd();
	*/
	gwbg_Display_Render(display);

        glutSwapBuffers();
}
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
	glutReshapeWindow(display->width, display->height);
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 8: /* Backspace */
			gwbg_TextBuffer_PopChar(display->text_buffer);
			break;
		case 13: /* Enter */
			gwbg_TextBuffer_CursorNextLine(display->text_buffer);	
			break;
		default:
			gwbg_TextBuffer_PushChar(display->text_buffer, key);
			break;
	}
	//printf("%d\n", key);
}

GWBG_Display* GWBG_CreateIde()
{
	GWBG_Display* display = gwbg_NewDisplay();
	gwbg_Display_CreateTextBuffer(display, 20, 40);

	// setup graphics window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(display->width, display->height);
	glutCreateWindow("GWBasic interpreter");
	
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(fixedSize);
	glutKeyboardFunc(processNormalKeys);
	
	return display;	
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
	display = GWBG_CreateIde();
	
	// Run Ide
	GWBG_RunIde();

	return 1;

}

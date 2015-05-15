
#include <GL/glut.h>
#include <string.h>

#include "inc/settings.h"
#include "inc/display.h"

int text_index = 0; 
char text[255];

GWBG_Display* display;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, display->width, 0.0, display->height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.0, 1.0, 0.0); // Green
	
	//draw a line
	glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);
	glEnd();
	
	glRasterPos2i(10, 10); // Text position
	
	void* font = GLUT_BITMAP_9_BY_15;
	
	int i;
	for (i = 0; i < strlen(text); i++)
	{
		glutBitmapCharacter(font, text[i]);
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

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
	text[text_index] = key;
	text_index++;
}

GWBG_Display* GWBG_CreateIde()
{
	GWBG_Display* display = gwbg_NewDisplay();
	gwbg_Display_CreateTextBuffer(display, 200, 80);

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
	// init GLUT and create Window
	glutInit(&argc, argv);

	// Create Ide
	display = GWBG_CreateIde();
	
	// Run Ide
	GWBG_RunIde();

	return 1;

}

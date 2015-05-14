
#include <GL/glut.h>
#include <string.h>

#define WIN_WIDTH 	320
#define WIN_HEIGHT 	240

int text_index = 0; 
char text[255];

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, WIN_WIDTH, 0.0, WIN_HEIGHT);

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
	glutReshapeWindow(WIN_WIDTH, WIN_HEIGHT);
}

void processNormalKeys(unsigned char key, int x, int y)
{
	text[text_index] = key;
	text_index++;
}
int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("GWBasic interpreter");
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(fixedSize);
	glutKeyboardFunc(processNormalKeys);
	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;

}

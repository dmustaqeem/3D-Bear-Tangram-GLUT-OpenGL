#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include "Bear.h"



//Camera Roation Variables  
float theeta = 0;
float xc = 0.0f, zc = 10.0f, yc = 1.0f;
double xcOffset = 0, zcOffset = 0;

//Screen Size Variables 
const int width = 1202;
const int height = 650;

//Variables to Keep the Old Values of Camera Rotation
int oldX = 0, oldY = 0;

//To Start The Camera Movement from Mouse
int camInit = 0;




//Function to set the new values for the camera position after the pressing of keys on keyboard
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {

	case GLUT_KEY_UP:
		yc -= 0.1;
		break;
	case GLUT_KEY_DOWN:
		yc += 0.1;
		break;
	case GLUT_KEY_LEFT:
		theeta -= 0.02f;
		xc = 10 * sin(theeta);
		zc = 10 * cos(theeta);
		break;
	case GLUT_KEY_RIGHT:
		theeta += 0.02f;
		xc = 10 * sin(theeta);
		zc = 10 * cos(theeta);
		break;

	}
}


//Function will key the Right Click as Input to Start/Stop the Camera Movement from Mouse
//int button1, state1;
void cameraHandelingFromMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) {
			if (camInit == 0) {
				camInit = 1;
			}
			else {
				camInit = 0;
			}
		}
	}
}

//Function to update the camera movement variables by motion of Cursor
void cameraMovementFromMouse(int x, int y) {
	if (camInit == 1) {
		int newX, newY;
		newX = (width / 2) - x;
		newY = (height / 2) - y;

		if (newX > oldX)
		{
			theeta -= 0.02f;
			xc = 10 * sin(theeta);
			zc = 10 * cos(theeta);
		}
		if (newX < oldX)
		{
			theeta += 0.02f;
			xc = 10 * sin(theeta);
			zc = 10 * cos(theeta);
		}

		if (newY > oldY)
		{
			yc -= 0.1;
		}
		if (newY < oldY)
		{
			yc += 0.1;
		}


		oldX = newX;
		oldY = newY;
	}
}


void resizableWindow(int w, int h)
{
	if (h == 0) {
		h = 1;
	}
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}



void illumination()
{
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pozitial0[] = { 10.0, 5.0, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(15.0, 10.0, -20.0);
	glutSolidCube(2.0f);
	glPopMatrix();
}

void disp(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	illumination();

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluLookAt(xc + xcOffset, yc, zc + zcOffset, 0, 0, 0, 0, 1, 0);
	drawFigures();
	glutSwapBuffers();

}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}




int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glColor3f(0.3f, 0.7f, 0.9f);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Bear Tangram");
	glutDisplayFunc(disp);
	glutKeyboardFunc(zAxisMovement);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(cameraMovementFromMouse);
	glutMouseFunc(cameraHandelingFromMouse);
	glutReshapeFunc(resizableWindow);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 1;
}
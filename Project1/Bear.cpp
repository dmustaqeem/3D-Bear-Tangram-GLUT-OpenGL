#include <GL/glut.h>
#include<stdio.h>
#include <iostream>

//Variable to keep the record of movement of Object on z_axis
float zoomIn = 1;

void zAxisMovement(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		zoomIn = zoomIn + 0.5;
	}

	if (key == 's')
	{
		zoomIn = zoomIn - 0.5;
	}
	glutPostRedisplay();
}


//Face of the bear

float faceVertices[] = {
	0, 0, 1,
	0.8, 0.3, 1,
	0.5, 1.3, 1,
	
	0, 0, 2,
	0.8, 0.3, 2,
	0.5, 1.3, 2,
};

int faceIndices[] = {
			0,1,2,
			3,4,5
};

int faceEdges[] =
{
	2,5,3,0
};


//Neck Square
float neckVertices[] = {
	0.8, 0.3, 1,
	1.8, 0.6, 1,
	1.5, 1.6, 1,
	0.5, 1.3, 1,

	0.8, 0.3, 2,
	1.8, 0.6, 2,
	1.5, 1.6, 2,
	0.5, 1.3, 2
};

int neckIndices[] = {
			0,1,2,3,
			4,5,6,7,
			4,5,1,0,
			7,6,2,3
};


//Right Triangle next to Neck
float tummyTriangleVertices[] = {
			1.5, 1.6, 1,
			1.98, 0, 1,
			3.5, 0.3, 1,

			1.5, 1.6, 2,
			1.98, 0, 2,
			3.5, 0.3, 2
};

int tummyTriangleIndices[] = {
			0,1,2,
			3,4,5
};

int tummyTriangleEdges[] = {
	0,3,4,1,
	1,4,5,2
};

//BTummyTriangle

float bTummyVertices[] = {
	1.5, 1.6, 1,
	4.2, -0.13, 1,
	3.9, 1.6, 1,

	1.5, 1.6, 2,
	4.2, -0.13, 2,
	3.9, 1.6, 2
};

int bTummyIndices[] = {
			0,1,2,
			3,4,5
};

int bTummyEdges[] = {
	0,3,4,1,
	0,2,5,3
};


//Parallelogram Leg
float leg1Vertices[] =
{
	1.68, -1, 1,
	2.58, -0.9, 1,
	2.68, 0.15, 1,
	1.98, -0.02, 1,

	1.68, -1, 2,
	2.58, -0.9, 2,
	2.68, 0.15, 2,
	1.98, -0.02, 2

};

int leg1Indices[] = {
	0,1,2,3,
	4,5,6,7,
	
	3,7,4,0,
	2,6,5,1,

	4,5,1,0,
	3,7,6,2
};


//Back Side
float backVertices[] = {
	 3.9, 1.6, 1,
	 4.25, -0.6, 1,
	 5.0, 0.65, 1,

	 3.9, 1.6, 2,
	 4.25, -0.6, 2,
	 5.0, 0.65, 2
};

int backIndices[] = {
			0,1,2,
			3,4,5
};

int backEdges[] = {
			1,2,5,4,
			0,3,4,1,
			0,3,5,2
};


//LEG2 Back Side
float leg2Vertices[] = {
	4.0, 0.0, 1,
	3.5, -0.8, 1,
	4.2, -0.7, 1,

	4.0, 0.0, 2,
	3.5, -0.8, 2,
	4.2, -0.7, 2
};
int leg2Indices[] = {
			0,1,2,
			3,4,5
};
int leg2Edges[] = {
			0,3,4,1,
			3,5,2,0,
			5,2,1,4
};



void drawFigures() {

	float material[] = { 1,0,0,0 };

	glPushMatrix();
	glRotatef(-25, 0, 1, 0);
	glTranslatef(-2, 0, zoomIn);

	//Leg1
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormal3f(0, 0, 1);
	glColor3f(1, 1, 0);
	glVertexPointer(3, GL_FLOAT, 0, leg1Vertices);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, leg1Indices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();

	//Back Side
	glPushMatrix();

	glColor3f(1, 0.5, 0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, backVertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, backIndices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	//EDGES
	glPushMatrix();

	glColor3f(1, 0.5, 0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, backVertices);
	glDrawElements(GL_QUADS, 12, GL_UNSIGNED_INT, backEdges);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();


	//B Tummy Vertices
	glPushMatrix();

	glColor3f(0, 0, 1);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, bTummyVertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, bTummyIndices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	//EDGES
	glPushMatrix();

	glColor3f(0, 0, 1);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, bTummyVertices);
	glDrawElements(GL_QUADS, 8, GL_UNSIGNED_INT, bTummyEdges);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	//Tummy Triangle
	glPushMatrix();

	glColor3f(1.0, 0.0, 1.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, tummyTriangleVertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, tummyTriangleIndices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();


	glPushMatrix();

	glColor3f(1.0, 0.0, 1.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, tummyTriangleVertices);
	glDrawElements(GL_QUADS, 8, GL_UNSIGNED_INT, tummyTriangleEdges);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();


	//Bear Face
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, faceVertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, faceIndices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	//Edges
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, faceVertices);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, faceEdges);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();


	//Neck
	glPushMatrix();

	glColor3f(0, 1.0, 0.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glVertexPointer(3, GL_FLOAT, 0, neckVertices);
	glDrawElements(GL_QUADS, 16, GL_UNSIGNED_INT, neckIndices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();


	//Leg 2
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glTranslatef(0.6, 0, 0);
	glVertexPointer(3, GL_FLOAT, 0, leg2Vertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, leg2Indices);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	//Edges
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glTranslatef(0.6, 0, 0);
	glVertexPointer(3, GL_FLOAT, 0, leg2Vertices);
	glDrawElements(GL_QUADS, 12, GL_UNSIGNED_INT, leg2Edges);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	glPopMatrix();
}






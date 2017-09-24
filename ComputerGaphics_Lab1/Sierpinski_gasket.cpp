#define GLUT_DISABLE_ATEXIT_HACK 

#include <stdlib.h>
#include <GL/GLUT.H>
//#include <stdlib.h>

void myinit()
{
	// attributes
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);

	// set up viewing
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}


void display()
{
	GLfloat vertices[3][3] = { { 0.0, 0.0, 0.0 }, { 25.0, 50.0, 0.0 }, { 50.0, 0.0, 0.0 } };
	// an arbitrary triangle in the plane z = 0;
	GLfloat p[3] = { 7.5, 5.0, 0.0 };
	// or set any desired initial point which is inside the triangle;
	int  j, k;
	int  rand();
	glBegin(GL_POINTS);
	for (k = 0; k < 5000; k++)
	{
		/* pick a random vertex from 0, 1, 2*/
		j = rand() % 3;
		// compute new location;
		p[0] = (p[0] + vertices[j][0]) / 2;
		p[1] = (p[1] + vertices[j][1]) / 2;
		// display new point
		glVertex3fv(p);
	}
	glEnd();
	glFlush();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simple OpenGL Example");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	//return 0;
}
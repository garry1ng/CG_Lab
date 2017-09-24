//#define GLUT_DISABLE_ATEXIT_HACK 

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <GL/GLUT.H>
//#include <stdlib.h>

#define MAX_TIME 100001

void myinit()
{
	// attributes
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	// set up viewing
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
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

void draw_DDA(){
	int rc = 1;
	glColor3f(1.0, 0.0, 0.0);
	//glPointSize(2.0f);
	int x_a, y_a, x_b, y_b;
	clock_t start = clock();
	while (rc < MAX_TIME){
		if (rc % 1000 == 0) {
			//glClear(GL_COLOR_BUFFER_BIT);
		}
		x_a = rand() % 2000;
		y_a = rand() % 2000;
		x_b = rand() % 2000;
		y_b = rand() % 2000;
		int dx = abs(x_a - x_b);
		int dy = abs(y_a - y_b);
		int steps = dx >= dy ? dx : dy;
		GLfloat delta_x = (GLfloat) (x_b - x_a) / (GLfloat)steps;
		GLfloat delta_y = (GLfloat) (y_b - y_a) / (GLfloat)steps;
		GLfloat current_x = (GLfloat)x_a;
		GLfloat current_y = (GLfloat)y_a;
		glBegin(GL_POINTS);

		for (int i = 0; i < steps; ++i)
		{
			//glColor3f(1.0, 0.0, 0.0);
			glVertex3f(current_x, current_y, 0.0);
			current_x += delta_x;
			current_y += delta_y;
		}

		//rc+= MAX_TIME;
		rc++;
	}
	glEnd();
	glFlush();
	clock_t end = clock();
	printf("The total time of DDA drawing lines is %.3f ms", (double) end - start / CLK_TCK);

}

void draw_Bresenham(){
	int rc = 0;
	glColor3f(1.0, 0.0, 0.0);
	//glPointSize(2.0f);
	int x_a, y_a, x_b, y_b;
	clock_t start = clock();
	while (rc < MAX_TIME){
		x_a = rand() % 2000;
		y_a = rand() % 2000;
		x_b = rand() % 2000;
		y_b = rand() % 2000;

	}
	clock_t end = clock();
	printf("The total time of Bresenham drawing lines is %.3f ms", (double)end - start / CLK_TCK);

}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simple OpenGL Example");
	//glutDisplayFunc(display);
	glutDisplayFunc(draw_DDA);
	myinit();
	glutMainLoop();
	return 0;
}
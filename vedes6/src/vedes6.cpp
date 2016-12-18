#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <iostream>

#include "point3d.h"
#include "point3dh.h"
#include "lap.h"
#include "compgraph.h"
#include "kocka.h"

const double PI = 3.141592653589;

const int WIDTH = 800;
const int HEIGHT = 600;

GLint keyStates[256];


void keyPressed (unsigned char key, int x, int y) {
	keyStates[key] = 1;
}

void keyUp (unsigned char key, int x, int y) {
	keyStates[key] = 0;
}

GLdouble alpha = PI/6;
GLdouble beta = PI/6;
GLdouble delta = 0.01;

POINT3D cam = POINT3D(5, 0, 0);

void keyOperations ( ) {

	if (keyStates['a']) {cam.x = norm(cam) * cos(delta); cam.y = norm(cam) * sin(delta); delta += 0.01; /*alpha += delta;*/}
	if (keyStates['d']) {cam.x = norm(cam) * cos(delta); cam.y = norm(cam) * sin(delta); delta -= 0.01; /*alpha -= delta;*/}
	if (keyStates['w']) {cam.x = norm(cam) * cos(delta); cam.z = norm(cam) * sin(delta); delta += 0.01;}
	if (keyStates['s']) {cam.x = norm(cam) * cos(delta); cam.z = norm(cam) * sin(delta); delta -= 0.01;}

	glutPostRedisplay( );
}


POINT3D getPoint3D (POINT3DH a){
	POINT3D b = POINT3D((a.x1/a.x4), (a.x2/a.x4), (a.x3/a.x4));
	return b;
}

//kezdeti window az egységnégyzet

POINT3D WinMax = POINT3D(1, 1, 0);
POINT3D WinMin = POINT3D(-1, -1, 0);

//két részre osztjuk az ablakot view1 a bal oldali view2 a jobb oldali

POINT3D View1Max = POINT3D(600, 500, 0);
POINT3D View1Min = POINT3D(200, 100, 0);





void window_to_viewport(POINT3D wmax, POINT3D wmin, POINT3D vmax, POINT3D vmin, double WTV[][4]){

	WTV[0][0] = (vmax.x - vmin.x) / (wmax.x - wmin.x);
	WTV[1][1] = (vmax.y - vmin.y) / (wmax.y - wmin.y);
	WTV[2][2] = 1;
	WTV[3][3] = 1;
	WTV[0][3] = vmin.x - wmin.x * ((vmax.x - vmin.x) / (wmax.x - wmin.x));
	WTV[1][3] = vmin.y - wmin.y * ((vmax.y - vmin.y) / (wmax.y - wmin.y));

}


void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 800.0, 0.0, 600.0);
}


void display(){

	glClear(GL_COLOR_BUFFER_BIT);

	POINT3D up = POINT3D(0, 0, 1);
	POINT3D KP = POINT3D(cam.x, cam.y, cam.z); //(0,0,0)-t vonjuk le belőle
	POINT3D W = vect_norm(KP);
	POINT3D upxW = vectorial_product(up, W);
	POINT3D U = vect_norm(upxW);
	POINT3D WxU = vectorial_product(W, U);
	POINT3D V = vect_norm(WxU);

	//std::cout << WxU.x << " " << WxU.y << " " << WxU.z << std::endl;
	//std::cout << norm(KP) << std::endl;

	GLdouble K[4][4] = {{U.x, U.y, U.z, -(inner_product(cam, U))}, {V.x, V.y, V.z, -(inner_product(cam, V))}, {W.x, W.y, W.z, -(inner_product(cam, W))}, {0, 0, 0, 1}};
	//GLdouble K[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	GLdouble WTV[4][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0},{0, 0, 0}};

	window_to_viewport(WinMax, WinMin, View1Max, View1Min, WTV);

	GLdouble Y[4][4] = {{cos(alpha), 0, sin(alpha), 0},{0, 1, 0, 0}, {-sin(alpha), 0, cos(alpha), 0}, {0, 0, 0, 1}};

	GLdouble Vc[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, -1.0/3, 1}};

	GLdouble temp1[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp2[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble M[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	keyOperations();

	/*mul_matrices(K, Y, temp1);
	mul_matrices(Vc, temp1, temp2);
	mul_matrices(WTV, temp2, M);*/

	mul_matrices(Vc, K, temp1);
	mul_matrices(WTV, temp1, M);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cout << "K[" << i << "][" << j << "] = " << K[i][j] << std::endl; 
		}
	}

	Cube A1 = Cube();
	A1.transformPoints(M);
	A1.draw();
	Cube A2 = Cube(0, 0, 2);
	Cube A3 = Cube(0, 0, -2);
	Cube A4 = Cube(0, 2, 0);
	Cube A5 = Cube(0, -2, 0);
	Cube A6 = Cube(2, 0, 0);
	A6.transformPoints(M);
	A6.draw();

	Cube A7 = Cube(-2, 0, 0);
	A7.transformPoints(M);
	A7.draw();

	A2.transformPoints(M);
	A3.transformPoints(M);
	A4.transformPoints(M);
	A5.transformPoints(M);
	
	A2.draw();
	A3.draw();
	A4.draw();
	A5.draw();
	
	

	glutSwapBuffers();

}


int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutCreateWindow ("Hatodik vedes");
	init ( );
	glutDisplayFunc (display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop ( );

	return 0;
}
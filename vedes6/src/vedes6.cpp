#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

#include "point3d.h"
#include "point3dh.h"
#include "lap.h"
#include "compgraph.h"
#include "kocka.h"


const int WIDTH = 800;
const int HEIGHT = 600;

GLint keyStates[256];


void keyPressed (unsigned char key, int x, int y) {
	keyStates[key] = 1;
}

void keyUp (unsigned char key, int x, int y) {
	keyStates[key] = 0;
}

GLdouble alpha = 0.0;
GLdouble delta = 0.0;

GLdouble camRad = 5;
POINT3D cam;
GLdouble s = 3;
POINT3D centrum = POINT3D(0, 0, s);
POINT3D origo = POINT3D(0, 0, 0);


void keyOperations ( ) {

	if (keyStates['q'] && camRad > 3) {camRad -= 0.1;}
	if (keyStates['e'] && camRad < 6) {camRad += 0.1;}
	if (keyStates['a']) { delta -= 0.01;}
	if (keyStates['d']) { delta += 0.01;}
	if (keyStates['w'] && alpha < 10) {alpha += 0.1;}
	if (keyStates['s'] && alpha > -10) {alpha -= 0.1;}

	glutPostRedisplay( );
}


POINT3D WinMax = POINT3D(1, 1, 0);
POINT3D WinMin = POINT3D(-1, -1, 0);

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

void placeCam(){
	cam = POINT3D(camRad, 0, 0);
	cam.x = camRad * cos(delta); cam.y = camRad * sin(delta);
	cam.x = camRad * cos(delta); cam.y = camRad * sin(delta);
	cam.z += alpha;
}

bool compare(Lap a, Lap b){
	return (a.camDist() > b.camDist());
}

bool isnotVisible(Lap a){
	GLdouble ip;
	ip = inner_product((a.getNormalVector()), (makeVect(centrum, a.getWeight())));
	return (ip < 0);
}


void display(){

	glClear(GL_COLOR_BUFFER_BIT);

	placeCam();

	POINT3D up = POINT3D(0, 0, 1);
	POINT3D PK = POINT3D(-(origo.x - cam.x), -(origo.y - cam.y), -(origo.z - cam.z));
	POINT3D W = vect_norm(PK);
	POINT3D upxW = vectorial_product(up, W);
	POINT3D U = vect_norm(upxW);
	POINT3D WxU = vectorial_product(W, U);
	POINT3D V = vect_norm(WxU);

	GLdouble K[4][4] = {{U.x, U.y, U.z, -(inner_product(cam, U))}, {V.x, V.y, V.z, -(inner_product(cam, V))}, {W.x, W.y, W.z, -(inner_product(cam, W))}, {0, 0, 0, 1}};
	GLdouble WTV[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},{0, 0, 0, 0}};

	window_to_viewport(WinMax, WinMin, View1Max, View1Min, WTV);

	GLdouble Vc[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, -1.0/s, 1}};
	GLdouble M[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	
	Cube A1 = Cube(0.5, 0.5, 0.5);
	Cube A2 = Cube(0, 0, 2, 0, 1, 0);
	Cube A3 = Cube(0, 0, -2, 1, 0, 0);
	Cube A4 = Cube(0, 2, 0, 1, 1, 0);
	Cube A5 = Cube(0, -2, 0, 1, 0, 1);
	Cube A6 = Cube(2, 0, 0, 0, 1, 1);
	Cube A7 = Cube(-2, 0, 0, 0, 0, 1);

	mul_matrices(WTV, Vc, M);

	keyOperations();

	A1.transformPoints(K);
	A2.transformPoints(K);
	A3.transformPoints(K);
	A4.transformPoints(K);
	A5.transformPoints(K);
	A6.transformPoints(K);
	A7.transformPoints(K);


	std::vector<Lap> mindenlap;

	for(size_t i = 0; i < A1.lapok.size(); i++){
		mindenlap.push_back(A1.lapok[i]);
	}
	for(size_t i = 0; i < A2.lapok.size(); i++){
		mindenlap.push_back(A2.lapok[i]);
	}
	for(size_t i = 0; i < A3.lapok.size(); i++){
		mindenlap.push_back(A3.lapok[i]);
	}
	for(size_t i = 0; i < A4.lapok.size(); i++){
		mindenlap.push_back(A4.lapok[i]);
	}
	for(size_t i = 0; i < A5.lapok.size(); i++){
		mindenlap.push_back(A5.lapok[i]);
	}
	for(size_t i = 0; i < A6.lapok.size(); i++){
		mindenlap.push_back(A6.lapok[i]);
	}
	for(size_t i = 0; i < A7.lapok.size(); i++){
		mindenlap.push_back(A7.lapok[i]);
	}


	for(auto it = mindenlap.begin(); it != mindenlap.end();){

		if(isnotVisible((*it))){
			it = mindenlap.erase(it);
		} else {
			it++;
		}

	}


	std::sort(mindenlap.begin(), mindenlap.end(), compare);

	for(auto it = mindenlap.begin(); it != mindenlap.end(); it++){
		(*it).C0.trsf(M);
		(*it).C1.trsf(M);
		(*it).C2.trsf(M);
		(*it).C3.trsf(M);
		(*it).draw();
	}

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
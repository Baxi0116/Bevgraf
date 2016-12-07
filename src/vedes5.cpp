#include <GL/glut.h>
#include <math.h>

const int WIDTH = 800;
const int HEIGHT = 600;

GLint keyStates[256];

class POINT3D {

public:

	POINT3D(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	POINT3D(GLdouble x, GLdouble y, GLdouble z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void init(GLdouble x, GLdouble y, GLdouble z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	GLdouble x, y, z;
};

class POINT3DH {

public:

	POINT3DH(){
		this->x1 = 0;
		this->x2 = 0;
		this->x3 = 0;
		this->x4 = 1;
	}

	POINT3DH(GLdouble x, GLdouble y, GLdouble z){
		this->x1 = x;
		this->x2 = y;
		this->x3 = z;
		this->x4 = 1;
	}

	void init(GLdouble x, GLdouble y, GLdouble z){
		this->x1 = x;
		this->x2 = y;
		this->x3 = z;
		this->x4 = 1;
	}

	GLdouble x1, x2, x3, x4;
};


POINT3D getPoint3D (POINT3DH a){
	POINT3D b = POINT3D((a.x1/a.x4), (a.x2/a.x4), (a.x3/a.x4));
	return b;
}


class Cube{
public:

	Cube(){
		C0 = POINT3DH(0.5, 0.5, -0.5);
		C1 = POINT3DH(-0.5, 0.5, -0.5);
		C2 = POINT3DH(-0.5, -0.5, -0.5);
		C3 = POINT3DH(0.5, -0.5, -0.5);
		C4 = POINT3DH(0.5, 0.5, 0.5);
		C5 = POINT3DH(-0.5, 0.5, 0.5);
		C6 = POINT3DH(-0.5, -0.5, 0.5);
		C7 = POINT3DH(0.5, -0.5, 0.5);
	}

	void draw(){
		   glColor3f(0.0, 0.0, 1.0);
		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C0).x, getPoint3D(C0).y);
		   	   glVertex2f(getPoint3D(C1).x, getPoint3D(C1).y);
		   	   glVertex2f(getPoint3D(C2).x, getPoint3D(C2).y);
		   	   glVertex2f(getPoint3D(C3).x, getPoint3D(C3).y);
		   glEnd();

		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C0).x, getPoint3D(C0).y);
		   	   glVertex2f(getPoint3D(C1).x, getPoint3D(C1).y);
		   	   glVertex2f(getPoint3D(C5).x, getPoint3D(C5).y);
		   	   glVertex2f(getPoint3D(C4).x, getPoint3D(C4).y);
		   glEnd();

		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C0).x, getPoint3D(C0).y);
		   	   glVertex2f(getPoint3D(C4).x, getPoint3D(C4).y);
		   	   glVertex2f(getPoint3D(C7).x, getPoint3D(C7).y);
		   	   glVertex2f(getPoint3D(C3).x, getPoint3D(C3).y);
		   glEnd();

		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C3).x, getPoint3D(C3).y);
		   	   glVertex2f(getPoint3D(C7).x, getPoint3D(C7).y);
		   	   glVertex2f(getPoint3D(C6).x, getPoint3D(C6).y);
		   	   glVertex2f(getPoint3D(C2).x, getPoint3D(C2).y);
		   glEnd();

		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C4).x, getPoint3D(C4).y);
		   	   glVertex2f(getPoint3D(C5).x, getPoint3D(C5).y);
		   	   glVertex2f(getPoint3D(C6).x, getPoint3D(C6).y);
		   	   glVertex2f(getPoint3D(C7).x, getPoint3D(C7).y);
		   glEnd();

		   glBegin(GL_LINE_LOOP);
		   	   glVertex2f(getPoint3D(C1).x, getPoint3D(C1).y);
		   	   glVertex2f(getPoint3D(C2).x, getPoint3D(C2).y);
		   	   glVertex2f(getPoint3D(C6).x, getPoint3D(C6).y);
		   	   glVertex2f(getPoint3D(C5).x, getPoint3D(C5).y);
		   glEnd();

	}

	POINT3DH C0, C1, C2, C3, C4, C5, C6, C7;

};

//kezdeti window az egységnégyzet

POINT3D WinMax = POINT3D(1, 1, 0);
POINT3D WinMin = POINT3D(-1, -1, 0);

//két részre osztjuk az ablakot view1 a bal oldali view2 a jobb oldali

POINT3D View1Max =POINT3D(400, 600, 0);
POINT3D View1Min =POINT3D(0, 0, 0);
POINT3D View2Max =POINT3D(400, 0, 0);
POINT3D View2Min =POINT3D(800, 600, 0);


void keyPressed (unsigned char key, int x, int y) {
	keyStates[key] = 1;
}


void keyUp (unsigned char key, int x, int y) {
	keyStates[key] = 0;
}


void keyOperations ( ) {
	if (keyStates['q']) {}
	if (keyStates['e']) {}
	if (keyStates['a']) {}
	if (keyStates['d']) {}
	if (keyStates['y']) {}
	if (keyStates['c']) {}

	glutPostRedisplay( );
}


GLdouble alpha = M_PI/6;
GLdouble beta = M_PI/7;

GLdouble S[4][4] = {{150, 0, 0, 0},{0, 150, 0, 0}, {0, 0, 150, 0}, {0, 0, 0, 1}};
GLdouble Y[4][4] = {{cos(alpha), 0, sin(alpha), 0},{0, 1, 0, 0}, {-sin(alpha), 0, cos(alpha), 0}, {0, 0, 0, 1}};
GLdouble X[4][4] = {{1, 0, 0, 0},{0, cos(beta), -sin(beta), 0}, {0, sin(beta), cos(beta), 0}, {0, 0, 0, 1}};
GLdouble T[4][4] = {{1, 0, 0, 400},{0, 1, 0, 300}, {0, 0, 1, 0}, {0, 0, 0, 1}};
GLdouble Vc[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, -1.0/300, 1}};
GLdouble Vm[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};
GLdouble WTV[4][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};


void window_to_viewport(POINT3D wmax, POINT3D wmin, POINT3D vmax, POINT3D vmin){

	WTV[0][0] = (vmax.x - vmin.x) / (wmax.x - wmin.x);
	WTV[1][1] = (vmax.y - vmin.y) / (wmax.y - wmin.y);
	WTV[2][2] = 1;
	WTV[3][3] = 1;
	WTV[0][3] = (vmin.x - wmin.x) * ((vmax.x - vmin.x) / (wmax.x - wmin.x));
	WTV[1][3] = (vmin.x - wmin.x) * ((vmax.y - vmin.y) / (wmax.y - wmin.y));

}


void mul_matrices( double A[ ][ 4 ], double B[ ][ 4 ], double C[ ][ 4 ] )
{
	int i, j, k;
	float sum;
	for( i = 0; i < 4; i++ )
		for( j = 0; j < 4; j++ ) {
			sum = 0;
			for( k = 0; k < 4; k++ )
				sum = sum + A[ i ][ k ] * B[ k ][ j ];
			C[ i ][ j ] = sum;
		}
}


POINT3DH transzf(GLdouble m[][4], POINT3DH p){
	POINT3DH q = POINT3DH(0, 0, 0);
	q.x1 = m[0][0] * p.x1 + m[0][1] * p.x2 + m[0][2] * p.x3 + m[0][3] * p.x4;
	q.x2 = m[1][0] * p.x1 + m[1][1] * p.x2 + m[1][2] * p.x3 + m[1][3] * p.x4;
	q.x3 = m[2][0] * p.x1 + m[2][1] * p.x2 + m[2][2] * p.x3 + m[2][3] * p.x4;
	q.x4 = m[3][0] * p.x1 + m[3][1] * p.x2 + m[3][2] * p.x3 + m[3][3] * p.x4;
	return q;
}


void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 800.0, 0.0, 600.0);
	glShadeModel( GL_FLAT );
}


void display(){

	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

}


int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutCreateWindow ("Ötödik vedes");
	init ( );
	glutDisplayFunc (display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	//glutTimerFunc( 5, update, 0 );
	glutMainLoop ( );

	return 0;
}

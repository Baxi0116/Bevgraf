#include <GL/glut.h>
#include <math.h>
#include <vector>


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


GLdouble alpha1 = PI/6;
GLdouble alpha2 = PI/6;
GLdouble alpha3 = PI/6;
GLdouble beta = PI/6;
GLdouble forg = 0.01;


void keyOperations ( ) {
	if (keyStates['q']) {alpha1 -= forg;}
	if (keyStates['e']) {alpha1 += forg;}
	if (keyStates['a']) {alpha2 -= forg;}
	if (keyStates['d']) {alpha2 += forg;}
	if (keyStates['y']) {alpha3 -= forg;}
	if (keyStates['c']) {alpha3 += forg;}
	if (keyStates['r']) {
		alpha1 = PI/6;
		alpha2 = PI/6;
		alpha3 = PI/6;
	}

	glutPostRedisplay( );
}

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

	POINT3D& operator=(const POINT3D& c){
		this->x = c.x;
		this->y = c.y;
		this->z = c.z;
		return *this;
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

	POINT3DH& operator=(const POINT3DH& c){
		this->x1 = c.x1;
		this->x2 = c.x2;
		this->x3 = c.x3;
		this->x4 = c.x4;
		return *this;
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
		//felső lap
		C0 = POINT3DH(0.5, 0.5, 0.5);
		C1 = POINT3DH(-0.5, 0.5, 0.5);
		C2 = POINT3DH(-0.5, 0.5, -0.5);
		C3 = POINT3DH(0.5, 0.5, -0.5);
		//felső tégla alja
		C4 = POINT3DH(0.5, 0.5*1/3.0, 0.5);
		C5 = POINT3DH(-0.5, 0.5*1/3.0, 0.5);
		C6 = POINT3DH(-0.5, 0.5*1/3.0, -0.5);
		C7 = POINT3DH(0.5, 0.5*1/3.0, -0.5);
		//középső tégla teteje
		C8 = POINT3DH(0.5, 0.5*1/3.0, 0.5);
		C9 = POINT3DH(-0.5, 0.5*1/3.0, 0.5);
		C10 = POINT3DH(-0.5, 0.5*1/3.0, -0.5);
		C11 = POINT3DH(0.5, 0.5*1/3.0, -0.5);
		//középső tégla alja
		C12 = POINT3DH(0.5, -0.5*1/3.0, 0.5);
		C13 = POINT3DH(-0.5, -0.5*1/3.0, 0.5);
		C14 = POINT3DH(-0.5, -0.5*1/3.0, -0.5);
		C15 = POINT3DH(0.5, -0.5*1/3.0, -0.5);
		//alsó tégla teteje
		C16 = POINT3DH(0.5, -0.5*1/3.0, 0.5);
		C17 = POINT3DH(-0.5, -0.5*1/3.0, 0.5);
		C18 = POINT3DH(-0.5, -0.5*1/3.0, -0.5);
		C19 = POINT3DH(0.5, -0.5*1/3.0, -0.5);
		//alsó lap
		C20 = POINT3DH(0.5, -0.5, 0.5);
		C21 = POINT3DH(-0.5, -0.5, 0.5);
		C22 = POINT3DH(-0.5, -0.5, -0.5);
		C23 = POINT3DH(0.5, -0.5, -0.5);

		pointsTop.push_back(C0);
		pointsTop.push_back(C1);
		pointsTop.push_back(C2);
		pointsTop.push_back(C3);
		pointsTop.push_back(C4);
		pointsTop.push_back(C5);
		pointsTop.push_back(C6);
		pointsTop.push_back(C7);

		pointsMid.push_back(C8);
		pointsMid.push_back(C9);
		pointsMid.push_back(C10);
		pointsMid.push_back(C11);
		pointsMid.push_back(C12);
		pointsMid.push_back(C13);
		pointsMid.push_back(C14);
		pointsMid.push_back(C15);

		pointsBot.push_back(C16);
		pointsBot.push_back(C17);
		pointsBot.push_back(C18);
		pointsBot.push_back(C19);
		pointsBot.push_back(C20);
		pointsBot.push_back(C21);
		pointsBot.push_back(C22);
		pointsBot.push_back(C23);
	}

	void draw(){

		keyOperations();
		
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2d(getPoint3D(pointsTop[2]).x, getPoint3D(pointsTop[2]).y);
		glVertex2d(getPoint3D(pointsTop[3]).x, getPoint3D(pointsTop[3]).y);
		glVertex2d(getPoint3D(pointsTop[0]).x, getPoint3D(pointsTop[0]).y);
		glVertex2d(getPoint3D(pointsTop[1]).x, getPoint3D(pointsTop[1]).y);
		glVertex2d(getPoint3D(pointsTop[2]).x, getPoint3D(pointsTop[2]).y);
		glVertex2d(getPoint3D(pointsTop[6]).x, getPoint3D(pointsTop[6]).y);
		glVertex2d(getPoint3D(pointsTop[7]).x, getPoint3D(pointsTop[7]).y);
		glVertex2d(getPoint3D(pointsTop[4]).x, getPoint3D(pointsTop[4]).y);
		glVertex2d(getPoint3D(pointsTop[5]).x, getPoint3D(pointsTop[5]).y);
		glVertex2d(getPoint3D(pointsTop[6]).x, getPoint3D(pointsTop[6]).y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2d(getPoint3D(pointsTop[1]).x, getPoint3D(pointsTop[1]).y);
		glVertex2d(getPoint3D(pointsTop[5]).x, getPoint3D(pointsTop[5]).y);
		glVertex2d(getPoint3D(pointsTop[0]).x, getPoint3D(pointsTop[0]).y);
		glVertex2d(getPoint3D(pointsTop[4]).x, getPoint3D(pointsTop[4]).y);
		glVertex2d(getPoint3D(pointsTop[3]).x, getPoint3D(pointsTop[3]).y);
		glVertex2d(getPoint3D(pointsTop[7]).x, getPoint3D(pointsTop[7]).y);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2d(getPoint3D(pointsMid[2]).x, getPoint3D(pointsMid[2]).y);
		glVertex2d(getPoint3D(pointsMid[3]).x, getPoint3D(pointsMid[3]).y);
		glVertex2d(getPoint3D(pointsMid[0]).x, getPoint3D(pointsMid[0]).y);
		glVertex2d(getPoint3D(pointsMid[1]).x, getPoint3D(pointsMid[1]).y);
		glVertex2d(getPoint3D(pointsMid[2]).x, getPoint3D(pointsMid[2]).y);
		glVertex2d(getPoint3D(pointsMid[6]).x, getPoint3D(pointsMid[6]).y);
		glVertex2d(getPoint3D(pointsMid[7]).x, getPoint3D(pointsMid[7]).y);
		glVertex2d(getPoint3D(pointsMid[4]).x, getPoint3D(pointsMid[4]).y);
		glVertex2d(getPoint3D(pointsMid[5]).x, getPoint3D(pointsMid[5]).y);
		glVertex2d(getPoint3D(pointsMid[6]).x, getPoint3D(pointsMid[6]).y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2d(getPoint3D(pointsMid[1]).x, getPoint3D(pointsMid[1]).y);
		glVertex2d(getPoint3D(pointsMid[5]).x, getPoint3D(pointsMid[5]).y);
		glVertex2d(getPoint3D(pointsMid[0]).x, getPoint3D(pointsMid[0]).y);
		glVertex2d(getPoint3D(pointsMid[4]).x, getPoint3D(pointsMid[4]).y);
		glVertex2d(getPoint3D(pointsMid[3]).x, getPoint3D(pointsMid[3]).y);
		glVertex2d(getPoint3D(pointsMid[7]).x, getPoint3D(pointsMid[7]).y);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2d(getPoint3D(pointsBot[2]).x, getPoint3D(pointsBot[2]).y);
		glVertex2d(getPoint3D(pointsBot[3]).x, getPoint3D(pointsBot[3]).y);
		glVertex2d(getPoint3D(pointsBot[0]).x, getPoint3D(pointsBot[0]).y);
		glVertex2d(getPoint3D(pointsBot[1]).x, getPoint3D(pointsBot[1]).y);
		glVertex2d(getPoint3D(pointsBot[2]).x, getPoint3D(pointsBot[2]).y);
		glVertex2d(getPoint3D(pointsBot[6]).x, getPoint3D(pointsBot[6]).y);
		glVertex2d(getPoint3D(pointsBot[7]).x, getPoint3D(pointsBot[7]).y);
		glVertex2d(getPoint3D(pointsBot[4]).x, getPoint3D(pointsBot[4]).y);
		glVertex2d(getPoint3D(pointsBot[5]).x, getPoint3D(pointsBot[5]).y);
		glVertex2d(getPoint3D(pointsBot[6]).x, getPoint3D(pointsBot[6]).y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2d(getPoint3D(pointsBot[1]).x, getPoint3D(pointsBot[1]).y);
		glVertex2d(getPoint3D(pointsBot[5]).x, getPoint3D(pointsBot[5]).y);
		glVertex2d(getPoint3D(pointsBot[0]).x, getPoint3D(pointsBot[0]).y);
		glVertex2d(getPoint3D(pointsBot[4]).x, getPoint3D(pointsBot[4]).y);
		glVertex2d(getPoint3D(pointsBot[3]).x, getPoint3D(pointsBot[3]).y);
		glVertex2d(getPoint3D(pointsBot[7]).x, getPoint3D(pointsBot[7]).y);
		glEnd();

	}


	void transformTopPoints(double m[][4]){
		POINT3DH q = POINT3DH(0, 0, 0);

		for(auto it = pointsTop.begin(); it != pointsTop.end(); it++){
			q.x1 = m[0][0] * (*it).x1 + m[0][1] * (*it).x2 + m[0][2] * (*it).x3 + m[0][3] * (*it).x4;
			q.x2 = m[1][0] * (*it).x1 + m[1][1] * (*it).x2 + m[1][2] * (*it).x3 + m[1][3] * (*it).x4;
			q.x3 = m[2][0] * (*it).x1 + m[2][1] * (*it).x2 + m[2][2] * (*it).x3 + m[2][3] * (*it).x4;
			q.x4 = m[3][0] * (*it).x1 + m[3][1] * (*it).x2 + m[3][2] * (*it).x3 + m[3][3] * (*it).x4;
			(*it) = q;
		}
	}


	void transformMidPoints(double m[][4]){POINT3DH q = POINT3DH(0, 0, 0);

		for(auto it = pointsMid.begin(); it != pointsMid.end(); it++){
			q.x1 = m[0][0] * (*it).x1 + m[0][1] * (*it).x2 + m[0][2] * (*it).x3 + m[0][3] * (*it).x4;
			q.x2 = m[1][0] * (*it).x1 + m[1][1] * (*it).x2 + m[1][2] * (*it).x3 + m[1][3] * (*it).x4;
			q.x3 = m[2][0] * (*it).x1 + m[2][1] * (*it).x2 + m[2][2] * (*it).x3 + m[2][3] * (*it).x4;
			q.x4 = m[3][0] * (*it).x1 + m[3][1] * (*it).x2 + m[3][2] * (*it).x3 + m[3][3] * (*it).x4;
			(*it) = q;
		}
	}


	void transformBotPoints(double m[][4]){
		POINT3DH q = POINT3DH(0, 0, 0);

		for(auto it = pointsBot.begin(); it != pointsBot.end(); it++){
			q.x1 = m[0][0] * (*it).x1 + m[0][1] * (*it).x2 + m[0][2] * (*it).x3 + m[0][3] * (*it).x4;
			q.x2 = m[1][0] * (*it).x1 + m[1][1] * (*it).x2 + m[1][2] * (*it).x3 + m[1][3] * (*it).x4;
			q.x3 = m[2][0] * (*it).x1 + m[2][1] * (*it).x2 + m[2][2] * (*it).x3 + m[2][3] * (*it).x4;
			q.x4 = m[3][0] * (*it).x1 + m[3][1] * (*it).x2 + m[3][2] * (*it).x3 + m[3][3] * (*it).x4;
			(*it) = q;
		}
	}

	POINT3DH C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19, C20, C21, C22, C23;

	std::vector<POINT3DH> pointsTop;
	std::vector<POINT3DH> pointsMid;
	std::vector<POINT3DH> pointsBot;

};

//kezdeti window az egységnégyzet

POINT3D WinMax = POINT3D(1, 1, 0);
POINT3D WinMin = POINT3D(-1, -1, 0);

//két részre osztjuk az ablakot view1 a bal oldali view2 a jobb oldali

POINT3D View1Max = POINT3D(400, 500, 0);
POINT3D View1Min = POINT3D(0, 100, 0);
POINT3D View2Max = POINT3D(800, 500, 0);
POINT3D View2Min = POINT3D(400, 100, 0);

void window_to_viewport(POINT3D wmax, POINT3D wmin, POINT3D vmax, POINT3D vmin, double WTV[][4]){

	WTV[0][0] = (vmax.x - vmin.x) / (wmax.x - wmin.x);
	WTV[1][1] = (vmax.y - vmin.y) / (wmax.y - wmin.y);
	WTV[2][2] = 1;
	WTV[3][3] = 1;
	WTV[0][3] = vmin.x - wmin.x * ((vmax.x - vmin.x) / (wmax.x - wmin.x));
	WTV[1][3] = vmin.y - wmin.y * ((vmax.y - vmin.y) / (wmax.y - wmin.y));

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


void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 800.0, 0.0, 600.0);
}

std::vector<Cube> cubes;


void display(){

	//keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);

	GLdouble WTV1[4][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0},{0, 0, 0}};
	GLdouble WTV2[4][4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	window_to_viewport(WinMax, WinMin, View1Max, View1Min, WTV1);
	window_to_viewport(WinMax, WinMin, View2Max, View2Min, WTV2);

	GLdouble Y1[4][4] = {{cos(alpha1), 0, sin(alpha1), 0},{0, 1, 0, 0}, {-sin(alpha1), 0, cos(alpha1), 0}, {0, 0, 0, 1}};
	GLdouble Y2[4][4] = {{cos(alpha2), 0, sin(alpha2), 0},{0, 1, 0, 0}, {-sin(alpha2), 0, cos(alpha2), 0}, {0, 0, 0, 1}};
	GLdouble Y3[4][4] = {{cos(alpha3), 0, sin(alpha3), 0},{0, 1, 0, 0}, {-sin(alpha3), 0, cos(alpha3), 0}, {0, 0, 0, 1}};
	GLdouble X[4][4] = {{1, 0, 0, 0},{0, cos(beta), -sin(beta), 0}, {0, sin(beta), cos(beta), 0}, {0, 0, 0, 1}};
	GLdouble Vc[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, -1.0/3, 1}};
	GLdouble Vm[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};

	GLdouble temp1[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp2[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble temp3[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp4[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble temp5[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp6[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble temp7[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp8[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble temp9[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp10[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble temp11[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble temp12[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	GLdouble M1[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble M2[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble M3[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble M4[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble M5[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	GLdouble M6[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};


	mul_matrices(X, Y1, temp1);
	mul_matrices(Vm, temp1, temp2);
	mul_matrices(WTV1, temp2, M1);

	mul_matrices(X, Y2, temp3);
	mul_matrices(Vm, temp3, temp4);
	mul_matrices(WTV1, temp4, M2);

	mul_matrices(X, Y3, temp5);
	mul_matrices(Vm, temp5, temp6);
	mul_matrices(WTV1, temp6, M3);

	mul_matrices(X, Y1, temp7);
	mul_matrices(Vc, temp7, temp8);
	mul_matrices(WTV2, temp8, M4);

	mul_matrices(X, Y2, temp9);
	mul_matrices(Vc, temp9, temp10);
	mul_matrices(WTV2, temp10, M5);

	mul_matrices(X, Y3, temp11);
	mul_matrices(Vc, temp11, temp12);
	mul_matrices(WTV2, temp12, M6);


	Cube A = Cube();
	Cube B = Cube();

	A.transformTopPoints(M1);
	A.transformMidPoints(M2);
	A.transformBotPoints(M3);
	A.draw();

	B.transformTopPoints(M4);
	B.transformMidPoints(M5);
	B.transformBotPoints(M6);
	B.draw();

	glutSwapBuffers();

}


int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutCreateWindow ("Ötödik vedes");
	init ( );
	glutDisplayFunc (display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop ( );

	return 0;
}
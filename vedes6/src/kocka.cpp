#include "kocka.h"


Cube::Cube(){
	//felső lap
		C0 = POINT3DH(0.5, 0.5, 0.5);
		C1 = POINT3DH(-0.5, 0.5, 0.5);
		C2 = POINT3DH(-0.5, 0.5, -0.5);
		C3 = POINT3DH(0.5, 0.5, -0.5);
		//alsó lap
		C4 = POINT3DH(0.5, -0.5, 0.5);
		C5 = POINT3DH(-0.5, -0.5, 0.5);
		C6 = POINT3DH(-0.5, -0.5, -0.5);
		C7 = POINT3DH(0.5, -0.5, -0.5);

		points.push_back(C0);
		points.push_back(C1);
		points.push_back(C2);
		points.push_back(C3);
		points.push_back(C4);
		points.push_back(C5);
		points.push_back(C6);
		points.push_back(C7);
}


Cube::Cube(GLdouble x, GLdouble y, GLdouble z){
	//felső lap
		C0 = POINT3DH(0.5+x, 0.5+y, 0.5+z);
		C1 = POINT3DH(-0.5+x, 0.5+y, 0.5+z);
		C2 = POINT3DH(-0.5+x, 0.5+y, -0.5+z);
		C3 = POINT3DH(0.5+x, 0.5+y, -0.5+z);
		//alsó lap
		C4 = POINT3DH(0.5+x, -0.5+y, 0.5+z);
		C5 = POINT3DH(-0.5+x, -0.5+y, 0.5+z);
		C6 = POINT3DH(-0.5+x, -0.5+y, -0.5+z);
		C7 = POINT3DH(0.5+x, -0.5+y, -0.5+z);

		points.push_back(C0);
		points.push_back(C1);
		points.push_back(C2);
		points.push_back(C3);
		points.push_back(C4);
		points.push_back(C5);
		points.push_back(C6);
		points.push_back(C7);
}

void Cube::draw(){
	glColor3f(0.0, 0.0, 0.5);
		glBegin(GL_POLYGON);
		glVertex2f((points[0].getPoint3D()).x, (points[0].getPoint3D()).y);
		glVertex2f((points[1].getPoint3D()).x, (points[1].getPoint3D()).y);
		glVertex2f((points[2].getPoint3D()).x, (points[2].getPoint3D()).y);
		glVertex2f((points[3].getPoint3D()).x, (points[3].getPoint3D()).y);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f((points[0].getPoint3D()).x, (points[0].getPoint3D()).y);
		glVertex2f((points[1].getPoint3D()).x, (points[1].getPoint3D()).y);
		glVertex2f((points[5].getPoint3D()).x, (points[5].getPoint3D()).y);
		glVertex2f((points[4].getPoint3D()).x, (points[4].getPoint3D()).y);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f((points[0].getPoint3D()).x, (points[0].getPoint3D()).y);
		glVertex2f((points[4].getPoint3D()).x, (points[4].getPoint3D()).y);
		glVertex2f((points[7].getPoint3D()).x, (points[7].getPoint3D()).y);
		glVertex2f((points[3].getPoint3D()).x, (points[3].getPoint3D()).y);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f((points[3].getPoint3D()).x, (points[3].getPoint3D()).y);
		glVertex2f((points[7].getPoint3D()).x, (points[7].getPoint3D()).y);
		glVertex2f((points[6].getPoint3D()).x, (points[6].getPoint3D()).y);
		glVertex2f((points[2].getPoint3D()).x, (points[2].getPoint3D()).y);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f((points[4].getPoint3D()).x, (points[4].getPoint3D()).y);
		glVertex2f((points[5].getPoint3D()).x, (points[5].getPoint3D()).y);
		glVertex2f((points[6].getPoint3D()).x, (points[6].getPoint3D()).y);
		glVertex2f((points[7].getPoint3D()).x, (points[7].getPoint3D()).y);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f((points[1].getPoint3D()).x, (points[1].getPoint3D()).y);
		glVertex2f((points[2].getPoint3D()).x, (points[2].getPoint3D()).y);
		glVertex2f((points[6].getPoint3D()).x, (points[6].getPoint3D()).y);
		glVertex2f((points[5].getPoint3D()).x, (points[5].getPoint3D()).y);
		glEnd();


		/*
		 *http://math.stackexchange.com/questions/253253/tracing-the-edges-of-a-cube-with-the-minimum-pencil-lifts
		 */
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(5);
		glBegin(GL_LINE_LOOP);
		glVertex2d((points[2].getPoint3D()).x, (points[2].getPoint3D()).y);
		glVertex2d((points[3].getPoint3D()).x, (points[3].getPoint3D()).y);
		glVertex2d((points[0].getPoint3D()).x, (points[0].getPoint3D()).y);
		glVertex2d((points[1].getPoint3D()).x, (points[1].getPoint3D()).y);
		glVertex2d((points[2].getPoint3D()).x, (points[2].getPoint3D()).y);
		glVertex2d((points[6].getPoint3D()).x, (points[6].getPoint3D()).y);
		glVertex2d((points[7].getPoint3D()).x, (points[7].getPoint3D()).y);
		glVertex2d((points[4].getPoint3D()).x, (points[4].getPoint3D()).y);
		glVertex2d((points[5].getPoint3D()).x, (points[5].getPoint3D()).y);
		glVertex2d((points[6].getPoint3D()).x, (points[6].getPoint3D()).y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2d((points[1].getPoint3D()).x, (points[1].getPoint3D()).y);
		glVertex2d((points[5].getPoint3D()).x, (points[5].getPoint3D()).y);
		glVertex2d((points[0].getPoint3D()).x, (points[0].getPoint3D()).y);
		glVertex2d((points[4].getPoint3D()).x, (points[4].getPoint3D()).y);
		glVertex2d((points[3].getPoint3D()).x, (points[3].getPoint3D()).y);
		glVertex2d((points[7].getPoint3D()).x, (points[7].getPoint3D()).y);
		glEnd();	
}


void Cube::transformPoints(double m[][4]){
		POINT3DH q = POINT3DH(0, 0, 0);

		for(auto it = points.begin(); it != points.end(); it++){
			q.x1 = m[0][0] * (*it).x1 + m[0][1] * (*it).x2 + m[0][2] * (*it).x3 + m[0][3] * (*it).x4;
			q.x2 = m[1][0] * (*it).x1 + m[1][1] * (*it).x2 + m[1][2] * (*it).x3 + m[1][3] * (*it).x4;
			q.x3 = m[2][0] * (*it).x1 + m[2][1] * (*it).x2 + m[2][2] * (*it).x3 + m[2][3] * (*it).x4;
			q.x4 = m[3][0] * (*it).x1 + m[3][1] * (*it).x2 + m[3][2] * (*it).x3 + m[3][3] * (*it).x4;
			(*it) = q;
		}
}

#include "lap.h"


Lap::Lap(){
	this->C0 = POINT3DH(0, 0, 0);
	this->C1 = POINT3DH(0, 0, 0);
	this->C2 = POINT3DH(0, 0, 0);
	this->C3 = POINT3DH(0, 0, 0);
}

Lap::Lap(POINT3DH c0, POINT3DH c1, POINT3DH c2, POINT3DH c3){
	this->C0 = c0;
	this->C1 = c1;
	this->C2 = c2;
	this->C3 = c3;
}

void Lap::draw(GLdouble R, GLdouble G, GLdouble B){

	glColor3f(R/2, G/2, B/2);
	glBegin(GL_POLYGON);
	glVertex2f((C0.getPoint3D()).x, (C0.getPoint3D()).y);
	glVertex2f((C1.getPoint3D()).x, (C1.getPoint3D()).y);
	glVertex2f((C2.getPoint3D()).x, (C2.getPoint3D()).y);
	glVertex2f((C3.getPoint3D()).x, (C3.getPoint3D()).y);
	glEnd();

	glColor3f(R, G, B);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f((C0.getPoint3D()).x, (C0.getPoint3D()).y);
	glVertex2f((C1.getPoint3D()).x, (C1.getPoint3D()).y);
	glVertex2f((C2.getPoint3D()).x, (C2.getPoint3D()).y);
	glVertex2f((C3.getPoint3D()).x, (C3.getPoint3D()).y);
	glEnd();
}

void Lap::setNormalVector(){
	POINT3D A = C0.getPoint3D();
	POINT3D B = C1.getPoint3D();
	POINT3D D = C3.getPoint3D();
	POINT3D AB = POINT3D((B.x - A.x), (B.y - A.y), (B.z-A.z));
	POINT3D AD = POINT3D((D.x - B.x), (D.y - B.y), (D.z-B.z));
	this -> normVect = vectorial_product(AB, AD);
}

POINT3D Lap::getNormalVector(){
	return normVect;
}
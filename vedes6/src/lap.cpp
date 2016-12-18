#include "lap.h"


Lap::Lap(POINT3DH c0, POINT3DH c1, POINT3DH c2, POINT3DH c3){
	this->C0 = c0;
	this->C1 = c1;
	this->C2 = c2;
	this->C3 = c3;
}

void Lap::draw(){

	glBegin(GL_POLYGON);
	glVertex2f((C0.getPoint3D()).x, (C0.getPoint3D()).y);
	glVertex2f((C1.getPoint3D()).x, (C1.getPoint3D()).y);
	glVertex2f((C2.getPoint3D()).x, (C2.getPoint3D()).y);
	glVertex2f((C3.getPoint3D()).x, (C3.getPoint3D()).y);
	glEnd();
}
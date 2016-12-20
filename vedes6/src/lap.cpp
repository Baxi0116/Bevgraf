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

void Lap::draw(){

	glColor3f(0.5, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f((C0.getPoint3D()).x, (C0.getPoint3D()).y);
	glVertex2f((C1.getPoint3D()).x, (C1.getPoint3D()).y);
	glVertex2f((C2.getPoint3D()).x, (C2.getPoint3D()).y);
	glVertex2f((C3.getPoint3D()).x, (C3.getPoint3D()).y);
	glEnd();

	glColor3f(1, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f((C0.getPoint3D()).x, (C0.getPoint3D()).y);
	glVertex2f((C1.getPoint3D()).x, (C1.getPoint3D()).y);
	glVertex2f((C2.getPoint3D()).x, (C2.getPoint3D()).y);
	glVertex2f((C3.getPoint3D()).x, (C3.getPoint3D()).y);
	glEnd();
}

POINT3D Lap::getNormalVector(){
	POINT3D A = C0.getPoint3D();
	POINT3D B = C1.getPoint3D();
	POINT3D C = C2.getPoint3D();
	POINT3D AB = POINT3D((B.x - A.x), (B.y - A.y), (B.z-A.z));
	POINT3D AC = POINT3D((C.x - A.x), (C.y - A.y), (C.z-A.z));
	this -> normVect = vectorial_product(AC, AB);
	return normVect;
}

POINT3D Lap::getWeight(){
	POINT3D res;
	res.x = (C0.getPoint3D().x + C1.getPoint3D().x + C2.getPoint3D().x + C3.getPoint3D().x) / 4;
	res.y = (C0.getPoint3D().y + C1.getPoint3D().y + C2.getPoint3D().y + C3.getPoint3D().y) / 4;
	res.z = (C0.getPoint3D().z + C1.getPoint3D().z + C2.getPoint3D().z + C3.getPoint3D().z) / 4;
	return res;
}


GLdouble Lap::camDist(){
	POINT3D tmp = this->getWeight();
	POINT3D CS = POINT3D((0-tmp.x), (0-tmp.y), (0-tmp.z)); //kamera súlypont vektora
	return norm(CS);
}
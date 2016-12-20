#ifndef _POINT3DH_H
#define _POINT3DH_H 

#include "point3d.h"

class POINT3DH {

public:

	POINT3DH(){
		this->x1 = 0;
		this->x2 = 0;
		this->x3 = 0;
		this->x4 = 1;
	}

	POINT3DH(double x, double y, double z){
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

	void init(double x, double y, double z){
		this->x1 = x;
		this->x2 = y;
		this->x3 = z;
		this->x4 = 1;
	}

	POINT3D getPoint3D (){
		POINT3D b = POINT3D((this->x1/this->x4), (this->x2/this->x4), (this->x3/this->x4));
		return b;
	}

	void trsf(GLdouble m[][4]){

		POINT3DH q = POINT3DH(0, 0, 0);
			q.x1 = m[0][0] * x1 + m[0][1] * x2 + m[0][2] * x3 + m[0][3] * x4;
			q.x2 = m[1][0] * x1 + m[1][1] * x2 + m[1][2] * x3 + m[1][3] * x4;
			q.x3 = m[2][0] * x1 + m[2][1] * x2 + m[2][2] * x3 + m[2][3] * x4;
			q.x4 = m[3][0] * x1 + m[3][1] * x2 + m[3][2] * x3 + m[3][3] * x4;
			
		this -> x1 = q.x1;
		this -> x2 = q.x2;
		this -> x3 = q.x3;
		this -> x4 = q.x4;
	}

	double x1, x2, x3, x4;
};

#endif
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

	double x1, x2, x3, x4;
};

#endif
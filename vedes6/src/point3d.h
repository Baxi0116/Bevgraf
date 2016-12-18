#ifndef _POINT3D_H
#define _POINT3D_H 

class POINT3D {

public:

	POINT3D(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	POINT3D(double x, double y, double z){
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

	void init(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double x, y, z;
};


#endif
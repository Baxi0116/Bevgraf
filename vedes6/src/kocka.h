#ifndef _KOCKA_H
#define _KOCKA_H

#include <GL/glut.h>
#include <vector>

#include "point3dh.h"
#include "point3d.h"


class Cube{
public:

	Cube();
	Cube(GLdouble x, GLdouble y, GLdouble z);

	void draw();

	void transformPoints(double m[][4]);

	POINT3DH C0, C1, C2, C3, C4, C5, C6, C7;

	std::vector<POINT3DH> points;

};

#endif
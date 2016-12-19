#ifndef _KOCKA_H
#define _KOCKA_H

#include <GL/glut.h>
#include <vector>
#include <iostream>

#include "point3dh.h"
#include "point3d.h"
#include "lap.h"


class Cube{
public:

	Cube(GLdouble R, GLdouble G, GLdouble B);
	Cube(GLdouble x, GLdouble y, GLdouble z, GLdouble R, GLdouble G, GLdouble B);

	void draw();

	void transformPoints(double m[][4]);

	POINT3DH C0, C1, C2, C3, C4, C5, C6, C7;

	GLdouble R, G, B;

	Lap L1, L2, L3, L4, L5, L6;

	std::vector<POINT3DH> points;

	std::vector<Lap> lapok;

};

#endif
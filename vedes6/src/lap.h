#ifndef _LAP_H
#define _LAP_H

#include <GL/glut.h>
#include <math.h>
#include <vector>

#include "point3d.h"
#include "point3dh.h"

class Lap
{
public:
	Lap(POINT3DH, POINT3DH, POINT3DH, POINT3DH);

	void draw();
	
	POINT3DH C0, C1, C2, C3;

};

#endif
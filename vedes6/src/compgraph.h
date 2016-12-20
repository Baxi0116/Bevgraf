#ifndef _COMPGRAPH_H
#define _COMPGRAPH_H

#include <cmath>

#include "point3d.h"

void mul_matrices( double A[ ][ 4 ], double B[ ][ 4 ], double C[ ][ 4 ] );

double inner_product(POINT3D A, POINT3D B);

POINT3D vectorial_product(POINT3D A, POINT3D B);

double norm(POINT3D A);

POINT3D vect_norm(POINT3D A);

POINT3D makeVect(POINT3D a, POINT3D b);


#endif
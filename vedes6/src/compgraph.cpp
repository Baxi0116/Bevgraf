#include "compgraph.h"

void mul_matrices( double A[ ][ 4 ], double B[ ][ 4 ], double C[ ][ 4 ] )
{
	int i, j, k;
	float sum;
	for( i = 0; i < 4; i++ )
		for( j = 0; j < 4; j++ ) {
			sum = 0;
			for( k = 0; k < 4; k++ )
				sum = sum + A[ i ][ k ] * B[ k ][ j ];
			C[ i ][ j ] = sum;
		}
}


double inner_product(POINT3D A, POINT3D B){
	return (A.x * B.x + A.y * B.y + A.z * B.z);
}

POINT3D vectorial_product(POINT3D A, POINT3D B){
	POINT3D C;
	C.x = A.y * B.z - A.z * B.y;
	C.y = A.z * B.x - A.x * B.z;
	C.z = A.x * B.y - A.y * B.x;
	return C;
}

double norm(POINT3D A){
	return sqrt(inner_product(A, A));
}

POINT3D vect_norm(POINT3D A){
	POINT3D res;
	res.x = A.x / norm(A);
	res.y = A.y / norm(A);
	res.z = A.z / norm(A);

	return res;
}
#include "kocka.h"


Cube::Cube(GLdouble R, GLdouble G, GLdouble B){
	//felső lap
		C0 = POINT3DH(0.5, 0.5, 0.5);
		C1 = POINT3DH(-0.5, 0.5, 0.5);
		C2 = POINT3DH(-0.5, 0.5, -0.5);
		C3 = POINT3DH(0.5, 0.5, -0.5);
		//alsó lap
		C4 = POINT3DH(0.5, -0.5, 0.5);
		C5 = POINT3DH(-0.5, -0.5, 0.5);
		C6 = POINT3DH(-0.5, -0.5, -0.5);
		C7 = POINT3DH(0.5, -0.5, -0.5);

		points.push_back(C0);
		points.push_back(C1);
		points.push_back(C2);
		points.push_back(C3);
		points.push_back(C4);
		points.push_back(C5);
		points.push_back(C6);
		points.push_back(C7);


		L1 = Lap(points[0], points[1], points[2], points[3]);
		L2 = Lap(points[0], points[1], points[5], points[4]);
		L3 = Lap(points[0], points[4], points[7], points[3]);
		L4 = Lap(points[3], points[7], points[6], points[2]);
		L5 = Lap(points[4], points[5], points[6], points[7]);
		L6 = Lap(points[1], points[2], points[6], points[5]);

		this->R = R;
		this->G = G;
		this->B = B;
}


Cube::Cube(GLdouble x, GLdouble y, GLdouble z, GLdouble R, GLdouble G, GLdouble B){
	//felső lap
		C0 = POINT3DH(0.5+x, 0.5+y, 0.5+z);
		C1 = POINT3DH(-0.5+x, 0.5+y, 0.5+z);
		C2 = POINT3DH(-0.5+x, 0.5+y, -0.5+z);
		C3 = POINT3DH(0.5+x, 0.5+y, -0.5+z);
		//alsó lap
		C4 = POINT3DH(0.5+x, -0.5+y, 0.5+z);
		C5 = POINT3DH(-0.5+x, -0.5+y, 0.5+z);
		C6 = POINT3DH(-0.5+x, -0.5+y, -0.5+z);
		C7 = POINT3DH(0.5+x, -0.5+y, -0.5+z);

		points.push_back(C0);
		points.push_back(C1);
		points.push_back(C2);
		points.push_back(C3);
		points.push_back(C4);
		points.push_back(C5);
		points.push_back(C6);
		points.push_back(C7);

		lapok.resize(6);

		lapok[0] = Lap(points[0], points[1], points[2], points[3]);
		lapok[1] = Lap(points[0], points[1], points[5], points[4]);
		lapok[2] = Lap(points[0], points[4], points[7], points[3]);
		lapok[3] = Lap(points[3], points[7], points[6], points[2]);
		lapok[4] = Lap(points[4], points[5], points[6], points[7]);
		lapok[5] = Lap(points[1], points[2], points[6], points[5]);

		this->R = R;
		this->G = G;
		this->B = B;
}

void Cube::draw(){

	/*for(int i = 0; i < 6; i++){
		std::cout << lapok[i].getNormalVector().x << " " << lapok[i].getNormalVector().y << " " << lapok[i].getNormalVector().z << std::endl;
	}*/

	lapok[0].draw(R,G,B);
	lapok[1].draw(R,G,B);
	lapok[2].draw(R,G,B);
	lapok[3].draw(R,G,B);
	lapok[4].draw(R,G,B);
	lapok[5].draw(R,G,B);
}


void Cube::transformPoints(double m[][4]){
		POINT3DH q = POINT3DH(0, 0, 0);

		for(auto it = points.begin(); it != points.end(); it++){
			q.x1 = m[0][0] * (*it).x1 + m[0][1] * (*it).x2 + m[0][2] * (*it).x3 + m[0][3] * (*it).x4;
			q.x2 = m[1][0] * (*it).x1 + m[1][1] * (*it).x2 + m[1][2] * (*it).x3 + m[1][3] * (*it).x4;
			q.x3 = m[2][0] * (*it).x1 + m[2][1] * (*it).x2 + m[2][2] * (*it).x3 + m[2][3] * (*it).x4;
			q.x4 = m[3][0] * (*it).x1 + m[3][1] * (*it).x2 + m[3][2] * (*it).x3 + m[3][3] * (*it).x4;
			(*it) = q;
		}

		lapok.resize(6);
		lapok[0] = Lap(points[0], points[1], points[2], points[3]);
		lapok[1] = Lap(points[0], points[1], points[5], points[4]);
		lapok[2] = Lap(points[0], points[4], points[7], points[3]);
		lapok[3] = Lap(points[3], points[7], points[6], points[2]);
		lapok[4] = Lap(points[4], points[5], points[6], points[7]);
		lapok[5] = Lap(points[1], points[2], points[6], points[5]);
}
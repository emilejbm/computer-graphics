
#pragma once

#include <ostream>
#include <istream>
#include <cmath>
using namespace std;

class V3 {
public:
	float xyz[3];
	
	V3() {};
	V3(float x, float y, float z); 

	//overloading
	V3 operator+(V3 v1);
	V3 operator-(V3 v1);
	float operator*(V3 v1);
	V3 operator^(V3 v1);
	V3 operator*(float scalar);
	V3 operator/(float scalar);
	bool operator==(V3 v1);
	float& operator[](int i);
	friend ostream& operator<<(ostream& os, V3 vec);
	friend istream& operator>>(istream& os, V3& vec);

	float getLength();
	V3 normalizedVec();

	//rotation functions
	V3 rotateAxis(V3 p1, V3 p2, float angle);
	V3 rotateDir(V3 dir, float angle);

    void SetFromColor(unsigned int col);
    unsigned int GetColor();
    V3 Light(V3 matColor, float ka, V3 ld, V3 norm, V3 eye, float* augments);
    V3 Shade(V3 matColor, float ka, V3 ld, V3 norm);

    void SetAsEdgeEquation(V3 p0, V3 p1, V3 p2);
};

class AABB {
public:
    V3 minv, maxv;
    AABB(V3 firstPoint);
    void AddPoint(V3 newPoint);
    int ClipWithFrame(int w, int h);
};

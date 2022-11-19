#pragma once

#include "V3.h"
#include <math.h>

using namespace std;


class M33 {
public:
	V3 rows[3];
	M33() {};
	V3& operator[](int i);
	V3 operator*(V3 v);
	M33 operator*(M33 m);
	V3 getColumn(int i);
	void setColumn(int i, V3 col);
	void setRotY(float theta);
	void setRotX(float theta);
	M33 invert();

	void makeIdentity();
	M33 transpose();

	friend ostream& operator<<(ostream& os, M33 m);
};


#include "M33.h"

V3& M33::operator[](int i){
    return rows[i];
}

ostream& operator<<(ostream& os, M33 m){
    os << "[" << m.rows[0] << "]" << endl;
    os << "[" << m.rows[1] << "]" << endl;
    os << "[" << m.rows[2] << "]" << endl;
    return os;
}

//matrix times col vector
V3 M33::operator*(V3 v){
    M33 &m = *this;
    V3 res;
    res[0] = m[0] * v;
    res[1] = m[1] * v;
    res[2] = m[2] * v;
    return res;
}

//matrix multiplication
M33 M33::operator*(M33 m2){
    M33 res;
    V3 temp;
    M33 &m1 = *this;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp[j] = m1.rows[i] * m2.getColumn(j);
        }
        res[i] = temp;
    }

    return res;
}

//check for this behavior *
V3 M33::getColumn(int col){
    V3 res = V3(rows[0][col], rows[1][col], rows[2][col]);
    return res;
}

void M33::setColumn(int i, V3 col){
    rows[0][i] = col[0];
    rows[1][i] = col[1];
    rows[2][i] = col[2];
}

void M33::setRotY(float theta){
    float thetaRad = theta / 180.0f * M_PI;
    float cosTheta = cosf(thetaRad);
    float sinTheta = sinf(thetaRad);
    M33 &m = *this;
    m[0] = V3(cosTheta, 0.0f, sinTheta);
    m[1] = V3(0.0f, 1.0f, 0.0f);
    m[2] = V3(-sinTheta, 0.0f, cosTheta);
}

void M33::setRotX(float theta){
    float thetaRad = theta / 180.0f * M_PI;
    float cosTheta = cosf(thetaRad);
    float sinTheta = sinf(thetaRad);
    M33 &m = *this;
    m[0] = V3(1.0f, 0.0f, 0.0f);
    m[1] = V3(0.0f, cosTheta, -sinTheta);
    m[2] = V3(0.0f, sinTheta, cosTheta);
}

void M33::makeIdentity(){
    rows[0] = V3(1.0f, 0.0f, 0.0f);
    rows[1] = V3(0.0f, 1.0f, 0.0f);
    rows[2] = V3(0.0f, 0.0f, 1.0f);
}

M33 M33::invert() {
	M33 res;
	V3 a = getColumn(0), b = getColumn(1), c = getColumn(2);
	V3 _a = b ^ c; _a = _a / (a * _a);
	V3 _b = c ^ a; _b = _b / (b * _b);
	V3 _c = a ^ b; _c = _c / (c * _c);
	res[0] = _a;
	res[1] = _b;
	res[2] = _c;

	return res;
}

M33 M33::transpose(){
    M33 res;
    res.setColumn(0, rows[0]);
    res.setColumn(1, rows[1]);
    res.setColumn(2, rows[2]);

    return res;
}

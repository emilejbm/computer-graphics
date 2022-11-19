
#include "V3.h"
#include "M33.h"
#include "iostream"

V3::V3(float x, float y, float z){
    this->xyz[0] = x;
    this->xyz[1] = y;
    this->xyz[2] = z;
}

V3 V3::operator+(V3 v1){
    V3 res;
    V3 &v0 = *this;
    res[0] = v0[0] + v1[0];
    res[1] = v0[1] + v1[1];
    res[2] = v0[2] + v1[2];

    return res;
}

V3 V3::operator-(V3 v1){
    V3 res;
    V3 &v0 = *this;
    res[0] = v0[0] - v1[0];
    res[1] = v0[1] - v1[1];
    res[2] = v0[2] - v1[2];

    return res;
}

float& V3::operator[](int i){
    return xyz[i];
}

//dot product
float V3::operator*(V3 v1){
    float res;
    V3 &v0 = *this;
    res = (v0[0] * v1[0]) + (v0[1] * v1[1]) + (v0[2] * v1[2]);

    return res;
}

//cross product
V3 V3::operator^(V3 v1){
    V3 res;
    V3 &v0 = *this;

    res[0] = v0[1]*v1[2] - v0[2]*v1[1];
    res[1] = v0[2]*v1[0] - v0[0]*v1[2];
    res[2] = v0[0]*v1[1] - v0[1]*v1[0];

    return res;
}

//multiplication with scalar
V3 V3::operator*(float scalar){

    V3 res;
    V3 &v0 = *this;
    res[0] = v0[0] * scalar;
    res[1] = v0[1] * scalar;
    res[2] = v0[2] * scalar;

    return res;
}

//division with scalar
V3 V3::operator/(float scalar){
    V3 res;
    V3 &v0 = *this;
    res[0] = v0[0] / scalar;
    res[1] = v0[1] / scalar;
    res[2] = v0[2] / scalar;

    return res;
}

bool V3::operator==(V3 v1){
    return ((v1[0] == this->xyz[0]) && (v1[1] == this->xyz[1]) && (v1[2] == this->xyz[2]));
}

ostream& operator<<(ostream&os, V3 vec){
    os << vec[0] << " " << vec[1] << " " << vec[2];
    return os;
}

istream& operator>>(istream& is, V3& vec){
    is >> vec[0] >> vec[1] >> vec[2];
    return is;
}

float V3::getLength(){
    float length;
    V3 &v0 = *this;
    float x_res = pow(v0[0], 2);
    float y_res = pow(v0[1], 2);
    float z_res = pow(v0[2], 2);
    length = sqrtf(x_res + y_res + z_res);

    return length;
}

V3 V3::normalizedVec(){
    V3 res;
    V3 &v0 = *this;
    float length = this->getLength(); 
    res[0] = v0[0]/length;
    res[1] = v0[1]/length;
    res[2] = v0[2]/length;

    return res;
}

// rotate point about p2-p1 axis by theta degrees
/*
V3 V3::rotateAxis(V3 p1, V3 p2, float theta){
    V3 a;
    V3 b;
    V3 c;
    V3 xAxis = V3(1.0f, 0.0f, 0.0f);
    V3 yAxis = V3(0.0f, 1.0f, 0.0f);
    V3 auxAxis;

    V3 p_t;
    M33 newSystem;
    M33 rotationMatrix;
    M33 invertedNewSystem;

    p_t = *this-p1;
    a = (p2-p1).normalizedVec();
    //include this within conditionals. rotate about Y and use another as aux. a = Y. if rotating about Y is not possible, use y as aux. a = X
    if(abs(xAxis*a) > abs(yAxis*a)){
        auxAxis = yAxis;
        rotationMatrix.setRotX(theta);

        b = (auxAxis^a).normalizedVec();
        c = (a^b).normalizedVec();
        newSystem[0] = a;
        newSystem[1] = b;
        newSystem[2] = c;
    }
    else{
        auxAxis = xAxis;
        rotationMatrix.setRotY(theta);
        //a = (p2-p1).normalizedVec();
        b = (auxAxis^a).normalizedVec();
        c = (a^b).normalizedVec();
        newSystem[0] = b;
        newSystem[1] = a;
        newSystem[2] = c;
    }

    invertedNewSystem = newSystem.invert();

    //translates to local coords
    p_t = newSystem * p_t;

    //rotates about coord sys axis
    p_t = rotationMatrix * p_t;

    //translate back
    p_t = (invertedNewSystem*p_t) + p1;

    return p_t;
}

//V3 V3::rotateDir(V3 dir, float angle){
//    V3 origin = V3(0.0f, 0.0f, 0.0f);
//    V3& rotatedPoint = *this;
//    rotatedPoint.rotateAxis(origin, dir, angle);
//    return rotatedPoint;
//}
*/

V3 V3::rotateDir(V3 aD, float theta) {

    return rotateAxis(V3(0.0f, 0.0f, 0.0f), aD, theta);

}

V3 V3::rotateAxis(V3 aO, V3 aD, float theta) {

    M33 laxes;
    laxes[1] = aD;
    V3 aux(1.0f, 0.0f, 0.0f);
    if (fabsf(aD[0]) > fabsf(aD[1]))
        aux = V3(0.0f, 1.0f, 0.0f);
    laxes[2] = aux ^ aD;
    laxes[0] = laxes[1] ^ laxes[2];

    V3 &P = *this;
    V3 Pl = laxes*(P - aO);
    M33 roty; roty.setRotY(theta);
    V3 Pr = roty * Pl;
    return laxes.invert()*Pr + aO;

}


void V3::SetFromColor(unsigned int col) {

    V3 &v = *this;
    v[0] = (float)(((unsigned char*)(&col))[0]) / 255.0f;
    v[1] = (float)(((unsigned char*)(&col))[1]) / 255.0f;
    v[2] = (float)(((unsigned char*)(&col))[2]) / 255.0f;

}

unsigned int V3::GetColor() {

    V3 v = *this;
    v[0] = (v[0] < 0.0f) ? 0.0f : v[0];
    v[1] = (v[1] < 0.0f) ? 0.0f : v[1];
    v[2] = (v[2] < 0.0f) ? 0.0f : v[2];

    v[0] = (v[0] > 1.0f) ? 1.0f : v[0];
    v[1] = (v[1] > 1.0f) ? 1.0f : v[1];
    v[2] = (v[2] > 1.0f) ? 1.0f : v[2];

    unsigned int ret;
    int rgb[3];
    rgb[0] = (int)(v[0] * 255.0f);
    rgb[1] = (int)(v[1] * 255.0f);
    rgb[2] = (int)(v[2] * 255.0f);
    ret = 0xFF000000 + 256 * 256 * rgb[2] + 256 * rgb[1] + rgb[0];
    return ret;
}

////pass in EYE vector
//V3 ret;
//ld = ld.normalizedVec();
//norm = norm.normalizedVec();
//
//float kd = (ld*-1.0f)*norm;
//kd = (kd < 0.0f) ? 0.0f : kd;
//
//ret = matColor*(ka + (1.0f - ka)*kd);
//return ret;

V3 V3::Light(V3 matColor, float ka, V3 ld, V3 norm, V3 eye, float* augments) {
    V3 ret; V3 lightCol(1.0f, 1.0f, 1.0f);
    ld = ld.normalizedVec();
    norm = norm.normalizedVec();

    float kd = (ld*-1.0f)*norm;
    kd = (kd < 0.0f) ? 0.0f : kd;
    float kspec = 0.0f;
    float ldnorm = (ld * norm < 0.0f) ? 0.0f : (ld * norm);

    if (kd > 0.0f){
        V3 reflected_vec = (ld - norm*(2*(ldnorm))).normalizedVec();
        kspec = max(0.0f,float(pow(reflected_vec*(eye-V3(xyz[0], xyz[1], xyz[2])).normalizedVec(), 32+augments[1])));
    }

    ret = lightCol*((ka+augments[0]) + (1.0f - ka)*kd + kspec);
    ret = V3(matColor[0]*ret[0], matColor[1]*ret[1], matColor[2]*ret[2]);
    return ret;
}

V3 V3::Shade(V3 matColor, float ka, V3 ld, V3 norm) {
    V3 ret; V3 shadeCol(0.5f, 0.5f, 0.5f);
    ld = ld.normalizedVec();
    norm = norm.normalizedVec();

    float kd = (ld*-1.0f)*norm;
    kd = (kd < 0.0f) ? 0.0f : kd;

    ret = shadeCol*(ka + (1.0f - ka)*kd);
    ret = V3(matColor[0]*ret[0], matColor[1]*ret[1], matColor[2]*ret[2]);
    return ret;
}

AABB::AABB(V3 firstPoint) {

    minv = maxv = firstPoint;

}

void AABB::AddPoint(V3 newPoint) {

    for (int ci = 0; ci < 3; ci++) {
        if (minv[ci] > newPoint[ci])
            minv[ci] = newPoint[ci];
        if (maxv[ci] < newPoint[ci])
            maxv[ci] = newPoint[ci];
    }

}

int AABB::ClipWithFrame(int w, int h) {

    if (minv[0] > (float)w)
        return 0;
    if (minv[1] > (float)h)
        return 0;
    if (maxv[0] < 0.0f)
        return 0;
    if (maxv[1] < 0.0f)
        return 0;

    if (minv[0] < 0.0f)
        minv[0] = 0.0f;
    if (minv[1] < 0.0f)
        minv[1] = 0.0f;
    if (maxv[0] > (float) w)
        maxv[0] = (float) w;
    if (maxv[1] > (float) h)
        maxv[1] = (float) h;

    return 1;

}

void V3::SetAsEdgeEquation(V3 p0, V3 p1, V3 p2) {

    // (x-x0)/(x1-x0) = (y-y0)/(y1-y0);
    // (x-x0)(y1-y0) = (y-y0)(x1-x0);
    // Ax+By+C = 0
    float x0 = p0[0], x1 = p1[0], y0 = p0[1], y1 = p1[1];
    float A, B, C;
    A = y1-y0;
    B = x0-x1;
    C = y0*(x1-x0) - x0*(y1-y0);
    V3 &v = *this;
    v[0] = A;
    v[1] = B;
    v[2] = C;

    p2[2] = 1.0f;
    if (v*p2 < 0)
        v = v * -1.0f;

}
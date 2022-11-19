#include "ppc.h"
#include "M33.h"
#include "scene.h"
#include <iostream>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <GL/glut.h>
#include <FL/glu.h>

PPC::PPC(float hfov, int _w, int _h) : w(_w), h(_h) {

	C = V3(0.0f, 0.0f, 0.0f);
	a = V3(1.0f, 0.0f, 0.0f);
	b = V3(0.0f, -1.0f, 0.0f);
	float hfovd = hfov / 180.0f * 3.1415926f;
	c = V3(-(float)w / 2.0f, (float)h / 2.0f, -(float)w / (2.0f * tan(hfovd / 2.0f)));
}

V3 PPC::GetVD() {
    return (a^b).normalizedVec();
}

float PPC::GetF() {
    return c*GetVD();
}

float PPC::GetHFOV(){
    return 2*atan(w/(2*a.getLength()/this->GetF()));
}

V3 PPC::GetPP(){
    float PPu = -(c*a.normalizedVec()/a.getLength());
    float PPv = -(c*b.normalizedVec()/b.getLength());
    return V3(PPu, PPv, 0.0f);
}

void PPC::Rotate(V3 aDir, float theta) {
    a = a.rotateDir(aDir, theta);
    b = b.rotateDir(aDir, theta);
    c = c.rotateDir(aDir, theta);
}

void PPC::TranslateLR(float step){
    this->C = C + a.normalizedVec()*step;
}
void PPC::TranslateUD(float step){
    this->C = C - b.normalizedVec()*step;
}
void PPC::TranslateFB(float step){
    this->C = C + (a^b).normalizedVec()*step;
}

void PPC::zoom(float z){
    V3 PP = GetPP();
    this->c = (a*(-PP[0])) - (b*PP[1]) + (GetVD()*z*(GetF()));
}

int PPC::Project(V3 P, V3 &pP) {

    M33 M;
    M.setColumn(0, a);
    M.setColumn(1, b);
    M.setColumn(2, c);
    V3 q = M.invert()*(P - C);
    if (q[2] <= 0.0f)
        return 0;

    pP[0] = q[0] / q[2];
    pP[1] = q[1] / q[2];
    pP[2] = 1.0f / q[2];
    return 1;

}

void PPC::PositionAndOrient(V3 Cn, V3 L, V3 upg) {

    V3 vdn = (L - Cn).normalizedVec();
    V3 an = (vdn ^ upg).normalizedVec();
    V3 bn = vdn ^ an;
    float f = GetF();
    V3 cn = vdn*f - an* (float)w / 2.0f - bn* (float)h / 2.0f;

    a = an;
    b = bn;
    c = cn;
    C = Cn;
}

void PPC::SaveToTextFile(){

    ofstream fw("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/phc_path/phcinternals.txt", ofstream::app);
    if(fw.is_open()){
        fw << "a: " << this->a << "\n";
        fw << "b: " << this->b << "\n";
        fw << "c: " << this->c << "\n";
        fw << "C: " << this->C << "\n";
        fw << "VD: " << this->GetVD() << "\n";
        fw << "F: " << this->GetF() << "\n";
        fw << "HFOV: " << this->GetHFOV() << "\n";
        fw.close();
    }
    else{
        cout << "Problem saving to text file";
    }

}

void PPC::Unproject(V3 pP, V3 &P) {
    P = C + (a*pP[0] + b*pP[1] + c) / pP[2];
}

void PPC::SetIntrinsicsHW(float nearz, float farz) {

    glViewport(0, 0, w, h);
    float scf = nearz / GetF();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-(float)w / 2.0f*scf, (float)w / 2.0f*scf, -(float)h / 2.0f*scf, (float)h / 2.0f*scf,
              nearz, farz);
    glMatrixMode(GL_MODELVIEW);

}


void PPC::SetExtrinsicsHW() {

    glLoadIdentity();
    V3 L = C + GetVD()*100.0f;
    gluLookAt(C[0], C[1], C[2], L[0], L[1], L[2], -b[0], -b[1], -b[2]);

}

M33 PPC::GetMatrix() {

    M33 ret;
    ret.setColumn(0, a);
    ret.setColumn(1, b);
    ret.setColumn(2, c);
    return ret;

}
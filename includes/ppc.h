#pragma once

#include "V3.h"
#include "scene.h"
#include "M33.h"

class PPC {
public:
	V3 a, b, c, C;
	int w, h;
    PPC() : a(0.0f, 0.0f, 0.0f), b(0.0f, 0.0f, 0.0f), c(0.0f, 0.0f, 0.0f), C(0.0f, 0.0f, 0.0f), w(0), h(0){};
	PPC(float hfov, int _w, int _h);
    V3 GetVD();
    V3 GetPP();
    float GetF();
    float GetHFOV();
    void Rotate(V3 dir, float theta);

    void TranslateLR(float step);
    void TranslateUD(float step);
    void TranslateFB(float step);
    void zoom(float z);
	int Project(V3 P, V3 &pP);
    void Unproject(V3 pP, V3 &P);
    void PositionAndOrient(V3 Cn, V3 L, V3 upg);

    void SetIntrinsicsHW(float nearz, float farz);
    void SetExtrinsicsHW();
    M33 GetMatrix();

    void SaveToTextFile();
};
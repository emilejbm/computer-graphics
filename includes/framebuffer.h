#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <GL/glut.h>

#include "V3.h"
#include "M33.h"

class PPC;

class FrameBuffer : public Fl_Gl_Window {
public:
    unsigned int *pix; // pixel array
    float *zb; // z buffer to resolve visibility
    int w, h, texturesN;
    int ishw; // is 1 when hardware framebuffer
    clock_t fps;
    FrameBuffer(int u0, int v0, int _w, int _h);

    void draw();
    void KeyboardHandle();
    int handle(int guievent);
    void SetBGR(unsigned int bgr);
    void Set(int u, int v, int col);
    unsigned int Get(int u, int v);
    void SetGuarded(int u, int v, int col);
    void SetChecker(unsigned int col0, unsigned int col1, int csize);
    void DrawAARectangle(V3 tlc, V3 brc, unsigned int col);
    void DrawDisk(V3 center, float r, unsigned int col);
    void DrawSegment(V3 p0, V3 p1, unsigned int col);
    void DrawSegment(V3 p0, V3 p1, V3 c0, V3 c1);
    void DrawTriangle2D(float x[3], float y[3], unsigned int col);
    void computeBBox(float x[3], float y[3], float bbox[2][2]);
    void clipBox(float bbox[2][2], int w, int h);
    void LoadTiff(char* fname);
    void LoadTiledTiff(char* fname, int tilesN);
    void LoadSTB(char* fname);
    void SaveAsTiff(char *fname);
    float Sidedness(float a, float b, float c, float pixX, float pixY);
    void Render3DSegment(PPC *ppc, V3 v0, V3 v1, V3 c0, V3 c1);
    void Render3DPoint(PPC *ppc, V3 p, V3 c, float psize);
    void SetZB(float zf);
    void PrintZB(float zf);
    int IsCloserThenSet(float currz, int u, int v);
    void DrawTriangle2DFilled(float x[3], float y[3], V3 abc, V3 abcR, V3 abcG, V3 abcB);
    unsigned int LookUpNN(float s, float t);
    unsigned int LookUpNNCM(float s, float t);
    unsigned int LookUpBilinear(float s, float t);
    unsigned int LookUpBilinearCM(float s, float t);


};
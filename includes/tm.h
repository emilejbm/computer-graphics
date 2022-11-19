#pragma once

#include "V3.h"
#include <vector>

class PPC;
class FrameBuffer;
class CubeMap;

class TM {
public:
    V3 A,B,C,D;
    V3 *verts;
    int vertsN, tcsN;
    V3 *cols, *normals, *tcs;
    unsigned int *tris;
    int trisN;
    FrameBuffer* textures;
    vector<FrameBuffer*> fbs;

    TM() : verts(0), vertsN(0), tris(0), trisN(0), cols(0), normals(0),
           tcs(0), textures(0) {};
    void SetOneTriangle(V3 v0, V3 v1, V3 v2);
    void SetTexturedRectangle(float rectw, float recth, int orient);
    void SetTexturedCube(V3 cc, float sl);
    void SetAsAACube(V3 cc, float sideLength);
    void SetAsSquare(V3 cc, float sidelength);
    void LoadBin(char *fname);
    void RenderAsPoints(int psize, PPC *ppc, FrameBuffer *fb);
    void RenderWireFrame(PPC *ppc, FrameBuffer *fb);
    V3 GetCenter();
    void Translate(V3 tv);
    void SetCenter(V3 newCenter);
    void Rotate(V3 aO, V3 aD, float theta);
    void Light(float ka, V3 ld, V3 eye, float* augments);
    void Explode(float t);
    void VisualizeVertexNormals(PPC *ppc, FrameBuffer *fb, float vlength);
    void SetUnshared(TM *tm);
    void SetAsCopy(TM *tm);
    void Scale(float s);
    void RenderFilled(PPC *ppc, FrameBuffer *fb);
    void RenderFilled(PPC *ppc, FrameBuffer *fb, FrameBuffer* shadowfb, PPC* lights, float* augments);
    void RenderEnvironment(PPC *ppc, FrameBuffer *fb, CubeMap *cm);
    void ShadowPass(PPC* lights, FrameBuffer* shadowfb);

    void RenderHW();
    void RenderTexturedHW(unsigned int *texture);
    AABB SetAABB();
};
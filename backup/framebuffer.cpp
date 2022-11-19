
#include "framebuffer.h"
#include "math.h"
#include <iostream>
#include "scene.h"

#include <tiffio.h>

using namespace std;

FrameBuffer::FrameBuffer(int u0, int v0, int _w, int _h) :
        Fl_Gl_Window(u0, v0, _w, _h, 0) {

    w = _w;
    h = _h;
    pix = new unsigned int[w*h];
    zb = new float[w*h];

}


void FrameBuffer::draw() {

    glDrawPixels(w, h, GL_RGBA, GL_UNSIGNED_BYTE, pix);

}

int FrameBuffer::handle(int event) {

    switch (event)
    {
        case FL_KEYBOARD: {
            KeyboardHandle();
            return 0;
        }
        case FL_MOVE: {
            int u = Fl::event_x();
            int v = Fl::event_y();
            cerr << u << " " << v << "      \r";
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}

void FrameBuffer::KeyboardHandle() {
    int key = Fl::event_key();
    switch (key) {
        case FL_Left: {
            cerr << "INFO: pressed left" << endl;
            break;
        }
        default:
            cerr << "INFO: do not understand keypress" << endl;
            return;
    }

}

void FrameBuffer::SetBGR(unsigned int bgr) {

    for (int uv = 0; uv < w*h; uv++)
        pix[uv] = bgr;

}

void FrameBuffer::SetZB(float zf) {

    for (int uv = 0; uv < w*h; uv++) {
        zb[uv] = zf;
    }

}

void FrameBuffer::PrintZB(float zf) {

    for (int uv = 0; uv < w*h; uv++) {
        cout << zb[uv] << "____";
    }

}

void FrameBuffer::SetChecker(unsigned int col0, unsigned int col1, int csize) {

    for (int v = 0; v < h; v++) {
        for (int u = 0; u < w; u++) {
            int cu = u / csize;
            int cv = v / csize;
            if ((cu + cv) % 2)
                Set(u, v, col0);
            else
                Set(u, v, col1);
        }
    }

}

void FrameBuffer::DrawAARectangle(V3 tlc, V3 brc, unsigned int col) {

    // entire rectangle off screen
    if (tlc[0] > (float)w)
        return;
    if (brc[0] < 0.0f)
        return;
    if (tlc[1] > (float)h)
        return;
    if (brc[1] < 0.0f)
        return;

    // rectangle partially off screen
    if (tlc[0] < 0.0f)
        tlc[0] = 0.0f;
    if (brc[0] > (float)w)
        brc[0] = (float)w;
    if (tlc[1] < 0.0f)
        tlc[1] = 0.0f;
    if (brc[1] > (float)h)
        brc[1] = (float)h;

    int umin = (int)(tlc[0]+0.5f);
    int umax = (int)(brc[0]-0.5f);
    int vmin = (int)(tlc[1]+0.5f);
    int vmax = (int)(brc[1]-0.5f);
    for (int v = vmin; v <= vmax; v++) {
        for (int u = umin; u <= umax; u++) {
            Set(u, v, col);
        }
    }

}

void FrameBuffer::DrawDisk(V3 center, float r, unsigned int col) {

    int umin = (int)(center[0] - r);
    int umax = (int)(center[0] + r);
    int vmin = (int)(center[1] - r);
    int vmax = (int)(center[1] + r);
    center[2] = 0.0f;
    for (int v = vmin; v <= vmax; v++) {
        for (int u = umin; u <= umax; u++) {
            V3 pixCenter(.5f + (float)u, .5f + (float)v, 0.0f);
            V3 distVector = pixCenter - center;
            if (r*r < distVector * distVector)
                continue;
            Set(u, v, col);
        }
    }
}

void FrameBuffer::computeBBox(float x[3], float y[3], float bbox[2][2]) {
    //use better numbers
    float minX = 99999, minY = 99999;
    float maxX = -99999, maxY = -99999;
    for(int i=0; i<3; i++){
        if(x[i] > maxX){
            maxX = x[i];
        }
        if(x[i] < minX){
            minX = x[i];
        }
        if(y[i] > maxY){
            maxY = y[i];
        }
        if(y[i] < minY) {
            minY = y[i];
        }
    }
    //2d array where rows are x and y, min max
    bbox[0][0] = minX - 0.5f;
    bbox[0][1] = maxX + 0.5f;
    bbox[1][0] = minY - 0.5f;
    bbox[1][1] = maxY + 0.5f;
}

void FrameBuffer::clipBox(float bbox[2][2], int w, int h) {
    if(bbox[1][0] < 0){
        bbox[1][0] = 0;
    }
    if(bbox[1][1] > (h-1)){
        bbox[1][1] = h-1;
    }
    if(bbox[0][0] < 0){
        bbox[0][0] = 0;
    }
    if(bbox[0][1] > w-1) {
        bbox[0][1] = w-1;
    }
}

float FrameBuffer::Sidedness(float a, float b, float c, float pixX, float pixY){
    return (a*pixX + b*pixY + c);
}

void FrameBuffer::DrawTriangle2D(float x[3], float y[3], unsigned int col){
    float a[3], b[3], c[3];
    float sidedness;

    //for edges: 0 means x, 1 means y, 2 means c
    //edge that goes from v0 to v1
    a[0] = y[1]-y[0];
    b[0] = -x[1]+x[0];
    c[0] = -x[0]*y[1] + y[0]*x[1];
    sidedness = a[0]*x[2] + b[0]*y[2] + c[0];
    if (sidedness < 0){
        a[0] = -a[0];
        b[0] = -b[0];
        c[0] = -c[0];
    }
    //edge goes from v1 to v2
    a[1] = y[2]-y[1];
    b[1] = -x[2]+x[1];
    c[1] = -x[1]*y[2] + y[1]*x[2];
    sidedness = a[1]*x[0] + b[1]*y[0] + c[1];
    if (sidedness < 0){
        a[1] = -a[1];
        b[1] = -b[1];
        c[1] = -c[1];
    }
    //edge goes from v2 to v0
    a[2] = y[0]-y[2];
    b[2] = -x[0]+x[2];
    c[2] = -x[2]*y[0] + y[2]*x[0];
    sidedness = a[2]*x[1] + b[2]*y[1] + c[2];
    if (sidedness < 0){
        a[2] = -a[2];
        b[2] = -b[2];
        c[2] = -c[2];
    }

    float bbox[2][2];
    computeBBox(x,y, bbox);
    clipBox(bbox, w, h);

    int left = (int)(bbox[0][0] + 0.5);
    int right = (int)(bbox[0][1] - 0.5);
    int top = (int)(bbox[1][0] + 0.5);
    int bottom = (int)(bbox[1][1] - 0.5);

    double side1, side2, side3;

    //check sidedness for each pixel 3 times, if negative it is inside
    int i = 0;
    int currX, currY;
    float currEL[3], currEdge[3];
    for(currY = top, currEL[i] = a[i]*(left+0.5) + b[i]*(top+0.5) + c[i]; currY <= bottom; currY++, currEL[i]+=b[i]){
        for(currX = left, currEdge[i] = currEL[i]; currX <= right; currX++, currEdge[i] += a[i]) {
            side1 = Sidedness(a[0], b[0], c[0], currX, currY);
            side2 = Sidedness(a[1], b[1], c[1], currX, currY);
            side3 = Sidedness(a[2], b[2], c[2], currX, currY);

            if (side1>=0 && side2>=0 && side3>=0) {
                Set(currX, currY, col);
            } else {
                continue;
            }
        }
    }
}

void FrameBuffer::DrawTriangle2DFilled(float x[3], float y[3], V3 abcZ, V3 abcR, V3 abcG, V3 abcB){
    float a[3], b[3], c[3];
    float sidedness;

    //for edges: 0 means x, 1 means y, 2 means c
    //edge that goes from v0 to v1
    a[0] = y[1]-y[0];
    b[0] = -x[1]+x[0];
    c[0] = -x[0]*y[1] + y[0]*x[1];
    sidedness = a[0]*x[2] + b[0]*y[2] + c[0];
    if (sidedness < 0){
        a[0] = -a[0];
        b[0] = -b[0];
        c[0] = -c[0];
    }
    //edge goes from v1 to v2
    a[1] = y[2]-y[1];
    b[1] = -x[2]+x[1];
    c[1] = -x[1]*y[2] + y[1]*x[2];
    sidedness = a[1]*x[0] + b[1]*y[0] + c[1];
    if (sidedness < 0){
        a[1] = -a[1];
        b[1] = -b[1];
        c[1] = -c[1];
    }
    //edge goes from v2 to v0
    a[2] = y[0]-y[2];
    b[2] = -x[0]+x[2];
    c[2] = -x[2]*y[0] + y[2]*x[0];
    sidedness = a[2]*x[1] + b[2]*y[1] + c[2];
    if (sidedness < 0){
        a[2] = -a[2];
        b[2] = -b[2];
        c[2] = -c[2];
    }

    float bbox[2][2];
    computeBBox(x,y, bbox);
    clipBox(bbox, w, h);

    int left = (int)(bbox[0][0] + 0.5);
    int right = (int)(bbox[0][1] - 0.5);
    int top = (int)(bbox[1][0] + 0.5);
    int bottom = (int)(bbox[1][1] - 0.5);

    double side1, side2, side3;

    //check sidedness for each pixel, if negative it is inside
    int i = 0;
    int currX, currY;
    float currEL[3], currEdge[3];
    for(currY = top, currEL[i] = a[i]*(left+0.5) + b[i]*(top+0.5) + c[i]; currY <= bottom; currY++, currEL[i]+=b[i]){
        for(currX = left, currEdge[i] = currEL[i]; currX <= right; currX++, currEdge[i] += a[i]) {
            side1 = Sidedness(a[0], b[0], c[0], currX, currY);
            side2 = Sidedness(a[1], b[1], c[1], currX, currY);
            side3 = Sidedness(a[2], b[2], c[2], currX, currY);

            if (side1>=0 && side2>=0 && side3>=0) {
                float z_interpolated = abcZ[0]*currX + abcZ[1]*currY + abcZ[2];
                float r_interpolated = abcR[0]*currX + abcR[1]*currY + abcR[2];
                float g_interpolated = abcG[0]*currX + abcG[1]*currY + abcG[2];
                float b_interpolated = abcB[0]*currX + abcB[1]*currY + abcB[2];
                /*
                float n1 = normalsM[0] * V3(currX, currY, 1.0f);
                float n2 = normalsM[1] * V3(currX, currY, 1.0f);
                float n3 = normalsM[2] * V3(currX, currY, 1.0f);
                */

                if (this->IsCloserThenSet(z_interpolated, currX, currY)){
                    V3 newColor = V3(r_interpolated, g_interpolated, b_interpolated);

                    //V3 newNormal = V3(n1, n2, n3).normalizedVec();
                    //newColor = newColor.LightAmbDiffSpec(V3(1.0f, 0.0f, 0.0f), 0.1f, V3(0.0f, 0.0f, -1.0f), newNormal);
                    Set(currX, currY, newColor.GetColor());
                }
            } else {
                continue;
            }
        }
    }
}


void FrameBuffer::Set(int u, int v, int col) {

    pix[(h - 1 - v)*w + u] = col;

}


void FrameBuffer::SetGuarded(int u, int v, int col) {

    if (u < 0 || u > w - 1 || v < 0 || v > h - 1)
        return;
    Set(u, v, col);

}

void FrameBuffer::DrawSegment(V3 p0, V3 p1, unsigned int col) {

    V3 cv;
    cv.SetFromColor(col);
    DrawSegment(p0, p1, cv, cv);

}

void FrameBuffer::DrawSegment(V3 p0, V3 p1, V3 c0, V3 c1) {

    float maxSpan = (fabsf(p0[0] - p1[0]) < fabsf(p0[1] - p1[1])) ?
                    fabsf(p0[1] - p1[1]) : fabsf(p0[0] - p1[0]);
    int segsN = (int)maxSpan + 1;
    V3 currPoint = p0;
    V3 currColor = c0;
    V3 stepv = (p1 - p0) / (float)segsN;
    V3 stepcv = (c1 - c0) / (float)segsN;
    int si;
    for (si = 0;
         si <= segsN;
         si++, currPoint = currPoint + stepv, currColor = currColor + stepcv) {
        int u = (int)currPoint[0];
        int v = (int)currPoint[1];
        if (u < 0 || u > w - 1 || v < 0 || v > h - 1)
            continue;
        if (IsCloserThenSet(currPoint[2], u, v))
            SetGuarded(u, v, currColor.GetColor());
    }

}


// load a tiff image to pixel buffer
void FrameBuffer::LoadTiff(char* fname) {
    TIFF* in = TIFFOpen(fname, "r");
    if (in == NULL) {
        cerr << fname << " could not be opened" << endl;
        return;
    }

    int width, height;
    TIFFGetField(in, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(in, TIFFTAG_IMAGELENGTH, &height);
    if (w != width || h != height) {
        w = width;
        h = height;
        delete[] pix;
        pix = new unsigned int[w*h];
        size(w, h);
        glFlush();
        glFlush();
    }

    if (TIFFReadRGBAImage(in, w, h, pix, 0) == 0) {
        cerr << "failed to load " << fname << endl;
    }

    TIFFClose(in);
}

// save as tiff image
void FrameBuffer::SaveAsTiff(char *fname) {

    TIFF* out = TIFFOpen(fname, "w");

    if (out == NULL) {
        cerr << fname << " could not be opened" << endl;
        return;
    }

    TIFFSetField(out, TIFFTAG_IMAGEWIDTH, w);
    TIFFSetField(out, TIFFTAG_IMAGELENGTH, h);
    TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, 4);
    TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 8);
    TIFFSetField(out, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(out, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);

    for (uint32 row = 0; row < (unsigned int)h; row++) {
        TIFFWriteScanline(out, &pix[(h - row - 1) * w], row);
    }

    TIFFClose(out);
}

void FrameBuffer::Render3DSegment(PPC *ppc, V3 v0, V3 v1, V3 c0, V3 c1) {
    V3 pv0, pv1;
    if (!ppc->Project(v0, pv0))
        return;
    if (!ppc->Project(v1, pv1))
        return;
    DrawSegment(pv0, pv1, c0, c1);
}

void FrameBuffer::Render3DPoint(PPC *ppc, V3 p, V3 c, float psize) {
    V3 pv;
    if (!ppc->Project(p, pv))
        return;
    DrawDisk(pv, psize, c.GetColor());
}

int FrameBuffer::IsCloserThenSet(float currz, int u, int v) {

    float zbz = zb[(h - 1 - v)*w + u];
    if (zbz > currz)
        return 0;
    zb[(h - 1 - v)*w + u] = currz;
    return 1;

}


unsigned int FrameBuffer::LookUpNN(float s, float t) {

    if (s < 0.0f || t < 0.0f)
        return 0xFFFFFF00;

    float sf = s - (float)((int)s);
    float tf = t - (float)((int)t);

    int u = (int)(sf * (float)w);
    int v = (int)(tf * (float)h);
    return Get(u, v);

}


unsigned int FrameBuffer::LookUpBilinear(float s, float t) {

    if (s < 0.0f || t < 0.0f)
        return 0xFFFFFF00;

    float sf = s - (float)((int)s);
    float tf = t - (float)((int)t);

    float uf = sf * (float)w;
    float vf = tf * (float)h;
    if (uf < 0.5f || vf < 0.5f || uf > -.5f + (float)w || vf > -.5f + (float)h)
        return LookUpNN(s, t);

    int uA = (int)(uf - 0.5f);
    int vA = (int)(vf - 0.5f);
    float x = uf - (.5f + (float)uA);
    float y = vf - (.5f + (float)vA);

    V3 A; A.SetFromColor(Get(uA, vA));
    V3 B; B.SetFromColor(Get(uA, vA+1));
    V3 C; C.SetFromColor(Get(uA+1, vA+1));
    V3 D; D.SetFromColor(Get(uA+1, vA));
    V3 bic = A*(1 - x)*(1 - y) + B*(1 - x)*y + C*x*y + D*x*(1 - y);

    return bic.GetColor();
}

unsigned int FrameBuffer::Get(int u, int v) {

    return pix[(h - 1 - v)*w + u];

}
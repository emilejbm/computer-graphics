
#include "framebuffer.h"
#include "math.h"
#include <iostream>
#include "scene.h"
#include "ppc.h"

#include <tiffio.h>

using namespace std;

FrameBuffer::FrameBuffer(int u0, int v0, int _w, int _h) :
        Fl_Gl_Window(u0, v0, _w, _h, 0) {

    ishw = 0;
    w = _w;
    h = _h;
    pix = new unsigned int[w*h];
    zb = new float[w*h];

}


void FrameBuffer::draw() {

    if(!ishw){
        glDrawPixels(w, h, GL_RGBA, GL_UNSIGNED_BYTE, pix);
    }
    else{
        scene->RenderHW();
    }

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
            if (u < 0 || u > w - 1 || v < 0 || v > h - 1)
                return 0;
            V3 cv; cv.SetFromColor(pix[(h - 1 - v)*w + u]);
            cerr << u << " " << v << " " << cv << "          \r";
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

    for (int uv = 0; uv < w*h; uv++)
        zb[uv] = zf;

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
            SetGuarded(u, v, col);
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
    cout << w << h << endl;
    if (TIFFReadRGBAImage(in, w, h, pix, 0) == 0) {
        cerr << "failed to load " << fname << endl;
    }
//    TIFFReadRGBAImageOriented(in, width, height, pix, ORIENTATION_TOPLEFT,0);
//    TIFFReadRGBAImageOriented(in, width, height, pix, ORIENTATION_TOPRIGHT,0);
//    TIFFReadRGBAImageOriented(in, width, height, pix, ORIENTATION_BOTLEFT,0);
//    TIFFReadRGBAImageOriented(in, width, height, pix, ORIENTATION_BOTRIGHT,0);

    TIFFClose(in);
}

void FrameBuffer::LoadTiledTiff(char* fname, int tilesN) {
    TIFF* in = TIFFOpen(fname, "r");
    if (in == NULL) {
        cerr << fname << " could not be opened" << endl;
        return;
    }
    int width, height;
    TIFFGetField(in, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(in, TIFFTAG_IMAGELENGTH, &height);
    if (w != width || h != height) {
        w = width * tilesN;
        h = height * tilesN;
        delete[] pix;
        pix = new unsigned int[w*h];
        size(w, h);
        glFlush();
        glFlush();
    }
    cout << w << h << endl;
    if (TIFFReadRGBAImage(in, w, h, pix, 0) == 0) {
        cerr << "failed to load " << fname << endl;
    }
    //pix[(h - 1 - v)*w + u] = col;
    else{
        uint32 color = 0x00000000;
        int innerRow = 0;
        int innerCol = 0;
        for(int col=0; col < h; col++){
            if(innerCol > height){
                innerCol = 0;
            }
            for(int row=0; row < w; row++){
                if(innerRow > width){
                    innerRow = 0;
                }
                color = 0x00000000;
                uint32 a = pix[4 * ((width*innerRow + innerCol) - 1)] >> 24 & 0xff;
                uint32 r = pix[4 * ((width*innerRow + innerCol) - 1)] & 0xff;
                uint32 g = pix[4 * ((width*innerRow + innerCol) - 1)] >> 8 & 0xff;
                uint32 b = pix[4 * ((width*innerRow + innerCol) - 1)] >> 16 & 0xff;
                color += a + r + g + b;
                //color += b + g + r + a;
                //color += pix[((width*innerRow + innerCol) - 1)];
                this->SetGuarded(row, col, color);
                innerRow++;
            }
            innerCol++;
        }
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

unsigned int FrameBuffer::LookUpNNCM(float s, float t) {

    if (s < 0.0f || t < 0.0f)
        return 0xFFFFFF00;

    int u = (int)(s * (float)w);
    int v = (int)(t * (float)h);
    return Get(u, v);

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

unsigned int FrameBuffer::LookUpBilinearCM(float s, float t){
    if (s < 0.0f || t < 0.0f)
        return 0xFFFFFF00;

    float uf = s * (float)(w);
    float vf = t * (float)(h);
    if (uf < 0.5f || vf < 0.5f || uf > -.5f + (float)w || vf > -.5f + (float)h)
        return LookUpNNCM(s, t);

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
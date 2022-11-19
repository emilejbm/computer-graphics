#include "tm.h"
#include "ppc.h"
#include "framebuffer.h"
#include "M33.h"

#include "stb_image.h"

using namespace std;

#include <fstream>
#include <iostream>

void TM::SetAsAACube(V3 cc, float sideLength) {

    vertsN = 8;
    verts = new V3[vertsN];
    float sl2 = sideLength / 2.0f;
    verts[0] = cc + V3(-sl2, +sl2, +sl2);
    verts[1] = cc + V3(-sl2, -sl2, +sl2);
    verts[2] = cc + V3(+sl2, -sl2, +sl2);
    verts[3] = cc + V3(+sl2, +sl2, +sl2);
    verts[4] = cc + V3(-sl2, +sl2, -sl2);
    verts[5] = cc + V3(-sl2, -sl2, -sl2);
    verts[6] = cc + V3(+sl2, -sl2, -sl2);
    verts[7] = cc + V3(+sl2, +sl2, -sl2);

    trisN = 12;
    tris = new unsigned int[trisN*3];
    int tri = 0;
    tris[3 * tri + 0] = 0; // tris[0] = 0;
    tris[3 * tri + 1] = 1;
    tris[3 * tri + 2] = 2;
    tri++;
    tris[3 * tri + 0] = 2;
    tris[3 * tri + 1] = 3;
    tris[3 * tri + 2] = 0;
    tri++;

    tris[3 * tri + 0] = 3;
    tris[3 * tri + 1] = 2;
    tris[3 * tri + 2] = 6;
    tri++;
    tris[3 * tri + 0] = 6;
    tris[3 * tri + 1] = 7;
    tris[3 * tri + 2] = 3;
    tri++;

    tris[3 * tri + 0] = 7;
    tris[3 * tri + 1] = 6;
    tris[3 * tri + 2] = 5;
    tri++;
    tris[3 * tri + 0] = 5;
    tris[3 * tri + 1] = 4;
    tris[3 * tri + 2] = 7;
    tri++;

    tris[3 * tri + 0] = 4;
    tris[3 * tri + 1] = 5;
    tris[3 * tri + 2] = 1;
    tri++;
    tris[3 * tri + 0] = 1;
    tris[3 * tri + 1] = 0;
    tris[3 * tri + 2] = 4;
    tri++;


    tris[3 * tri + 0] = 1;
    tris[3 * tri + 1] = 5;
    tris[3 * tri + 2] = 6;
    tri++;
    tris[3 * tri + 0] = 6;
    tris[3 * tri + 1] = 2;
    tris[3 * tri + 2] = 1;
    tri++;

    tris[3 * tri + 0] = 4;
    tris[3 * tri + 1] = 0;
    tris[3 * tri + 2] = 3;
    tri++;
    tris[3 * tri + 0] = 3;
    tris[3 * tri + 1] = 7;
    tris[3 * tri + 2] = 4;
    tri++;

    normals = new V3[vertsN];
    normals[0] = V3(0.0f, 0.0f, -1.0f);
    normals[1] = V3(1.0f, 0.0f, 0.0f);
    normals[2] = V3(0.0f, 0.0f, 1.0f);
    normals[3] = V3(-1.0f, 0.0f, 0.0f);
    normals[4] = V3(0.0f, -1.0f, 0.0f);
    normals[5] = V3(0.0f, 1.0f, 0.0f);

    cols = new V3[vertsN];
    cols[0] =
    cols[1] =
    cols[2] =
    cols[3] = V3(1.0f, 0.0f, 0.0f);
    cols[4] =
    cols[5] =
    cols[6] =
    cols[7] = V3(0.0f, 0.0f, 0.0f);
}

#if 0
4      7

0     3
    5      6
1     2
#endif

void TM::LoadBin(char *fname) {

    ifstream ifs(fname, ios::binary);
    if (ifs.fail()) {
        cerr << "INFO: cannot open file: " << fname << endl;
        return;
    }

    ifs.read((char*)&vertsN, sizeof(int));
    char yn;
    ifs.read(&yn, 1); // always xyz
    if (yn != 'y') {
        cerr << "INTERNAL ERROR: there should always be vertex xyz data" << endl;
        return;
    }
    if (verts)
        delete verts;
    verts = new V3[vertsN];

    ifs.read(&yn, 1); // cols 3 floats
    normals = 0;
    if (cols)
        delete cols;
    cols = 0;
    if (yn == 'y') {
        cols = new V3[vertsN];
    }

    ifs.read(&yn, 1); // normals 3 floats
    if (normals)
        delete normals;
    normals = 0;
    if (yn == 'y') {
        normals = new V3[vertsN];
    }

    ifs.read(&yn, 1); // texture coordinates 2 floats
    float *tcs = 0; // don't have texture coordinates for now
    if (tcs)
        delete tcs;
    tcs = 0;
    if (yn == 'y') {
        tcs = new float[vertsN * 2];
    }


    ifs.read((char*)verts, vertsN * 3 * sizeof(float)); // load verts

    if (cols) {
        ifs.read((char*)cols, vertsN * 3 * sizeof(float)); // load cols
    }

    if (normals)
        ifs.read((char*)normals, vertsN * 3 * sizeof(float)); // load normals

    if (tcs)
        ifs.read((char*)tcs, vertsN * 2 * sizeof(float)); // load texture coordinates

    ifs.read((char*)&trisN, sizeof(int));
    if (tris)
        delete tris;
    tris = new unsigned int[trisN * 3];
    ifs.read((char*)tris, trisN * 3 * sizeof(unsigned int)); // read tiangles

    ifs.close();

    cerr << "INFO: loaded " << vertsN << " verts, " << trisN << " tris from " << endl << "      " << fname << endl;
    cerr << "      xyz " << ((cols) ? "rgb " : "") << ((normals) ? "nxnynz " : "") << ((tcs) ? "tcstct " : "") << endl;

}


void TM::RenderAsPoints(int psize, PPC *ppc, FrameBuffer *fb) {

    for (int vi = 0; vi < vertsN; vi++) {
        V3 pp;
        if (!ppc->Project(verts[vi], pp))
            continue;
        fb->DrawDisk(pp, (float)psize, 0xFF0000FF);
    }

}

void TM::RenderWireFrame(PPC *ppc, FrameBuffer *fb) {

    for (int tri = 0; tri < trisN; tri++) {
        for (int ei = 0; ei < 3; ei++) {
            V3 v0 = verts[tris[3 * tri + ei]];
            V3 v1 = verts[tris[3 * tri + (ei + 1) % 3]];
            V3 c0 = cols[tris[3 * tri + ei]];
            V3 c1 = cols[tris[3 * tri + (ei + 1) % 3]];
            V3 pv0, pv1;
            if (!ppc->Project(v0, pv0))
                continue;
            if (!ppc->Project(v1, pv1))
                continue;
            fb->DrawSegment(pv0, pv1, c0, c1);
        }
    }

}
//
void TM::RenderFilled(PPC *ppc, FrameBuffer *fb, FrameBuffer* shadowfb, PPC* lights, float* augments) {

	
    // render with model space interpolation of textures and colors	
	
    for (int tri = 0; tri < trisN; tri++) {
        V3 vs[3], cs[3], ns[3], ttcs[3];
        for (int vi = 0; vi < 3; vi++) {
            vs[vi] = verts[tris[3 * tri + vi]];
            cs[vi] = cols[tris[3 * tri + vi]];
            ns[vi] = normals[tris[3 * tri + vi]];
            if (tcs)
                ttcs[vi] = tcs[tris[3 * tri + vi]];
        }

        // project vertices
        V3 pvs[3];
        int needContinue = 0;
        for (int vi = 0; vi < 3; vi++) {
            if (!ppc->Project(vs[vi], pvs[vi])) {
                needContinue = 1;
                break;
            }
        }
        if (needContinue)
            continue;

        // clip axis aligned bounding box
        AABB aabb(pvs[0]);
        aabb.AddPoint(pvs[1]);
        aabb.AddPoint(pvs[2]);
        if (!aabb.ClipWithFrame(fb->w, fb->h))
            continue;
        int top = (int)(aabb.minv[1] + 0.5f);
        int bottom = (int)(aabb.maxv[1] - 0.5f);
        int left = (int)(aabb.minv[0] + 0.5f);
        int right = (int)(aabb.maxv[0] - 0.5f);

        // setup edge equations
        M33 eeqs;
        eeqs[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
        eeqs[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
        eeqs[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);

        // setup screen space interpolation
        M33 ssim; ssim[0] = pvs[0]; ssim[1] = pvs[1]; ssim[2] = pvs[2];
        ssim.setColumn(2, V3(1.0f, 1.0f, 1.0f)); ssim = ssim.invert();
        V3 le1w = ssim * V3(pvs[0][2], pvs[1][2], pvs[2][2]);
        M33 colm; colm[0] = cs[0]; colm[1] = cs[1]; colm[2] = cs[2];
        M33 lecols = (ssim * colm).transpose();
        M33 nm; nm[0] = ns[0]; nm[1] = ns[1]; nm[2] = ns[2];
        M33 lenormals = (ssim * nm).transpose();
        M33 tcm; tcm[0] = ttcs[0]; tcm[1] = ttcs[1]; tcm[2] = ttcs[2];
        M33 letcs = (ssim * tcm).transpose();

        M33 modelSpaceInterp;
        modelSpaceInterp.setColumn(0, vs[0]-ppc->C);
        modelSpaceInterp.setColumn(1, vs[1]-ppc->C);
        modelSpaceInterp.setColumn(2, vs[2]-ppc->C);
        M33 abc; abc.setColumn(0, ppc->a); abc.setColumn(1, ppc->b); abc.setColumn(2, ppc->c);
        modelSpaceInterp = modelSpaceInterp.invert() * abc;

        V3 s;
        V3 t;

        for (int v = top; v <= bottom; v++) {

            for (int u = left; u <= right; u++) {

                V3 pixv(.5f + (float)u, .5f + (float)v, 1.0f);
                V3 svs = eeqs*pixv;
                if (svs[0] < 0.0f || svs[1] < 0.0f || svs[2] < 0.0f)
                    continue;
                float currz = (le1w * pixv);
                if (fb->IsCloserThenSet(currz, u, v)) {
                    V3 currCol = lecols*pixv;
                    V3 currNormal = (lenormals*pixv).normalizedVec();
             
                    fb->Set(u, v, currCol.GetColor());
                    if (textures) {

                        V3 currtcs = letcs*pixv;
                        for(int i=0; i < 3; i++){
                            //ttcs[i] = tcs[tris[3 * tri + i]];
                            s[i] = ttcs[i].xyz[0];
                            t[i] = ttcs[i].xyz[1];
                        }
                        float denom = (modelSpaceInterp.getColumn(0) * pixv[0] * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(1) * pixv[1] * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(2) * V3(1.0f, 1.0f ,1.0f));
                        float s_interp = ((modelSpaceInterp.getColumn(0) * s * pixv[0]) + (modelSpaceInterp.getColumn(1) * s * pixv[1]) + (modelSpaceInterp.getColumn(2) * s)) / denom;
                        float t_interp = ((modelSpaceInterp.getColumn(0) * t * pixv[0]) + (modelSpaceInterp.getColumn(1) * t * pixv[1]) + (modelSpaceInterp.getColumn(2) * t)) / denom;
						//fb->Set(u, v, textures->LookUpNN(currtcs[0], currtcs[1]));
                        fb->Set(u, v, textures->LookUpBilinear(s_interp, t_interp));
                        //fb->Set(u, v, textures->LookUpNN(s_interp, t_interp));
                    }
                }
            }    
        }
    }
}

void TM::RenderEnvironment(PPC *ppc, FrameBuffer *fb, CubeMap *cm){

    // render environment from cube map first, then render tm objects
    V3 dir;
    float texU, texV;
    int tU, tV, face;
    for(int v = 0; v <= fb->h; v++){
        for(int u = 0; u <= fb->w; u++){
            ppc->Unproject(V3(float(u),float(v),1.0f), dir);
            //dir = V3(float(u), float(v), 1.0f);
            unsigned int col = cm->GetColor2(dir);
            fb->Set(u,v, col);
        }
    }

    for (int tri = 0; tri < trisN; tri++) {
        V3 vs[3], cs[3], ns[3], ttcs[3];
        for (int vi = 0; vi < 3; vi++) {
            vs[vi] = verts[tris[3 * tri + vi]];
            cs[vi] = cols[tris[3 * tri + vi]];
            ns[vi] = normals[tris[3 * tri + vi]];
            if (tcs)
                ttcs[vi] = tcs[tris[3 * tri + vi]];
        }

        // project vertices
        V3 pvs[3];
        int needContinue = 0;
        for (int vi = 0; vi < 3; vi++) {
            if (!ppc->Project(vs[vi], pvs[vi])) {
                needContinue = 1;
                break;
            }
        }
        if (needContinue)
            continue;

        // clip axis aligned bounding box
        AABB aabb(pvs[0]);
        aabb.AddPoint(pvs[1]);
        aabb.AddPoint(pvs[2]);
        if (!aabb.ClipWithFrame(fb->w, fb->h))
            continue;
        int top = (int)(aabb.minv[1] + 0.5f);
        int bottom = (int)(aabb.maxv[1] - 0.5f);
        int left = (int)(aabb.minv[0] + 0.5f);
        int right = (int)(aabb.maxv[0] - 0.5f);

        // setup edge equations
        M33 eeqs;
        eeqs[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
        eeqs[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
        eeqs[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);

        // setup screen space interpolation
        M33 ssim; ssim[0] = pvs[0]; ssim[1] = pvs[1]; ssim[2] = pvs[2];
        ssim.setColumn(2, V3(1.0f, 1.0f, 1.0f)); ssim = ssim.invert();
        V3 le1w = ssim * V3(pvs[0][2], pvs[1][2], pvs[2][2]);
        M33 colm; colm[0] = cs[0]; colm[1] = cs[1]; colm[2] = cs[2];
        M33 lecols = (ssim * colm).transpose();
        M33 nm; nm[0] = ns[0]; nm[1] = ns[1]; nm[2] = ns[2];
        M33 lenormals = (ssim * nm).transpose();

        for (int v = top; v <= bottom; v++) {
            for (int u = left; u <= right; u++) {
                V3 pixv(.5f + (float)u, .5f + (float)v, 1.0f);
                V3 svs = eeqs*pixv;
                if (svs[0] < 0.0f || svs[1] < 0.0f || svs[2] < 0.0f)
                    continue;
                float currz = (le1w * pixv);
                if (fb->IsCloserThenSet(currz, u, v)) {
                    //V3 currCol = lecols * pixv;
                    //V3 currNormal = (lenormals * pixv).normalizedVec();
                    //fb->Set(u, v, currCol.GetColor());
                    V3 dir, reflected;
                    V3 currNormal = (lenormals * pixv).normalizedVec();
                    ppc->Unproject(V3(float(u), float(v), 1.0f), dir);
                    reflected = (dir - currNormal*(2*(dir*currNormal))).normalizedVec();
                    unsigned int newCol = cm->GetColor2(reflected);
                    fb->Set(u, v, newCol);
                }
            }
        }
    }
}


void TM::RenderFilled(PPC *ppc, FrameBuffer *fb){

    // screen space interpolation of tm object colors, normals
    
    for (int tri = 0; tri < trisN; tri++) {
        V3 vs[3], cs[3], ns[3], ttcs[3];
        for (int vi = 0; vi < 3; vi++) {
            vs[vi] = verts[tris[3 * tri + vi]];
            cs[vi] = cols[tris[3 * tri + vi]];
            ns[vi] = normals[tris[3 * tri + vi]];
            if (tcs)
                ttcs[vi] = tcs[tris[3 * tri + vi]];
        }

        // project vertices
        V3 pvs[3];
        int needContinue = 0;
        for (int vi = 0; vi < 3; vi++) {
            if (!ppc->Project(vs[vi], pvs[vi])) {
                needContinue = 1;
                break;
            }
        }
        if (needContinue)
            continue;

        // clip axis aligned bounding box
        AABB aabb(pvs[0]);
        aabb.AddPoint(pvs[1]);
        aabb.AddPoint(pvs[2]);
        if (!aabb.ClipWithFrame(fb->w, fb->h))
            continue;
        int top = (int)(aabb.minv[1] + 0.5f);
        int bottom = (int)(aabb.maxv[1] - 0.5f);
        int left = (int)(aabb.minv[0] + 0.5f);
        int right = (int)(aabb.maxv[0] - 0.5f);

        // setup edge equations
        M33 eeqs;
        eeqs[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
        eeqs[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
        eeqs[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);

        // setup screen space interpolation
        M33 ssim; ssim[0] = pvs[0]; ssim[1] = pvs[1]; ssim[2] = pvs[2];
        ssim.setColumn(2, V3(1.0f, 1.0f, 1.0f)); ssim = ssim.invert();
        V3 le1w = ssim * V3(pvs[0][2], pvs[1][2], pvs[2][2]);
        M33 colm; colm[0] = cs[0]; colm[1] = cs[1]; colm[2] = cs[2];
        M33 lecols = (ssim * colm).transpose();
        M33 nm; nm[0] = ns[0]; nm[1] = ns[1]; nm[2] = ns[2];
        M33 lenormals = (ssim * nm).transpose();

//        M33 modelSpaceInterp;
//        modelSpaceInterp.setColumn(0, vs[0]-ppc->C);
//        modelSpaceInterp.setColumn(1, vs[1]-ppc->C);
//        modelSpaceInterp.setColumn(2, vs[2]-ppc->C);
//        M33 abc; abc.setColumn(0, ppc->a); abc.setColumn(1, ppc->b); abc.setColumn(2, ppc->c);
//        modelSpaceInterp = modelSpaceInterp.invert() * abc;

        //V3 s, t;
        for (int v = top; v <= bottom; v++) {
            for (int u = left; u <= right; u++) {
                V3 pixv(.5f + (float)u, .5f + (float)v, 1.0f);
                V3 svs = eeqs*pixv;
                if (svs[0] < 0.0f || svs[1] < 0.0f || svs[2] < 0.0f)
                    continue;
                float currz = (le1w * pixv);
                if (fb->IsCloserThenSet(currz, u, v)) {
                    V3 currCol = lecols * pixv;
                    V3 currNormal = (lenormals * pixv).normalizedVec();
                    fb->Set(u, v, currCol.GetColor());
//                    for(int i=0; i < 3; i++){
//                        s[i] = ttcs[i].xyz[0];
//                        t[i] = ttcs[i].xyz[1];
//                    }
//                    float denom = (modelSpaceInterp.getColumn(0) * pixv[0] * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(1) * pixv[1] * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(2) * V3(1.0f, 1.0f ,1.0f));
//                    float s_interp = ((modelSpaceInterp.getColumn(0) * s * pixv[0]) + (modelSpaceInterp.getColumn(1) * s * pixv[1]) + (modelSpaceInterp.getColumn(2) * s)) / denom;
//                    float t_interp = ((modelSpaceInterp.getColumn(0) * t * pixv[0]) + (modelSpaceInterp.getColumn(1) * t * pixv[1]) + (modelSpaceInterp.getColumn(2) * t)) / denom;
//                    fb->Set(u, v, textures->LookUpBilinear(s_interp, t_interp));

                }
            }
        }
    }
}


V3 TM::GetCenter() {

    V3 ret(0.0f, 0.0f, 0.0f);
    for (int vi = 0; vi < vertsN; vi++)
        ret = ret + verts[vi];
    ret = ret / (float)vertsN;
    return ret;

}

void TM::Rotate(V3 aO, V3 aD, float theta) {

    for (int vi = 0; vi < vertsN; vi++) {
        verts[vi] = verts[vi].rotateAxis(aO, aD, theta);
    }

}


void TM::Translate(V3 tv) {

    for (int vi = 0; vi < vertsN; vi++)
        verts[vi] = verts[vi] + tv;

}

void TM::SetCenter(V3 newCenter) {

    V3 center = GetCenter();
    V3 tv = newCenter - center;
    Translate(tv);

}


void TM::Light(float ka, V3 ld, V3 eye, float* augments) {

    if (!normals) {
        cerr << "INFO: need normals" << endl;
        return;
    }
    for (int vi = 0; vi < vertsN; vi++) {
        //cols[vi] = verts[vi].Light(matColor, ka, ld, normals[vi]);
    }

}


void TM::VisualizeVertexNormals(PPC *ppc, FrameBuffer *fb, float vlength) {

    if (!normals)
        return;
    for (int vi = 0; vi < vertsN; vi++) {
        fb->Render3DSegment(ppc, verts[vi], verts[vi] + normals[vi] * vlength,
                            V3(0.0f, 0.0f, 0.0f), V3(1.0f, 0.0f, 0.0f));
    }
    fb->redraw();

}

void TM::SetUnshared(TM *tm) {

    trisN = tm->trisN;
    vertsN = tm->trisN * 3;
    verts = new V3[vertsN];
    tris = new unsigned int[trisN*3];
    if (tm->cols)
        cols = new V3[vertsN];
    if (tm->normals)
        normals = new V3[vertsN];

    for (int ti = 0; ti < tm->trisN; ti++) {
        verts[3 * ti + 0] = tm->verts[tm->tris[ti * 3 + 0]];
        verts[3 * ti + 1] = tm->verts[tm->tris[ti * 3 + 1]];
        verts[3 * ti + 2] = tm->verts[tm->tris[ti * 3 + 2]];
        if (cols) {
            cols[3 * ti + 0] = tm->cols[tm->tris[ti * 3 + 0]];
            cols[3 * ti + 1] = tm->cols[tm->tris[ti * 3 + 1]];
            cols[3 * ti + 2] = tm->cols[tm->tris[ti * 3 + 2]];
        }
        if (normals) {
            normals[3 * ti + 0] = tm->normals[tm->tris[ti * 3 + 0]];
            normals[3 * ti + 1] = tm->normals[tm->tris[ti * 3 + 1]];
            normals[3 * ti + 2] = tm->normals[tm->tris[ti * 3 + 2]];
        }
        tris[3 * ti + 0] = 3 * ti + 0;
        tris[3 * ti + 1] = 3 * ti + 1;
        tris[3 * ti + 2] = 3 * ti + 2;
    }


}

void TM::SetAsCopy(TM *tm) {

    vertsN = tm->vertsN;
    trisN = tm->trisN;
    verts = new V3[vertsN];
    for (int vi = 0; vi < vertsN; vi++)
        verts[vi] = tm->verts[vi];
    tris = new unsigned int[3 * trisN];
    for (int ti = 0; ti < trisN*3; ti++)
        tris[ti] = tm->tris[ti];
    if (tm->cols) {
        cols = new V3[vertsN];
        for (int vi = 0; vi < vertsN; vi++)
            cols[vi] = tm->cols[vi];
    }
    if (tm->normals) {
        normals = new V3[vertsN];
        for (int vi = 0; vi < vertsN; vi++)
            normals[vi] = tm->normals[vi];
    }

}

void TM::Explode(float t) {
    for (int ti = 0; ti < trisN; ti++) {
        unsigned int inds[3];
        inds[0] = tris[3 * ti + 0];
        inds[1] = tris[3 * ti + 1];
        inds[2] = tris[3 * ti + 2];
        // v = (v1-v0) ^ (v2-v0)
        V3 n = (verts[inds[1]] - verts[inds[0]]) ^
               (verts[inds[2]] - verts[inds[0]]);
        n = n.normalizedVec();
        verts[inds[0]] = verts[inds[0]] + n*t;
        verts[inds[1]] = verts[inds[1]] + n*t;
        verts[inds[2]] = verts[inds[2]] + n*t;
    }
}

void TM::SetOneTriangle(V3 v0, V3 v1, V3 v2) {

    vertsN = 3;
    trisN = 1;
    verts = new V3[vertsN];
    cols = new V3[vertsN];
    normals = new V3[vertsN];

    verts[0] = v0;
    verts[1] = v1;
    verts[2] = v2;
    cols[0] = V3(0.0f, 0.0f, 0.0f);
    cols[1] = cols[0];
    cols[2] = cols[0];
    V3 n = ((v1 - v0) ^ (v2 - v0)).normalizedVec();
    normals[0] =
    normals[1] =
    normals[2] = n;

    tris = new unsigned int[3 * trisN];
    tris[0] = 0;
    tris[1] = 1;
    tris[2] = 2;
}


// vertical rectangle in x0y plane, with O as center
void TM::SetTexturedRectangle(float rectw, float recth, int orient) {

    trisN = 2;
    vertsN = 4;
    verts = new V3[vertsN];
    cols = new V3[vertsN];
    normals = new V3[vertsN];
    tcs = new V3[vertsN];

    tris = new unsigned int[trisN*3];

//0(0, 0)       3 (1, 0)
//	   \
//		   \
//1(0, 1)       2 (1, 1)

    int tri = 0;
    tris[3 * tri + 0] = 0; // tris[0] = 0;
    tris[3 * tri + 1] = 1;
    tris[3 * tri + 2] = 2;
    tri++;
    tris[3 * tri + 0] = 2;
    tris[3 * tri + 1] = 3;
    tris[3 * tri + 2] = 0;
    tri++;

    // orient is 1 for z as upg, 0 for y as upg
    if(orient){
        verts[0] = V3(-rectw / 2.0f, recth / 2.0f, 0.0f);
        verts[1] = V3(-rectw / 2.0f, -recth / 2.0f, 0.0f);
        verts[2] = V3(rectw / 2.0f, -recth / 2.0f, 0.0f);
        verts[3] = V3(rectw / 2.0f, recth / 2.0f, 0.0f);
    }
    else{
        verts[0] = V3(-rectw / 2.0f, 0.0f, recth / 2.0f);
        verts[1] = V3(-rectw / 2.0f, 0.0f, -recth / 2.0f);
        verts[2] = V3(rectw / 2.0f, 0.0f, -recth / 2.0f);
        verts[3] = V3(rectw / 2.0f, 0.0f, recth / 2.0f);
    }

    normals[0] =
    normals[1] =
    normals[2] =
    normals[3] = V3(0.0f, 1.0f, 0.0f);

    cols[0] = cols[1] = cols[2] = cols[3] = V3(1.0f, 0.0f, 0.0f);

    float tc = 3.0f;
    A = V3(0.0f, 0.0f, 0.0f);
    B = V3(0.0f, tc, 0.0f);
    C = V3(tc, tc, 0.0f);
    D = V3(tc, 0.0f, 0.0f);

    //nothing flipped
    tcs[0] = A;
    tcs[1] = B;
    tcs[2] = C;
    tcs[3] = D;

//    //flipped x
//    tcs[0] = V3(tc, 0.0f, 0.0f);
//    tcs[1] = V3(tc, tc, 0.0f);
//    tcs[2] = V3(0.0f, tc, 0.0f);
//    tcs[3] = V3(0.0f, 0.0f, 0.0f);
//
//    //flipped y
//    tcs[0] = V3(0.0f, tc, 0.0f);
//    tcs[1] = V3(0.0f, 0.0f, 0.0f);
//    tcs[2] = V3(tc, 0.0f, 0.0f);
//    tcs[3] = V3(tc, tc, 0.0f);
//
//    //flipped xy
//    tcs[0] = V3(tc, tc, 0.0f);
//    tcs[1] = V3(tc, 0.0f, 0.0f);
//    tcs[2] = V3(0.0f, 0.0f, 0.0f);
//    tcs[3] = V3(0.0f, tc, 0.0f);

}

void TM::SetTexturedCube(V3 cc, float sl) {

    vertsN = 24;
    trisN = 12;
    tcsN = 24;
    tris = new unsigned int[trisN*3];
    verts = new V3[vertsN];
    cols = new V3[vertsN];
    tcs = new V3[tcsN*4];
    normals = new V3[tcsN];

    float sl2 = sl / 2.0f;

    V3 v0 = cc + V3(-sl2, +sl2, +sl2);
    V3 v1 = cc + V3(-sl2, -sl2, +sl2);
    V3 v2 = cc + V3(+sl2, -sl2, +sl2);
    V3 v3 = cc + V3(+sl2, +sl2, +sl2);
    V3 v4 = cc + V3(-sl2, +sl2, -sl2);
    V3 v5 = cc + V3(-sl2, -sl2, -sl2);
    V3 v6 = cc + V3(+sl2, -sl2, -sl2);
    V3 v7 = cc + V3(+sl2, +sl2, -sl2);

    //front
    verts[0] = cc + v0;
    verts[1] = cc + v1;
    verts[2] = cc + v2;
    verts[3] = cc + v3;

    //back
    verts[4] = cc + v7;
    verts[5] = cc + v6;
    verts[6] = cc + v5;
    verts[7] = cc + v4;

    //right
    verts[8] = cc + v3;
    verts[9] = cc + v2;
    verts[10] = cc + v6;
    verts[11] = cc + v7;

    //left
    verts[12] = cc + v4;
    verts[13] = cc + v5;
    verts[14] = cc + v1;
    verts[15] = cc + v0;

    //top
    verts[16] = cc + v4;
    verts[17] = cc + v0;
    verts[18] = cc + v3;
    verts[19] = cc + v7;

    //bottom
    verts[20] = cc + v5;
    verts[21] = cc + v1;
    verts[22] = cc + v2;
    verts[23] = cc + v6;


    int tri = 0;
    //top
    tris[3 * tri + 0] = 0;
    tris[3 * tri + 1] = 1;
    tris[3 * tri + 2] = 2;
    tri++;
    tris[3 * tri + 0] = 2;
    tris[3 * tri + 1] = 3;
    tris[3 * tri + 2] = 0;
    tri++;

    //back
    tris[3 * tri + 0] = 7;
    tris[3 * tri + 1] = 6;
    tris[3 * tri + 2] = 5;
    tri++;
    tris[3 * tri + 0] = 5;
    tris[3 * tri + 1] = 4;
    tris[3 * tri + 2] = 7;
    tri++;

    //right
    tris[3 * tri + 0] = 3;
    tris[3 * tri + 1] = 2;
    tris[3 * tri + 2] = 6;
    tri++;
    tris[3 * tri + 0] = 6;
    tris[3 * tri + 1] = 7;
    tris[3 * tri + 2] = 3;
    tri++;

    //left
    tris[3 * tri + 0] = 4;
    tris[3 * tri + 1] = 5;
    tris[3 * tri + 2] = 1;
    tri++;
    tris[3 * tri + 0] = 1;
    tris[3 * tri + 1] = 0;
    tris[3 * tri + 2] = 4;
    tri++;

    //top
    tris[3 * tri + 0] = 4;
    tris[3 * tri + 1] = 0;
    tris[3 * tri + 2] = 3;
    tri++;
    tris[3 * tri + 0] = 3;
    tris[3 * tri + 1] = 7;
    tris[3 * tri + 2] = 4;
    tri++;

    //bottom
    tris[3 * tri + 0] = 5;
    tris[3 * tri + 1] = 1;
    tris[3 * tri + 2] = 2;
    tri++;
    tris[3 * tri + 0] = 2;
    tris[3 * tri + 1] = 6;
    tris[3 * tri + 2] = 5;
    tri++;

    //reversed because directions go into cube
    //front
    normals[0] = V3(0.0f, 0.0f, -1.0f);
    normals[1] = V3(0.0f, 0.0f, -1.0f);
    normals[2] = V3(0.0f, 0.0f, -1.0f);
    normals[3] = V3(0.0f, 0.0f, -1.0f);
    //back
    normals[4] = V3(0.0f, 0.0f, 1.0f);
    normals[5] = V3(0.0f, 0.0f, 1.0f);
    normals[6] = V3(0.0f, 0.0f, 1.0f);
    normals[7] = V3(0.0f, 0.0f, 1.0f);

    //right
    normals[8] = V3(-1.0f, 0.0f, 0.0f);
    normals[9] = V3(-1.0f, 0.0f, 0.0f);
    normals[10] = V3(-1.0f, 0.0f, 0.0f);
    normals[11] = V3(-1.0f, 0.0f, 0.0f);
    //left
    normals[12] = V3(1.0f, 0.0f, 0.0f);
    normals[13] = V3(1.0f, 0.0f, 0.0f);
    normals[14] = V3(1.0f, 0.0f, 0.0f);
    normals[15] = V3(1.0f, 0.0f, 0.0f);

    //top
    normals[16] = V3(0.0f, -1.0f, 0.0f);
    normals[17] = V3(0.0f, -1.0f, 0.0f);
    normals[18] = V3(0.0f, -1.0f, 0.0f);
    normals[19] = V3(0.0f, -1.0f, 0.0f);

    //bottom
    normals[20] = V3(0.0f, 1.0f, 0.0f);
    normals[21] = V3(0.0f, 1.0f, 0.0f);
    normals[22] = V3(0.0f, 1.0f, 0.0f);
    normals[23] = V3(0.0f, 1.0f, 0.0f);


    cols[0] =
    cols[1] =
    cols[2] =
    cols[3] = V3(1.0f, 0.0f, 1.0f);
    cols[4] =
    cols[5] =
    cols[6] =
    cols[7] = V3(1.0f, 0.0f, 1.0f);

    float tc = 1.0f;
    //Face front
    tcs[0] = V3(0.0f, 0.0f, 0.0f);
    tcs[1] = V3(0.0f, tc, 0.0f);
    tcs[2] = V3(tc, tc, 0.0f);
    tcs[3] = V3(tc, 0.0f, 0.0f);

    //Face back
    tcs[4] = V3(tc, 0.0f, tc);
    tcs[5] = V3(tc, tc, tc);
    tcs[6] = V3(0.0f, tc, tc);
    tcs[7] = V3(0.0f, 0.0f, tc);

    //Face right
    tcs[8] = V3(tc, 0.0f, 0.0f);
    tcs[9] = V3(tc, tc, 0.0f);
    tcs[10] = V3(tc, tc, tc);
    tcs[11] = V3(tc, 0.0f, tc);

    //Face left
    tcs[12] = V3(0.0f, 0.0f, tc);
    tcs[13] = V3(0.0f, tc, tc);
    tcs[14] = V3(0.0f, tc, 0.0f);
    tcs[15] = V3(0.0f, 0.0f, 0.0f);

    //Face top
    tcs[16] = V3(0.0f, 0.0f, tc);
    tcs[17] = V3(0.0f, 0.0f, 0.0f);
    tcs[18] = V3(tc, 0.0f, 0.0f);
    tcs[19] = V3(tc, 0.0f, tc);

    //Face bottom
    tcs[20] = V3(0.0f, tc, tc);
    tcs[21] = V3(0.0f, tc, 0.0f);
    tcs[22] = V3(tc, tc, 0.0f);
    tcs[23] = V3(tc, tc, tc);

}


void TM::RenderTexturedHW(unsigned int *texture) {

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    //glEnable(GL_TEXTURE_2D);

    if (texture != NULL) {
        // enable texture coordinate array
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    if(normals)
        glEnableClientState(GL_NORMAL_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, verts);
    glColorPointer(3, GL_FLOAT, 0, cols);

    if (texture != NULL) {
        // provide array of texture coordinates
        glTexCoordPointer(3, GL_FLOAT, 0, verts);
    }

    if(normals)
        glNormalPointer(GL_FLOAT, 0, normals);

    glDrawElements(GL_TRIANGLES, 3 * trisN, GL_UNSIGNED_INT, tris);

    if(normals){
        glDisableClientState(GL_NORMAL_ARRAY);
    }
    if (texture != NULL) {
        // disable what was enabled for hw texturing
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}

void TM::RenderHW() {

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verts);
    glColorPointer(3, GL_FLOAT, 0, cols);

    glDrawElements(GL_TRIANGLES, 3 * trisN, GL_UNSIGNED_INT, tris);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}


AABB TM::SetAABB() {
    AABB ret(verts[0]);
    for (int vi = 0; vi < vertsN; vi++)
        ret.AddPoint(verts[vi]);

    return ret;
}

#include "tm.h"
#include "ppc.h"
#include "framebuffer.h"
#include "M33.h"

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

void TM::SetAsSquare(V3 cc, float sideLength) {

    vertsN = 4;
    verts = new V3[vertsN];
    float sl2 = sideLength / 2.0f;

    verts[0] = cc + V3(-sl2, -sl2, +sl2);
    verts[1] = cc + V3(-sl2, -sl2, -sl2);
    verts[2] = cc + V3(+sl2, -sl2, -sl2);
    verts[3] = cc + V3(+sl2, -sl2, +sl2);

    trisN = 2;
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


    cols = new V3[vertsN];
    unsigned int tableColor = 0xFF3EB489;
    V3 newCol;
    newCol.SetFromColor(tableColor);
    cols[0] = newCol;
    cols[1] = newCol;
    cols[2] = newCol;
    cols[3] = newCol;
    normals = new V3[vertsN];
    normals[0] = V3(0.0f, 1.0f, 0.0f);
    normals[1] = V3(0.0f, 1.0f, 0.0f);
    normals[2] = V3(0.0f, 1.0f, 0.0f);
    normals[3] = V3(0.0f, 1.0f, 0.0f);



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
        fb->DrawDisk(pp, (float)psize, 0xFF000000);
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
        cols[vi] = verts[vi].Light(cols[vi], ka, (ld).normalizedVec(), normals[vi], eye, augments);
        //cols[vi] = verts[vi].LightAmbDiffSpec(matColor, ka, (ld-verts[vi]).normalizedVec(), normals[vi], eye, augments);
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

void TM::Scale(float s) {
    for(int vi=0; vi < vertsN; vi++){
        verts[vi] = verts[vi] + (verts[vi]-this->GetCenter()).normalizedVec()*s;
        //maybe add to original point?
    }
}

//hw5 shadows
//void TM::RenderFilled(PPC *ppc, FrameBuffer *fb, FrameBuffer* shadowfb, PPC* lights, float* augments) {
//    M33 interpolationM = M33();
//    for (int tri = 0; tri < trisN; tri++) {
//        V3 vs[3], cs[3], ns[3];
//        for (int vi = 0; vi < 3; vi++) {
//            vs[vi] = verts[tris[3 * tri + vi]];
//            cs[vi] = cols[tris[3 * tri + vi]];
//            ns[vi] = normals[tris[3 * tri + vi]];
//        }
//
//        V3 pvs[3];
//
//        int needContinue = 0;
//        for (int vi = 0; vi < 3; vi++) {
//            if (!ppc->Project(vs[vi], pvs[vi])) {
//                needContinue = 1;
//                break;
//            }
//        }
//        if (needContinue)
//            continue;
//
//        AABB aabb(pvs[0]);
//        aabb.AddPoint(pvs[1]);
//        aabb.AddPoint(pvs[2]);
//        if (!aabb.ClipWithFrame(fb->w, fb->h))
//            continue;
//
//        int top = (int)(aabb.minv[1] + 0.5f);
//        int bottom = (int)(aabb.maxv[1] - 0.5f);
//        int left = (int)(aabb.minv[0] + 0.5f);
//        int right = (int)(aabb.maxv[0] - 0.5f);
//
//        M33 edges;
//        edges[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
//        edges[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
//        edges[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);
//
//        V3 u_vec = V3(pvs[0].xyz[0], pvs[1].xyz[0], pvs[2].xyz[0]);
//        V3 v_vec = V3(pvs[0].xyz[1], pvs[1].xyz[1], pvs[2].xyz[1]);
//        V3 z_vec = V3(pvs[0].xyz[2], pvs[1].xyz[2], pvs[2].xyz[2]);
//
//        M33 colInterp; M33 normInterp;
//        normInterp[0] = ns[0]; normInterp[1] = ns[1]; normInterp[2] = ns[2];
//        colInterp[0] = cs[0]; colInterp[1] = cs[1]; colInterp[2] = cs[2];
//
//        interpolationM.setColumn(0, u_vec);
//        interpolationM.setColumn(1, v_vec);
//        interpolationM.setColumn(2, V3(1.0f, 1.0f, 1.0f));
//        interpolationM = interpolationM.invert();
//
//        V3 zInterp = interpolationM * z_vec;
//        colInterp = (interpolationM * colInterp).transpose();
//        normInterp = (interpolationM * normInterp).transpose();
//
//        for (int currV = top; currV <= bottom; currV++) {
//            for (int currU = left; currU <= right; currU++) {
//                V3 currPix(.5f + (float) currU, .5f + (float) currV, 1.0f);
//                V3 sides = edges * currPix;
//
//                //if visible
//                if (sides[0] > 0.0f && sides[1] > 0.0f && sides[2] > 0.0f) {
//                    V3 unprojected;
//                    V3 proj;
//
//                    ppc->Unproject(currPix, unprojected);
//                    lights[0].Project(unprojected, proj);
//
//                    float currZ = (zInterp * currPix);
//                    float currshadowZ = proj.xyz[2];
//                    V3 newCol = colInterp * currPix;
//                    V3 newNormal = (normInterp * currPix).normalizedVec();
//
//                    if (proj.xyz[0] < 0.0f || proj.xyz[0] > shadowfb->w - 1 || proj.xyz[1] < 0.0f || proj.xyz[1] > shadowfb->h - 1) {
//                        //if not seen from lights pov
//                        //fb->Set(currU, currV, V3(0.0f, 0.0f, 0.0f).GetColor());
//                        newCol = newCol.Shade(newCol, 0.5f, lights[0].GetVD(), newNormal);
//                        fb->Set(currU, currV, newCol.GetColor());
//                    } else {
//                        float shadowZ = shadowfb->zb[int(((512) - 1 - proj.xyz[1]) * (512) + proj.xyz[0])];
//                        if (currshadowZ < shadowZ - 0.05f) {
//                            //make black
//                            newCol = newCol.Shade(newCol, 0.5f, lights[0].GetVD(), newNormal);
//                            fb->Set(currU, currV, newCol.GetColor());
//                        } else {
//                            if (fb->IsCloserThenSet(currZ, currU, currV)) {
//                                //V3 newCol = colInterp * currPix;
//                                //V3 newNormal = (normInterp * currPix).normalizedVec();
//                                newCol = newCol.Light(newCol, 0.5f, lights[0].GetVD(), newNormal, ppc->GetVD(), augments);
//                                fb->Set(currU, currV, newCol.GetColor());
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//}


//hw6 texture mapping
void TM::RenderFilled(PPC *ppc, FrameBuffer *fb, FrameBuffer* shadowfb, PPC* lights, float* augments) {
    M33 interpolationM = M33();
    for (int tri = 0; tri < trisN; tri++) {
        V3 vs[3], cs[3], ns[3], ttcs[3];
        for (int vi = 0; vi < 3; vi++) {
            vs[vi] = verts[tris[3 * tri + vi]];
            cs[vi] = cols[tris[3 * tri + vi]];
            ns[vi] = normals[tris[3 * tri + vi]];
            if (tcs)
                ttcs[vi] = tcs[tris[3 * tri + vi]];
        }

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

        AABB aabb(pvs[0]);
        aabb.AddPoint(pvs[1]);
        aabb.AddPoint(pvs[2]);
        if (!aabb.ClipWithFrame(fb->w, fb->h))
            continue;

        int top = (int)(aabb.minv[1] + 0.5f);
        int bottom = (int)(aabb.maxv[1] - 0.5f);
        int left = (int)(aabb.minv[0] + 0.5f);
        int right = (int)(aabb.maxv[0] - 0.5f);

        M33 edges;
        edges[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
        edges[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
        edges[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);

        V3 u_vec = V3(pvs[0].xyz[0], pvs[1].xyz[0], pvs[2].xyz[0]);
        V3 v_vec = V3(pvs[0].xyz[1], pvs[1].xyz[1], pvs[2].xyz[1]);
        V3 z_vec = V3(pvs[0].xyz[2], pvs[1].xyz[2], pvs[2].xyz[2]);

        M33 colInterp; M33 normInterp; M33 tcsInterp; M33 modelSpaceInterp;
        normInterp[0] = ns[0]; normInterp[1] = ns[1]; normInterp[2] = ns[2];
        colInterp[0] = cs[0]; colInterp[1] = cs[1]; colInterp[2] = cs[2];
        tcsInterp[0] = ttcs[0]; tcsInterp[1] = ttcs[1]; tcsInterp[2] = ttcs[2];

        modelSpaceInterp.setColumn(0, vs[0]-ppc->C);
        modelSpaceInterp.setColumn(1, vs[1]-ppc->C);
        modelSpaceInterp.setColumn(2, vs[2]-ppc->C);
        M33 abc; abc.setColumn(0, ppc->a); abc.setColumn(1, ppc->b); abc.setColumn(2, ppc->c);
        modelSpaceInterp = modelSpaceInterp.invert() * abc;

        V3 s = V3(0.0f, 0.0f, 0.0f);
        V3 t = V3(0.0f, 0.0f, 0.0f);
        for(int i=0; i < 2; i++){
               s[i] = ttcs[i].xyz[0];
               t[i] = ttcs[i].xyz[1];
        }

        interpolationM.setColumn(0, u_vec);
        interpolationM.setColumn(1, v_vec);
        interpolationM.setColumn(2, V3(1.0f, 1.0f, 1.0f));
        interpolationM = interpolationM.invert();

        V3 zInterp = interpolationM * z_vec;
        colInterp = (interpolationM * colInterp).transpose();
        normInterp = (interpolationM * normInterp).transpose();
        tcsInterp = (interpolationM * tcsInterp).transpose();

        for (int currV = top; currV <= bottom; currV++) {
            for (int currU = left; currU <= right; currU++) {
                V3 currPix(.5f + (float) currU, .5f + (float) currV, 1.0f);
                V3 sides = edges * currPix;

                //if visible
                if (sides[0] > 0.0f && sides[1] > 0.0f && sides[2] > 0.0f) {
                    float currZ =(zInterp * currPix);

                    if (fb->IsCloserThenSet(currZ, currU, currV)) {
                        V3 newCol = colInterp * currPix;
                        V3 newNormal = (normInterp * currPix).normalizedVec();
                        //newCol = newCol.Light(newCol, 0.5f, lights[0].GetVD(), newNormal, ppc->GetVD(), augments);
                        fb->Set(currU, currV, newCol.GetColor());
                        if (texture) {
                            //V3 currtcs = tcsInterp*currPix;

                            float denom = (modelSpaceInterp.getColumn(0) * currU * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(1) * currV * V3(1.0f, 1.0f ,1.0f)) + (modelSpaceInterp.getColumn(2) * V3(1.0f, 1.0f ,1.0f));
                            float s_interp = ((modelSpaceInterp.getColumn(0) * s * currU) + (modelSpaceInterp.getColumn(1) * s * currV) + (modelSpaceInterp.getColumn(2) * s)) / denom;
                            float t_interp = ((modelSpaceInterp.getColumn(0) * t * currU) + (modelSpaceInterp.getColumn(1) * t * currV) + (modelSpaceInterp.getColumn(2) * s)) / denom;

                            fb->Set(currU, currV, texture->LookUpNN(s_interp, t_interp));
                            //fb->Set(currU, currV, texture->LookUpBilinear(s_interp, t_interp));
                        }
                    }

                }
                else{
                    continue;
                }

            }
        }
    }

}

void TM::ShadowPass(PPC* light, FrameBuffer* shadowfb){
    M33 interpolationM = M33();
    for (int tri = 0; tri < trisN; tri++) {
        V3 vs[3], cs[3], ns[3];
        for (int vi = 0; vi < 3; vi++){
            vs[vi] = verts[tris[3 * tri + vi]];
        }

        V3 pvs[3];

        int needContinue = 0;
        for (int vi = 0; vi < 3; vi++) {
            if (!light[0].Project(vs[vi], pvs[vi])) {
                needContinue = 1;
                break;
            }
        }
        if (needContinue)
            continue;

        AABB aabb(pvs[0]);
        aabb.AddPoint(pvs[1]);
        aabb.AddPoint(pvs[2]);
        if (!aabb.ClipWithFrame(shadowfb->w, shadowfb->h))
            continue;

        int top = (int)(aabb.minv[1] + 0.5f);
        int bottom = (int)(aabb.maxv[1] - 0.5f);
        int left = (int)(aabb.minv[0] + 0.5f);
        int right = (int)(aabb.maxv[0] - 0.5f);

        M33 edges;
        edges[0].SetAsEdgeEquation(pvs[0], pvs[1], pvs[2]);
        edges[1].SetAsEdgeEquation(pvs[1], pvs[2], pvs[0]);
        edges[2].SetAsEdgeEquation(pvs[2], pvs[0], pvs[1]);

        V3 u_vec = V3(pvs[0].xyz[0], pvs[1].xyz[0], pvs[2].xyz[0]);
        V3 v_vec = V3(pvs[0].xyz[1], pvs[1].xyz[1], pvs[2].xyz[1]);
        V3 z_vec = V3(pvs[0].xyz[2], pvs[1].xyz[2], pvs[2].xyz[2]);

        interpolationM.setColumn(0, u_vec);
        interpolationM.setColumn(1, v_vec);
        interpolationM.setColumn(2, V3(1.0f, 1.0f, 1.0f));
        interpolationM = interpolationM.invert();

        V3 zInterp = interpolationM * z_vec;

        for (int currV = top; currV <= bottom; currV++) {
            for (int currU = left; currU <= right; currU++) {
                V3 currPix(.5f + (float) currU, .5f + (float) currV, 1.0f);
                V3 sides = edges * currPix;
                if (sides[0] > 0.0f && sides[1] > 0.0f && sides[2] > 0.0f) {
                    float currZ = (zInterp * currPix);
                    int check = shadowfb->IsCloserThenSet(currZ, currU, currV);
                }
                else{
                    continue;
                }

            }
        }
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
void TM::SetTexturedRectangle(float rectw, float recth) {

    trisN = 2;
    vertsN = 4;
    verts = new V3[vertsN];
    cols = new V3[vertsN];
    normals = new V3[vertsN];
    tcs = new V3[vertsN];

//0(0, 0)       3 (1, 0)
//	   \
//		   \
//1(0, 1)       2 (1, 1)

    verts[0] = V3(-rectw / 2.0f, recth / 2.0f, 0.0f);
    verts[1] = V3(-rectw / 2.0f, -recth / 2.0f, 0.0f);
    verts[2] = V3(rectw / 2.0f, -recth / 2.0f, 0.0f);
    verts[3] = V3(rectw / 2.0f, recth / 2.0f, 0.0f);

    normals[0] =
        normals[1] =
        normals[2] =
        normals[3] = V3(0.0f, 0.0f, 1.0f);

    cols[0] = cols[1] = cols[2] = cols[3] = V3(1.0f, 0.0f, 0.0f);

    float tc = 1.0f;
    tcs[0] = V3(0.0f, 0.0f, 0.0f);
    tcs[1] = V3(0.0f, tc, 0.0f);
    tcs[2] = V3(tc, tc, 0.0f);
    tcs[3] = V3(tc, 0.0f, 0.0f);

}
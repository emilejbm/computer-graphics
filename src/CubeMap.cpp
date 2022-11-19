//
// Created by emilejbm on 26/10/22.
//

#include "CubeMap.h"
#include <iostream>

void CubeMap::LoadFaces() {
    w = 512;
    h = 512;

    FrameBuffer* front = new FrameBuffer(100,100,w,h);
    FrameBuffer* back = new FrameBuffer(100,100,w,h);
    FrameBuffer* right = new FrameBuffer(100,100,w,h);
    FrameBuffer* left = new FrameBuffer(100,100,w,h);
    FrameBuffer* top = new FrameBuffer(100,100,w,h);
    FrameBuffer* bottom = new FrameBuffer(100,100,w,h);

    front->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_front.tiff");
    back->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_back.tiff");
    right->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_right.tiff");
    left->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_left.tiff");
    top->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_top.tiff");
    bottom->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/tiffs/uffizi_bottom.tiff");

//    front->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_front.tif");
//    back->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_back.tif");
//    right->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_right.tif");
//    left->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_left.tif");
//    top->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_top.tif");
//    bottom->LoadTiff("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw7/apt_pics/room_bottom.tif");


    PPC* ppc_front = new PPC(90, front->w, front->h);
    PPC* ppc_back = new PPC(90, back->w, back->h);
    PPC* ppc_right = new PPC(90, right->w, right->h);
    PPC* ppc_left = new PPC(90, left->w, left->h);
    PPC* ppc_top = new PPC(90, top->w, top->h);
    PPC* ppc_bottom = new PPC(90, bottom->w, bottom->h);

    ppc_front->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, -1.0f), V3(0.0f, -1.0f, 0.0f));
    ppc_back->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, 1.0f), V3(0.0f, -1.0f, 0.0f));
    ppc_right->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(1.0f, 0.0f, 0.0f), V3(0.0f, -1.0f, 0.0f));
    ppc_left->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(-1.0f, 0.0f, 0.0f), V3(0.0f, -1.0f, 0.0f));
    ppc_top->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 1.0f, 0.0f), V3(0.0f, -1.0f, 0.0f));
    ppc_bottom->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, -1.0f, 0.0f), V3(0.0f, -1.0f, 0.0f));

    ppcs.push_back(ppc_front);
    ppcs.push_back(ppc_back);
    ppcs.push_back(ppc_right);
    ppcs.push_back(ppc_left);
    ppcs.push_back(ppc_top);
    ppcs.push_back(ppc_bottom);

    fbs.push_back(front);
    fbs.push_back(back);
    fbs.push_back(right);
    fbs.push_back(left);
    fbs.push_back(top);
    fbs.push_back(bottom);

    last_face = 0;
}

unsigned int CubeMap::GetColor(V3 dir){

    V3 pp;
    if(ppcs[last_face]->Project(dir, pp)){
        if(pp[0] > 0 && pp[0] < fbs[last_face]->w && pp[1] > 0 && pp[1] < fbs[last_face]->h){
            return fbs[last_face]->LookUpBilinearCM(pp[0], pp[1]);
            //return fbs[last_face]->LookUpNNCM(pp[0], pp[1]);
        }
    }

    for(int i = 0; i < 6; i++){
        if(!ppcs[i]->Project(dir, pp)){
            continue;
        }
        if(pp[0] > 0 && pp[0] < fbs[i]->w && pp[1] > 0 && pp[1] < fbs[i]->h){
            last_face = i;
            return fbs[last_face]->LookUpBilinearCM(pp[0], pp[1]);
            //return fbs[i]->LookUpNNCM(pp[0], pp[1]);
        }
    }
}


//inspired from https://en.wikipedia.org/wiki/Cube_mapping#Memory_addressing
unsigned int CubeMap::GetColor2(V3 dir) {
    V3 pp;
//    if(ppcs[last_face]->Project(dir, pp)){
//f
//    }

    float absX = fabs(dir[0]); float absY = fabs(dir[1]); float absZ = fabs(dir[2]);

    bool isXPositive = dir[0] > 0 ? true : false;
    bool isYPositive = dir[1] > 0 ? true : false;
    bool isZPositive = dir[2] > 0 ? true : false;

    float maxAxis, u, v;


    //front
    if (!isZPositive && (absZ >= absX && absZ >= absY)) {
        last_face = 0;
        maxAxis = absZ;
        u = -dir[0];
        v = dir[1];
    }
    //back
    if (isZPositive && (absZ >= absX && absZ >= absY)) {
        last_face = 1;
        maxAxis = absZ;
        u = dir[0];
        v = dir[1];
    }
    //right
    if (isXPositive && (absX >= absY && absX >= absZ)) {
        last_face = 2;
        maxAxis = absX;
        u = -dir[2];
        v = dir[1];
    }
    //left
    if (!isXPositive && (absX >= absY && absX >= absZ)) {
        last_face = 3;
        maxAxis = absX;
        u = dir[2];
        v = dir[1];
    }
    //top
    if (!isYPositive && (absY >= absX && absY >= absZ)) {
        last_face = 5;
        maxAxis = absY;
        u = dir[0];
        v = dir[2];
    }
    //bottom
    if (isYPositive && (absY >= absX && absY >= absZ)) {
        last_face = 4;
        maxAxis = absY;
        u = dir[0];
        v = -dir[2];
    }

    u = (0.5f*(u/maxAxis+1.0f));
    v = (0.5f*(v/maxAxis+1.0f));
    return fbs[last_face]->LookUpBilinearCM(u,v);
//    int fbw = fbs[last_face]->w;
//    int fbh = fbs[last_face]->h;

    //return fbs[last_face]->pix[(fbh - 1 - int(v))*fbw + int(u)];

}

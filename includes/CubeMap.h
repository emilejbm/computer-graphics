//
// Created by emilejbm on 26/10/22.
//

#ifndef CS334_BEGINNER_CUBEMAP_H
#define CS334_BEGINNER_CUBEMAP_H

#include "framebuffer.h"
#include "tm.h"
#include "V3.h"
#include "ppc.h"
#include <vector>

class PPC;
class FrameBuffer;


class CubeMap {
public:
    int w, h, last_face;
    vector<PPC *> ppcs;
    vector<FrameBuffer *> fbs;

    void LoadFaces();
    unsigned int GetColor(V3 dir);
    unsigned int GetColor2(V3 dir);
    unsigned int GetReflectedColor(V3 dir);

};
#endif //CS334_BEGINNER_CUBEMAP_H

#pragma once

#include "gui.h"
#include "framebuffer.h"
#include "ppc.h"
#include "tm.h"
#include "CubeMap.h"
#include "CGInterface.h"

class Scene {
public:

    GUI *gui;
    FrameBuffer *fb, *fb3, *shadowfb, *hwfb;
    PPC *ppc, *ppc3, *lights;
    TM *tms;
    CubeMap* cm;
    int tmsN;
    bool SM1_check;
    bool SM2_check;
    bool SM3_check;
    float bwFraction;
    float augments[2]; //where 0 is the ambient augment, 1 is the spec augment

    V3 hwClearColor;
    Scene();
    void Render(PPC *renderPPC, FrameBuffer *renderFB);
    void Render();
    void RenderHW();
    void DBG();
    void PlayButton();
    void NewButton();

    FrameBuffer* textures;
    int texturesN;
    int needInitHW;
    CGInterface *cgi;
    ShaderOneInterface *soi;

    void KeyboardHandle();

    void SM1();
    void SM2();
    void SM3();
    void AmbPlus();
    void AmbMinus();
    void SpecPlus();
    void SpecMinus();

    void LeftButton();
    void RightButton();
    void UpButton();
    void DownButton();
    void ForwardButton();
    void BackwardButton();
    void ZPlusButton();
    void ZMinusButton();
    void TiltPlusButton();
    void TiltMinusButton();
    void PanPlusButton();
    void PanMinusButton();
    void RollPlusButton();
    void RollMinusButton();
};

extern Scene *scene;
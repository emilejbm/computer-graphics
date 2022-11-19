#include "scene.h"

#include "V3.h"
#include "M33.h"
#include "tm.h"

Scene *scene;

using namespace std;

#define LIGHT_UP 105
#define LIGHT_DOWN 107
#define LIGHT_LEFT 106
#define LIGHT_RIGHT 108
#define PPC_UP 119
#define PPC_DOWN 115
#define PPC_LEFT 97
#define PPC_RIGHT 100

#include <iostream>
#include <fstream>

Scene::Scene() {

    gui = new GUI();
    gui->show();

    int u0 = 16;
    int v0 = 40;
    int h = 400;
    int w = 600;
    int smwh = 512;

    fb = new FrameBuffer(u0, v0, w, h);
    fb->position(u0, v0);
    fb->label("first person");
    fb->show();
    fb->SetBGR(0xFF0000FF);
    fb->redraw();

    fb3 = new FrameBuffer(u0, v0, w, h);
    fb3->position(u0+fb->w+u0, v0);
    fb3->label("3rd person");
    fb3->show();
    fb3->SetBGR(0xFFFF0000);
    fb3->redraw();

    shadowfb = new FrameBuffer(u0, v0, smwh, smwh);
    shadowfb->position(u0+fb->w+fb3->w, v0);
    shadowfb->show();
    shadowfb->SetBGR(0xFFFF0000);
    shadowfb->redraw();


    float hfov = 60.0f;
    ppc = new PPC(hfov, w, h);
    ppc3 = new PPC(hfov, w, h);
    ppc3->C = V3(-200.0f, 200.0f, 120.0f);
    lights = new PPC(hfov, 50.0f, 50.0f);

    tmsN = 3;
    tms = new TM[tmsN];
    TM loadedTM;
    //TM loadedTM1;
    loadedTM.LoadBin("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/geometry/teapot1K.bin");
    //loadedTM1.LoadBin("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/geometry/teapot1K.bin");
    tms[0].SetUnshared(&loadedTM);
//	tms[0].LoadBin("geometry/teapot1K.bin");
//	tms[0].LoadBin("geometry/teapot57K.bin");
    tms[0].SetCenter(V3(-30.0f, 0.0f, -150.0f));
    tms[1].SetAsSquare(V3(0.0f, 0.0f, 0.0f), 250.0f);
    //tms[1].SetCenter(V3(0.0f, -35.0f, -150.0f));
    //tms[1].SetAsAACube(V3(0.0f, 10.0f, -150.0f), 250.0f);
    //tms[2].SetUnshared(&loadedTM1);
    //tms[2].SetCenter(V3(50.0f, 0.0f, -150.0f));


    ppc3->PositionAndOrient(ppc3->C, tms[0].GetCenter(), V3(0.0f, 1.0f, 0.0f));

    gui->uiw->position(u0, v0 + fb->h + v0);

    augments[0] = 0.0f;
    augments[1] = 0.0f;
    SM1_check = false;
    SM2_check = false;
    SM3_check = false;
}

void Scene::Render(PPC *rppc, FrameBuffer *rfb) {

    rfb->SetBGR(0xFFFFFFFF);
    rfb->SetZB(0.0f);


//    for (int tmi = 0; tmi < tmsN; tmi++) {
//        tms[tmi].RenderFilled(lights[0], fb)
//        tms[tmi].RenderFilled(rppc, rfb, lights, augments);
//    }

    //tms[0].ShadowPass(lights, shadowfb);
    tms[0].RenderFilled(rppc, rfb, shadowfb, lights, augments);
    tms[1].RenderFilled(rppc, rfb, shadowfb, lights, augments);
    //tms[2].RenderFilled(rppc, rfb, shadowfb, lights, augments);
    rfb->redraw();
    shadowfb->redraw();

}

void Scene::Render() {

    Render(ppc, fb);
    Render(ppc3, fb3);
    //Render(lights, shadowfb);

    fb3->Render3DSegment(ppc3, ppc->C, ppc->C + ppc->GetVD()*100.0f,V3(1.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, 0.0f));
    fb3->Render3DPoint(ppc3, ppc->C, V3(1.0f, 0.0f, 0.0f), 7.0f);
    fb3->Render3DPoint(ppc3, lights[0].C, V3(1.0f, 0.0f, 0.0f), 7.0f);
    fb3->Render3DSegment(ppc3, lights[0].C, lights[0].C + lights->GetVD()*100.0f, V3(1.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, 0.0f));
    fb3->redraw();

}

void Scene::DBG() {

//    {
//        float ka = 0.03f;
//        V3 center = tms[0].GetCenter();
//
//        if(SM1_check){
//            //reload the file to get correct colors - eliminate lighting
//            for (int i = 0; i < 10; i++){
//                ppc->TranslateLR(10.0f);
//                ppc->PositionAndOrient(ppc->C, center, V3(0.0f, 1.0f, 0.0f));
//                Fl::check();
//                Render();
//            }
//        }
//        else if(SM2_check || SM3_check){
//            V3 eye = ppc->GetVD();
//            for (int i = 0; i < 10; i++){
//                lights[0].TranslateLR(10.0f);
//                lights[0].PositionAndOrient(lights[0].C, center, V3(0.0f, 1.0f, 0.0f));
//                Fl::check();
//                Render();
//            }
//        }
//        return;
//    }

    {
        FrameBuffer *texture = new FrameBuffer(100, 100, 128, 64);
        texture->SetChecker(0xFF000000, 0xFFDDDDDD, 16);
        ppc->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, -100.0f), V3(0.0f, 1.0f, 0.0f));
        float rw = 200.0f;
        float rh = 100.0f;
        tms[0].SetTexturedRectangle(rw, rh);
        tms[0].Translate(V3(0.0f, 0.0f, -200.0f));
        tms[0].Rotate(tms[0].GetCenter(), V3(0.0f, 0.0f, 1.0f), 5.0f);
        tms[0].texture = texture;
        Render();
        //fb->SaveAsTiff("mydbg/bilinear.tif");
        //return;

        fb3->hide();
        for (int fi = 0; fi < 450; fi++) {
            Render();
            Fl::check();
            tms[0].Rotate(tms[0].GetCenter(), V3(0.0f, 1.0f, 0.0f), .1f);
        }
        Render();
        return;
    }
    {
        Render();
        return;
    }

    {
        V3 v0(-100.0f, 50.0f, -200.0f);
        V3 v1(100.0f, -50.0f, -200.0f);
        V3 v2(100.0f, 50.0f, -200.0f);
        tms[0].SetOneTriangle(v0, v1, v2);
        ppc->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, -200.0f),
                               V3(0.0f, 1.0f, 0.0f));
        for (int fi = 0; fi < 360; fi++) {
            tms[0].Rotate(tms[0].GetCenter(), V3(0.0f, 0.0f, -1.0f), 1.0f);
            Render();
            tms[0].RenderWireFrame(ppc, fb);
            Fl::check();
        }
        return;
    }

    {

    }

    {

        V3 P0(-5.0f, 0.0f, -10.0f);
        V3 P1(+100.0f, 0.0f, -200.0f);
        V3 c0(1.0f, 0.0f, 0.0f);
        V3 c1(0.0f, 0.0f, 0.0f);
        ppc->PositionAndOrient(V3(0.0f, 0.0f, 0.0f), V3(0.0f, 0.0f, -10.0f), V3(0.0f, 1.0f, 0.0f));
        fb->SetBGR(0xFFFFFFFF);
        fb->Render3DSegment(ppc, P0, P1, c0, c1);
        fb->redraw();
        ppc3->PositionAndOrient(V3(0.0f, 500.0f, 100.0f), V3(0.0f, 0.0f, 0.0f), V3(0.0f, 1.0f, 0.0f));
        fb3->SetBGR(0xFFFFFFFF);
        fb3->Render3DSegment(ppc3, P0, P1, c0, c1);
        int stepsN = 4;
        for (int si = 0; si <= stepsN; si++) {
            V3 currp = P0 + (P1 - P0) * (float) si / (float)stepsN;
            V3 currc = c0 + (c1 - c0) * (float) si / (float)stepsN;
            fb->Render3DPoint(ppc, currp, currc, 9.0f);
            fb3->Render3DPoint(ppc3, currp, currc, 9.0f);
        }
        V3 P0p, P1p;
        ppc->Project(P0, P0p);
        ppc->Project(P1, P1p);
        float w0 = 1.0f / P0p[2];
        float w1 = 1.0f / P1p[2];
        for (int si = 0; si <= stepsN; si++) {
            float frac = (float)si / (float)stepsN;
            V3 currp = P0p + (P1p - P0p) * frac;
            float currw = w0 + (w1 - w0)*frac;
            fb->DrawDisk(currp, 5.0f, 0xFF00FF00);
            V3 ucurrp;
            ppc->Unproject(currp, ucurrp);
            fb3->Render3DPoint(ppc3, ucurrp, V3(0.0f, 1.0f, 0.0f), 5.0f);
            currp[2] = 1.0f / currw;
            ppc->Unproject(currp, ucurrp);
            fb3->Render3DPoint(ppc3, ucurrp, V3(0.0f, 0.0f, 1.0f), 5.0f);
        }
        fb->redraw();
        fb3->redraw();
        return;
    }

    {
        for (int fi = 0; fi < 100; fi++) {
            Render();
            Fl::check();
            ppc->C = ppc->C + V3(0.0f, 0.5f, 0.0f);
            ppc->PositionAndOrient(ppc->C, tms[0].GetCenter(), V3(0.0f, 1.0f, 0.0f));
        }
        return;
    }

    {
        V3 cc(0.0f, 0.0f, -100.0f);
        float cubeSideLength = 30.0f;
        TM tm;
//		tm.SetAsAACube(cc, cubeSideLength);
        tm.LoadBin("geometry/teapot57K.bin");
        tm.SetCenter(V3(0.0f, 0.0f, -150.0f));
        int psize = 5;
        V3 Cn(ppc->C);
        V3 L = tm.GetCenter();
        V3 upg(0.0f, 1.0f, 0.0f);
        PPC ppc0(*ppc);
        int fN = 36;
//		fN = 1;
        for (int fi = 0; fi < fN; fi++) {
            fb->SetBGR(0xFFFFFFFF);
            fb->SetZB(0.0f);
//			tm.RenderAsPoints(psize, ppc, fb);
            tm.RenderWireFrame(ppc, fb);
            fb->redraw();
            Fl::check();
            float tstep = 0.1f;
            V3 tv = ppc->GetVD()*tstep;
            tv = ppc->a*tstep;
            V3 center = tm.GetCenter();
            ppc->Rotate(ppc->b.normalizedVec()*-1.0f, 0.01f);
//			tm.Rotate(center, V3(0.0f, 1.0f, 0.0f), 0.1f);
//			ppc->C = ppc->C + tv;
            ppc->PositionAndOrient(Cn, L, upg);
            Cn = Cn + V3(0.0f, 5.0f, 0.0f);
        }
        *ppc = ppc0;
        return;
    }
    {
        V3 P(0.0f, 0.0f, -100.0f);
        V3 pP;
        ppc->Project(P, pP);
        cerr << pP << endl;
        return;
    }

    {

        fb->SetBGR(0xFF000000);
        fb->SaveAsTiff("mydbg/blackImage.tif");
        fb->SetBGR(0xFF00FF00);
        fb->redraw();
        Fl::check();
        char c;
        cin >> c;
        fb->LoadTiff("mydbg/redImage.tif");
        fb->redraw();
        return;
    }

    {

        V3 p0(20.0f, 430.0f, 0.0f);
        V3 p1(520.0f, 331.0f, 0.0f);
        fb->SetBGR(0xFFFFFFFF);
        fb->DrawSegment(p0, p1, 0xFF000000);
        fb->redraw();
        return;

    }

    {
        V3 tlc(100.5f, 45.5f, 0.0f);
        V3 brc(300.5f, 145.5f, 0.0f);
        unsigned int col = 0xFF0000FF;
        unsigned int colDisk = 0xFFFFFF00;
        V3 center(114.1f, 300.1f, 0.0f);
        float r = 110.0f;
        int fN = 1000;
        float du = 1.f;
        for (int fi = 0; fi < fN; fi++) {
            fb->SetBGR(0xFFFFFFFF);
            fb->DrawAARectangle(tlc, brc, col);
//			fb->DrawDisk(center, r, colDisk);
            fb->redraw();
            Fl::check();
            tlc[0] += du;
            brc[0] += du;
            center[0] += du;
        }
        return;
    }

    {
        M33 m;
        V3 v(1.0f, 2.0f, 3.0f);
        m[0] = v;
        m[1] = v;
        m[2] = v;
        V3 ret = m*v;
        cerr << "mv: " << ret << endl;
        return;
    }
    {
        V3 v(1.0f, 2.0f, 3.0f);
        cerr << "v: " << v << endl;
        return;
    }

    cerr << "INFO: pressed DBG button on GUI" << endl;

    {
        V3 v0(1.0f, 2.0f, 3.0f);
        V3 v1(-1.0f, -2.0f, -3.0f);
        V3 v01 = v0 + v1;
        cerr << "v0 + v1: " << v01[0] << " " << v01[1] << " " << v01[2] << endl;
        return;
    }

    return;

    unsigned int col0 = 0xFF000000;
    unsigned int col1 = 0xFFFFFFFF;
    int csize = 100;
    fb->SetChecker(col0, col1, csize);
    fb->redraw();
}

void Scene::KeyboardHandle() {
    int key = Fl::event_key();
    switch (key) {
        case FL_Left: {
            cerr << "INFO: pressed left" << endl;
            break;
        }
        case LIGHT_UP: {
            cout << "LIGHT UP" << endl;
        }
        case LIGHT_DOWN: {
            cout << "LIGHT DOWN" << endl;
        }
        case LIGHT_LEFT: {
            cout << "LIGHT LEFT" << endl;
        }
        case LIGHT_RIGHT: {
            cout << "LIGHT RIGHT" << endl;
        }

        case PPC_UP: {
            cout << "UP" << endl;
        }
        case PPC_DOWN: {
            cout << "UP" << endl;
        }
        case PPC_LEFT: {
            cout << "UP" << endl;
        }
        case PPC_RIGHT: {
            cout << "UP" << endl;
        }


        default:
            cerr << "INFO: do not understand keypress" << endl;
            return;
    }

}


//Buttons for HW4

void Scene::SM1(){
    if(SM1_check){
        SM1_check = false;
    }
    else{
        SM1_check = true;
        SM2_check = false;
        SM3_check = false;
    }
}

void Scene::SM2(){
    if(SM2_check){
        SM2_check = false;
    }
    else{
        SM2_check = true;
        SM1_check = false;
        SM3_check = false;
    }
}

void Scene::SM3(){
    if(SM3_check){
        SM3_check = false;
    }
    else{
        SM3_check = true;
        SM1_check = false;
        SM2_check = false;
    }
}

void Scene::AmbPlus(){
    augments[0] += 0.05f;
}

void Scene::AmbMinus(){
    augments[0] -= 0.05f;
}

void Scene::SpecPlus(){
    augments[1] += 0.05f;
}

void Scene::SpecMinus(){
    augments[1] -= 0.05f;
}



/* Play Scene Explained
 *
 * 8 Actions: Pan, Tilt, Roll, Translate LR, UP, FB, then zoom in zoom out
 * 300 frames divided per action is approx 38
 * Each action receives this fraction amount of time
 */

void Scene::PlayButton() {
//    cerr << "INFO: pressed Play button on GUI" << endl;
//    V3 cc(0.0f, 0.0f, -150.0f);
//    float cubeSideLength = 30.0f;
//    TM tm;
//    tm.SetAsAACube(cc, cubeSideLength);
//    tm.LoadBin("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/geometry/teapot1K.bin");
//    tm.SetCenter(V3(0.0f, 0.0f, -150.0f));
//
//    int fN = 38*3;
//    string fname;
//    char fname_arr[10];
//    for(int i = 0; i<fN; i++){
//        ppc->SaveToTextFile();
//        fb->SetBGR(0xFFFFFFFF);
//        fb->SetZB(0.0f);
//        tm.RenderWireFrame(ppc, fb);
//        fb->redraw();
//        fname = "../frames/frame"+to_string(i)+".tif";
//        strcpy(fname_arr, fname.c_str());
//        fb->SaveAsTiff(fname_arr);
//        Fl::check();
//        if(i < fN/3){
//            ppc->Pan(-0.2f);
//        }
//        else if(i < 2*fN/3){
//            ppc->Tilt(0.2f);
//        }
//        else{
//            ppc->Roll(3.5f);
//        }
//    }
//
//    for(int i = 0; i<fN; i++){
//        ppc->SaveToTextFile();
//        fb->SetBGR(0xFFFFFFFF);
//        fb->SetZB(0.0f);
//        tm.RenderWireFrame(ppc, fb);
//        fname = "../frames/frame"+to_string(i+114)+".tif";
//        strcpy(fname_arr, fname.c_str());
//        fb->SaveAsTiff(fname_arr);
//        fb->redraw();
//        Fl::check();
//        if(i < fN/3){
//            ppc->TranslateLR(-.3f);
//        }
//        else if(i < 2*fN/3){
//            ppc->TranslateUD(-.5f);
//        }
//        else{
//            ppc->TranslateFB(-1.0f);
//        }
//    }
//
//    for(int i = 0; i<72; i++){
//        ppc->SaveToTextFile();
//        fb->SetBGR(0xFFFFFFFF);
//        fb->SetZB(0.0f);
//        tm.RenderWireFrame(ppc, fb);
//        fname = "../frames/frame"+to_string(i+228)+".tif";
//        strcpy(fname_arr, fname.c_str());
//        fb->SaveAsTiff(fname_arr);
//        fb->redraw();
//        Fl::check();
//        if(i < 36){
//            ppc->zoom(1.02f);
//        }
//        else{
//            ppc->zoom(.98f);
//        }
//    }
return;
}

void Scene::LeftButton(){
    int fN = 10;
    for(int i = 0; i<fN; i++) {
        ppc->TranslateLR(-1.0f);
        Fl::check();
        Render();

    }
}
void Scene::RightButton(){

    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->TranslateLR(1.0f);
        Fl::check();
        Render();
    }

}
void Scene::UpButton(){

    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->TranslateUD(1.0f);
        Fl::check();
        Render();
    }
}
void Scene::DownButton(){

    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->TranslateUD(-1.0f);
        Fl::check();
        Render();
    }
}
void Scene::ForwardButton(){
    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->TranslateFB(1.0f);
        Fl::check();
        Render();
    }
}
void Scene::BackwardButton(){
    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->TranslateFB(-1.0f);
        Fl::check();
        Render();
    }
}
void Scene::ZPlusButton(){
    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->zoom(1.01f);
        Fl::check();
        Render();
    }
}
void Scene::ZMinusButton(){
    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->zoom(.99f);
        Fl::check();
        Render();
    }
}
void Scene::TiltPlusButton(){

    int fN = 2;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(0.0f, 1.0f, 0.0f), 2.0f);
        Fl::check();
        Render();
    }
}
void Scene::TiltMinusButton(){

    int fN = 2;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(0.0f, 1.0f, 0.0f), -2.0f);
        Fl::check();
        Render();
    }
}
void Scene::PanPlusButton(){

    int fN = 2;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(1.0f, 0.0f, 0.0f), 2.0f);
        Fl::check();
        Render();
    }
}
void Scene::PanMinusButton(){
    int fN = 2;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(1.0f, 0.0f, 0.0f), -2.0f);
        Fl::check();
        Render();
    }
}
void Scene::RollPlusButton(){

    int fN = 2;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(0.0f, 0.0f, 1.0f), 2.0f);
        Fl::check();
        Render();

    }
}
void Scene::RollMinusButton(){

    int fN = 10;
    for(int i = 0; i<fN; i++){
        ppc->Rotate(V3(0.0f, 0.0f, 1.0f), -2.0f);
        Fl::check();
        Render();
    }
}

#include "view.h"

View::View(){}

View::View(int Xv,int Yv, int Zv){
    viewPos[0] = Xv;
    viewPos[1] = Yv;
    viewPos[2] = Zv;
}

int View::getXv(){return viewPos[0];};
int View::getYv(){return viewPos[1];};
int View::getZv(){return viewPos[2];};

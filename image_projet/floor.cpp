#include "floor.h"

Floor::Floor(){}

Floor::~Floor(){}

Floor::Floor(int Zf, int R,int G,int B):
    Zf(Zf),
    R(R),
    G(G),
    B(B){}

int Floor:: getR(){return R;}

int Floor:: getG(){return G;}

int Floor:: getB(){return B;}

int Floor::getZf(){return Zf;}

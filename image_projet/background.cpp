#include "background.h"

Background::Background(){}

Background::Background(int R,int G,int B):
    R(R),
    G(G),
    B(B){}

int Background:: getR(){return R;}

int Background:: getG(){return G;}

int Background:: getB(){return B;}

#include "objet.h"



Object::Object(){};

Object::~Object(){};

Object::Object(int centreX,int centreY, int centreZ, int r , int R , int G, int B):
    centreX(centreX),
    centreY(centreY),
    centreZ(centreZ),
    r(r)
{
    setRGB(R ,G,B);
}

int Object::getCentreX(){return centreX;}

int Object::getCentreY(){return centreY;}

int Object::getCentreZ(){return centreZ;}

int Object::getRayon(){return r;}

int Object::getR(){return RGB[0];};

int Object::getG(){return RGB[1];};

int Object::getB(){return RGB[2];};

void Object:: setRGB(int R , int G , int B){
    RGB[0]= R;
    RGB[1] = G;
    RGB[2] = B;
}

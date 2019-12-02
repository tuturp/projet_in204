#include<iostream>
#include"object.h"


Object::Object(){};

Object::~Object(){};

Object::Object(int centreX,int centreY , int r):  centreX(centreX),centreY(centreY),r(r){}

int Object::getCentreX(){return centreX;}

int Object::getCentreY(){return centreY;}

int Object::getRayon(){return r;}

void Object::objectTrace(){}



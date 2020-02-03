#include "source.h"




Source::Source(){};

Source::~Source(){};

Source::Source(int centreX,int centreY, int centreZ, int r):
    centreX(centreX),
    centreY(centreY),
    centreZ(centreZ),
    r(r){}

int Source::getCentreX(){return centreX;}

int Source::getCentreY(){return centreY;}

int Source::getCentreZ(){return centreZ;}

int Source::getRayon(){return r;}

int Source::getRGB(){return *RGB;};

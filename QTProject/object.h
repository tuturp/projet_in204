#ifndef OBJECT_H
#define OBJECT_H

class Object{
    private:
    int centreX;
    int centreY;
    int r;

    public:
    Object();
    ~Object();
    Object(int centreX,int centreY , int r);
    void objectTrace();
    int getCentreX();
    int getCentreY();
    int getRayon();
};



#endif // OBJECT_H

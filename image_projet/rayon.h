#ifndef RAYON_H
#define RAYON_H


#include <vector>
#include"cmath"
#include"objet.h"
#include"source.h"
#include"view.h"
#include"floor.h"
#include"background.h"

using namespace std;

class Rayon{
    private:
    int origineRayX;
    int origineRayY;
    int origineRayZ;
    int VectDir[3];
    vector<int> coordonatesX;
    vector<int> coordonatesY;
    int inter=0;
    int currentInterId;
    vector<int> listObjectInter;
    int currentObjetInterId;
    int R;
    int G;
    int B;



    public:
    Rayon();
    Rayon(View camera, int VectX, int VectY, int VectZ, vector<Object*> listObject, vector<Source*> listSource, Floor sol, Background back);
    ~Rayon();
    int getVectDir();
    int getOrigineRayX();
    int getOrigineRayY();
    int getOrigineRayZ();
    int getInter();
    int getR();
    int getG();
    int getB();
    void RayInter(vector<Object*> listObject, vector<Source*> listSource, View camera, Floor sol, Background back);
};




#endif // RAYON_H

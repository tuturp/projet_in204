#ifndef RAYON_H
#define RAYON_H



#include<vector>
#include<object.h>
#include<QPicture>

using namespace std;

class Rayon{
    private:
    int direction;
    int origineRayY;
    int origineRayX;
    vector<int> coordonatesX;
    vector<int> coordonatesY;
    vector<int> inter;



    public:
    Rayon();
    Rayon(int origineRayX, int origineRayY, int direction);
    ~Rayon();
    void createCoordonates(int W, int H);
    void rayIntersection(Object testObject);
    int rayTrace(QPicture pi);
    double getCoefdir();
    int getOrigineRayX();
    int getOrigineRayY();
    vector<int> getInter();
    vector<int> getCoordonatesX();
    vector<int> getCoordonatesY();

};

#endif // RAYON_H

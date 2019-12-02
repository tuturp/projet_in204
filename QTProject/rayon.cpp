#include<iostream>
#include"rayon.h"
#include<cmath>
#include<QtWidgets>
#include<QApplication>
#include<QPainter>
#include<QPaintEvent>
#include<QPicture>
#include<QLabel>

const double pi = 3.14159265358979323846;

Rayon::Rayon(){}

Rayon::Rayon(int origineRayX, int origineRayY, int direction ) : direction(direction), origineRayY(origineRayY), origineRayX(origineRayX){
    coordonatesX.push_back(origineRayX);
    coordonatesY.push_back(origineRayY);
}

Rayon::~Rayon(){}

double Rayon::getCoefdir(){
    return (double) (coordonatesY[coordonatesY.size()-1]-coordonatesY[0])/(coordonatesX[coordonatesX.size()-1]-coordonatesX[0]);

}
int Rayon::getOrigineRayX(){return origineRayX;}
int Rayon::getOrigineRayY(){return origineRayY;}

vector<int> Rayon::getInter(){return inter;}

vector<int> Rayon::getCoordonatesX(){return coordonatesX;}
vector<int> Rayon::getCoordonatesY(){return coordonatesY;}

void Rayon::createCoordonates(int W, int H){

    if((direction<=45 && direction>=0) || (direction>=315 && direction < 360)){
        for(int i=origineRayX;i<W;i++){
            if(floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY)<H && floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY)>0){
                coordonatesX.push_back(i);
                coordonatesY.push_back(floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY));
            }
        }
    }
    if(direction>45 && direction<=135){
        for(int i=origineRayY;i<H;i++){
            if(floor(tan(pi/2-direction*pi/180)*(i-origineRayY)+origineRayX)<H && floor(tan(pi/2-direction*pi/180)*(i-origineRayY)+origineRayX)>0){
                coordonatesY.push_back(i);
                coordonatesX.push_back(floor(tan(pi/2-direction*pi/180)*(i-origineRayY)+origineRayX));
            }
        }
    }

    if(direction<=225 && direction>135){
        for(int i=origineRayX;i>=0;i--){
            if(floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY)<H && floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY)>0){
                coordonatesX.push_back(i);
                coordonatesY.push_back(floor(tan(direction*pi/180)*(i-origineRayX)+origineRayY));
            }
        }
    }

    if(direction>=225 && direction<315){
        for(int i=origineRayY ;i>=0;i--){
            if(floor(tan(3*pi/2-direction*pi/180)*(i-origineRayY)+origineRayX)<W && floor(tan(3*pi/2-direction*pi/180)*(i-origineRayY)+origineRayX)>0){
                coordonatesY.push_back(i);
                coordonatesX.push_back(floor(tan(3*pi/2-direction*pi/180)*(i-origineRayY)+origineRayX));
            }
        }
    }


cout<< coordonatesY[coordonatesY.size()-1] <<endl;

}

/*int Rayon::rayTrace(QPicture pi){
    QPainter p(&pi);
    p.drawLine(origineRayX,origineRayY,coordonatesX[coordonatesX.size()-1], coordonatesY[coordonatesY.size()-1]);    
}*/

void Rayon::rayIntersection(Object testObject){
    double a = (double)getCoefdir();
    double eps =0.001;
    double b = (double)getOrigineRayY();
    double Yoc = (double)testObject.getCentreY();
    double Xoc = (double)testObject.getCentreX();
    double r = (double)testObject.getRayon();
    double detX = 4*(pow((a*(b-Yoc)-Xoc),2)-(1+pow(a,2))*(pow(Xoc,2) + pow(b,2)-2*Yoc*b+pow(Yoc,2)-pow(r,2)));
    if(detX>eps){
        int Xsol1= floor((-2*(a*(b-Yoc)-Xoc)-sqrt(detX))/(2*(1+pow(a,2))));
        int Xsol2= floor((-2*(a*(b-Yoc)-Xoc)+sqrt(detX))/(2*(1+pow(a,2))));
        int Ysol1 = floor(a*Xsol1+b);
        int Ysol2 = floor(a*Xsol2+b);
        inter.push_back(Xsol1);
        inter.push_back(Ysol1);
        inter.push_back(Xsol2);
        inter.push_back(Ysol2);
    }
}

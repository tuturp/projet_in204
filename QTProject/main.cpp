#include<iostream>
#include"rayon.h"
#include<string>
#include<QtWidgets>
#include<QApplication>
#include<QPainter>
#include<QPaintEvent>
#include<QPicture>
#include<QLabel>
#include<cmath>



using namespace std;
const int H = 1200;
const int W = 1200;
const double PI = 3.14159265358979323846;


int main(int argc, char *argv[]){
    QApplication app(argc , argv);
        QPicture pi;
        QPainter p(&pi);
        p.setRenderHint(QPainter::Antialiasing);
        p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
        p.drawLine(0,0,0, H);
        p.drawLine(0,0,W,0);

        Rayon rayon1(0,0,45);
        Rayon rayon2(0,0,70);
        Object objet1(300,300,200);
        rayon1.createCoordonates(W, H);
        rayon2.createCoordonates(W, H);
        rayon1.rayIntersection(objet1);
        rayon2.rayIntersection(objet1);
        //cout<< floor(atan((objet1.getCentreY()-rayon2.getInter()[1])/(objet1.getCentreY()-rayon2.getInter()[1]))*180/PI)<<endl;
        Rayon rayon3(rayon2.getInter()[0],rayon2.getInter()[1],floor((PI/2+atan((objet1.getCentreY()-rayon2.getInter()[1])/(objet1.getCentreY()-rayon2.getInter()[1])))*180/PI));
        rayon3.createCoordonates(W, H);
        p.drawLine(rayon1.getOrigineRayX(),rayon1.getOrigineRayY(),rayon1.getCoordonatesX()[rayon1.getCoordonatesX().size()-1], rayon1.getCoordonatesY()[rayon1.getCoordonatesY().size()-1]);
        p.drawLine(rayon2.getOrigineRayX(),rayon2.getOrigineRayY(),rayon2.getCoordonatesX()[rayon2.getCoordonatesX().size()-1], rayon2.getCoordonatesY()[rayon2.getCoordonatesY().size()-1]);
        p.drawLine(rayon3.getOrigineRayX(),rayon3.getOrigineRayY(),rayon3.getCoordonatesX()[rayon3.getCoordonatesX().size()-1], rayon3.getCoordonatesY()[rayon3.getCoordonatesY().size()-1]);
        p.drawEllipse(objet1.getCentreX()-objet1.getRayon(),objet1.getCentreY()-objet1.getRayon(),objet1.getRayon()*2,objet1.getRayon()*2);
        //rayon1.rayTrace(pi);

        p.end();
        QLabel l;
        l.setPicture(pi);
        l.show();
     return app.exec();


}

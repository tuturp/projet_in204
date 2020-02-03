#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include"objet.h"
#include"rayon.h"
#include"view.h"
#include"floor.h"
#include "background.h"
#include<iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int sizeX = 2500;
    int sizeY = 1500;
    vector<Object*> listObject;
    vector<Rayon*> listRay;
    vector<Source*> listSource;

    QImage image(sizeX, sizeY, QImage::QImage::Format_RGBA8888);

    View camera(0,-3000,0);
    Floor sol(sizeY/2, 200, 200, 200);
    Background back(0, 0, 0);

    listObject.push_back(new Object(-500,200,0,200,22, 184, 78));
    listObject.push_back(new Object(700,300,-400,200,161, 6, 132));
    listObject.push_back(new Object(0,400,-500,200,255, 127, 0));
    listObject.push_back(new Object(200,1000,-900,200,0, 204, 203));

    listSource.push_back(new Source(-1250,100,750,50));

    for (int i = 0; i<sizeX;i++){
        for (int j= sizeY-1 ; j>=0;j--){
            listRay.push_back(new Rayon(camera, i-sizeX/2 , 0, sizeY/2-j, listObject, listSource, sol, back));
            image.setPixel(i,j,qRgba(listRay[listRay.size()-1]->getR(),listRay[listRay.size()-1]->getG(),listRay[listRay.size()-1]->getB(),255));
        }

    }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


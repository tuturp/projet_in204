#include "rayon.h"
#include<iostream>




Rayon::Rayon(){}
Rayon::~Rayon(){}

Rayon::Rayon(View camera, int VectX, int VectY, int VectZ, vector<Object*> listObject, vector<Source*> listSource, Floor sol, Background back) :
    origineRayX(camera.getXv()),
    origineRayY(camera.getYv()),
    origineRayZ(camera.getZv())
{
    VectDir[0]=VectX-origineRayX;
    VectDir[1]=VectY-origineRayY;
    VectDir[2]=VectZ-origineRayZ;
    RayInter( listObject , listSource, camera, sol, back);

}


int Rayon::getOrigineRayX(){return origineRayX;}
int Rayon::getOrigineRayY(){return origineRayY;}
int Rayon::getOrigineRayZ(){return origineRayZ;}
int Rayon::getInter(){return inter;}
int Rayon::getR(){return R;}
int Rayon::getG(){return G;}
int Rayon::getB(){return B;}


void Rayon::RayInter(vector<Object*> listObject, vector<Source*> listSource, View camera, Floor sol, Background back){
    Source * testSource = listSource[listSource.size()-1];
    int Vx = VectDir[0];
    int Vy = VectDir[1];
    int Vz = VectDir[2];
    int Xs = testSource->getCentreX();
    int Ys = testSource->getCentreY();
    int Zs = testSource->getCentreZ();
    double solTestN = -(camera.getZv()+sol.getZf());
    double T = 0;
    if (Vz!=0){T = solTestN/Vz;}
    if (T>0){
        R= sol.getR();
        G = sol.getG();
        B = sol.getB();
        for (unsigned int s = 0 ; s< listObject.size();s++){
                Object* testObjetShadow= listObject[s];
                double Xss = Vx*T + camera.getXv();
                double Yss = Vy*T + camera.getYv();
                double Zss = Vz*T + camera.getZv();
                int Xo = testObjetShadow->getCentreX();
                int Yo = testObjetShadow->getCentreY();
                int Zo = testObjetShadow->getCentreZ();
                int r = testObjetShadow->getRayon();
                double ass = (Xs-Xss)*(Xs-Xss)+(Ys-Yss)*(Ys-Yss)+(Zs-Zss)*(Zs-Zss);
                double bss = 2*((Xs-Xss)*(Xss-Xo)+(Ys-Yss)*(Yss-Yo)+(Zs-Zss)*(Zss-Zo));
                double css = (Xss-Xo)*(Xss-Xo)+(Yss-Yo)*(Yss-Yo)+(Zss-Zo)*(Zss-Zo)-r*r;
                double detSs = bss*bss-4*ass*css;
                if(detSs>0){
                    double solTS1 = (-bss-sqrt(detSs))/(2*ass);
                    double solTS2 = (-bss+sqrt(detSs))/(2*ass);
                    if( solTS1>0 && solTS2>0 && (R!=0 && G!=0 && B!=0)){
                        R=floor(0.5+R/2);
                        G= floor(0.5+G/2);
                        B= floor(0.5+B/2);
                    }
                }
        }


    }else {
        R= back.getR();
        G = back.getG();
        B = back.getB();
    }
    double solT1=0;
    double solT2 = 0;
    for(unsigned int i= 0; i< listObject.size(); i++){
        Object * testObjet= listObject[i];
        int Xr = origineRayX;
        int Yr = origineRayY;
        int Zr = origineRayZ;
        int Xo = testObjet->getCentreX();
        int Yo = testObjet->getCentreY();
        int Zo = testObjet->getCentreZ();
        int r = testObjet->getRayon();
        double a = Vx*Vx+Vy*Vy+Vz*Vz;
        double b = 2*(Vx*(Xr-Xo)+Vy*(Yr-Yo)+Vz*(Zr-Zo));
        double c = (Xr-Xo)*(Xr-Xo)+(Yr-Yo)*(Yr-Yo)+(Zr-Zo)*(Zr-Zo)-r*r;
        double detX = b*b-4*a*c;
        if (detX>0){
            double currentT1 = (-b - sqrt(detX))/(2*a);
            double currentT2 = (-b + sqrt(detX))/(2*a);
            if (solT1==0){solT1 = currentT1;solT2 = currentT2;}
            else{
                if (currentT1<solT1 || currentT2<solT2){
                    solT1 = currentT1;
                    solT2 = currentT2;
                }
            }
            double solX;
            double solY;
            double solZ;
            if (((T>0 && (solT1< T || solT2<T))|| T<=0)&&solT1==currentT1){
                if(solT1<solT2){
                     solX =Vx*solT1 + Xr;
                     solY = Vy*solT1 + Yr;
                     solZ = Vz*solT1 + Zr;
                }else{
                    solX =Vx*solT2 + Xr;
                    solY = Vy*solT2 + Yr;
                    solZ = Vz*solT2 + Zr;
                }
                double N[3] = {(solX-Xo)/r,(solY-Yo)/r,(solZ-Zo)/r};
                double NormeN = sqrt((testSource->getCentreX()-solX)*(testSource->getCentreX()-solX) + (testSource->getCentreY()-solY)*(testSource->getCentreY()-solY)+(testSource->getCentreZ()-solZ)*(testSource->getCentreZ()-solZ));
                double L[3] = {(testSource->getCentreX()-solX)/NormeN , (testSource->getCentreY()-solY)/NormeN ,(testSource->getCentreZ()-solZ)/NormeN };
                double NormeV= sqrt((camera.getXv()-solX)*(camera.getXv()-solX) + (camera.getYv()-solY)*(camera.getYv()-solY)+(camera.getZv()-solZ)*(camera.getZv()-solZ));
                double V[3] = {(camera.getXv()-solX)/NormeV , (camera.getYv()-solY)/NormeV ,(camera.getZv()-solZ)/NormeV };
                double NormeH = sqrt((L[0]+V[0])*(L[0]+V[0])+(L[1]+V[1])*(L[1]+V[1])+(L[2]+V[2])*(L[2]+V[2]));
                double H[3]= {(L[0]+V[0])/NormeH,(L[1]+V[1])/NormeH,(L[2]+V[2])/NormeH};
                double hf = N[0]*H[0]+N[1]*H[1]+N[2]*H[2];
                double fctr = N[0]*L[0]+N[1]*L[1]+N[2]*L[2];
                double ka = 0.2;
                double kd = 0.8;
                double ks = 0.5;
                int n = 100;
                double specAdd = ks*pow(hf,n);
                if (ka*testObjet->getR()+kd*fctr*testObjet->getR()+specAdd*testObjet->getR()>0){
                    if (ka*testObjet->getR()+kd*fctr*testObjet->getR()+specAdd*testObjet->getR()<255){
                        R= floor(0.5+ka*testObjet->getR()+kd*fctr*testObjet->getR()+specAdd*testObjet->getR());
                    }else {R=255;}
                }else{R=0;}

                if(ka*testObjet->getG()+kd*fctr*testObjet->getG()+specAdd*testObjet->getR()>0){
                    if (ka*testObjet->getG()+kd*fctr*testObjet->getG()+specAdd*testObjet->getR()<255){
                        G= floor(0.5+ka*testObjet->getG()+kd*fctr*testObjet->getG()+specAdd*testObjet->getR());
                    }else {G=255;}
                }else{G=0;}

                if(ka*testObjet->getB()+kd*fctr*testObjet->getB()+specAdd*testObjet->getR()>0){
                    if (ka*testObjet->getB()+kd*fctr*testObjet->getB()+specAdd*testObjet->getR()<255){
                        B= floor(0.5+ka*testObjet->getB()+kd*fctr*testObjet->getB()+specAdd*testObjet->getR());
                    }else {B=255;}
                }else {B=0;}


                for (unsigned int s = 0 ; s< listObject.size();s++){
                    if (s!=i){
                        Object* testObjetShadow= listObject[s];
                        Xo = testObjetShadow->getCentreX();
                        Yo = testObjetShadow->getCentreY();
                        Zo = testObjetShadow->getCentreZ();
                        r = testObjetShadow->getRayon();
                        double as = (Xs-solX)*(Xs-solX)+(Ys-solY)*(Ys-solY)+(Zs-solZ)*(Zs-solZ);
                        double bs = 2*((Xs-solX)*(solX-Xo)+(Ys-solY)*(solY-Yo)+(Zs-solZ)*(solZ-Zo));
                        double cs = (solX-Xo)*(solX-Xo)+(solY-Yo)*(solY-Yo)+(solZ-Zo)*(solZ-Zo)-r*r;
                        double detS = bs*bs-4*as*cs;
                        if(detS>0){
                            double solTS1 = (-bs-sqrt(detS))/(2*as);
                            double solTS2 = (-bs+sqrt(detS))/(2*as);
                            if( solTS1>0 && solTS2>0 && (R!=0 && G!=0 && B!=0)){
                                R=floor(0.5+ka*testObjet->getR());
                                G= floor(0.5+ka*testObjet->getG());
                                B= floor(0.5+ka*testObjet->getB());
                            }
                        }
                    }
                }

            }
        }
    }
}



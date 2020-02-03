#ifndef OBJET_H
#define OBJET_H





class Object{
    private:
    int centreX;
    int centreY;
    int centreZ;
    int r;
    int RGB[3];



    public:
    Object();
    ~Object();
    Object(int centreX,int centreY, int centreZ , int r , int R , int G, int B);
    void objectTrace();
    int getCentreX();
    int getCentreY();
    int getCentreZ();
    int getRayon();
    int getR();
    int getG();
    int getB();
    void setRGB(int R , int G , int B);

};

#endif // OBJET_H

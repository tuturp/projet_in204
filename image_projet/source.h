#ifndef SOURCE_H
#define SOURCE_H


class Source
{
    private:
    int centreX;
    int centreY;
    int centreZ;
    int r;
    int RGB[3];

    public:
    Source();
    ~Source();
    Source(int centreX,int centreY, int centreZ , int r);
    void objectTrace();
    int getCentreX();
    int getCentreY();
    int getCentreZ();
    int getRayon();
    int getRGB();
    };

#endif // SOURCE_H

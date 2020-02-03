#ifndef FLOOR_H
#define FLOOR_H


class Floor
{
private:
    int Zf, R, G, B;
public:
    Floor();
    ~Floor();
    Floor(int Zf, int R,int G,int B);
    int getR();
    int getG();
    int getB();
    int getZf();
};

#endif // FLOOR_H

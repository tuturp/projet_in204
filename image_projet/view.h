#ifndef VIEW_H
#define VIEW_H


class View
{
private:
    int viewPos[3];

public:
    View();
    View(int Xv,int Yv, int Zv);
    int getXv();
    int getYv();
    int getZv();
};

#endif // VIEW_H

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"point.h"

class Triangle
{
public:
    Triangle(double l);
    Triangle(double l, float alpha, Point p);
    void drawTriange();
    void rotate(double alpha);
    void move(Point p);


private:

    Point a;
    Point b;
    Point c;
};


#endif // TRIANGLE_H

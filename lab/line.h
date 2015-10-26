#ifndef LINE_H
#define LINE_H
#include "point.h"

class Line
{
public:
    Line(double l);
    Line(Point start, Point vect);
    Line(Point start, double alpha, double len);
    void drawLine();
    double getEndX();
    double getEndY();
    double getStartX();
    double getStartY();
     Point start;
private:
    Point vect;
};

#endif // LINE_H

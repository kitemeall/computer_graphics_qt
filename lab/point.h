#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double x, double y);
    void rotate(double alpha);
    void add(Point& p);
    void sub(Point& p);
    double getX(){return x;}
    double getY(){return y;}
private:
    double x;
    double y;

};

#endif // POINT_H

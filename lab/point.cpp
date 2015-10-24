#include "point.h"
#include <math.h>
Point::Point()
{
   Point(0, 0);
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::rotate(double alpha)
{
   double x = this->x;
   double y = this->y;

   this->x = x * cos(alpha) - y * sin(alpha);
   this->y = x * sin(alpha) + y * cos(alpha);
}
void Point::add(Point& p)
{
    this->x += p.x;
    this->y += p.y;
}

void Point::sub(Point& p)
{
    this->x -= p.x;
    this->y -= p.y;
}

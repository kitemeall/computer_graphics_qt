#include "triangle.h"
#include<GL/gl.h>
#include <math.h>

Triangle::Triangle(double l){
    a = Point(-0.4 * l, 0);
    b = Point(0, 1 * l);
    c = Point(0.4 * l, 0);
}
void Triangle::rotate(double alpha){
    a.rotate(alpha);
    b.rotate(alpha);
    c.rotate(alpha);
}
void Triangle::move(Point p){
    a.add(p);
    b.add(p);
    c.add(p);
}

Triangle::Triangle(double l, float alpha, Point p)
{
    a = Point(-0.5 * l, 0);
    b = Point(0, l);
    c = Point(0.5 * l, 0);
    rotate( alpha - M_PI/2);
    move(p);

}
void Triangle::drawTriange(){

    glBegin(GL_LINE_LOOP);
        glVertex2f(a.getX(), a.getY());
        glVertex2f(b.getX(), b.getY());
        glVertex2f(c.getX(), c.getY());
    glEnd();
}

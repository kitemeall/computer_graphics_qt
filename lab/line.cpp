#include "line.h"
#include<GL/gl.h>
#include <math.h>
Line::Line(double l)
{
    start = Point(0, 0);
    vect = Point(0, l);
}

Line::Line(Point start, Point vect){
    this->start = start;
    this->vect = vect;
}

Line::Line(Point start, double alpha, double len){
    this->start = start;
    this->vect = Point(len * cos(alpha), len * sin(alpha));
}

void Line::extendX2(){
    this->vect.add(this->vect);
}

void Line::drawLine(){
    glBegin(GL_LINES);
        glVertex2f(start.getX(), start.getY());
        glVertex2f(start.getX()+vect.getX(),
                   start.getY()+vect.getY());
    glEnd();
}

double Line::getEndX(){
    return start.getX()+vect.getX();
}
double Line::getEndY(){
    return start.getY()+vect.getY();
}

double Line::getStartX(){
    return start.getX();
}
double Line::getStartY(){
    return start.getY();
}

#include <QGLWidget>
#include "glwidget.h"
#include <math.h>
#include <qdebug.h>
float Xt(float x0, float x1, float x2, float x3, float x4, float t);
int factorial(int n);


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;
}


void GLWidget::initializeGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glLineWidth(2);
    glPointSize(5);

    glOrtho(0, 10, 0, 10, 1, -1 );





}

void GLWidget::paintGL()
{


    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    glBegin(GL_LINE_STRIP);
        glColor3f(1, 0.0, 0.0);
       for (double t = 0; t <= 1.01; t += 0.05)
           glVertex2f(Xt(x0, x1, x2, x3, x4, t),
                      Xt(y0, y1, y2, y3, y4, t));



    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 1, 0);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();


    glBegin(GL_POINTS);
    glColor3f(0, 0, 1);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
   glEnd();



}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0,width, height);
}

void GLWidget::setPoints(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    this->x0 = x0; this->y0 = y0;
    this->x1 = x1; this->y1 = y1;
    this->x2 = x2; this->y2 = y2;
    this->x3 = x3; this->y3 = y3;
    this->x4 = x4; this->y4 = y4;

    paintGL();
    updateGL();
}

float J(int n, int i, float t){

   int C = factorial(n) / (factorial(i) * factorial(n - i));
   return C * pow(t, i) * pow(1 - t , n - i);
}

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

float Xt(float x0, float x1, float x2, float x3, float x4, float t){

    float ans = x0 * J(4, 0, t)
            + x1 * J(4, 1, t)
            + x2 * J(4, 2, t)
            + x3 * J(4, 3, t)
            + x4 * J(4, 4, t);
    return ans;
}









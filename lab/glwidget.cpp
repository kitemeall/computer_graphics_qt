#include <QGLWidget>
#include "glwidget.h"
#include <math.h>
#include <qdebug.h>
float Xt(float x0, float x1, float x2, float x3, float t);
int factorial(int n);


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;
}


void GLWidget::initializeGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glLineWidth(5);
    glPointSize(5);

    float x0 = 1; float y0 = 1;
    float x1 = 2; float y1 = 3;
    float x2 = 4; float y2 = 3;
    float x3 = 3; float y3 = 1;




}

void GLWidget::paintGL()
{


    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex2d(0.3, 0.3);
    glEnd();

}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0,width, height);
}
float J(int n, int i, float t){

   int C = factorial(n) / (factorial(i) * factorial(n - i));
   return C * pow(t, i) * pow(1 - t , n - i);
}

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

float Xt(float x0, float x1, float x2, float x3, float t){

    float ans = x0 * J(3, 0, t)
            + x1 * J(3, 1, t)
            + x2 * J(3, 2, t)
            + x3 * J(3, 3, t);
    return ans;
}









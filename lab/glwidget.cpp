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

    glOrtho(0, 10, 0, 10, 1, -1 );





}

void GLWidget::paintGL()
{
    float x0 = 1; float y0 = 1;
    float x1 = 4; float y1 = 2;
    float x2 = 1; float y2 = 5;
    float x3 = 4; float y3 = 7;


    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    glBegin(GL_POINTS);
        glColor3f(1, 0.0, 0.0);
       for (double t = 0; t <= 1.0; t += 0.1)
           glVertex2f(Xt(x0, x1, x2, x3, t),
                      Xt(y0, y1, y2, y3, t));

       glColor3f(0, 0, 1);
       glVertex2f(x0, y0);
       glVertex2f(x1, y1);
       glVertex2f(x2, y2);
       glVertex2f(x3, y3);
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









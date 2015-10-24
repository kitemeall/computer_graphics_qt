#include <QGLWidget>
#include "glwidget.h"
#include"triangle.h"
#include"line.h"
#include<math.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;
}

void GLWidget::initializeGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glLineWidth(1);


}

void GLWidget::paintGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,1);


   iteration(0.5, 0, Point(0,0.5), 5);






}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0,width, height);
}


void GLWidget::iteration(double len, double angle, Point p, int iter){
    Triangle tr(len, angle, p);
    tr.drawTriange();
    Line ln(p, angle-M_PI/2, len/3);
    for(int i = 0; i < iter; i++){
        ln.drawLine();
        iteration(len/2, angle - M_PI/3,
                  Point(ln.getEndX() + len*i/6 * sin(angle + M_PI/3),
                        ln.getEndY() - len*i/6 * cos(angle + M_PI/3)),
                  i);

        ln = Line(p, angle-M_PI/2, len/3 * (i+2));
    }


}





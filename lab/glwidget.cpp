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
     glViewport(0, 0,578, 578);

}

void GLWidget::paintGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,1);


   iteration(0.5, 0.0, Point(0.0,0.5), 5);






}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, ,width, height);
}



void GLWidget::iteration(double len, double angle, Point p, int iter){

    Triangle tr(len/2, angle, p);
    tr.drawTriange();
    Line lne(p,0, 0);
    for(int i = 0; i < iter; i++){
        Line ln(Point(lne.getEndX(), lne.getEndY()),
                angle-M_PI/2, len/6.0);
        ln.drawLine();

        iteration(len/2.0, angle + M_PI/3.0,
                  Point(ln.getStartX() - len*i/6.0 * sin(abs(angle) + M_PI/3.0),
                        ln.getStartY() + len*i/6.0 * cos(abs(angle) + M_PI/3.0)),
                  i);

        Line ln2(Point(ln.getEndX(), ln.getEndY()),
                angle-M_PI/2, len/6.0);
        ln2.drawLine();

        iteration(len/2.0, angle - M_PI/3.0,
                  Point(ln2.getStartX() + len*i/6.0 * sin(abs(angle) + M_PI/3.0),
                        ln2.getStartY() + len*i/6.0 * cos(abs(angle) + M_PI/3.0)),
                  i);





        lne = ln2;



    }




}





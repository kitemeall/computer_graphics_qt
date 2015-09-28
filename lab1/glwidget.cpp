#include <QGLWidget>
#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;
}
void GLWidget :: setType(int t)
{
    type = t;
    paintGL();
}

void GLWidget::initializeGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
}

void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0, 0.5, 0);
        glVertex3f(1, 0.5, 0);
    glEnd();

/*
    switch (type)
    {
        case 0:  drawPoints() ;
                 break;
        case 1:  drawLines();
                 break;
        case 2:  drawLineStrip();
                 break;
        case 3:  drawLineLoop();
                 break;
        case 4:  drawPolygons();
                 break;
        case 5:  drawNonconvex();
                 break;
        case 6:  drawTriangles();
                 break;
        case 7:  drawTriangleStrip();
                 break;
        case 8:  drawTriangleFan();
                 break;
        case 9:  drawQuads();
                 break;
        case 10: drawQuadStrip();
                 break;
        default: break;
    }
    */

}

void GLWidget::resizeGL(int width, int height)
{

}


void GLWidget::drawPoints(){

}

void GLWidget::drawLines(){


    glLineWidth(10);
       glColor4f(0.0, 1.0, 0.0, 1);
       glBegin(GL_LINES);
       glVertex3f(0.0, 0.0, 1);        glVertex3f(1, 0.5, 1);
       glVertex3f(0.0, 0.0, 1);        glVertex3f(0.5, 0.5, 1);
       glVertex3f(0.0, 0.0, 1);        glVertex3f(0.5, 1, 1);
       glEnd();
}

void GLWidget::drawLineStrip(){

}

void GLWidget::drawLineLoop(){

}

void GLWidget::drawPolygons(){

}

void GLWidget::drawNonconvex(){

}

void GLWidget::drawTriangles(){

}

void GLWidget::drawTriangleStrip(){

}

void GLWidget::drawTriangleFan(){

}

void GLWidget::drawQuads(){

}

void GLWidget::drawQuadStrip(){

}







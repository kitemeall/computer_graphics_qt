#include <QGLWidget>
#include "glwidget.h"
#include<GL/glut.h>


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;
}


void GLWidget::initializeGL()
{

    glClearColor(1.0, 1.0, 0.0, 1.0);
    glLineWidth(1);
    glPointSize(1);


}

void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glutSolidTorus(0.2, 0.8, 50, 50);



}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0,width, height);
}

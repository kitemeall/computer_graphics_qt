#include <QGLWidget>
#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 0;

    scissorEnabled = false;
    scissorX = 100;
    scissorY = 100;
    scissorW = 200;
    scissorH = 200;

    alphaTestEnabled = false;
    alphaFunc = GL_NEVER;
    alphaValue = 1.0;


}

void GLWidget::refreshScreen(){
    paintGL();
    updateGL();
}

void GLWidget :: setType(int t)
{
    type = t;
    refreshScreen();

}

void GLWidget::initializeGL()
{

    glEnable(GL_BLEND);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(5);
    glPointSize(5);


}

void GLWidget::paintGL()
{

    if(alphaTestEnabled)
    {
        glEnable(GL_ALPHA_TEST);
    }
    glAlphaFunc(alphaFunc, alphaValue);

    if(scissorEnabled)
    {
        clearScreen();
        glEnable(GL_SCISSOR_TEST);
    }
    glScissor(scissorX, scissorY,
              scissorW, scissorH);


    drawFigures();


        glDisable(GL_SCISSOR_TEST);
        glDisable(GL_ALPHA_TEST);



}

void GLWidget::clearScreen(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::drawFigures(){
    clearScreen();

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
        case 4:  drawTriangles();
                 break;
        case 5:  drawTriangleStrip();
                 break;
        case 6:  drawTriangleFan();
                 break;
        case 7:  drawQuads();
                 break;
        case 8:  drawQuadStrip();
                 break;
        case 9:  drawPolygons();
                 break;
        default: break;
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0,width, height);

}


void GLWidget::drawPoints(){
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(0.3, 0.2, 0);
        glVertex3f(0.2, 0.2, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();


}

void GLWidget::drawLines(){
    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();

}

void GLWidget::drawLineStrip(){
    glColor3f(0,1,0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(0, 0, 0);
        glVertex3f(0.9, 0.9, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();
}

void GLWidget::drawLineLoop(){
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0.9, 0.9, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();
}

void GLWidget::drawPolygons(){
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.0, 0.1, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();
}


void GLWidget::drawTriangles(){
    glColor4f(0,0,1, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);

        glVertex3f(-0.5, 0.25, 0);
        glVertex3f(0.0, 0.25, 0);
        glVertex3f(0.0, 0.75, 0);

    glEnd();
}

void GLWidget::drawTriangleStrip(){
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);

        glVertex3f(1.0, 0.0, 0);

    glEnd();
}

void GLWidget::drawTriangleFan(){
    glColor4f(0,0,1, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0, 0.0, 0);
        glVertex3f(0.5, 0.0, 0);
        glVertex3f(0.5, 0.5, 0);

        glVertex3f(0.3, 0.6, 0);

        glVertex3f(0.2, 0.7, 0);

        glVertex3f(0.0, 0.8, 0);

        glVertex3f(-0.3, 0.6, 0);

    glEnd();
}

void GLWidget::drawQuads(){
    glColor4f(0.8,0,0.8, 0.4);
    glBegin(GL_QUADS);
        glVertex3f(0.4, 0.1, 0);
        glVertex3f(0.7, 0.2, 0);
        glVertex3f(0.7, 0.6, 0);
        glVertex3f(0.4, 0.7, 0);

        glVertex3f(0.1, 0.9, 0);
        glVertex3f(-0.1, 0.6, 0);
        glVertex3f(-0.1, 0.3, 0);
        glVertex3f(0.1, -0.1, 0);


    glEnd();
}

void GLWidget::drawQuadStrip(){

    glColor3f(0,1,0);
    glBegin(GL_QUAD_STRIP);
        glVertex3f(0.7, 0.2, 0);
        glVertex3f(0.7, 0.6, 0);
        glVertex3f(0.4, 0.1, 0);
        glVertex3f(0.4, 0.7, 0);

        glVertex3f(0.1, -0.1, 0);
        glVertex3f(0.1, 0.9, 0);





    glEnd();

}

//scrissor section
void GLWidget::updateScissorParameters(int Sx, int Sy, int w, int h)
{
    scissorX = Sx;
    scissorY = Sy;
    scissorW = w;
    scissorH = h;
    updateGL();

}

void GLWidget::updateScissorAccessibility(bool b){
    scissorEnabled = b;
    updateGL();

}

//scrissor section


//alpha section

void GLWidget::updateAlphaAccessibility(bool b){
    alphaTestEnabled = b;
    updateGL();
}

void GLWidget::updateAlphaFunc(int val){
    switch (val) {
    case 0: alphaFunc = GL_NEVER;
            break;
    case 1: alphaFunc = GL_LESS;
            break;
    case 2: alphaFunc = GL_EQUAL;
            break;
    case 3: alphaFunc = GL_LEQUAL;
            break;
    case 4: alphaFunc = GL_GREATER;
            break;
    case 5: alphaFunc = GL_NOTEQUAL;
            break;
    case 6: alphaFunc = GL_GEQUAL;
            break;
    case 7: alphaFunc = GL_ALWAYS;
            break;
    default:
        break;
    }
    updateGL();
}

void GLWidget::updateAlphaValue(double val)
{
    alphaValue = val;
    updateGL();
}

//alpha section





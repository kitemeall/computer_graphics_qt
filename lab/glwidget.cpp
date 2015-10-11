#include <QGLWidget>
#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    type = 4;

    scissorEnabled = false;
    scissorX = 100;
    scissorY = 100;
    scissorW = 200;
    scissorH = 200;

    alphaTestEnabled = false;
    alphaFunc = GL_NEVER;
    alphaValue = 1.0;

    blendTestEnabled = false;
    sfactor = GL_ZERO;
    dfactor = GL_ZERO;


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

   // glEnable(GL_BLEND);
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glLineWidth(5);
    glPointSize(5);


}

void GLWidget::paintGL()
{
    if(blendTestEnabled)
        glEnable(GL_BLEND);
    glBlendFunc(sfactor, dfactor);


    if(alphaTestEnabled)
        glEnable(GL_ALPHA_TEST);
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
        glDisable(GL_BLEND);



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
    glColor4f(1,0,0, 1.0);
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
    glColor4f(0,1,0, 0.9);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();

}

void GLWidget::drawLineStrip(){
    glColor4f(0,1,0,0.8);
    glBegin(GL_LINE_STRIP);
        glVertex3f(0, 0, 0);
        glVertex3f(0.9, 0.9, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();
}

void GLWidget::drawLineLoop(){
    glColor4f(0,1,0, 0.7);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0.9, 0.9, 0);
        glVertex3f(-0.7, 0.2, 0);
        glVertex3f(-0.1, 0.4, 0);
    glEnd();
}

void GLWidget::drawPolygons(){
    glColor4f(0,0,1, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.0, 0.1, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();

    glColor4f(0.8,0.3,0.5, 0.4);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4, -0.5, 0);
        glVertex3f(0.3, -0.1, 0);
        glVertex3f(0.5, 0.7, 0);
        glVertex3f(0.0, 0.1, 0);
        glVertex3f(-0.3, 0.5, 0);
    glEnd();

    glColor4f(0.4,0.7,0.1, 0.4);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4, -0.3, 0);
        glVertex3f(0.3, -0.1, 0);
        glVertex3f(0.8, 0.2, 0);
        glVertex3f(0.7, 0.3, 0);
        glVertex3f(-0.1, 0.5, 0);
    glEnd();
}


void GLWidget::drawTriangles(){
    glColor4f(0,0,1, 1);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);

        glColor4f(0.7,0.2,0.5, 0.6);
        glVertex3f(-0.3, 0.3, 0);
        glVertex3f(0.0, 0.3, 0);
        glVertex3f(0.0, -0.6, 0);

    glEnd();
}

void GLWidget::drawTriangleStrip(){
    glColor4f(0,0,1, 0.5);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);

        glVertex3f(1.0, 0.0, 0);

    glEnd();
}

void GLWidget::drawTriangleFan(){
    glColor4f(0,0,1, 0.4);
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
    glColor4f(0.8,0,0.8, 0.3);
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

    glColor4f(0,1,0,0.2);
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



//blend section
void GLWidget::updateBlendAccessibility(bool b){
    blendTestEnabled = b;
    updateGL();
}

void GLWidget::updateBlendParameters(int sf, int df){
    switch(sf){
    case 0: sfactor = GL_ZERO;
            break;
    case 1: sfactor = GL_ONE;
            break;
    case 2: sfactor = GL_DST_COLOR;
            break;
    case 3: sfactor = GL_ONE_MINUS_DST_COLOR;
            break;
    case 4: sfactor = GL_SRC_ALPHA;
            break;
    case 5: sfactor = GL_ONE_MINUS_SRC_ALPHA;
            break;
    case 6: sfactor = GL_DST_ALPHA;
            break;
    case 7: sfactor = GL_ONE_MINUS_DST_ALPHA;
            break;
    case 8: sfactor = GL_SRC_ALPHA_SATURATE;
            break;
    default:
        break;
    }

    switch(df){
    case 0: dfactor = GL_ZERO;
            break;
    case 1: dfactor = GL_ONE;
            break;
    case 2: dfactor = GL_SRC_COLOR;
            break;
    case 3: dfactor = GL_ONE_MINUS_SRC_COLOR;
            break;
    case 4: dfactor = GL_SRC_ALPHA;
            break;
    case 5: dfactor = GL_ONE_MINUS_SRC_ALPHA;
            break;
    case 6: dfactor = GL_DST_ALPHA;
            break;
    case 7: dfactor = GL_ONE_MINUS_DST_ALPHA;
            break;
    default:
        break;
    }
    updateGL();
}

//blend section

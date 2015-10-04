#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    int type;

    bool scissorEnabled;
    int scissorX;
    int scissorY;
    int scissorW;
    int scissorH;

    int alphaTestEnabled;
    GLenum alphaFunc;
    GLclampf alphaValue;


public:
    GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

public slots:
    void setType(int t);

    void updateScissorParameters(int Sx, int Sy, int w, int h);
    void updateScissorAccessibility(bool b);

    void updateAlphaFunc(int val);
    void updateAlphaAccessibility(bool b);
    void updateAlphaValue(double val);

private:

    void clearScreen();
    void refreshScreen();
    void drawFigures();


    void drawPoints();
    void drawLines();
    void drawLineStrip();
    void drawLineLoop();
    void drawPolygons();
    void drawNonconvex();
    void drawTriangles();
    void drawTriangleStrip();
    void drawTriangleFan();
    void drawQuads();
    void drawQuadStrip();
};

#endif // GLWIDGET_H

#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    int type;
public:
    GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

public slots:
    void setType(int t);



private:

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

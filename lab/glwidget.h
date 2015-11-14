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
    void setPoints(float x0, float y0,
                   float x1, float y1,
                   float x2, float y2,
                   float x3, float y3,
                   float x4, float y4);

private:
    float x0 = 1; float y0 = 1;
    float x1 = 4; float y1 = 2;
    float x2 = 1; float y2 = 5;
    float x3 = 7; float y3 = 3;
    float x4 = 9; float y4 = 9;


};


#endif // GLWIDGET_H

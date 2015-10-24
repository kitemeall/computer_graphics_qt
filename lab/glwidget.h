#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include"point.h"

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



private:
    void iteration(double len, double angle, Point p, int iter);

};

#endif // GLWIDGET_H

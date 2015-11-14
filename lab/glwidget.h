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




};


#endif // GLWIDGET_H

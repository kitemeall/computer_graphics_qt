#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "glwidget.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_blend_sfactorCombo_activated(int index);


    void on_blend_dfactorCombo_activated(int index);

private:
    Ui::MainWindow *ui;
    GLWidget *glWidget;
};

#endif // MAINWINDOW_H

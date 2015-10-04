#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    glWidget = ui->widget;
    connect(ui->comboBox, SIGNAL(activated(int)), glWidget, SLOT(setType(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

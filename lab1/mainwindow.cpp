#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    glWidget = new GLWidget(this);
    ui->setupUi(this);
    connect(ui->comboBox, SIGNAL(activated(int)), glWidget, SLOT(setType(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

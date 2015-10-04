#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    glWidget = ui->widget;
    connect(ui->comboBox, SIGNAL(activated(int)), glWidget, SLOT(setType(int)));

    connect(ui->checkBox, SIGNAL(clicked(bool)), glWidget,SLOT(updateScissorAccessibility(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int x)
{
    int sx = ui->spinBox->value();
    int sy = ui->spinBox_2->value();
    int w = ui->spinBox_3->value();
    int h = ui->spinBox_4->value();
    glWidget->updateScissorParameters(sx, sy, w, h);
}

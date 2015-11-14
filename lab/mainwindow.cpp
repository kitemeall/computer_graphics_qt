#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    glWidget = ui->widget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    glWidget->setPoints(ui->x1->value(),ui->y1->value(),
                        ui->x2->value(),ui->y2->value(),
                        ui->x3->value(),ui->y3->value(),
                        ui->x4->value(),ui->y4->value(),
                        ui->x5->value(),ui->y5->value());
}

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

    connect(ui->alpha_check, SIGNAL(clicked(bool)),glWidget, SLOT(updateAlphaAccessibility(bool)));
    connect(ui->alpha_combo, SIGNAL(activated(int)), glWidget, SLOT(updateAlphaFunc(int)));
    connect(ui->alpha_spin, SIGNAL(valueChanged(double)), glWidget, SLOT(updateAlphaValue(double)));
    connect(ui->blend_check, SIGNAL(clicked(bool)), glWidget, SLOT(updateBlendAccessibility(bool)));
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

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    int sx = ui->spinBox->value();
    int sy = ui->spinBox_2->value();
    int w = ui->spinBox_3->value();
    int h = ui->spinBox_4->value();
    glWidget->updateScissorParameters(sx, sy, w, h);
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    int sx = ui->spinBox->value();
    int sy = ui->spinBox_2->value();
    int w = ui->spinBox_3->value();
    int h = ui->spinBox_4->value();
    glWidget->updateScissorParameters(sx, sy, w, h);
}

void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    int sx = ui->spinBox->value();
    int sy = ui->spinBox_2->value();
    int w = ui->spinBox_3->value();
    int h = ui->spinBox_4->value();
    glWidget->updateScissorParameters(sx, sy, w, h);
}

void MainWindow::on_blend_sfactorCombo_activated(int index)
{
    int sf = ui->blend_sfactorCombo->currentIndex();
    int df = ui->blend_dfactorCombo->currentIndex();
    glWidget->updateBlendParameters(sf,df);

}


void MainWindow::on_blend_dfactorCombo_activated(int index)
{
    int sf = ui->blend_sfactorCombo->currentIndex();
    int df = ui->blend_dfactorCombo->currentIndex();
    glWidget->updateBlendParameters(sf,df);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    ui->textBrowser->setText(ui->lineEdit->text());
}

void MainWindow::on_pushButton_2_released()
{
    ui->lineEdit->clear();
    ui->textBrowser->clear();
}

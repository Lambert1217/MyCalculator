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
    expression = ui->lineEdit->text().toStdString();
    if(expression.compare("") == 0){ QApplication::beep(); ui->textBrowser->setText("Error:Expression is NULL."); return;}
    if(expression[expression.size()-1] != '=') expression.push_back('=');
    if(cal.getResult(expression)){
        ui->textBrowser->setText(QString::number(cal.result,'f',fnum));
    }else{
        ui->textBrowser->setText(cal.error_message);
        QApplication::beep();
    }
}

void MainWindow::on_pushButton_2_released()
{
    ui->lineEdit->clear();
    ui->textBrowser->clear();
    cal.reset();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    fnum = arg1;
}

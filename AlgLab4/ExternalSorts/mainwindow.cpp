#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "external_sorts.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenButton_clicked()
{

}

void MainWindow::on_SortButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:{
        SimpleMergingSort("data.txt");
        break;
    }
    case 1:{
        break;
    }
    }
}

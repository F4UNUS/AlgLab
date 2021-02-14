#include "mainwindow.h"
#include "ui_mainwindow.h"

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

int table[26];

void MainWindow::on_pushButton_clicked(){
    if(ui->tableWidget->rowCount() > 0){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
    }
    for (int i = 0;i < 26;i++) {
        table[i] = 0;
    }
    QString str = ui->lineEdit->text().toLower();
    for (int i = 0;i < str.size();i++) {
        if(str[i].toLatin1() >= 97 && str[i].toLatin1() <= 122){
            int count = 0;
            for(int j = 0;j < str.size();j++){
                if(str[i].toLatin1() == str[j].toLatin1())
                    count++;
            }
            table[str[i].toLatin1() - 97] = count;
        }
    }
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Буква"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Кол-во вхождений"));
    ui->tableWidget->setColumnWidth(1,150);
    for (int i = 0;i < 26;i++) {
        if(table[i] > 0){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QChar(i + 97)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(table[i])));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit_2->text().toLower();
    if(str[0].toLatin1() >= 97 && str[0].toLatin1() <= 122){
        if(table[str[0].toLatin1() - 97] > 0){
            ui->label->setText(QString("Количесвто вхождений: " + QString::number(table[str[0].toLatin1() - 97])));
        }else{
            ui->label->setText("Введенная буква отсутствует \nв хеш таблице");
        }
    }else{
        ui->label->setText("Введенная буква отсутствует \nв хеш таблице");
    }
}

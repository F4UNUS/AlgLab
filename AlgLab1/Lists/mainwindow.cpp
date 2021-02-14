#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lists.h"

UD_List List1;
BD_List List2;
UD_Cicle List3;
BD_Cicle List4;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    ui->MyTable->insertRow(ui->MyTable->rowCount());
    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));

    ui->InsertButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TypeItemBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->spinBox->setEnabled(true);
        ui->doubleSpinBox->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        break;
    }
    case 1:{
        ui->spinBox->setEnabled(false);
        ui->doubleSpinBox->setEnabled(true);
        ui->lineEdit->setEnabled(false);
        break;
    }
    case 2:{
        ui->spinBox->setEnabled(false);
        ui->doubleSpinBox->setEnabled(false);
        ui->lineEdit->setEnabled(true);
        break;
    }
    }
}

void MainWindow::on_AddButton_clicked()
{
    int index = ui->TypeItemBox->currentIndex();
    ui->InsertButton->setEnabled(true);
    //выбор типа элемента
    switch (index) {
    case 0:{
        //добавление элемента в зависимости от типа списка
        switch(ui->ListTypeBox->currentIndex()){
        case 0:{
            List1.addIntItem(ui->spinBox->value());
            if (List1.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List1.getInt())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List1.getInt())));
            }
            break;
        }
        case 1:{
            List2.addIntItem(ui->spinBox->value());
            if (List2.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List2.getInt())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List2.getInt())));
            }
            break;
        }
        case 2:{
            List3.addIntItem(ui->spinBox->value());
            if (List3.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List3.getInt())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List3.getInt())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List3.getAdr()));
            }
            break;
        }
        case 3:{
            List4.addIntItem(ui->spinBox->value());
            if (List4.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
                ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List4.getInt())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List4.getInt())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
                ui->MyTable->setItem(0, 3, new QTableWidgetItem(List4.getAdr(List4.getCount())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List4.getAdr()));
            }
            break;
        }
        }
        break;
    }
    case 1:{
        //добавление элемента в зависимости от типа списка
        switch(ui->ListTypeBox->currentIndex()){
        case 0:{
            List1.addDoubItem(ui->doubleSpinBox->value());
            if (List1.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List1.getDoub())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List1.getDoub())));
            }
            break;
        }
        case 1:{
            List2.addDoubItem(ui->doubleSpinBox->value());
            if (List2.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List2.getDoub())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List2.getDoub())));
            }
            break;
        }
        case 2:{
            List3.addDoubItem(ui->doubleSpinBox->value());
            if (List3.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List3.getDoub())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List3.getDoub())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List3.getAdr()));
            }
            break;
        }
        case 3:{
            List4.addDoubItem(ui->doubleSpinBox->value());
            if (List4.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
                ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List4.getDoub())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(List4.getDoub())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
                ui->MyTable->setItem(0, 3, new QTableWidgetItem(List4.getAdr(List4.getCount())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List4.getAdr()));
            }
            break;
        }
        }
        break;
    }
    case 2:{
        //добавление элемента в зависимости от типа списка
        switch(ui->ListTypeBox->currentIndex()){
        case 0:{
            List1.addCharItem(ui->lineEdit->text()[0]);
            if (List1.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List1.getChar())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List1.getChar())));
            }
            break;
        }
        case 1:{
            List2.addCharItem(ui->lineEdit->text()[0]);
            if (List2.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List2.getChar())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List2.getChar())));
            }
            break;
        }
        case 2:{
            List3.addCharItem(ui->lineEdit->text()[0]);
            if (List3.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List3.getChar())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List3.getChar())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List3.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List3.getAdr()));
            }
            break;
        }
        case 3:{
            List4.addCharItem(ui->lineEdit->text()[0]);
            if (List4.getCount() == 1){
                ui->MyTable->clear();
                ui->MyTable->setRowCount(0);
                ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
                ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
                ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
                ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List4.getChar())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(List4.getChar())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem(List4.getAdr()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem(List4.getPrev()));
                ui->MyTable->setItem(0, 3, new QTableWidgetItem(List4.getAdr(List4.getCount())));
                ui->MyTable->setItem(ui->MyTable->rowCount()-2, 2, new QTableWidgetItem(List4.getAdr()));
            }
            break;
        }
        }
        break;
    }
    }
}

void MainWindow::on_DelButton_clicked()
{
    int index = ui->DelSpinBox->value();
    switch(ui->ListTypeBox->currentIndex()){
    case 0:{
        List1.delItem(index);
        if (List1.getCount() == 0){
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));

        }else{
            ui->MyTable->removeRow(index-1);
        }
        break;
    }
    case 1:{
        List2.delItem(index);
        if (List2.getCount() == 0){
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));

        }else{
            ui->MyTable->removeRow(index-1);
        }
        break;
    }
    case 2:{
        List3.delItem(index);
        if (List3.getCount() == 0){
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
            ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
            ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));

        }else{
            ui->MyTable->removeRow(index-1);
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List3.getLink()));
        }
        break;
    }
    case 3:{
        List4.delItem(index);
        if (List4.getCount() == 0){
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
            ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
            ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
            ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem("Пусто"));

        }else{
            ui->MyTable->removeRow(index-1);
            ui->MyTable->setItem(0, 3, new QTableWidgetItem(List4.getAdr()));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem(List4.getNext()));
        }
        break;
    }
    }
}

void MainWindow::on_InsertButton_clicked()
{
    int index = ui->insertSpinBox->value();
    switch(ui->ListTypeBox->currentIndex()){
    case 0:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            List1.insertIntItem(index, ui->spinBox->value());
            break;
        }
        case 1:{
            List1.insertDoubItem(index, ui->doubleSpinBox->value());
            break;
        }
        case 2:{
            List1.insertCharItem(index, ui->lineEdit->text()[0]);
            break;
        }
        }
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        for(int i =1; i <= List1.getCount();i++){
            switch(List1.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getInt(i))));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getDoub(i))));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List1.getChar(i))));
                break;
            }
            }
        }
        break;
    }
    case 1:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            List2.insertIntItem(index, ui->spinBox->value());
            break;
        }
        case 1:{
            List2.insertDoubItem(index, ui->doubleSpinBox->value());
            break;
        }
        case 2:{
            List2.insertCharItem(index, ui->lineEdit->text()[0]);
            break;
        }
        }
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        for(int i =1; i <= List2.getCount();i++){
            switch(List2.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getInt(i))));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getDoub(i))));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List2.getChar(i))));
                break;
            }
            }
        }
        break;
    }
    case 2:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            List3.insertIntItem(index, ui->spinBox->value());
            break;
        }
        case 1:{
            List3.insertDoubItem(index, ui->doubleSpinBox->value());
            break;
        }
        case 2:{
            List3.insertCharItem(index, ui->lineEdit->text()[0]);
            break;
        }
        }
        ui->MyTable->clear();
        ui->MyTable->setColumnCount(3);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        for(int i =1; i <= List3.getCount();i++){
            switch(List3.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getInt(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getDoub(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List3.getChar(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                break;
            }
            }
        }
        break;
    }
    case 3:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            List4.insertIntItem(index, ui->spinBox->value());
            break;
        }
        case 1:{
            List4.insertDoubItem(index, ui->doubleSpinBox->value());
            break;
        }
        case 2:{
            List4.insertCharItem(index, ui->lineEdit->text()[0]);
            break;
        }
        }
        ui->MyTable->clear();
        ui->MyTable->setColumnCount(4);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
        ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        for(int i =1; i <= List4.getCount();i++){
            switch(List4.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getInt(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getDoub(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List4.getChar(i))));
                ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                break;
            }
            }
        }
        break;
    }
    }
}

void MainWindow::on_clearButton_clicked()
{
    switch(ui->ListTypeBox->currentIndex()){
    case 0:{
        ui->MyTable->clear();
        ui->MyTable->setRowCount(0);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        List1.~UD_List();
        break;
    }
    case 1:{
        ui->MyTable->clear();
        ui->MyTable->setRowCount(0);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        List2.~BD_List();
        break;
    }
    case 2:{
        ui->MyTable->clear();
        ui->MyTable->setRowCount(0);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
        List3.~UD_Cicle();
        break;
    }
    case 3:{
        ui->MyTable->clear();
        ui->MyTable->setRowCount(0);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
        ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem("Пусто"));
        List4.~BD_Cicle();
        break;
    }
    }
}

void MainWindow::on_searchButton_clicked()
{
    ui->clearButton->setEnabled(false);
    switch(ui->ListTypeBox->currentIndex()){
    case 0:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List1.searchInt(ui->spinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List1.searchInt(ui->spinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.searchInt(ui->spinBox->value()).getInt(i))));
                }
            }
            break;
        }
        case 1:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List1.searchDoub(ui->doubleSpinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List1.searchDoub(ui->doubleSpinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.searchDoub(ui->doubleSpinBox->value()).getDoub(i))));
                }
            }
            break;
        }
        case 2:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List1.searchChar(ui->lineEdit->text()[0]).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List1.searchChar(ui->lineEdit->text()[0]).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List1.searchChar(ui->lineEdit->text()[0]).getChar(i))));
                }
            }
            break;
        }
        }
        break;
    }
    case 1:{
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List2.searchInt(ui->spinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List2.searchInt(ui->spinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.searchInt(ui->spinBox->value()).getInt(i))));
                }
            }
            break;
        }
        case 1:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List2.searchDoub(ui->doubleSpinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List2.searchDoub(ui->doubleSpinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.searchDoub(ui->doubleSpinBox->value()).getDoub(i))));
                }
            }
            break;
        }
        case 2:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List2.searchChar(ui->lineEdit->text()[0]).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List2.searchChar(ui->lineEdit->text()[0]).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List2.searchChar(ui->lineEdit->text()[0]).getChar(i))));
                }
            }
            break;
        }
        }
        break;
    }
    case 2:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List3.searchInt(ui->spinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List3.searchInt(ui->spinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.searchInt(ui->spinBox->value()).getInt(i))));
                }
            }
            break;
        }
        case 1:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List3.searchDoub(ui->doubleSpinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List3.searchDoub(ui->doubleSpinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.searchDoub(ui->doubleSpinBox->value()).getDoub(i))));
                }
            }
            break;
        }
        case 2:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List3.searchChar(ui->lineEdit->text()[0]).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List3.searchChar(ui->lineEdit->text()[0]).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List3.searchChar(ui->lineEdit->text()[0]).getChar(i))));
                }
            }
            break;
        }
        }
        break;
    }
    case 3:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        switch(ui->TypeItemBox->currentIndex()){
        case 0:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List4.searchInt(ui->spinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List4.searchInt(ui->spinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.searchInt(ui->spinBox->value()).getInt(i))));
                }
            }
            break;
        }
        case 1:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List4.searchDoub(ui->doubleSpinBox->value()).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List4.searchDoub(ui->doubleSpinBox->value()).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.searchDoub(ui->doubleSpinBox->value()).getDoub(i))));
                }
            }
            break;
        }
        case 2:{
            ui->MyTable->clear();
            ui->MyTable->setRowCount(0);
            ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Результат"));
            if (List4.searchChar(ui->lineEdit->text()[0]).getCount() == 0){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Не найдено"));
            }else{
                for(int i = 1; i <= List4.searchChar(ui->lineEdit->text()[0]).getCount();i++){
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List4.searchChar(ui->lineEdit->text()[0]).getChar(i))));
                }
            }
            break;
        }
        }
        break;
    }
    }
}

void MainWindow::on_getBackButton_clicked()
{
    ui->clearButton->setEnabled(true);
    ui->MyTable->clear();
    ui->MyTable->setRowCount(0);
    ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
    switch(ui->ListTypeBox->currentIndex()){
    case 0:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        if (List1.getCount() == 0){
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        }else{
            for(int i =1; i <= List1.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List1.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getInt(i))));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getDoub(i))));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List1.getChar(i))));
                    break;
                }
                }
            }
        }
        break;
    }
    case 1:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        if (List2.getCount() == 0){
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        }else{
            for(int i =1; i <= List2.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List2.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getInt(i))));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getDoub(i))));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List2.getChar(i))));
                    break;
                }
                }
            }
        }
        break;
    }
    case 2:{
        ui->MyTable->setColumnCount(3);
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адресс"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
        setFixedWidth(563);
        ui->MyTable->setFixedWidth(396);
        ui->ListTypeBox->setGeometry(410, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(410, 40, 141, 211);
        ui->delBox->setGeometry(410, 260, 141, 91);
        ui->getBackButton->setGeometry(410, 360, 141, 25);
        ui->clearButton->setGeometry(410, 390, 141, 25);
        if (List3.getCount() == 0){
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
        }else{
            for(int i =1; i <= List3.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List3.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getInt(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getDoub(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List3.getChar(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                }
            }
        }
        break;
    }
    case 3:{
        ui->MyTable->setColumnCount(4);
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
        ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
        setFixedWidth(691);
        ui->MyTable->setFixedWidth(521);
        ui->ListTypeBox->setGeometry(540, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(540, 40, 141, 211);
        ui->delBox->setGeometry(540, 260, 141, 91);
        ui->getBackButton->setGeometry(540, 360, 141, 25);
        ui->clearButton->setGeometry(540, 390, 141, 25);
        if (List4.getCount() == 0){
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem("Пусто"));
        }else{
            for(int i =1; i <= List4.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List4.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getInt(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getDoub(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List4.getChar(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                }
            }
        }
        break;
    }
    }
}

void MainWindow::on_ListTypeBox_currentIndexChanged(int index)
{
    ui->MyTable->clear();
    ui->MyTable->setRowCount(0);
    ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы"));
    switch(index){
    case 0:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        if (List1.getCount() == 0){
            ui->InsertButton->setEnabled(false);
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        }else{
            ui->InsertButton->setEnabled(true);
            for(int i =1; i <= List1.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List1.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getInt(i))));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List1.getDoub(i))));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List1.getChar(i))));
                    break;
                }
                }
            }
        }
        break;
    }
    case 1:{
        ui->MyTable->setColumnCount(1);
        setFixedWidth(313);
        ui->MyTable->setFixedWidth(140);
        ui->ListTypeBox->setGeometry(160, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(160, 40, 141, 211);
        ui->delBox->setGeometry(160, 260, 141, 91);
        ui->getBackButton->setGeometry(160, 360, 141, 25);
        ui->clearButton->setGeometry(160, 390, 141, 25);
        if (List2.getCount() == 0){
            ui->InsertButton->setEnabled(false);
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        }else{
            ui->InsertButton->setEnabled(true);
            for(int i =1; i <= List2.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List2.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getInt(i))));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List2.getDoub(i))));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List2.getChar(i))));
                    break;
                }
                }
            }
        }
        break;
    }
    case 2:{
        ui->MyTable->setColumnCount(3);
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Указтель"));
        setFixedWidth(563);
        ui->MyTable->setFixedWidth(396);
        ui->ListTypeBox->setGeometry(410, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(410, 40, 141, 211);
        ui->delBox->setGeometry(410, 260, 141, 91);
        ui->getBackButton->setGeometry(410, 360, 141, 25);
        ui->clearButton->setGeometry(410, 390, 141, 25);
        if (List3.getCount() == 0){
            ui->InsertButton->setEnabled(false);
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
        }else{
            ui->InsertButton->setEnabled(true);
            for(int i =1; i <= List3.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List3.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getInt(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List3.getDoub(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List3.getChar(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List3.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List3.getLink(i)));
                    break;
                }
                }
            }
        }
        break;
    }
    case 3:{
        ui->MyTable->setColumnCount(4);
        ui->MyTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Адрес"));
        ui->MyTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Адрес сл. эл."));
        ui->MyTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Адрес пред. эл."));
        setFixedWidth(691);
        ui->MyTable->setFixedWidth(521);
        ui->ListTypeBox->setGeometry(540, 10, 141, 24);
        ui->AddInsertSearchGroup->setGeometry(540, 40, 141, 211);
        ui->delBox->setGeometry(540, 260, 141, 91);
        ui->getBackButton->setGeometry(540, 360, 141, 25);
        ui->clearButton->setGeometry(540, 390, 141, 25);
        if (List4.getCount() == 0){
            ui->InsertButton->setEnabled(false);
            ui->MyTable->insertRow(ui->MyTable->rowCount());
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 1, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 2, new QTableWidgetItem("Пусто"));
            ui->MyTable->setItem(ui->MyTable->rowCount()-1, 3, new QTableWidgetItem("Пусто"));
        }else{
            ui->InsertButton->setEnabled(true);
            for(int i =1; i <= List4.getCount();i++){
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                switch(List4.getKey(i)){
                case integ:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getInt(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                case doub:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List4.getDoub(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                case ch:{
                    ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List4.getChar(i))));
                    ui->MyTable->setItem(i-1, 1, new QTableWidgetItem(List4.getAdr(i)));
                    ui->MyTable->setItem(i-1, 2, new QTableWidgetItem(List4.getNext(i)));
                    ui->MyTable->setItem(i-1, 3, new QTableWidgetItem(List4.getPrev(i)));
                    break;
                }
                }
            }
        }
        break;
    }
    }
}

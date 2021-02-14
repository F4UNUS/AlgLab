#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "search.cpp"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setEnabled(false);
    ui->searchDoubleSpinBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toOutputInTable(int *array, int size, int nCol, int nRow){
    ui->myTable->setRowCount(0);
    ui->myTable->setRowCount(size);
    for(int i = 0; i < nRow; i++){
        ui->myTable->setItem(i, nCol, new QTableWidgetItem(QString::number(array[i])));
    }
}

void MainWindow::toOutputInTable(double *array, int size, int nCol, int nRow){
    ui->myTable->setRowCount(0);
    ui->myTable->setRowCount(size);
    for(int i = 0; i < nRow; i++){
        ui->myTable->setItem(i, nCol, new QTableWidgetItem(QString::number(array[i])));
    }
}

void MainWindow::on_addButton_clicked()
{
    switch (ui->arrayTypeBox->currentIndex()) {
    case 0 :{
        if(iSize != 0){
            if(ii < iSize - 1){
                ii++;
                arri[ii] = ui->spinBox->value();
                toOutputInTable(arri, iSize, 0, ii + 1);
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно добавить, максимальное количество элементов");
            }
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно добавить, память не выделена");
        }
            break;
        }
    case 1:{
        if(dSize != 0){
            if (id < dSize - 1){
                    id++;
                arrd[id] = ui->doubleSpinBox->value();
                toOutputInTable(arrd, dSize, 0, id + 1);
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно добавить, максимальное количество элементов");
            }
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно добавить, память не выделена");
        }
            break;
        }
    }
}

void MainWindow::on_delButton_clicked()
{
    switch (ui->arrayTypeBox->currentIndex()) {
    case 0 :{
        if(ii != -1){
            ii--;
            toOutputInTable(arri, iSize, 0, ii + 1);
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно удалить, отсутствуют элементы");
        }
        break;
    }
    case 1:{
        if(id != -1){
            id--;
            toOutputInTable(arrd, dSize, 0, id + 1);
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно удалить, отсутствуют элементы");
        }
        break;
    }
    }
}

void MainWindow::on_addButton_2_clicked()
{
    switch (ui->arrayTypeBox->currentIndex()) {
    case 0:{
        if(iSize == 0){
            iSize = ui->sizeSpinBox->value();
            arri = new int[iSize];
            ui->myTable->setRowCount(iSize);
        }else{
            delete [] arri;
            iSize = ui->sizeSpinBox->value();
            arri = new int[iSize];
            ui->myTable->setRowCount(iSize);
        }
        break;
    }
    case 1:{
        if(dSize == 0){
            dSize = ui->sizeSpinBox->value();
            arrd = new double[dSize];
            ui->myTable->setRowCount(dSize);
        }else{
            delete [] arrd;
            dSize = ui->sizeSpinBox->value();
            arrd = new double[dSize];
            ui->myTable->setRowCount(dSize);
        }
        break;
    }
    }
}

void MainWindow::on_arrayTypeBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->myTable->setRowCount(0);
        ui->myTable->setRowCount(iSize);
        if(iSize != 0 && ii != -1){
            toOutputInTable(arri, iSize, 0, iSize);
            for(int i = 0;i < ui->myTable->rowCount();i++){
                ui->myTable->item(i, 0)->setBackground(Qt::white);
            }
        }
        ui->spinBox->setEnabled(true);
        ui->searchSpinBox->setEnabled(true);
        ui->doubleSpinBox->setEnabled(false);
        ui->searchDoubleSpinBox->setEnabled(false);
        break;
    }
    case 1:{
        ui->myTable->setRowCount(0);
        ui->myTable->setRowCount(dSize);
        if(dSize != 0 && id != -1){
            toOutputInTable(arrd, dSize, 0, dSize);
            for(int i = 0;i < ui->myTable->rowCount();i++){
                ui->myTable->item(i, 0)->setBackground(Qt::white);
            }
        }
        ui->spinBox->setEnabled(false);
        ui->searchSpinBox->setEnabled(false);
        ui->doubleSpinBox->setEnabled(true);
        ui->searchDoubleSpinBox->setEnabled(true);
        break;
    }
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->myTable->setRowCount(0);
    switch (ui->arrayTypeBox->currentIndex()) {
    case 0:{
        if(iSize != 0){
            iSize = 0;
            ii = - 1;
            delete [] arri;
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно очистить, память не выделена");
        }
        break;
    }
    case 1:{
        if(dSize != 0){
            dSize = 0;
            id = -1;
            delete [] arrd;
        }else{
            QMessageBox::warning(this, "Внимание", "Невозможно очистить, память не выделена");
        }
        break;
    }
    }
}

void MainWindow::on_searchButton_clicked()
{
    switch (ui->searchTypeBox->currentIndex()) {
    case 0:{
        switch (ui->arrayTypeBox->currentIndex()) {
        case 0:{
            if((iSize != 0) && (iSize == (ii + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                int index = LinearSearch<int>(arri, iSize, ui->searchSpinBox->value());
                if(index != -1){
                    ui->myTable->item(index, 0)->setBackground(Qt::green);
                }else{
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        case 1:{
            if((dSize != 0) && (dSize == (id + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                int index = LinearSearch<double>(arrd, dSize, ui->searchDoubleSpinBox->value());
                if(index != -1){
                    ui->myTable->item(index, 0)->setBackground(Qt::green);
                }else{
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        }
        break;
    }
    case 1:{
        switch (ui->arrayTypeBox->currentIndex()){
        case 0:{
            if((iSize != 0) && (iSize == (ii + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<int>(&arri, iSize);
                toOutputInTable(arri, iSize, 0, iSize);
                int index = BinarySearch<int>(arri, iSize, ui->searchSpinBox->value());
                if(index != -1){
                    ui->myTable->item(index, 0)->setBackground(Qt::green);
                }else{
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        case 1:{
            if((dSize != 0) && (dSize == (id + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<double>(&arrd, dSize);
                toOutputInTable(arrd, dSize, 0, dSize);
                int index = BinarySearch<double>(arrd, dSize, ui->searchDoubleSpinBox->value());
                if(index != -1){
                    ui->myTable->item(index, 0)->setBackground(Qt::green);
                }else{
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        }
        break;
    }
    case 2:{
        switch (ui->arrayTypeBox->currentIndex()){
        case 0:{
            if((iSize != 0) && (iSize == (ii + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<int>(&arri, iSize);
                toOutputInTable(arri, iSize, 0, iSize);
                int first = -1;
                int last = 0;
                BinarySearchModify<int>(arri, iSize, ui->searchSpinBox->value(), first, last);
                if(first != -1){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                    ui->myTable->item(last, 0)->setBackground(Qt::green);
                }else if(first == last){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                }else {
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        case 1:{
            if((dSize != 0) && (dSize == (id + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<double>(&arrd, dSize);
                toOutputInTable(arrd, dSize, 0, dSize);
                int first = -1;
                int last = 0;
                BinarySearchModify<double>(arrd, dSize, ui->searchDoubleSpinBox->value(), first, last);
                if(first != -1){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                    ui->myTable->item(last, 0)->setBackground(Qt::green);
                }else if(first == last){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                }else {
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        }
        break;
    }
    case 3:{
        switch (ui->arrayTypeBox->currentIndex()){
        case 0:{
            if((iSize != 0) && (iSize == (ii + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<int>(&arri, iSize);
                toOutputInTable(arri, iSize, 0, iSize);
                int first = -1;
                int last = 0;
                BinarySearchModify<int>(arri, iSize, ui->searchSpinBox->value(), first, last);
                if(first != -1){
                    for(int i = first;i <= last;i++)
                        ui->myTable->item(i, 0)->setBackground(Qt::green);
                }else if(first == last){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                }else {
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        case 1:{
            if((dSize != 0) && (dSize == (id + 1))){
                for(int i = 0;i < ui->myTable->rowCount();i++){
                    ui->myTable->item(i, 0)->setBackground(Qt::white);
                }
                SimpleInsertSort<double>(&arrd, dSize);
                toOutputInTable(arrd, dSize, 0, dSize);
                int first = -1;
                int last = 0;
                BinarySearchModify<double>(arrd, dSize, ui->searchDoubleSpinBox->value(), first, last);
                if(first != -1){
                    for(int i = first;i <= last;i++)
                        ui->myTable->item(i, 0)->setBackground(Qt::green);
                }else if(first == last){
                    ui->myTable->item(first, 0)->setBackground(Qt::green);
                }else {
                    QMessageBox::warning(this, "Внимание", "Не найдено");
                }
            }else{
                QMessageBox::warning(this, "Внимание", "Невозможно найти, память не выделена или не заполнен массив");
            }
            break;
        }
        }
        break;
    }
    }
}

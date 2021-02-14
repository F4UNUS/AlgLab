#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "internal_sorts.cpp"
#include "QErrorMessage"

int zd = 0;

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
//вывод в таблицу
void MainWindow::toOutInTable(int *array, int arrSize, int N){
    if(ui->MyTable->rowCount() < arrSize)
        ui->MyTable->setRowCount(arrSize);
    for(int i = 0; i<arrSize; i++){
        ui->MyTable->setItem(i, N, new QTableWidgetItem(QString::number(array[i])));
    }
};

void MainWindow::on_FillButton_clicked()
{
    if(ui->comboBox->currentIndex() != 7){
        arrSize = ui->spinBox->value();
        ui->MyTable->setRowCount(0);
        toCreateArray(&array, arrSize);
        toOutInTable(array, arrSize, 0);
    }else{
        switch(zd){
        case 0:{
            size_a = ui->spinBox->value();
            toCreateArray(&a, size_a);
            QuickSort(&a, 0, size_a - 1);
            toOutInTable(a, size_a, 0);
            zd++;
            break;
        }
        case 1:{
            size_b = ui->spinBox->value();
            toCreateArray(&b, size_b);
            QuickSort(&b, 0, size_b - 1);
            toOutInTable(b, size_b, 1);
            zd++;
            break;
        }
        default:{
            (new QErrorMessage(this))->showMessage("Созданно максимальное количество массивов");
            break;
        }
        }
    }
}

void MainWindow::on_SortButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    if(ui->MyTable->rowCount() != 0){
        switch (index) {
        case 0:{
            SimpleChoiceSort(&array, arrSize);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 1:{
            BubbleSort(&array, arrSize);
            toOutInTable(array, arrSize, 1);
            break;
            }
        case 2:{
            SimpleInsertSort(&array, arrSize);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 3:{
            HeapSort(&array, arrSize);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 4:{
            ShellSort(&array, arrSize);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 5:{
            QuickSort(&array, 0, arrSize - 1);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 6:{
            MergeSort(&array, 0, arrSize - 1);
            toOutInTable(array, arrSize, 1);
            break;
        }
        case 7:{
            if (zd == 2){
                toOutInTable(TheTask(&a, &b, size_a, size_b), size_a + size_b, 2);
            }else{
                (new QErrorMessage(this))->showMessage("Сгенерируйте исходные массивы");
            }
        break;
        }
        }
    }else{
       (new QErrorMessage(this))->showMessage("Массив не создан");
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index != 7){
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Входной"));
        ui->MyTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Выходной"));
        ui->MyTable->setColumnCount(2);
        ui->MyTable->setFixedWidth(251);
        setFixedWidth(545);
        ui->label->setGeometry(260, 60, 151, 31);
        ui->spinBox->setGeometry(420, 60, 45, 31);
        ui->comboBox->setGeometry(270, 20, 257, 31);
        ui->FillButton->setGeometry(270, 100, 257, 31);
        ui->SortButton->setGeometry(270, 140, 257, 31);
        ui->SortButton->setText("Сортировать");
        ui->ClearButton->setGeometry(270, 180, 257, 31);
        ui->MyTable->setRowCount(0);
    }else{
        ui->MyTable->setColumnCount(3);
        ui->MyTable->setFixedWidth(331);
        setFixedWidth(633);
        ui->label->setGeometry(350, 60, 151, 31);
        ui->spinBox->setGeometry(510, 60, 45, 31);
        ui->comboBox->setGeometry(360, 20, 257, 31);
        ui->FillButton->setGeometry(360, 100, 257, 31);
        ui->SortButton->setGeometry(360, 140, 257, 31);
        ui->SortButton->setText("Слить");
        ui->ClearButton->setGeometry(360, 180, 257, 31);
        ui->MyTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Элементы a"));
        ui->MyTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Элементы b"));
        ui->MyTable->setHorizontalHeaderItem(2,new QTableWidgetItem("Элементы c"));
        zd = 0;
        ui->MyTable->setRowCount(0);
    }
}

void MainWindow::on_ClearButton_clicked()
{
    if(ui->comboBox->currentIndex() != 7){
        ui->MyTable->setRowCount(0);
    }else{
        zd = 0;
        ui->MyTable->setRowCount(0);
    }
}

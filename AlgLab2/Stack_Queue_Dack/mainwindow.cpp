#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#define MAXSIZE 50

UD_List stack;
BD_List queue;
BD_List dack;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->AddButton_2->setEnabled(false);
    ui->DelButton_2->setEnabled(false);

    ui->MyTable->insertRow(ui->MyTable->rowCount());
    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//вывод в таблицу списка
void MainWindow::setTable(UD_List &List){
    if(List.getCount() == 0){
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Элементы"));
        ui->MyTable->setRowCount(0);
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
    }else{
        ui->MyTable->setRowCount(List.getCount());
        for(int i =1; i <= List.getCount();i++){
            switch(List.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List.getInt(i))));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List.getDoub(i))));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List.getChar(i))));
                break;
            }
            }
        }
    }
};

void MainWindow::setTable(BD_List &List){
    if(List.getCount() == 0){
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Элементы"));
        ui->MyTable->setRowCount(0);
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
    }else{
        ui->MyTable->setRowCount(List.getCount());
        for(int i =1; i <= List.getCount();i++){
            switch(List.getKey(i)){
            case integ:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List.getInt(i))));
                break;
            }
            case doub:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString::number(List.getDoub(i))));
                break;
            }
            case ch:{
                ui->MyTable->setItem(i-1, 0, new QTableWidgetItem(QString(List.getChar(i))));
                break;
            }
            }
        }
    }
};

void MainWindow::on_AddButton_clicked(){
    switch (ui->ListTypeBox->currentIndex()) {
    case 0:{
        if(stack.getCount() >= MAXSIZE){
            ui->AddButton->setEnabled(false);
            QMessageBox::warning(this, "Внимание", "Стек переполнен");
        }else{
            switch (ui->TypeItemBox->currentIndex()){
            case 0:{
                if (stack.getCount() == 0){
                    stack.addIntItem(ui->spinBox->value());
                    ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString::number(stack.getInt())));
                }else{
                    stack.insertIntItem(1, ui->spinBox->value());
                    setTable(stack);
                }
                break;
            }
            case 1:{
                if (stack.getCount() == 0){
                    stack.addDoubItem(ui->doubleSpinBox->value());
                    ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString::number(stack.getDoub())));
                }else{
                    stack.insertDoubItem(1, ui->doubleSpinBox->value());
                    setTable(stack);
                }
                break;
            }
            case 2:{
                if (stack.getCount() == 0){
                    stack.addCharItem(ui->lineEdit->text()[0]);
                    ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString(stack.getChar())));
                }else{
                    stack.insertCharItem(1, ui->lineEdit->text()[0]);
                    setTable(stack);
                }
                break;
            }
            }
        }
        break;
    }
    case 1:{
        if(queue.getCount() >= MAXSIZE){
            ui->AddButton->setEnabled(false);
            QMessageBox::warning(this, "Внимание", "Очередь переполнена");
        }else{
            switch (ui->TypeItemBox->currentIndex()){
            case 0:{
                queue.addIntItem(ui->spinBox->value());
                    if (queue.getCount() == 1){
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(queue.getInt())));
                }else{
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(queue.getInt())));
                }
                break;
            }
            case 1:{
                queue.addDoubItem(ui->doubleSpinBox->value());
                if (queue.getCount() == 1){
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(queue.getDoub())));
                }else{
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(queue.getDoub())));
                }
                break;
            }
                case 2:{
                queue.addCharItem(ui->lineEdit->text()[0]);
                if (queue.getCount() == 1){
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(queue.getChar())));
                }else{
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(queue.getChar())));
                }
                break;
            }
            }
        }
        break;
    }
    case 2:{
        if(dack.getCount() >= MAXSIZE){
            ui->AddButton->setEnabled(false);
            ui->AddButton_2->setEnabled(false);
            QMessageBox::warning(this, "Внимание", "Дек переполнен");
        }else{
            switch (ui->TypeItemBox->currentIndex()){
            case 0:{
                if (dack.getCount() == 0){
                    dack.addIntItem(ui->spinBox->value());
                    ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString::number(dack.getInt())));
                }else{
                    dack.insertIntItem(1, ui->spinBox->value());
                    setTable(dack);
                }
                break;
            }
            case 1:{
                if (dack.getCount() == 0){
                    dack.addDoubItem(ui->doubleSpinBox->value());
                        ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString::number(dack.getDoub())));
            }else{
                    dack.insertDoubItem(1, ui->doubleSpinBox->value());
                        setTable(dack);
            }
                break;
            }
            case 2:{
                if (dack.getCount() == 0){
                    dack.addCharItem(ui->lineEdit->text()[0]);
                    ui->MyTable->setItem(0, 0, new QTableWidgetItem(QString(dack.getChar())));
                    }else{
                    dack.insertCharItem(1, ui->lineEdit->text()[0]);
                    setTable(dack);
                }
                break;
            }
            }
        }
        break;
    }
    }
}

void MainWindow::on_TypeItemBox_currentIndexChanged(int index)
{
    switch (index) {
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

void MainWindow::on_DelButton_clicked()
{
   int index = ui->ListTypeBox->currentIndex();
   switch (index) {
   case 0:{
       stack.delItem(1);
       ui->MyTable->removeRow(0);
       if(stack.getCount() == 0){
           ui->MyTable->insertRow(ui->MyTable->rowCount());
           ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
       };
       if(stack.getCount() < MAXSIZE)
           ui->AddButton->setEnabled(true);
       break;
   }
   case 1:{
       queue.delItem(1);
       ui->MyTable->removeRow(0);
       if(queue.getCount() == 0){
           ui->MyTable->insertRow(ui->MyTable->rowCount());
           ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
       };
       if(queue.getCount() < MAXSIZE)
           ui->AddButton->setEnabled(true);
       break;
   }
   case 2:{
       dack.delItem(1);
       ui->MyTable->removeRow(0);
       if(dack.getCount() == 0){
           ui->MyTable->insertRow(ui->MyTable->rowCount());
           ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
       };
       if(dack.getCount() < MAXSIZE){
           ui->AddButton->setEnabled(true);
           ui->AddButton_2->setEnabled(true);
          }
       break;
   }
   }
}

void MainWindow::on_clearButton_clicked()
{
    int index = ui->ListTypeBox->currentIndex();
    switch (index) {
    case 0:{
        if(stack.getCount() < MAXSIZE)
            ui->AddButton->setEnabled(true);
        stack.~UD_List();
        ui->MyTable->clear();
        ui->MyTable->setRowCount(0);
        ui->MyTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Элементы"));
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        break;
    }
    case 1:{
        if(queue.getCount() < MAXSIZE)
            ui->AddButton->setEnabled(true);
        queue.~BD_List();
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Элементы"));
        ui->MyTable->setRowCount(0);
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        break;
    }
    case 2:{
        if(dack.getCount() < MAXSIZE){
            ui->AddButton->setEnabled(true);
            ui->AddButton_2->setEnabled(true);
        }
        dack.~BD_List();
        ui->MyTable->clear();
        ui->MyTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Элементы"));
        ui->MyTable->setRowCount(0);
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
        break;
    }
    }
}

void MainWindow::on_ListTypeBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:{
        if(stack.getCount() < MAXSIZE)
            ui->AddButton->setEnabled(true);
        setTable(stack);
        ui->AddButton->setText("Добавить");
        ui->DelButton->setText("Извлечь");
        ui->AddButton_2->setEnabled(false);
        ui->DelButton_2->setEnabled(false);
        break;
    }
    case 1:{
        if(queue.getCount() < MAXSIZE)
            ui->AddButton->setEnabled(true);
        ui->AddButton->setText("Добавить");
        ui->DelButton->setText("Извлечь");
        ui->AddButton_2->setEnabled(false);
        ui->DelButton_2->setEnabled(false);
        setTable(queue);
        break;
    }
    case 2:{
        if(dack.getCount() < MAXSIZE){
            ui->AddButton->setEnabled(true);
            ui->AddButton_2->setEnabled(true);
        }
        ui->AddButton->setText("Добавить в начало");
        ui->DelButton->setText("Извлечь из начала");
        ui->DelButton_2->setEnabled(true);
        setTable(dack);
        break;
    }
    }
}

void MainWindow::on_AddButton_2_clicked()
{
    if(dack.getCount() >= MAXSIZE){
        ui->AddButton->setEnabled(false);
        ui->AddButton_2->setEnabled(false);
        QMessageBox::warning(this, "Внимание", "Дек переполнен");
    }else{
        switch (ui->TypeItemBox->currentIndex()){
        case 0:{
            dack.addIntItem(ui->spinBox->value());
            if (dack.getCount() == 1){
                    ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(dack.getInt())));
            }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(dack.getInt())));
            }
            break;
        }
        case 1:{
            dack.addDoubItem(ui->doubleSpinBox->value());
            if (dack.getCount() == 1){
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(dack.getDoub())));
            }else{
                    ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString::number(dack.getDoub())));
            }
            break;
        }
        case 2:{
            dack.addCharItem(ui->lineEdit->text()[0]);
            if (dack.getCount() == 1){
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(dack.getChar())));
                }else{
                ui->MyTable->insertRow(ui->MyTable->rowCount());
                ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem(QString(dack.getChar())));
            }
            break;
        }
        }
    }
}

void MainWindow::on_DelButton_2_clicked()
{
    dack.delItem(dack.getCount());
    ui->MyTable->removeRow(ui->MyTable->rowCount()-1);
    if(dack.getCount() == 0){
        ui->MyTable->insertRow(ui->MyTable->rowCount());
        ui->MyTable->setItem(ui->MyTable->rowCount()-1, 0, new QTableWidgetItem("Пусто"));
    };
    if(dack.getCount() < MAXSIZE){
        ui->AddButton->setEnabled(true);
        ui->AddButton_2->setEnabled(true);
    }
}

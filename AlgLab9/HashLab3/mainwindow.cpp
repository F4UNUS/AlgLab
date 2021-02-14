#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QErrorMessage"
#include "QFileDialog"

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

struct item{
    int data;
    item *next;
};
item **hashTab;
int tabSize;

int MainWindow::hashFunc(int data){
    return (data % tabSize);
}

void MainWindow::on_pushButton_clicked()
{
    tabSize = ui->spinBox->value();
    if(tabSize <= 256){
        QString fileName = QFileDialog::getOpenFileName(0, "Открытие файла", "", "*.txt");
        FILE *file;
        if((file = fopen(fileName.toLocal8Bit().constData(), "r")) == NULL){
            (new QErrorMessage(this))->showMessage("Внимание, файл не найден");
            return;
        }
        if(hashTab != NULL) delete [] hashTab;
        hashTab = new item*[tabSize];
        for (int i = 0;i < tabSize;i++) {
            hashTab[i] = NULL;
        }
        int num = 0;
        while(!feof(file)){
            fscanf(file, "%d", &num);
            int index = hashFunc(num);
            if(hashTab[index] == NULL){
                hashTab[index] = new item;
                hashTab[index]->data = num;
                hashTab[index]->next = NULL;
            }else{
                item *tmp = hashTab[index];
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = new item;
                tmp = tmp->next;
                tmp->data = num;
                tmp->next = NULL;
            }
        }
        fclose(file);
        QString res;
        for (int i = 0;i < tabSize;i++){
            res +=QString::number(i) + ":";
            item *tmp = hashTab[i];
            while(tmp != NULL){
                res += QString::number(tmp->data) + "->";
                tmp = tmp->next;
            }
            res += "\n";
        }
        ui->textBrowser->setText(res);
    }else{
        (new QErrorMessage(this))->showMessage("Ошибка: превышен максимально допустимый размер хеш-таблицы");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int num = ui->spinBox_2->value();
    int index = hashFunc(num);
    if(hashTab[index] != NULL){
        item *tmp = hashTab[index];
        int count = 0;
        while (tmp != NULL && tmp->data !=num ) {
            tmp = tmp->next;
            count++;
        }
        if(tmp != NULL){
            ui->label_4->setText("№ Сегмента: " + QString::number(index) + "\nКол-во сравнений: " + QString::number(count + 1));
        }else{
            ui->label_4->setText("Введенное число \nотсутствует в \nхеш-таблице!");
        }
    }else{
        ui->label_4->setText("Введенное число \nотсутствует в \nхеш-таблице!");
    }
}

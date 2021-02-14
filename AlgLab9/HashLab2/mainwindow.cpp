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
    QString data;
    item *next;
};
item **hashTab;
int tabSize;

int MainWindow::hashFunc(QString str){
    int index = str[0].toLatin1();
    return index % tabSize;
};

bool MainWindow::remove(QString data){
    bool res = false;
    item *tmp1 = NULL;
    int index = hashFunc(data);
    item *tmp2 = hashTab[index];
    while (tmp2 != NULL && tmp2->data[0] != data[0]){
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    if(tmp2 != NULL){
        if(tmp1 != NULL){
            tmp1->next = tmp2->next;
        }else{
            hashTab[index] = tmp2->next;
        }
        delete tmp2;
        tmp2 = NULL;
        res = true;
    }
    return res;
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
        if(hashTab != NULL) delete[] hashTab;
        hashTab = new item*[tabSize];
        for (int i = 0;i < tabSize;i++) {
            hashTab[i] = NULL;
        }
        QString buffer;
        char *str = new char[255];
        while(!feof(file)){
            fscanf(file, "%s", str);
            buffer = QString::fromLocal8Bit(str).toLower();
            int index = hashFunc(buffer);
            if(hashTab[index] == NULL){
                hashTab[index] = new item;
                hashTab[index]->data = buffer;
                hashTab[index]->next = NULL;
            }else{
                item *tmp = hashTab[index];
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = new item;
                tmp = tmp->next;
                tmp->data = buffer;
                tmp->next = NULL;
            }
        }
        delete[] str;
        fclose(file);
        QString res;
        for (int i = 0;i < tabSize;i++){
            res +=QString::number(i) + ":";
            item *tmp = hashTab[i];
            while(tmp != NULL){
                res += tmp->data + "->";
                tmp = tmp->next;
            }
            res += "\n";
        }
        ui->textBrowser->setText(res);
    }else{
        (new QErrorMessage(this))->showMessage("Ошибка: превышен максимально допустимый размер хеш-таблицы");
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text().toLower();
    int index = hashFunc(str);
    if(hashTab[index] != NULL){
        item *tmp = hashTab[index];
        int count = 0;
        while (tmp != NULL && tmp->data !=str ) {
            tmp = tmp->next;
            count++;
        }
        if(tmp != NULL){
            ui->label_4->setText("№ Сегмента: " + QString::number(index) + "\nКол-во сравнений: " + QString::number(count + 1));
        }else{
            ui->label_4->setText("Введенное слово отсутствует в хеш-таблице!");
        }
    }else{
        ui->label_4->setText("Введенное слово отсутствует в хеш-таблице!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit_2->text().toLower();
    bool succsess = true;
    int count = -1;
    while (succsess) {
        succsess = remove(str);
        count++;
    }
    if(count > 0){
        QString res;
        for (int i = 0;i < tabSize;i++){
            res +=QString::number(i) + ":";
            item *tmp = hashTab[i];
            while(tmp != NULL){
                res += tmp->data + "->";
                tmp = tmp->next;
            }
            res += "\n";
        }
        ui->textBrowser->setText(res);
    }else{
        (new QErrorMessage(this))->showMessage("Нет слов начинающихся на заданную букву");
    }
}

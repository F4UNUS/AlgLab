#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack_queue_dack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();

    void setTable(UD_List &List);//вывод однонаправленного в таблицу списка

    void setTable(BD_List &List);//вывод двунаправленного в таблицу

    void on_TypeItemBox_currentIndexChanged(int index);

    void on_DelButton_clicked();

    void on_clearButton_clicked();

    void on_ListTypeBox_currentIndexChanged(int index);

    void on_AddButton_2_clicked();

    void on_DelButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

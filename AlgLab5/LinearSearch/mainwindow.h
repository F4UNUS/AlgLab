#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_addButton_clicked();

    void toOutputInTable(int *array, int size, int nCol, int nRow);//вывод в таблицу

    void toOutputInTable(double *array, int size, int nCol, int nRow);//вывод в таблицу

    void on_delButton_clicked();

    void on_addButton_2_clicked();

    void on_arrayTypeBox_currentIndexChanged(int index);

    void on_clearButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

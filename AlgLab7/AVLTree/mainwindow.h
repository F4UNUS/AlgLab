#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include "avl_tree.h"
#include "bst_tree.h"

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
    void on_createTreeButton_clicked();

    void printTree(avl_tree Tree, int currentIndex, int X, int Y, bool Search);

    void printTree(bst_tree Tree, int currentIndex, int X, int Y, bool Search);

    void on_delItemButton_clicked();

    void on_delTreeButton_clicked();

    void on_searchButton_clicked();

    void on_squereButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};
#endif // MAINWINDOW_H

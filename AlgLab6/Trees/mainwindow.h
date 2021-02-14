#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include "binarytree.h"
#include "binarytree.cpp"

#include "rb_binarytree.h"
#include "rb_binarytree.cpp"

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

    void on_addLeftButton_clicked();

    void on_addRightButton_clicked();

    void printTree(BinaryTree<int> Tree, int currentIndex, int X, int Y);

    void printTree(BinaryTree<double> Tree, int currentIndex, int X, int Y);

    void printTree(BinaryTree<QChar> Tree, int currentIndex, int X, int Y);

    void preOrder(BinaryTree<int> Tree, int index);

    void postOrder(BinaryTree<int> Tree, int index);

    void SymmetricOrder(BinaryTree<int> Tree, int index);

    void preOrder(BinaryTree<double> Tree, int index);

    void postOrder(BinaryTree<double> Tree, int index);

    void SymmetricOrder(BinaryTree<double> Tree, int index);

    void preOrder(BinaryTree<QChar> Tree, int index);

    void postOrder(BinaryTree<QChar> Tree, int index);

    void SymmetricOrder(BinaryTree<QChar> Tree, int index);

    void printTree(RB_BinaryTree<int> Tree, int currentIndex, int X, int Y);

    void preOrder(RB_BinaryTree<int> Tree, int index);

    void postOrder(RB_BinaryTree<int> Tree, int index);

    void SymmetricOrder(RB_BinaryTree<int> Tree, int index);

    void on_insertLeftButton_clicked();

    void on_insertRightButton_clicked();

    void on_delItemButton_clicked();

    void on_orderButton_clicked();

    void on_typeBox_currentIndexChanged(int index);

    void on_delTreeButton_clicked();

    void on_treeTypeBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};
#endif // MAINWINDOW_H

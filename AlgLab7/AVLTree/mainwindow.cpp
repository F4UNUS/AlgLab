#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QErrorMessage"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-310, -290, 620, 580);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

avl_tree AVLTree;
bst_tree BSTree;

void MainWindow::printTree(avl_tree Tree, int currentIndex, int X, int Y, bool Search){
    Tree.setCurrentOnIndex(currentIndex);

    QBrush whiteBrush(Qt::white);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    if(currentIndex == Tree.search(ui->spinIndexBox->value()) && Search){
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, greenBrush);
    }else{
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
    }
    text = scene->addText(QString::number(Tree.getCurrentData()) + "(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setPos(X, Y);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y, Search);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y, Search);
    }
}

void MainWindow::printTree(bst_tree Tree, int currentIndex, int X, int Y, bool Search){
    Tree.setCurrentOnIndex(currentIndex);

    QBrush whiteBrush(Qt::white);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    if(currentIndex == Tree.search(ui->spinIndexBox->value()) && Search){
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, greenBrush);
    }else{
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
    }
    text = scene->addText(QString::number(Tree.getCurrentData()) + "(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setPos(X, Y);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y, Search);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y, Search);
    }
}

void MainWindow::on_createTreeButton_clicked()
{
    switch(ui->comboBox->currentIndex()){
    case 0:{
        BSTree.insert(ui->spinBox->value());
        if(!BSTree.empty()){
            scene->clear();
            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            scene->setSceneRect(-310, -290, 620, 580);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        }
        printTree(BSTree, 1, 0, -290, false);
        break;
    }
    case 1:{
        AVLTree.insert(ui->spinBox->value());
        if(!AVLTree.empty()){
            scene->clear();
            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            scene->setSceneRect(-310, -290, 620, 580);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        }
        printTree(AVLTree, 1, 0, -290, false);
        break;
    }
    }
}

void MainWindow::on_delItemButton_clicked()
{
    switch(ui->comboBox->currentIndex()){
    case 0:{
        if(!BSTree.empty()){
            int c = BSTree.getCount();
            BSTree.remove(ui->spinIndexBox_2->value());
            scene->clear();
            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            scene->setSceneRect(-310, -290, 620, 580);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
            printTree(BSTree, 1, 0, -290, false);
            if(c == BSTree.getCount()){
                (new QErrorMessage(this))->showMessage("Элемент не найден");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    case 1:{
        if(!AVLTree.empty()){
            int c = AVLTree.getCount();
            AVLTree.remove(ui->spinIndexBox_2->value());
            scene->clear();
            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            scene->setSceneRect(-310, -290, 620, 580);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
            printTree(AVLTree, 1, 0, -290, false);
            if(c == AVLTree.getCount()){
                (new QErrorMessage(this))->showMessage("Элемент не найден");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    }
}

void MainWindow::on_delTreeButton_clicked()
{
    switch(ui->comboBox->currentIndex()){
    case 0:{
        if(!BSTree.empty()){
            scene->clear();
            BSTree.clear();
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    case 1:{
        if(!AVLTree.empty()){
            scene->clear();
            AVLTree.clear();
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    }
}

void MainWindow::on_searchButton_clicked()
{
    switch (ui->comboBox->currentIndex()){
    case 0:{
        if(!BSTree.empty()){
            if(BSTree.search(ui->spinIndexBox->value()) > 0){
                scene->clear();
                scene = new QGraphicsScene(this);
                ui->graphicsView->setScene(scene);
                scene->setSceneRect(-310, -290, 620, 580);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);
                printTree(BSTree, 1, 0, -290, true);
            }else{
                (new QErrorMessage(this))->showMessage("Элемент не найден");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    case 1:{
        if(!AVLTree.empty()){
            if(AVLTree.search(ui->spinIndexBox->value()) > 0){
                scene->clear();
                scene = new QGraphicsScene(this);
                ui->graphicsView->setScene(scene);
                scene->setSceneRect(-310, -290, 620, 580);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);
                printTree(AVLTree, 1, 0, -290, true);
            }else{
                (new QErrorMessage(this))->showMessage("Элемент не найден");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Дерево не создано");
        }
        break;
    }
    }
}

void MainWindow::on_squereButton_clicked()
{
    if(!BSTree.empty()){
        BSTree.squereRoot();
        scene->clear();
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-310, -290, 620, 580);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        printTree(BSTree, 1, 0, -290, false);
    }else{
        (new QErrorMessage(this))->showMessage("Дерево не создано");
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index){
    case 0:{
        ui->squereButton->setEnabled(true);
        break;
    }
    case 1:{
        ui->squereButton->setEnabled(false);
        break;
    }
    }
}

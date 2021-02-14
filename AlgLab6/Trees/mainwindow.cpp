#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>
#include "math.h"

int currentIntIndex = 0;
int currentDoubleIndex = 0;
int currentCharIndex = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

BinaryTree<int> intTree;
BinaryTree<double> doubleTree;
BinaryTree<QChar> charTree;
RB_BinaryTree<int> rbTree;
//отрисвки бинарных разного типа
void MainWindow::printTree(BinaryTree<int> Tree, int currentIndex, int X, int Y){
    Tree.setcurrentOnIndex(currentIndex);

    QBrush whiteBrush(Qt::white);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
    text = scene->addText(QString::number(Tree.getCurrentData()) + "(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setPos(X, Y);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
    }
}

void MainWindow::printTree(BinaryTree<double> Tree, int currentIndex, int X, int Y){
    Tree.setcurrentOnIndex(currentIndex);

    QBrush whiteBrush(Qt::white);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
    text = scene->addText(QString::number(Tree.getCurrentData()) + "\n" +"(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setPos(X + 3, Y - 2);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
    }
};

void MainWindow::printTree(BinaryTree<QChar> Tree, int currentIndex, int X, int Y){
    Tree.setcurrentOnIndex(currentIndex);

    QBrush whiteBrush(Qt::white);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
    text = scene->addText(QString(Tree.getCurrentData()) + "(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setPos(X, Y);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
    }
};
//отрисовка кч дерева
void MainWindow::printTree(RB_BinaryTree<int> Tree, int currentIndex, int X, int Y){
    Tree.setcurrentOnIndex(currentIndex);

    QBrush blackBrush(Qt::black);
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    QPen whitePen(Qt::white);
    blackPen.setWidth(1);
    whitePen.setWidth(1);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    if(Tree.getCurrentColor()){
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, redBrush);
    }else{
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, blackBrush);
    }
    text = scene->addText(QString::number(Tree.getCurrentData()) + "(" + QString::number(Tree.getCurrentIndex()) + ")");
    text->setDefaultTextColor(Qt::white);
    text->setPos(X, Y);
    if(!Tree.leftBranchEmpty()){
        currentIndex *= 2;
        scene->addLine(X + 15, Y + 30, X - 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X -= 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
        currentIndex /= 2;
        X += 150/pow(2, Tree.getCurrentDepth());
        Y -= 30*pow(2, Tree.getCurrentDepth());
    }
    if(!Tree.rightBranchEmpty()){
        currentIndex = currentIndex*2 + 1;
        scene->addLine(X + 15, Y + 30, X + 150/pow(2, Tree.getCurrentDepth()) + 15, Y + 30*pow(2, Tree.getCurrentDepth()) + 15);
        X += 150/pow(2, Tree.getCurrentDepth());
        Y += 30*pow(2, Tree.getCurrentDepth());
        printTree(Tree, currentIndex, X, Y);
    }
}
//обходы бинарного
void MainWindow::preOrder(BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(Tree.currentBranchEmpty())
        return;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    index *= 2;
    preOrder(Tree, index);
    index ++;
    preOrder(Tree, index);
};

void MainWindow::postOrder(BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        postOrder(Tree, index);
        index ++;
        postOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    }
};

void MainWindow::SymmetricOrder(BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        SymmetricOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
        index ++;
        SymmetricOrder(Tree, index);
    }
};

void MainWindow::preOrder(BinaryTree<double> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(Tree.currentBranchEmpty())
        return;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    index *= 2;
    preOrder(Tree, index);
    index ++;
    preOrder(Tree, index);
};

void MainWindow::postOrder(BinaryTree<double> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        postOrder(Tree, index);
        index ++;
        postOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    }
};

void MainWindow::SymmetricOrder(BinaryTree<double> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        SymmetricOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
        index ++;
        SymmetricOrder(Tree, index);
    }
};

void MainWindow::preOrder(BinaryTree<QChar> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(Tree.currentBranchEmpty())
        return;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString(Tree.getCurrentData())));
    index *= 2;
    preOrder(Tree, index);
    index ++;
    preOrder(Tree, index);
};

void MainWindow::postOrder(BinaryTree<QChar> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        postOrder(Tree, index);
        index ++;
        postOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString(Tree.getCurrentData())));
    }
};

void MainWindow::SymmetricOrder(BinaryTree<QChar> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        SymmetricOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString(Tree.getCurrentData())));
        index ++;
        SymmetricOrder(Tree, index);
    }
};

//обходы кч дерева
void MainWindow::preOrder(RB_BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(Tree.currentBranchEmpty())
        return;
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    index *= 2;
    preOrder(Tree, index);
    index ++;
    preOrder(Tree, index);
};

void MainWindow::postOrder(RB_BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        postOrder(Tree, index);
        index ++;
        postOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
    }
};

void MainWindow::SymmetricOrder(RB_BinaryTree<int> Tree, int index){
    Tree.setcurrentOnIndex(index);
    if(!Tree.currentBranchEmpty()){
        index *= 2;
        SymmetricOrder(Tree, index);
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(Tree.getCurrentData())));
        index ++;
        SymmetricOrder(Tree, index);
    }
};

void MainWindow::on_createTreeButton_clicked()
{
    switch(ui->treeTypeBox->currentIndex()){
    case 0:{
        switch(ui->typeBox->currentIndex()){
        case 0:{
            if(intTree.empty()){
                intTree.toCreateRoot(ui->spinBox->value());
                currentIntIndex++;

                scene = new QGraphicsScene(this);
                ui->graphicsView->setScene(scene);
                scene->setSceneRect(-310, -290, 620, 580);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);

                printTree(intTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева уже создан");
            }
            break;
        }
        case 1:{
            if(doubleTree.empty()){
                doubleTree.toCreateRoot(ui->doubleSpinBox->value());
                currentDoubleIndex++;

                scene = new QGraphicsScene(this);
                ui->graphicsView->setScene(scene);
                scene->setSceneRect(-310, -290, 620, 580);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);

                printTree(doubleTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева уже создан");
            }
            break;
        }
        case 2:{
            if(charTree.empty()){
                charTree.toCreateRoot(ui->lineEdit->text()[0]);
                currentCharIndex++;

                scene = new QGraphicsScene(this);
                ui->graphicsView->setScene(scene);
                scene->setSceneRect(-310, -290, 620, 580);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);

                printTree(charTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева уже создан");
            }
            break;
        }
        }
        break;
    }
    case 1:{
        if(rbTree.empty()){
            rbTree.toCreateRoot(ui->spinBox->value());

            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            scene->setSceneRect(-310, -290, 620, 580);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);

            printTree(rbTree, 1, 0, -290);
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева уже создан");
        }
        break;
    }
    }
}

void MainWindow::on_addLeftButton_clicked()
{
    switch(ui->treeTypeBox->currentIndex()){
    case 0:{
        switch(ui->typeBox->currentIndex()){
        case 0:{
            if(!intTree.empty()){
                intTree.toAddLeftItem(ui->spinBox->value(), currentIntIndex);
                currentIntIndex *= 2;

                scene->clear();
                printTree(intTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 1:{
            if(!doubleTree.empty()){
                doubleTree.toAddLeftItem(ui->doubleSpinBox->value(), currentDoubleIndex);
                currentDoubleIndex *= 2;

                scene->clear();
                printTree(doubleTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 2:{
            if(!charTree.empty()){
                charTree.toAddLeftItem(ui->lineEdit->text()[0], currentCharIndex);
                currentCharIndex *= 2;

                scene->clear();
                printTree(charTree, 1, 0, -290);
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        }
            break;
    }
    case 1:{
        if(!rbTree.empty()){
            rbTree.toAddItem(ui->spinBox->value());

            scene->clear();
            printTree(rbTree, 1, 0, -290);
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_addRightButton_clicked()
{
    switch(ui->typeBox->currentIndex()){
    case 0:{
        if(!intTree.empty()){
            intTree.toAddRightItem(ui->spinBox->value(), currentIntIndex);
            currentIntIndex = currentIntIndex*2 + 1;

            scene->clear();
            printTree(intTree, 1, 0, -290);
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 1:{
        if(!doubleTree.empty()){
            doubleTree.toAddRightItem(ui->doubleSpinBox->value(), currentDoubleIndex);
            currentDoubleIndex =currentDoubleIndex*2 + 1;

            scene->clear();
            printTree(doubleTree, 1, 0, -290);
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 2:{
        if(!charTree.empty()){
            charTree.toAddRightItem(ui->lineEdit->text()[0], currentCharIndex);
            currentCharIndex =currentCharIndex*2 + 1;

            scene->clear();
            printTree(charTree, 1, 0, -290);
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_insertLeftButton_clicked()
{
    switch(ui->typeBox->currentIndex()){
    case 0:{
        if(!intTree.empty()){
            intTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!intTree.currentBranchEmpty()){
                intTree.toAddLeftItem(ui->spinBox->value(), ui->spinIndexBox->value());

                scene->clear();
                printTree(intTree, 1, 0, -290);
                currentIntIndex = ui->spinIndexBox->value()*2;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 1:{
        if(!doubleTree.empty()){
            doubleTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!doubleTree.currentBranchEmpty()){
                doubleTree.toAddLeftItem(ui->doubleSpinBox->value(), ui->spinIndexBox->value());

                scene->clear();
                printTree(doubleTree, 1, 0, -290);
                currentDoubleIndex = ui->spinIndexBox->value()*2;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 2:{
        if(!charTree.empty()){
            charTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!charTree.currentBranchEmpty()){
                charTree.toAddLeftItem(ui->lineEdit->text()[0], ui->spinIndexBox->value());

                scene->clear();
                printTree(charTree, 1, 0, -290);
                currentCharIndex = ui->spinIndexBox->value()*2;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_insertRightButton_clicked()
{
    switch(ui->typeBox->currentIndex()){
    case 0:{
        if(!intTree.empty()){
            intTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!intTree.currentBranchEmpty()){
                intTree.toAddRightItem(ui->spinBox->value(), ui->spinIndexBox->value());

                scene->clear();
                printTree(intTree, 1, 0, -290);
                currentIntIndex = ui->spinIndexBox->value()*2 + 1;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 1:{
        if(!doubleTree.empty()){
            doubleTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!doubleTree.currentBranchEmpty()){
                doubleTree.toAddRightItem(ui->doubleSpinBox->value(), ui->spinIndexBox->value());

                scene->clear();
                printTree(doubleTree, 1, 0, -290);
                currentDoubleIndex = ui->spinIndexBox->value()*2 + 1;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 2:{
        if(!charTree.empty()){
            charTree.setcurrentOnIndex(ui->spinIndexBox->value());
            if(!charTree.currentBranchEmpty()){
                charTree.toAddRightItem(ui->lineEdit->text()[0], ui->spinIndexBox->value());

                scene->clear();
                printTree(charTree, 1, 0, -290);
                currentCharIndex = ui->spinIndexBox->value()*2 + 1;
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_delItemButton_clicked()
{
    switch (ui->treeTypeBox->currentIndex()) {
    case 0:{
        switch(ui->typeBox->currentIndex()){
        case 0:{
            if(!intTree.empty()){
                intTree.setcurrentOnIndex(ui->spinIndexBox_2->value());
                if(!intTree.currentBranchEmpty()){
                    intTree.toDelItem(ui->spinIndexBox_2->value());

                    scene->clear();
                    if(!intTree.empty()){
                        printTree(intTree, 1, 0, -290);
                    }else{
                        currentIntIndex = 0;
                    }
                }else{
                    (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 1:{
            if(!doubleTree.empty()){
                doubleTree.setcurrentOnIndex(ui->spinIndexBox_2->value());
                if(!doubleTree.currentBranchEmpty()){
                    doubleTree.toDelItem(ui->spinIndexBox_2->value());

                    scene->clear();
                    if(!doubleTree.empty()){
                        printTree(doubleTree, 1, 0, -290);
                    }else{
                        currentDoubleIndex = 0;
                    }
                }else{
                    (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 2:{
            if(!charTree.empty()){
                charTree.setcurrentOnIndex(ui->spinIndexBox_2->value());
                if(!charTree.currentBranchEmpty()){
                    charTree.toDelItem(ui->spinIndexBox_2->value());

                    scene->clear();
                    if(!charTree.empty()){
                        printTree(charTree, 1, 0, -290);
                    }else{
                        currentCharIndex = 0;
                    }
                }else{
                    (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        }
        break;
    }
    case 1:{
        if(!rbTree.empty()){
            rbTree.setcurrentOnIndex(ui->spinIndexBox_2->value());
            if(!rbTree.currentBranchEmpty()){
                rbTree.toDelItem(ui->spinIndexBox_2->value());

                scene->clear();
                if(!rbTree.empty()){
                    printTree(rbTree, 1, 0, -290);
                }
            }else{
                (new QErrorMessage(this))->showMessage("Нет элемента с заданным индексом");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_orderButton_clicked()
{
    switch(ui->treeTypeBox->currentIndex()){
    case 0:{
        switch(ui->typeBox->currentIndex()){
        case 0:{
            if(!intTree.empty()){
                switch(ui->orderTypeBox->currentIndex()){
                case 0:{
                    ui->tableWidget->setRowCount(0);
                    preOrder(intTree, 1);
                    break;
                }
                case 1:{
                    ui->tableWidget->setRowCount(0);
                    postOrder(intTree, 1);
                    break;
                }
                case 2:{
                    ui->tableWidget->setRowCount(0);
                    SymmetricOrder(intTree, 1);
                    break;
                }
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 1:{
            if(!doubleTree.empty()){
                switch(ui->orderTypeBox->currentIndex()){
                case 0:{
                    ui->tableWidget->setRowCount(0);
                    preOrder(doubleTree, 1);
                    break;
                }
                case 1:{
                    ui->tableWidget->setRowCount(0);
                    postOrder(doubleTree, 1);
                    break;
                }
                case 2:{
                    ui->tableWidget->setRowCount(0);
                    SymmetricOrder(doubleTree, 1);
                    break;
                }
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        case 2:{
            if(!charTree.empty()){
                switch(ui->orderTypeBox->currentIndex()){
                case 0:{
                    ui->tableWidget->setRowCount(0);
                    preOrder(charTree, 1);
                    break;
                }
                case 1:{
                    ui->tableWidget->setRowCount(0);
                    postOrder(charTree, 1);
                    break;
                }
                case 2:{
                    ui->tableWidget->setRowCount(0);
                    SymmetricOrder(charTree, 1);
                    break;
                }
                }
            }else{
                (new QErrorMessage(this))->showMessage("Корень дерева не создан");
            }
            break;
        }
        }
        break;
    }
    case 1:{
        if(!rbTree.empty()){
            switch(ui->orderTypeBox->currentIndex()){
            case 0:{
                ui->tableWidget->setRowCount(0);
                preOrder(rbTree, 1);
                break;
            }
            case 1:{
                ui->tableWidget->setRowCount(0);
                postOrder(rbTree, 1);
                break;
            }
            case 2:{
                ui->tableWidget->setRowCount(0);
                SymmetricOrder(rbTree, 1);
                break;
            }
            }
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_typeBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->spinBox->setEnabled(true);
        ui->doubleSpinBox->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        if(!intTree.empty()){
            if(!doubleTree.empty() || !charTree.empty())
                scene->clear();
            printTree(intTree, 1, 0, -290);
        }
        break;
    }
    case 1:{
        ui->spinBox->setEnabled(false);
        ui->doubleSpinBox->setEnabled(true);
        ui->lineEdit->setEnabled(false);
        if(!doubleTree.empty()){
            if(!intTree.empty() || !charTree.empty())
                scene->clear();
            printTree(doubleTree, 1, 0, -290);
        }
        break;
    }
    case 2:{
        ui->spinBox->setEnabled(false);
        ui->doubleSpinBox->setEnabled(false);
        ui->lineEdit->setEnabled(true);
        if(!charTree.empty()){
            if(!doubleTree.empty() || !intTree.empty())
                scene->clear();
            printTree(charTree, 1, 0, -290);
        }
        break;}
    }
}

void MainWindow::on_delTreeButton_clicked()
{
    switch(ui->treeTypeBox->currentIndex()){
    case 0:{
    switch(ui->typeBox->currentIndex()){
    case 0:{
        if(!intTree.empty()){
            intTree.clear();
            currentIntIndex = 0;

            scene->clear();
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 1:{
        if(!doubleTree.empty()){
            doubleTree.clear();
            currentDoubleIndex = 0;

            scene->clear();
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    case 2:{
        if(!charTree.empty()){
            charTree.clear();
            currentCharIndex = 0;

            scene->clear();
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
    break;
    }
    case 1:{
        if(!rbTree.empty()){
            rbTree.clear();

            scene->clear();
        }else{
            (new QErrorMessage(this))->showMessage("Корень дерева не создан");
        }
        break;
    }
    }
}

void MainWindow::on_treeTypeBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:{
        ui->typeBox->setEnabled(true);
        ui->addLeftButton->setText("Добавить слева");
        ui->addRightButton->setEnabled(true);
        ui->spinIndexBox->setEnabled(true);
        ui->insertLeftButton->setEnabled(true);
        ui->insertRightButton->setEnabled(true);
        break;
    }
    case 1:{
        ui->typeBox->setCurrentIndex(0);
        ui->typeBox->setEnabled(false);
        if(!intTree.empty())
            scene->clear();
        ui->addLeftButton->setText("Добавить");
        ui->addRightButton->setEnabled(false);
        ui->spinIndexBox->setEnabled(false);
        ui->insertLeftButton->setEnabled(false);
        ui->insertRightButton->setEnabled(false);
        break;
    }
    }
}

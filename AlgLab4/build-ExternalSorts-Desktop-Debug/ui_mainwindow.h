/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SortButton;
    QPushButton *ClearButton;
    QPushButton *OpenButton;
    QTableWidget *MyTable;
    QComboBox *comboBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(545, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SortButton = new QPushButton(centralwidget);
        SortButton->setObjectName(QString::fromUtf8("SortButton"));
        SortButton->setGeometry(QRect(270, 100, 257, 31));
        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(270, 150, 257, 31));
        OpenButton = new QPushButton(centralwidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setGeometry(QRect(270, 50, 257, 31));
        MyTable = new QTableWidget(centralwidget);
        if (MyTable->columnCount() < 2)
            MyTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        MyTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        MyTable->setObjectName(QString::fromUtf8("MyTable"));
        MyTable->setGeometry(QRect(10, 10, 251, 571));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 10, 257, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SortButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        ClearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        OpenButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem = MyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\320\276\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = MyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\201\320\273\320\270\321\217\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\225\321\201\321\202\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\201\320\273\320\270\321\217\320\275\320\270\320\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

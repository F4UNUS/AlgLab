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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *myTable;
    QComboBox *arrayTypeBox;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *addButton;
    QPushButton *delButton;
    QComboBox *searchTypeBox;
    QPushButton *searchButton;
    QPushButton *clearButton;
    QDoubleSpinBox *searchDoubleSpinBox;
    QSpinBox *searchSpinBox;
    QPushButton *addButton_2;
    QLabel *label;
    QSpinBox *sizeSpinBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(355, 594);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myTable = new QTableWidget(centralwidget);
        if (myTable->columnCount() < 1)
            myTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        myTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        myTable->setObjectName(QString::fromUtf8("myTable"));
        myTable->setGeometry(QRect(10, 10, 151, 571));
        arrayTypeBox = new QComboBox(centralwidget);
        arrayTypeBox->addItem(QString());
        arrayTypeBox->addItem(QString());
        arrayTypeBox->setObjectName(QString::fromUtf8("arrayTypeBox"));
        arrayTypeBox->setGeometry(QRect(170, 10, 171, 31));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(170, 150, 61, 25));
        spinBox->setMinimum(-100);
        spinBox->setMaximum(100);
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(250, 150, 91, 25));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMinimum(-100.000000000000000);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox->setSingleStep(0.001000000000000);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(170, 190, 171, 31));
        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setGeometry(QRect(170, 240, 171, 31));
        searchTypeBox = new QComboBox(centralwidget);
        searchTypeBox->addItem(QString());
        searchTypeBox->addItem(QString());
        searchTypeBox->addItem(QString());
        searchTypeBox->addItem(QString());
        searchTypeBox->setObjectName(QString::fromUtf8("searchTypeBox"));
        searchTypeBox->setGeometry(QRect(170, 290, 171, 31));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(170, 380, 171, 31));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(170, 430, 171, 31));
        searchDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        searchDoubleSpinBox->setObjectName(QString::fromUtf8("searchDoubleSpinBox"));
        searchDoubleSpinBox->setGeometry(QRect(250, 340, 91, 25));
        searchDoubleSpinBox->setDecimals(3);
        searchDoubleSpinBox->setMinimum(-100.000000000000000);
        searchDoubleSpinBox->setMaximum(100.000000000000000);
        searchDoubleSpinBox->setSingleStep(0.001000000000000);
        searchSpinBox = new QSpinBox(centralwidget);
        searchSpinBox->setObjectName(QString::fromUtf8("searchSpinBox"));
        searchSpinBox->setGeometry(QRect(170, 340, 61, 25));
        searchSpinBox->setMinimum(-100);
        searchSpinBox->setMaximum(100);
        addButton_2 = new QPushButton(centralwidget);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));
        addButton_2->setGeometry(QRect(170, 100, 171, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 60, 121, 21));
        sizeSpinBox = new QSpinBox(centralwidget);
        sizeSpinBox->setObjectName(QString::fromUtf8("sizeSpinBox"));
        sizeSpinBox->setGeometry(QRect(290, 60, 51, 25));
        sizeSpinBox->setMinimum(1);
        sizeSpinBox->setMaximum(100);
        sizeSpinBox->setValue(1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = myTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\270\320\262", nullptr));
        arrayTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\320\276\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        arrayTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\265\321\210\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));

        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        searchTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272", nullptr));
        searchTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272", nullptr));
        searchTypeBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272 \320\277\320\265\321\200\320\262\320\276\320\265 \320\270 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\265", nullptr));
        searchTypeBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272 \320\262\321\201\320\265", nullptr));

        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\270 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        addButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\277\320\260\320\274\321\217\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273 - \320\262\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

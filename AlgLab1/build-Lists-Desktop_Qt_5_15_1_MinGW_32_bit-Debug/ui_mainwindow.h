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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QTableWidget *MyTable;
    QGroupBox *AddInsertSearchGroup;
    QSpinBox *spinBox;
    QComboBox *TypeItemBox;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *AddButton;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *insertSpinBox;
    QPushButton *InsertButton;
    QPushButton *searchButton;
    QComboBox *ListTypeBox;
    QGroupBox *delBox;
    QSpinBox *DelSpinBox;
    QLabel *label;
    QPushButton *DelButton;
    QPushButton *clearButton;
    QPushButton *getBackButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(313, 426);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MyTable = new QTableWidget(centralwidget);
        if (MyTable->columnCount() < 1)
            MyTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        MyTable->setObjectName(QString::fromUtf8("MyTable"));
        MyTable->setGeometry(QRect(10, 10, 140, 404));
        AddInsertSearchGroup = new QGroupBox(centralwidget);
        AddInsertSearchGroup->setObjectName(QString::fromUtf8("AddInsertSearchGroup"));
        AddInsertSearchGroup->setGeometry(QRect(160, 40, 141, 211));
        spinBox = new QSpinBox(AddInsertSearchGroup);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 60, 46, 25));
        spinBox->setMinimum(-10000000);
        spinBox->setMaximum(10000000);
        TypeItemBox = new QComboBox(AddInsertSearchGroup);
        TypeItemBox->addItem(QString());
        TypeItemBox->addItem(QString());
        TypeItemBox->addItem(QString());
        TypeItemBox->setObjectName(QString::fromUtf8("TypeItemBox"));
        TypeItemBox->setGeometry(QRect(10, 30, 121, 24));
        doubleSpinBox = new QDoubleSpinBox(AddInsertSearchGroup);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 60, 61, 25));
        doubleSpinBox->setMinimum(-1000000000.899999976158142);
        doubleSpinBox->setMaximum(100000000.989999994635582);
        AddButton = new QPushButton(AddInsertSearchGroup);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(40, 90, 91, 25));
        lineEdit = new QLineEdit(AddInsertSearchGroup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 21, 24));
        lineEdit->setMaxLength(1);
        label_2 = new QLabel(AddInsertSearchGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 55, 21));
        insertSpinBox = new QSpinBox(AddInsertSearchGroup);
        insertSpinBox->setObjectName(QString::fromUtf8("insertSpinBox"));
        insertSpinBox->setGeometry(QRect(80, 120, 51, 25));
        insertSpinBox->setMinimum(1);
        insertSpinBox->setMaximum(1000000);
        InsertButton = new QPushButton(AddInsertSearchGroup);
        InsertButton->setObjectName(QString::fromUtf8("InsertButton"));
        InsertButton->setGeometry(QRect(10, 150, 121, 25));
        searchButton = new QPushButton(AddInsertSearchGroup);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(10, 180, 121, 25));
        ListTypeBox = new QComboBox(centralwidget);
        ListTypeBox->addItem(QString());
        ListTypeBox->addItem(QString());
        ListTypeBox->addItem(QString());
        ListTypeBox->addItem(QString());
        ListTypeBox->setObjectName(QString::fromUtf8("ListTypeBox"));
        ListTypeBox->setGeometry(QRect(160, 10, 141, 24));
        delBox = new QGroupBox(centralwidget);
        delBox->setObjectName(QString::fromUtf8("delBox"));
        delBox->setGeometry(QRect(160, 260, 141, 91));
        DelSpinBox = new QSpinBox(delBox);
        DelSpinBox->setObjectName(QString::fromUtf8("DelSpinBox"));
        DelSpinBox->setGeometry(QRect(80, 30, 51, 25));
        DelSpinBox->setMinimum(1);
        DelSpinBox->setMaximum(10000000);
        label = new QLabel(delBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 71, 21));
        DelButton = new QPushButton(delBox);
        DelButton->setObjectName(QString::fromUtf8("DelButton"));
        DelButton->setGeometry(QRect(10, 60, 121, 25));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(160, 390, 141, 25));
        getBackButton = new QPushButton(centralwidget);
        getBackButton->setObjectName(QString::fromUtf8("getBackButton"));
        getBackButton->setGeometry(QRect(160, 360, 141, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = MyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));
        AddInsertSearchGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\270 \320\262\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        TypeItemBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\321\213\320\271", nullptr));
        TypeItemBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        TypeItemBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\320\262\320\276\320\273\321\214\320\275\321\213\320\271", nullptr));

        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264", nullptr));
        InsertButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        ListTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\320\235 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        ListTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\235 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        ListTypeBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\236\320\235\320\246 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        ListTypeBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\224\320\235\320\246 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));

        delBox->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202 \342\204\226", nullptr));
        DelButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        getBackButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \321\201\320\277\320\270\321\201\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

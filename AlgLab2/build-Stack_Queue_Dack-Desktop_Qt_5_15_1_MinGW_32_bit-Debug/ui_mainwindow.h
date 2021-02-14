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
    QGroupBox *AddDelGroup;
    QSpinBox *spinBox;
    QComboBox *TypeItemBox;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *AddButton;
    QLineEdit *lineEdit;
    QPushButton *DelButton;
    QPushButton *AddButton_2;
    QPushButton *DelButton_2;
    QPushButton *clearButton;
    QComboBox *ListTypeBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(313, 345);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(313, 345));
        MainWindow->setMaximumSize(QSize(313, 345));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MyTable = new QTableWidget(centralwidget);
        if (MyTable->columnCount() < 1)
            MyTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        MyTable->setObjectName(QString::fromUtf8("MyTable"));
        MyTable->setGeometry(QRect(10, 10, 140, 325));
        AddDelGroup = new QGroupBox(centralwidget);
        AddDelGroup->setObjectName(QString::fromUtf8("AddDelGroup"));
        AddDelGroup->setGeometry(QRect(160, 40, 141, 241));
        spinBox = new QSpinBox(AddDelGroup);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 60, 46, 25));
        spinBox->setMinimum(-10000000);
        spinBox->setMaximum(10000000);
        TypeItemBox = new QComboBox(AddDelGroup);
        TypeItemBox->addItem(QString());
        TypeItemBox->addItem(QString());
        TypeItemBox->addItem(QString());
        TypeItemBox->setObjectName(QString::fromUtf8("TypeItemBox"));
        TypeItemBox->setGeometry(QRect(10, 30, 121, 24));
        doubleSpinBox = new QDoubleSpinBox(AddDelGroup);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 60, 61, 25));
        doubleSpinBox->setMinimum(-1000000000.899999976158142);
        doubleSpinBox->setMaximum(100000000.989999994635582);
        doubleSpinBox->setSingleStep(0.500000000000000);
        AddButton = new QPushButton(AddDelGroup);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(10, 120, 121, 25));
        lineEdit = new QLineEdit(AddDelGroup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 90, 121, 24));
        lineEdit->setMaxLength(1);
        DelButton = new QPushButton(AddDelGroup);
        DelButton->setObjectName(QString::fromUtf8("DelButton"));
        DelButton->setGeometry(QRect(10, 180, 121, 25));
        AddButton_2 = new QPushButton(AddDelGroup);
        AddButton_2->setObjectName(QString::fromUtf8("AddButton_2"));
        AddButton_2->setGeometry(QRect(10, 150, 121, 25));
        DelButton_2 = new QPushButton(AddDelGroup);
        DelButton_2->setObjectName(QString::fromUtf8("DelButton_2"));
        DelButton_2->setGeometry(QRect(10, 210, 121, 25));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(160, 310, 141, 25));
        ListTypeBox = new QComboBox(centralwidget);
        ListTypeBox->addItem(QString());
        ListTypeBox->addItem(QString());
        ListTypeBox->addItem(QString());
        ListTypeBox->setObjectName(QString::fromUtf8("ListTypeBox"));
        ListTypeBox->setGeometry(QRect(160, 10, 141, 24));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = MyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));
        AddDelGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        TypeItemBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\321\213\320\271", nullptr));
        TypeItemBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        TypeItemBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\320\262\320\276\320\273\321\214\320\275\321\213\320\271", nullptr));

        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DelButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\262\320\273\320\265\321\207\321\214", nullptr));
        AddButton_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\272\320\276\320\275\320\265\321\206", nullptr));
        DelButton_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\262\320\273\320\265\321\207\321\214 \320\270\320\267 \320\272\320\276\320\275\321\206\320\260", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        ListTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\320\272", nullptr));
        ListTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\236\321\207\320\265\321\200\320\265\320\264\321\214", nullptr));
        ListTypeBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\265\320\272", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

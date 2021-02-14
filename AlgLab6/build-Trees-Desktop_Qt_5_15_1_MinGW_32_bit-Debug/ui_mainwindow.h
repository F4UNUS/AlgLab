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
#include <QtWidgets/QGraphicsView>
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
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QPushButton *createTreeButton;
    QComboBox *typeBox;
    QPushButton *addLeftButton;
    QPushButton *addRightButton;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinIndexBox;
    QPushButton *insertLeftButton;
    QPushButton *insertRightButton;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinIndexBox_2;
    QPushButton *delItemButton;
    QGroupBox *groupBox_4;
    QComboBox *orderTypeBox;
    QPushButton *orderButton;
    QComboBox *treeTypeBox;
    QPushButton *delTreeButton;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(973, 608);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 620, 580));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(770, 40, 191, 191));
        createTreeButton = new QPushButton(groupBox);
        createTreeButton->setObjectName(QString::fromUtf8("createTreeButton"));
        createTreeButton->setGeometry(QRect(10, 100, 171, 21));
        typeBox = new QComboBox(groupBox);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setGeometry(QRect(10, 40, 171, 22));
        addLeftButton = new QPushButton(groupBox);
        addLeftButton->setObjectName(QString::fromUtf8("addLeftButton"));
        addLeftButton->setGeometry(QRect(10, 130, 171, 21));
        addRightButton = new QPushButton(groupBox);
        addRightButton->setObjectName(QString::fromUtf8("addRightButton"));
        addRightButton->setGeometry(QRect(10, 160, 171, 21));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 70, 42, 22));
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);
        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(60, 70, 62, 22));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(-1000.000000000000000);
        doubleSpinBox->setMaximum(1000.000000000000000);
        doubleSpinBox->setSingleStep(0.200000000000000);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 51, 21));
        lineEdit->setMaxLength(1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 121, 16));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(770, 240, 191, 121));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 91, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 111, 21));
        spinIndexBox = new QSpinBox(groupBox_2);
        spinIndexBox->setObjectName(QString::fromUtf8("spinIndexBox"));
        spinIndexBox->setGeometry(QRect(130, 30, 51, 21));
        spinIndexBox->setMinimum(1);
        spinIndexBox->setMaximum(1000);
        insertLeftButton = new QPushButton(groupBox_2);
        insertLeftButton->setObjectName(QString::fromUtf8("insertLeftButton"));
        insertLeftButton->setGeometry(QRect(10, 60, 171, 21));
        insertRightButton = new QPushButton(groupBox_2);
        insertRightButton->setObjectName(QString::fromUtf8("insertRightButton"));
        insertRightButton->setGeometry(QRect(10, 90, 171, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(770, 370, 191, 91));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 91, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 111, 21));
        spinIndexBox_2 = new QSpinBox(groupBox_3);
        spinIndexBox_2->setObjectName(QString::fromUtf8("spinIndexBox_2"));
        spinIndexBox_2->setGeometry(QRect(130, 30, 51, 21));
        spinIndexBox_2->setMinimum(1);
        spinIndexBox_2->setMaximum(1000);
        delItemButton = new QPushButton(groupBox_3);
        delItemButton->setObjectName(QString::fromUtf8("delItemButton"));
        delItemButton->setGeometry(QRect(10, 60, 171, 21));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(770, 470, 191, 91));
        orderTypeBox = new QComboBox(groupBox_4);
        orderTypeBox->addItem(QString());
        orderTypeBox->addItem(QString());
        orderTypeBox->addItem(QString());
        orderTypeBox->setObjectName(QString::fromUtf8("orderTypeBox"));
        orderTypeBox->setGeometry(QRect(10, 30, 171, 22));
        orderButton = new QPushButton(groupBox_4);
        orderButton->setObjectName(QString::fromUtf8("orderButton"));
        orderButton->setGeometry(QRect(10, 60, 171, 21));
        treeTypeBox = new QComboBox(centralwidget);
        treeTypeBox->addItem(QString());
        treeTypeBox->addItem(QString());
        treeTypeBox->setObjectName(QString::fromUtf8("treeTypeBox"));
        treeTypeBox->setGeometry(QRect(770, 10, 191, 22));
        delTreeButton = new QPushButton(centralwidget);
        delTreeButton->setObjectName(QString::fromUtf8("delTreeButton"));
        delTreeButton->setGeometry(QRect(770, 570, 191, 21));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(640, 10, 121, 581));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        createTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\321\213\320\271", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        typeBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\320\262\320\276\320\273\321\214\320\275\321\213\320\271", nullptr));

        addLeftButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\265\320\262\320\260", nullptr));
        addRightButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\201\320\273\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\262\320\265\321\200\321\210\320\270\320\275\321\213 \321\201 \320\270\320\275\320\264\320\265\320\272\321\201\320\276\320\274", nullptr));
        insertLeftButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\265\320\262\320\260", nullptr));
        insertRightButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\262\320\265\321\200\321\210\320\270\320\275\321\203 \321\201 \320\270\320\275\320\264\320\265\320\272\321\201\320\276\320\274", nullptr));
        delItemButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264", nullptr));
        orderTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\271", nullptr));
        orderTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271", nullptr));
        orderTypeBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\320\274\320\265\321\202\321\200\320\270\321\207\320\275\321\213\320\271", nullptr));

        orderButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        treeTypeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        treeTypeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\320\276-\320\247\320\265\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));

        delTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\276\320\261\321\205\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

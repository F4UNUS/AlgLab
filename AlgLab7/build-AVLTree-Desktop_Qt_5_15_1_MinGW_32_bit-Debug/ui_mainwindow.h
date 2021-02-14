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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *delTreeButton;
    QGroupBox *groupBox;
    QPushButton *createTreeButton;
    QSpinBox *spinBox;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinIndexBox_2;
    QPushButton *delItemButton;
    QComboBox *comboBox;
    QPushButton *squereButton;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *spinIndexBox;
    QPushButton *searchButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(847, 605);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        delTreeButton = new QPushButton(centralwidget);
        delTreeButton->setObjectName(QString::fromUtf8("delTreeButton"));
        delTreeButton->setGeometry(QRect(640, 340, 191, 21));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(640, 40, 191, 61));
        createTreeButton = new QPushButton(groupBox);
        createTreeButton->setObjectName(QString::fromUtf8("createTreeButton"));
        createTreeButton->setGeometry(QRect(60, 30, 121, 21));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 30, 42, 22));
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 620, 580));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(640, 110, 191, 91));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 91, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 121, 21));
        spinIndexBox_2 = new QSpinBox(groupBox_3);
        spinIndexBox_2->setObjectName(QString::fromUtf8("spinIndexBox_2"));
        spinIndexBox_2->setGeometry(QRect(130, 30, 51, 21));
        spinIndexBox_2->setMinimum(-1000);
        spinIndexBox_2->setMaximum(1000);
        delItemButton = new QPushButton(groupBox_3);
        delItemButton->setObjectName(QString::fromUtf8("delItemButton"));
        delItemButton->setGeometry(QRect(10, 60, 171, 21));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(640, 10, 191, 22));
        squereButton = new QPushButton(centralwidget);
        squereButton->setObjectName(QString::fromUtf8("squereButton"));
        squereButton->setGeometry(QRect(640, 310, 191, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 210, 191, 91));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 121, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 91, 16));
        spinIndexBox = new QSpinBox(groupBox_2);
        spinIndexBox->setObjectName(QString::fromUtf8("spinIndexBox"));
        spinIndexBox->setGeometry(QRect(130, 30, 51, 21));
        spinIndexBox->setMinimum(-1000);
        spinIndexBox->setMaximum(1000);
        searchButton = new QPushButton(groupBox_2);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(10, 60, 171, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        delTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
        createTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\262\320\265\321\200\321\210\320\270\320\275\321\203 \321\201\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\274", nullptr));
        delItemButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\220\320\222\320\233 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));

        squereButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\262\320\265\321\201\321\202\320\270 \320\272\320\276\321\200\320\265\320\275\321\214 \320\262 \320\272\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\262\320\265\321\200\321\210\320\270\320\275\321\203 \321\201\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\274", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

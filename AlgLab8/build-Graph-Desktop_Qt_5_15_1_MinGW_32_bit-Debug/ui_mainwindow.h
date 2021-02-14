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
    QGraphicsView *graphicsView;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QPushButton *execOrderButton;
    QComboBox *orderBox;
    QLabel *label_3;
    QSpinBox *spinOrderBox;
    QGroupBox *groupBox_2;
    QPushButton *deleteButton;
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *createButton;
    QGroupBox *groupBox_3;
    QPushButton *searchButton;
    QComboBox *comboBox;
    QLabel *label_4;
    QSpinBox *spinWayBox;
    QLabel *label_2;
    QTableWidget *tableWidget_2;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(972, 584);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 471, 391));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(490, 10, 471, 361));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 410, 171, 131));
        execOrderButton = new QPushButton(groupBox);
        execOrderButton->setObjectName(QString::fromUtf8("execOrderButton"));
        execOrderButton->setGeometry(QRect(10, 90, 151, 31));
        orderBox = new QComboBox(groupBox);
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->setObjectName(QString::fromUtf8("orderBox"));
        orderBox->setGeometry(QRect(10, 30, 151, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 111, 21));
        spinOrderBox = new QSpinBox(groupBox);
        spinOrderBox->setObjectName(QString::fromUtf8("spinOrderBox"));
        spinOrderBox->setGeometry(QRect(120, 60, 42, 22));
        spinOrderBox->setMinimum(1);
        spinOrderBox->setMaximum(100);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 410, 171, 131));
        deleteButton = new QPushButton(groupBox_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 90, 151, 31));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(120, 20, 42, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 101, 21));
        createButton = new QPushButton(groupBox_2);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(10, 50, 151, 31));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(190, 410, 171, 131));
        searchButton = new QPushButton(groupBox_3);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(10, 90, 151, 31));
        comboBox = new QComboBox(groupBox_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 151, 22));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 111, 21));
        spinWayBox = new QSpinBox(groupBox_3);
        spinWayBox->setObjectName(QString::fromUtf8("spinWayBox"));
        spinWayBox->setGeometry(QRect(120, 60, 42, 22));
        spinWayBox->setMinimum(1);
        spinWayBox->setMaximum(100);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(670, 380, 161, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        tableWidget_2 = new QTableWidget(centralwidget);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(550, 410, 411, 131));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(560, 550, 381, 21));
        label_5->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264", nullptr));
        execOrderButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        orderBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        orderBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222 \320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\320\275\321\210\320\270\320\275\320\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\270 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213 \320\277\320\276\320\270\321\201\320\272\320\260 \320\277\321\203\321\202\320\270", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\244\320\273\320\276\320\271\320\264\320\260", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\320\275\321\210\320\270\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260 \320\262\320\265\321\201\320\276\320\262", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\276\320\261\321\205\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

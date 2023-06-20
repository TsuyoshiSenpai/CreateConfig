/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *pathToHeaderTextEdit;
    QLabel *label;
    QPushButton *pathToHeaderButton;
    QLabel *label_2;
    QPlainTextEdit *pathToXMLTextEdit;
    QPushButton *pathToXMLButton;
    QPushButton *generateXMLButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pathToHeaderTextEdit = new QPlainTextEdit(centralwidget);
        pathToHeaderTextEdit->setObjectName("pathToHeaderTextEdit");
        pathToHeaderTextEdit->setGeometry(QRect(10, 30, 411, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 151, 16));
        pathToHeaderButton = new QPushButton(centralwidget);
        pathToHeaderButton->setObjectName("pathToHeaderButton");
        pathToHeaderButton->setGeometry(QRect(430, 30, 80, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 241, 20));
        pathToXMLTextEdit = new QPlainTextEdit(centralwidget);
        pathToXMLTextEdit->setObjectName("pathToXMLTextEdit");
        pathToXMLTextEdit->setGeometry(QRect(10, 100, 411, 31));
        pathToXMLButton = new QPushButton(centralwidget);
        pathToXMLButton->setObjectName("pathToXMLButton");
        pathToXMLButton->setGeometry(QRect(430, 100, 80, 31));
        generateXMLButton = new QPushButton(centralwidget);
        generateXMLButton->setObjectName("generateXMLButton");
        generateXMLButton->setGeometry(QRect(10, 150, 181, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273 system.h", nullptr));
        pathToHeaderButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 config.xml", nullptr));
        pathToXMLButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        generateXMLButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 config \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

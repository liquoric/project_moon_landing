/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *a_spin;
    QSpinBox *h_spin;
    QSpinBox *V0_spin;
    QSpinBox *S0_spin;
    QSpinBox *tmax_spin;
    QLineEdit *sol_edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 16, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 16, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 70, 16, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 110, 16, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 140, 31, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 260, 49, 16));
        a_spin = new QSpinBox(centralwidget);
        a_spin->setObjectName("a_spin");
        a_spin->setGeometry(QRect(70, 10, 91, 25));
        h_spin = new QSpinBox(centralwidget);
        h_spin->setObjectName("h_spin");
        h_spin->setGeometry(QRect(70, 40, 91, 25));
        V0_spin = new QSpinBox(centralwidget);
        V0_spin->setObjectName("V0_spin");
        V0_spin->setGeometry(QRect(70, 70, 91, 25));
        S0_spin = new QSpinBox(centralwidget);
        S0_spin->setObjectName("S0_spin");
        S0_spin->setGeometry(QRect(70, 110, 91, 25));
        tmax_spin = new QSpinBox(centralwidget);
        tmax_spin->setObjectName("tmax_spin");
        tmax_spin->setGeometry(QRect(70, 140, 91, 25));
        sol_edit = new QLineEdit(centralwidget);
        sol_edit->setObjectName("sol_edit");
        sol_edit->setEnabled(false);
        sol_edit->setGeometry(QRect(100, 260, 113, 24));
        sol_edit->setReadOnly(true);
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
        label->setText(QCoreApplication::translate("MainWindow", "a:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "h:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "V0:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "S0:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "tmax:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "solution:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

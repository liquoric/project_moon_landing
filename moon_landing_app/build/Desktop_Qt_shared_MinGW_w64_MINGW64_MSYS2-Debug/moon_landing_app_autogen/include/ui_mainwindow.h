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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *Count_but;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *m_doubleSpinBox;
    QDoubleSpinBox *Pmin_doubleSpinBox;
    QDoubleSpinBox *H0_doubleSpinBox;
    QDoubleSpinBox *g_doubleSpinBox;
    QTableWidget *res_table;
    QPushButton *save_to_but;
    QLineEdit *FileName_line;
    QDoubleSpinBox *Pmax_doubleSpinBox;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 16, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 70, 16, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(270, 30, 49, 16));
        Count_but = new QPushButton(centralwidget);
        Count_but->setObjectName("Count_but");
        Count_but->setEnabled(true);
        Count_but->setGeometry(QRect(40, 210, 80, 24));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 160, 31, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 100, 31, 16));
        m_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        m_doubleSpinBox->setObjectName("m_doubleSpinBox");
        m_doubleSpinBox->setGeometry(QRect(70, 150, 91, 25));
        m_doubleSpinBox->setMinimum(-999999.989999999990687);
        m_doubleSpinBox->setMaximum(999999.989999999990687);
        m_doubleSpinBox->setSingleStep(1.000000000000000);
        Pmin_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        Pmin_doubleSpinBox->setObjectName("Pmin_doubleSpinBox");
        Pmin_doubleSpinBox->setGeometry(QRect(70, 90, 91, 25));
        Pmin_doubleSpinBox->setMinimum(-999999.989999999990687);
        Pmin_doubleSpinBox->setMaximum(999999.989999999990687);
        Pmin_doubleSpinBox->setSingleStep(1.000000000000000);
        H0_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        H0_doubleSpinBox->setObjectName("H0_doubleSpinBox");
        H0_doubleSpinBox->setGeometry(QRect(70, 60, 91, 25));
        H0_doubleSpinBox->setMinimum(-999999.989999999990687);
        H0_doubleSpinBox->setMaximum(999999.989999999990687);
        H0_doubleSpinBox->setSingleStep(1.000000000000000);
        g_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        g_doubleSpinBox->setObjectName("g_doubleSpinBox");
        g_doubleSpinBox->setGeometry(QRect(70, 30, 91, 25));
        g_doubleSpinBox->setMinimum(-999999.989999999990687);
        g_doubleSpinBox->setMaximum(999999.989999999990687);
        g_doubleSpinBox->setSingleStep(1.000000000000000);
        res_table = new QTableWidget(centralwidget);
        res_table->setObjectName("res_table");
        res_table->setGeometry(QRect(330, 30, 311, 192));
        save_to_but = new QPushButton(centralwidget);
        save_to_but->setObjectName("save_to_but");
        save_to_but->setGeometry(QRect(560, 230, 80, 24));
        FileName_line = new QLineEdit(centralwidget);
        FileName_line->setObjectName("FileName_line");
        FileName_line->setGeometry(QRect(330, 230, 221, 24));
        FileName_line->setContextMenuPolicy(Qt::CustomContextMenu);
        FileName_line->setClearButtonEnabled(true);
        Pmax_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        Pmax_doubleSpinBox->setObjectName("Pmax_doubleSpinBox");
        Pmax_doubleSpinBox->setGeometry(QRect(70, 120, 91, 25));
        Pmax_doubleSpinBox->setMinimum(-999999.989999999990687);
        Pmax_doubleSpinBox->setMaximum(999999.989999999990687);
        Pmax_doubleSpinBox->setSingleStep(1.000000000000000);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 130, 31, 16));
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
        label->setText(QCoreApplication::translate("MainWindow", "g:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "H0:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "solution:", nullptr));
        Count_but->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pmin", nullptr));
        save_to_but->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
        FileName_line->setText(QCoreApplication::translate("MainWindow", "Enter a file name to save results to", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pmax", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

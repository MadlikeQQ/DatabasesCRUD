/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTableView *tableView;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *dbLabel;
    QPushButton *createButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLabel *errors;
    QLineEdit *quickSearch;
    QLabel *label_3;
    QPushButton *extInfo;
    QPushButton *qry1Btn;
    QPushButton *qry2Btn;
    QLabel *label_4;
    QPushButton *qry3Btn;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *exitBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1430, 659);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 570, 151, 18));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(270, 10, 1121, 421));
        tableView->setFrameShadow(QFrame::Sunken);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 80, 111, 32));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 101, 18));
        dbLabel = new QLabel(centralWidget);
        dbLabel->setObjectName(QStringLiteral("dbLabel"));
        dbLabel->setGeometry(QRect(730, 560, 281, 21));
        createButton = new QPushButton(centralWidget);
        createButton->setObjectName(QStringLiteral("createButton"));
        createButton->setGeometry(QRect(540, 490, 88, 34));
        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(750, 490, 88, 34));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(950, 490, 88, 34));
        errors = new QLabel(centralWidget);
        errors->setObjectName(QStringLiteral("errors"));
        errors->setGeometry(QRect(270, 450, 1121, 20));
        quickSearch = new QLineEdit(centralWidget);
        quickSearch->setObjectName(QStringLiteral("quickSearch"));
        quickSearch->setGeometry(QRect(20, 160, 211, 32));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 101, 18));
        extInfo = new QPushButton(centralWidget);
        extInfo->setObjectName(QStringLiteral("extInfo"));
        extInfo->setGeometry(QRect(320, 490, 151, 34));
        qry1Btn = new QPushButton(centralWidget);
        qry1Btn->setObjectName(QStringLiteral("qry1Btn"));
        qry1Btn->setGeometry(QRect(10, 340, 181, 34));
        qry2Btn = new QPushButton(centralWidget);
        qry2Btn->setObjectName(QStringLiteral("qry2Btn"));
        qry2Btn->setGeometry(QRect(10, 390, 181, 34));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 310, 101, 18));
        qry3Btn = new QPushButton(centralWidget);
        qry3Btn->setObjectName(QStringLiteral("qry3Btn"));
        qry3Btn->setGeometry(QRect(10, 440, 181, 34));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(100, 480, 104, 22));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 510, 104, 22));
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(1320, 550, 88, 34));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1430, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Connecting..", 0));
        label_2->setText(QApplication::translate("MainWindow", "Select Database:", 0));
        dbLabel->setText(QApplication::translate("MainWindow", "Current Table: None", 0));
        createButton->setText(QApplication::translate("MainWindow", "Create New", 0));
        editButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        errors->setText(QString());
        quickSearch->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Quick Search:", 0));
        extInfo->setText(QApplication::translate("MainWindow", "Extended Information", 0));
#ifndef QT_NO_TOOLTIP
        qry1Btn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        qry1Btn->setText(QApplication::translate("MainWindow", "Query 1", 0));
        qry2Btn->setText(QApplication::translate("MainWindow", "Query 2", 0));
        label_4->setText(QApplication::translate("MainWindow", "More Queries:", 0));
        qry3Btn->setText(QApplication::translate("MainWindow", "Query 3", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Sum", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "A&verage", 0));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

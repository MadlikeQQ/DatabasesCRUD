/********************************************************************************
** Form generated from reading UI file 'extinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTINFO_H
#define UI_EXTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_extInfo
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QTableView *tableView_2;
    QTableView *tableView_3;
    QTableView *tableView_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QLabel *label_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QCheckBox *chkPL;
    QCheckBox *chkPCurr;
    QCheckBox *chkLLen;
    QCheckBox *chkLNum;
    QLabel *label_2;
    QCheckBox *chkLRem;
    QCheckBox *chkLMed;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *extInfo)
    {
        if (extInfo->objectName().isEmpty())
            extInfo->setObjectName(QStringLiteral("extInfo"));
        extInfo->resize(1276, 626);
        label = new QLabel(extInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 71, 18));
        lineEdit = new QLineEdit(extInfo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 113, 32));
        tableView = new QTableView(extInfo);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 310, 256, 301));
        tableView_2 = new QTableView(extInfo);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(350, 310, 256, 301));
        tableView_3 = new QTableView(extInfo);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(640, 310, 256, 301));
        tableView_4 = new QTableView(extInfo);
        tableView_4->setObjectName(QStringLiteral("tableView_4"));
        tableView_4->setGeometry(QRect(970, 310, 256, 301));
        frame = new QFrame(extInfo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(310, 60, 611, 178));
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 4, 1, 1);

        chkPL = new QCheckBox(frame);
        chkPL->setObjectName(QStringLiteral("chkPL"));

        gridLayout->addWidget(chkPL, 3, 3, 2, 2);

        chkPCurr = new QCheckBox(frame);
        chkPCurr->setObjectName(QStringLiteral("chkPCurr"));

        gridLayout->addWidget(chkPCurr, 2, 3, 1, 2);

        chkLLen = new QCheckBox(frame);
        chkLLen->setObjectName(QStringLiteral("chkLLen"));

        gridLayout->addWidget(chkLLen, 5, 0, 1, 2);

        chkLNum = new QCheckBox(frame);
        chkLNum->setObjectName(QStringLiteral("chkLNum"));

        gridLayout->addWidget(chkLNum, 4, 0, 1, 2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        chkLRem = new QCheckBox(frame);
        chkLRem->setObjectName(QStringLiteral("chkLRem"));

        gridLayout->addWidget(chkLRem, 2, 0, 2, 2);

        chkLMed = new QCheckBox(frame);
        chkLMed->setObjectName(QStringLiteral("chkLMed"));

        gridLayout->addWidget(chkLMed, 6, 0, 1, 2);

        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 2, 1, 2);


        retranslateUi(extInfo);

        QMetaObject::connectSlotsByName(extInfo);
    } // setupUi

    void retranslateUi(QDialog *extInfo)
    {
        extInfo->setWindowTitle(QApplication::translate("extInfo", "Dialog", 0));
        label->setText(QApplication::translate("extInfo", "Info for ID:", 0));
        radioButton->setText(QString());
        label_3->setText(QApplication::translate("extInfo", "Pending Requests:", 0));
        chkPL->setText(QApplication::translate("extInfo", "Lenders", 0));
        chkPCurr->setText(QApplication::translate("extInfo", "Current Amount", 0));
        chkLLen->setText(QApplication::translate("extInfo", "Lenders", 0));
        chkLNum->setText(QApplication::translate("extInfo", "Number of  installments", 0));
        label_2->setText(QApplication::translate("extInfo", "Loan:", 0));
        chkLRem->setText(QApplication::translate("extInfo", "Remaining Amount", 0));
        chkLMed->setText(QApplication::translate("extInfo", "Medians", 0));
        radioButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class extInfo: public Ui_extInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTINFO_H

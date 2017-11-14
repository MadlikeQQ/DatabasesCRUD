/********************************************************************************
** Form generated from reading UI file 'advancedselect.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDSELECT_H
#define UI_ADVANCEDSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_advancedSelect
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *advancedSelect)
    {
        if (advancedSelect->objectName().isEmpty())
            advancedSelect->setObjectName(QStringLiteral("advancedSelect"));
        advancedSelect->resize(108, 300);
        pushButton = new QPushButton(advancedSelect);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 88, 34));
        pushButton_2 = new QPushButton(advancedSelect);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 70, 88, 34));

        retranslateUi(advancedSelect);

        QMetaObject::connectSlotsByName(advancedSelect);
    } // setupUi

    void retranslateUi(QDialog *advancedSelect)
    {
        advancedSelect->setWindowTitle(QApplication::translate("advancedSelect", "Dialog", 0));
        pushButton->setText(QApplication::translate("advancedSelect", "Query 1", 0));
        pushButton_2->setText(QApplication::translate("advancedSelect", "Query 2", 0));
    } // retranslateUi

};

namespace Ui {
    class advancedSelect: public Ui_advancedSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDSELECT_H

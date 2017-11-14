/********************************************************************************
** Form generated from reading UI file 'createdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIALOG_H
#define UI_CREATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_createDialog
{
public:

    void setupUi(QDialog *createDialog)
    {
        if (createDialog->objectName().isEmpty())
            createDialog->setObjectName(QStringLiteral("createDialog"));
        createDialog->resize(400, 300);

        retranslateUi(createDialog);

        QMetaObject::connectSlotsByName(createDialog);
    } // setupUi

    void retranslateUi(QDialog *createDialog)
    {
        createDialog->setWindowTitle(QApplication::translate("createDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class createDialog: public Ui_createDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'ext2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXT2_H
#define UI_EXT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ext2
{
public:
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit;
    QTableView *tableView_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *ext2)
    {
        if (ext2->objectName().isEmpty())
            ext2->setObjectName(QStringLiteral("ext2"));
        ext2->resize(726, 511);
        tableView = new QTableView(ext2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 100, 291, 381));
        label = new QLabel(ext2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 18));
        lineEdit = new QLineEdit(ext2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 10, 113, 32));
        tableView_2 = new QTableView(ext2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(390, 100, 311, 381));
        label_2 = new QLabel(ext2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 50, 181, 31));
        label_3 = new QLabel(ext2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 50, 181, 31));

        retranslateUi(ext2);

        QMetaObject::connectSlotsByName(ext2);
    } // setupUi

    void retranslateUi(QDialog *ext2)
    {
        ext2->setWindowTitle(QApplication::translate("ext2", "Dialog", 0));
        label->setText(QApplication::translate("ext2", "Info for ID:", 0));
        label_2->setText(QApplication::translate("ext2", "TRUST", 0));
        label_3->setText(QApplication::translate("ext2", "BORROWERS", 0));
    } // retranslateUi

};

namespace Ui {
    class ext2: public Ui_ext2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXT2_H

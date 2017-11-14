#ifndef EXTINFO_H
#define EXTINFO_H

#include <QDialog>
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QCloseEvent>
#include <QDataWidgetMapper>
namespace Ui {
class extInfo;
}

class extInfo : public QDialog
{
    Q_OBJECT

public:
    explicit extInfo(QSqlTableModel *model, QItemSelectionModel * select, QWidget *parent = 0);
    ~extInfo();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_chkLRem_clicked();

    void on_chkLNum_clicked();

    void on_chkLLen_clicked();

    void on_chkLMed_clicked();

    void on_chkPCurr_clicked();

    void on_chkPL_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::extInfo *ui;
    QString BID;
    QSqlDatabase *db;

    QItemSelectionModel * select;
};

#endif // EXTINFO_H

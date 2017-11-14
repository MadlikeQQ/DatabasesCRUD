#ifndef EDITDIALOG_H
#define EDITDIALOG_H

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
class editDialog;
}

class editDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDialog(QString tablename, QSqlTableModel *model, QItemSelectionModel * select,
                        QWidget *parent = 0);
    ~editDialog();
private slots:
    void handleButton();
    void handleButton1();
private:
    Ui::editDialog *ui;
    void queryNotOK(const QString &arg);
    void fadeOut();
   // void closeEvent(QCloseEvent *event);
    QSqlQueryModel * model;
    QLabel *error ;
    QDataWidgetMapper *mapper;
//    void closeEvent(QCloseEvent *event);




};

#endif // EDITDIALOG_H

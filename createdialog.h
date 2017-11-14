#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H


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
#include <QLineEdit>
namespace Ui {
class createDialog;
}

class createDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createDialog(QString tablename, QSqlTableModel *model, QItemSelectionModel *select, QWidget *parent = 0);
    ~createDialog();
private slots:
    QString handleButton();

private:
    Ui::createDialog *ui;
    void queryNotOK(const QString &arg);
    void fadeOut();
    QSqlTableModel * model;
    QLabel *error ;
    QLineEdit *lines[9];
    QDataWidgetMapper *mapper;

};

#endif // CREATEDIALOG_H

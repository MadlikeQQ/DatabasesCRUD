#ifndef EXT2_H
#define EXT2_H

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
class ext2;
}

class ext2 : public QDialog
{
    Q_OBJECT

public:
    explicit ext2(QSqlTableModel *model, QItemSelectionModel *select, QWidget *parent = 0);
    ~ext2();

private:
    Ui::ext2 *ui;
    QString LID;
    //QSqlDatabase *db;

    QItemSelectionModel * select;



};

#endif // EXT2_H

#include "ext2.h"
#include "ui_ext2.h"
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
ext2::ext2(QSqlTableModel *model, QItemSelectionModel * select,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ext2)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","extInfo2");
    db.setHostName("localhost");
    db.setDatabaseName("microloans");
    db.setUserName("root");
    db.setPassword("SaSSanidV@riabl3");
    if(db.open())
        qDebug() << "COnn";
    else
        qDebug() << "no COnn";


    ///this->db = &db;
    this->select = select;
    this->LID = select->currentIndex().data().toString();
    ui->lineEdit->setText(LID);

    QSqlQueryModel * tmodel = new QSqlQueryModel();
    QSqlQuery qry ;

    ui->tableView->setModel(tmodel);
    qry.prepare(("SELECT B.NAME AS BORROWER ,C.AMOUNT, C.DATE_OF_REQUEST  FROM COMMITMENT AS C , BORROWER AS B WHERE C.LID ='"+
            this->LID +"' AND C.BID = B.ID"));



    qry.exec();
    qDebug() << qry.lastError().text();
    tmodel->setQuery(qry);

     QSqlQueryModel * tmodel1 = new QSqlQueryModel();
    qry.prepare(QString("SELECT B.NAME AS BORROWER , T.PERCENTAGE FROM TRUST AS T , BORROWER AS B WHERE T.LID ='"+
            this->LID +"' AND B.ID = T.BID"));


    qry.exec();
    qDebug() << qry.lastError().text();
    tmodel1->setQuery(qry);
    ui->tableView_2->setModel(tmodel1);


}

ext2::~ext2()
{
    delete ui;
}

#include "extinfo.h"
#include "ui_extinfo.h"
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
extInfo::extInfo(QSqlTableModel *model, QItemSelectionModel * select,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::extInfo)
{


    ui->setupUi(this);

    //Establish connection and open DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","extInfo");
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
    this->BID = select->currentIndex().data().toString();
    ui->lineEdit->setText(BID);





}

extInfo::~extInfo()
{
    delete ui;
}



void extInfo::on_radioButton_2_clicked()
{
    int i;
    for(i=0; i<ui->comboBox_2->count() ;i++)
        ui->comboBox_2->removeItem(i);
if(ui->radioButton->isChecked())
{
    ui->radioButton_2->setChecked(false);

    return;
}
else
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->clear();
    ui->tableView->setModel(model);
    ui->tableView_4->setModel(model);
    ui->tableView_2->setModel(model);
    ui->tableView_3->setModel(model);
    qDebug() << "Q2";
    QSqlQuery qry ;
    qry.prepare("SELECT DATE_OF_REQUEST FROM LOAN_REQUEST WHERE LOAN_REQUEST.BID ='"+this->BID+"' AND " +
                "LOAN_REQUEST.CUR_AMOUNT < LOAN_REQUEST.AMOUNT");
    if(qry.exec()) qDebug() << "OK";
    qDebug() << qry.lastError();



//        ui->comboBox->addItem(NULL,qry.first().value(0).toString());
    while(qry.next())
           {
        QString text = qry.value(qry.record().indexOf("DATE_OF_REQUEST")).toString();
        ui->comboBox_2->addItem(text);
        on_chkPCurr_clicked();

    }




}
}

void extInfo::on_chkPCurr_clicked()
{
    if(ui->chkPCurr->isChecked() && ui->radioButton_2->isChecked())
    {
        QString qry = "SELECT L.CUR_AMOUNT FROM LOAN_REQUEST AS L WHERE L.BID='" +this->BID+ "' AND L.DATE_OF_REQUEST = '"+ui->comboBox_2->currentText() +"'"  ;
        qDebug() << ui->comboBox->currentText();
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView->setModel(model);
    }
    else if(!ui->chkPCurr->isChecked() && ui->radioButton_2->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView->setModel(model);
    }
}

void extInfo::on_chkPL_clicked()
{
    if(ui->chkPL->isChecked() && ui->radioButton_2->isChecked())
    {
        QString qry = "SELECT L.ID AS ID ,L.NAME AS LENDER FROM LENDER AS L, COMMITMENT AS C WHERE C.BID='" +this->BID+ "' AND C.DATE_OF_REQUEST = '"+ui->comboBox_2->currentText() +"'"+
                "AND L.ID =C.LID" ;
        //qDebug() << ui->comboBox->currentText();
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView_2->setModel(model);
    }
    else if(!ui->chkPL->isChecked() && ui->radioButton_2->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView_2->setModel(model);
    }
}

void extInfo::on_radioButton_clicked()
{

        int i;
        for(i=0; i<ui->comboBox->count() ;i++)
            ui->comboBox->removeItem(i);

    if(ui->radioButton_2->isChecked())
    {
        ui->radioButton->setChecked(false);

        return;
    }

    else
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView->setModel(model);
        ui->tableView_4->setModel(model);
        ui->tableView_2->setModel(model);
        ui->tableView_3->setModel(model);
        qDebug() << "Q1";
        QSqlQuery qry ;
        qry.prepare("SELECT ID FROM LOAN WHERE LOAN.BID ='"+this->BID+"'");
        if(qry.exec()) qDebug() << "OK";
        qDebug() << qry.lastError();



//        ui->comboBox->addItem(NULL,qry.first().value(0).toString());
        while(qry.next())
               {
            QString text = qry.value(qry.record().indexOf("ID")).toString();
            ui->comboBox->addItem(text);

            on_chkLRem_clicked();
            on_chkLNum_clicked();
            on_chkLLen_clicked();
            on_chkLMed_clicked();




        }
    }
}






void extInfo::on_chkLRem_clicked()
{

    if(ui->chkLRem->isChecked() && ui->radioButton->isChecked())
    {
        QString qry = "SELECT LOAN.REM_AMOUNT FROM LOAN WHERE LOAN.BID = '"+BID+"' AND LOAN.ID = '"+ui->comboBox->currentText() + "'";
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView->setModel(model);
    }
    else if(!ui->chkLRem->isChecked() && ui->radioButton->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView->setModel(model);
    }

}


void extInfo::on_chkLNum_clicked()
{

    if(ui->chkLNum->isChecked() && ui->radioButton->isChecked())
    {
        QString qry = "SELECT R.DATE_OF_PAYMENT,R.AMOUNT FROM REPAYMENT AS R WHERE R.ID = "+ui->comboBox->currentText()  ;
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView_2->setModel(model);
    }
    else if(!ui->chkLNum->isChecked() && ui->radioButton->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView_2->setModel(model);
    }

}


void extInfo::on_chkLLen_clicked()
{
    if(ui->chkLLen->isChecked() && ui->radioButton->isChecked())
    {
        QString qry = "SELECT L.ID AS ID,L.NAME AS LENDER FROM LOAN AS LR,COMMITMENT AS C,LENDER AS L WHERE L.ID=C.LID AND LR.DATE_OF_REQUEST=C.DATE_OF_REQUEST AND C.BID ='" +this->BID+ "' AND LR.ID = "+ui->comboBox->currentText()  ;
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView_3->setModel(model);
    }
    else if(!ui->chkLLen->isChecked() && ui->radioButton->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView_3->setModel(model);
    }
}

void extInfo::on_chkLMed_clicked()
{
    if(ui->chkLMed->isChecked() && ui->radioButton->isChecked())
    {
        QString qry = "SELECT M.ID AS ID, M.NAME AS INTER FROM INTERMEDIARY AS M, LOAN AS L WHERE L.BID='" +this->BID+ "' AND M.ID=L.MID AND L.ID = "+ui->comboBox->currentText()   ;
        //if(qry.exec()) qDebug() << "LQ1 OK";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(qry);
        //model->query().exec();
        ui->tableView_4->setModel(model);
    }
    else if(!ui->chkLMed->isChecked() && ui->radioButton->isChecked())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->clear();
        ui->tableView_4->setModel(model);
    }
}





void extInfo::on_lineEdit_returnPressed()
{
    this->BID=ui->lineEdit->text();
    if(ui->radioButton->isChecked())
        on_radioButton_clicked();
    else on_radioButton_2_clicked();

}

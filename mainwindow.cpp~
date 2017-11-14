#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editdialog.h"
#include "createdialog.h"
#include "extinfo.h"
#include "ext2.h"
#include "advancedselect.h"
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QDebug>
#include <QGridLayout>
#include <QToolTip>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->qry1Btn->setToolTip("View For all borrowers the sum of loans and total amount");
    ui->qry2Btn->setToolTip("Select an INTERMEDIARY to view info on loans which he is involved");
    ui->qry3Btn->setToolTip("Show borrowers with FUNCTION amounts > average");
    ui->errors->setAutoFillBackground(true);
    ui->errors->setAlignment(Qt::AlignCenter);

    ui->comboBox->addItem("Select...");
    ui->comboBox->addItem("BORROWER");
    ui->comboBox->addItem("COMMITMENT");
    ui->comboBox->addItem("DEADLINE");
    ui->comboBox->addItem("INTERMEDIARY");
    ui->comboBox->addItem("LENDER");
    ui->comboBox->addItem("LOAN");
    ui->comboBox->addItem("LOAN_REQUEST");
    ui->comboBox->addItem("REPAYMENT");
    ui->comboBox->addItem("TRUST");
    ui->comboBox->addItem("LOAN_DISP");
    ui->comboBox->addItem("COMPO_VIEW");
    ui->extInfo->hide();

    //Establish connection and open DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("microloans");
    db.setUserName("root");
    db.setPassword("SaSSanidV@riabl3");
    if(db.open())
        ui->label->setText("Connected");
    else
        ui->label->setText("Not Connected");
    //QSqlDatabase dbPointer = QSqlDatabase::database();

    model= new QSqlQueryModel();
    tmodel = new QSqlTableModel(this,db);





}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

    if(arg1 =="BORROWER" || arg1 =="LENDER") ui->extInfo->show();
    else ui->extInfo->hide();
    if(arg1=="Select...") {ui->dbLabel->setText("Current Table: None "); return ;}
    else ui->dbLabel->setText("Current table:" + arg1);

    tmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    tmodel->setTable(arg1);
    tmodel->select();
    model->clear();
    ui->tableView->setModel(tmodel);
    queryOK(NULL);
}

void MainWindow::on_deleteButton_clicked()
{
    //check if something selected

    QItemSelectionModel *select =ui->tableView->selectionModel();
    QModelIndexList indexes = select->selectedRows();

    QModelIndex index;

    if(select->hasSelection())
    {
       foreach(index, indexes){
           //QString text=QString("(%1,%2)").arg(index.row()).arg(index.column());
           QString str = ui->tableView->model()->index(index.row() , 0).data().toString(); // ui->tableView->model()->data(index).toString();
           qDebug() << str;

          //execute delete query

           QSqlQuery query;
           QString currentTable = ui->comboBox->currentText();
           ui->tableView->setModel(model);

           query.prepare("DELETE FROM "+currentTable+" WHERE ID = "+"'"+str+"'");
           model->setQuery(query);

           if(query.exec());
           else queryNotOK(query.lastError().text());

           //refresh table in UI
            on_comboBox_activated(currentTable);
       }

    }
    else queryNotOK("Please select some entries to delete");



}


void MainWindow::on_editButton_clicked()
{
    QItemSelectionModel *select =ui->tableView->selectionModel();
    QModelIndexList indexes = select->selectedRows();

    QModelIndex index;

    if(indexes.count() > 1)
        queryNotOK("You can edit one entry at a time");
    else if(indexes.count() == 0)
        queryNotOK("Please select table entry to edit");
    else
    {


        editDialog editdialog(ui->comboBox->currentText(),tmodel,select);
        editdialog.setModal(true);
        editdialog.exec();
        //editdialog.open();
        //editdialog.deleteLater();
        //ui->tableView->setModel(model);
        on_comboBox_activated(ui->comboBox->currentText());
    }
}


void MainWindow::queryOK(const QString &arg)
{
    QString msg;
    if(arg==NULL) msg="Query successful";
    else msg = arg;
    //output sucess mesage
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, Qt::green);
    sample_palette.setColor(QPalette::WindowText, Qt::black);
    ui->errors->setPalette(sample_palette);
    ui->errors->setText(msg);

    fadeOut();

}
void MainWindow::queryNotOK(const QString &arg)
{

    QString msg;
    if(arg==NULL) msg="An error has occured";
    else msg = arg;
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window,Qt::red);
    sample_palette.setColor(QPalette::WindowText, Qt::black);
    ui->errors->setPalette(sample_palette);
    ui->errors->setText(msg);
    fadeOut();

}
 void MainWindow::fadeOut()
 {
     QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
     ui->errors->setGraphicsEffect(eff);
     QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");

     //start fade
     a->setDuration(7350);
     a->setStartValue(5);
     a->setEndValue(0);
     a->setEasingCurve(QEasingCurve::OutBack);
     //a->pause();
     //QTimer::singleShot(700, a, SLOT(start()));
     a->start(QPropertyAnimation::DeleteWhenStopped);
     //connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));
     //connect(a,SIGNAL(finished()),this,SLOT());
 }

void MainWindow::on_createButton_clicked()
{
    QItemSelectionModel *select =ui->tableView->selectionModel();
    createDialog createdialog(ui->comboBox->currentText(),tmodel,select);

    createdialog.setModal(true);
    createdialog.exec();
    createdialog.deleteLater();
    on_comboBox_activated(ui->comboBox->currentText());
}
void MainWindow::on_quickSearch_returnPressed()
{
    //tmodel->setFilter("TOWN LIKE '%ATH%' ");
    int i,cc=tmodel->columnCount();
    QString search = ui->quickSearch->text();
    QString qry = NULL;




    for(i=0;i<cc;i++){
        if(i==0)
           qry.append(tmodel->record().fieldName(i)+" LIKE '%"+search+"%'");
        else
            qry.append(" OR "+tmodel->record().fieldName(i)+
                       " LIKE '%"+search+"%'");
        tmodel->setTable(ui->comboBox->currentText());
        tmodel->setFilter(qry);
        tmodel->select();
        ui->tableView->setModel(tmodel);

    }
}





void MainWindow::on_extInfo_clicked()
{
    QItemSelectionModel *select =ui->tableView->selectionModel();
    if(ui->comboBox->currentText()=="BORROWER")
    {
    if(select->hasSelection())
    {
        extInfo extinfodialog(tmodel,select);
        extinfodialog.setModal(true);
        extinfodialog.exec();
        extinfodialog.deleteLater();
    }
    }
    if(ui->comboBox->currentText()=="LENDER")
    {
        ext2 extinfodialog(tmodel,select);
        extinfodialog.setModal(true);
        extinfodialog.exec();
        extinfodialog.deleteLater();
    }
}

void MainWindow::on_quickSearch_textEdited(const QString &arg1)
{
    //tmodel->setFilter("TOWN LIKE '%ATH%' ");
    int i,cc=tmodel->columnCount();
    QString search = arg1;
    QString qry = NULL;




    for(i=0;i<cc;i++){
        if(i==0)
           qry.append(tmodel->record().fieldName(i)+" LIKE '%"+search+"%'");
        else
            qry.append(" OR "+tmodel->record().fieldName(i)+
                       " LIKE '%"+search+"%'");
        tmodel->setTable(ui->comboBox->currentText());
        tmodel->setFilter(qry);
        tmodel->select();
        ui->tableView->setModel(tmodel);

    }
}


void MainWindow::on_qry1Btn_clicked()
{
    ui->dbLabel->setText("Current table: Query 1");
    QString qry = QString("SELECT B.NAME AS BORROWER, COUNT(LO.ID) AS NUM_OF_LOANS, SUM(L.AMOUNT) AS WHOLE_SUM \
                  FROM BORROWER AS B, LOAN_REQUEST AS L, LOAN AS LO \
            WHERE L.BID=B.ID AND L.DATE_OF_REQUEST=LO.DATE_OF_REQUEST AND LO.BID = B.ID GROUP BY B.ID ORDER BY WHOLE_SUM DESC");
    advancedQueries(qry);
}


void MainWindow::advancedQueries(QString qry)
{
    QSqlQuery query;
    query.prepare(qry);
    if(query.exec())
        queryOK(NULL);
    else {queryNotOK(NULL);return;}
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void MainWindow::on_qry2Btn_clicked()
{
    ui->dbLabel->setText("Current table: Query 2");
    QItemSelectionModel *select =ui->tableView->selectionModel();

    if(ui->comboBox->currentText() == "INTERMEDIARY"){
        if(select->hasSelection()){
            if(select->selectedRows().count() == 1){
            QString MID = select->currentIndex().data().toString();
            QString qry = QString("SELECT M.NAME AS INTERMEDIARY, L.BID AS BORROWER_ID, \
                                  L.DATE_OF_REQUEST FROM LOAN AS L INNER JOIN INTERMEDIARY AS M \
                                  ON M.ID=L.MID \
                                  WHERE M.ID='"+MID +"'");
            QSqlQuery query ;
                    query.prepare(qry);

            if(query.exec()) queryOK(NULL);
            else queryNotOK(query.lastError().text());
            model->setQuery(query);

            ui->tableView->setModel(model);
        }
            else if (select->selectedRows().count() > 1)
                queryNotOK("Please select one entry");


        }
        else queryNotOK("Please select an intermediary");
    }
    else queryNotOK("Please select an intermediary");
}





void MainWindow::on_qry3Btn_clicked()
{
    ui->dbLabel->setText("Current table: Query 3");
    QString function;
    if(ui->radioButton->isChecked()) function = "SUM";
    else if (ui->radioButton_2->isChecked()) function = "AVG";
    else {queryNotOK("Please select a function");return;}




            QString qry = QString("SELECT  B.NAME AS BORROWER,SUM(L.AMOUNT) AS TOTAL_AMOUNT \
                                  FROM BORROWER AS B, LOAN_REQUEST AS L, LOAN AS LO \
                                  WHERE B.ID=L.BID AND L.BID=LO.BID AND LO.DATE_OF_REQUEST = L.DATE_OF_REQUEST GROUP BY B.ID \
                                  HAVING "+function+"(L.AMOUNT) > ( \
                                  SELECT AVG(L.AMOUNT) FROM LOAN_REQUEST AS L, LOAN AS LO \
                                  WHERE LO.BID=L.BID ) ; ");
            QSqlQuery query ;
                    query.prepare(qry);

            if(query.exec()) queryOK(NULL);
            else queryNotOK(query.lastError().text());
            model->setQuery(query);

            ui->tableView->setModel(model);



}

void MainWindow::on_exitBtn_clicked()
{
   this->close();
}

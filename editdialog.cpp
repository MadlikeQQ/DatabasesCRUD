#include "editdialog.h"
#include "ui_editdialog.h"
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>
#include <QCloseEvent>
#include<QMessageBox>
#include <QDataWidgetMapper>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
editDialog::editDialog(QString tablename, QSqlTableModel * model, QItemSelectionModel * select
                       , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDialog)
{
    ui->setupUi(this);

    this->model=model;
    //sql connection
    //Establish connection and open DB

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","edit");
    db.setHostName("localhost");
    db.setDatabaseName("microloans");
    db.setUserName("root");
    db.setPassword("SaSSanidV@riabl3");
    db.open();
    setWindowTitle(tr("Edit"));

    QGroupBox * formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout();
    //layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    //layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    //layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);


        //QModelIndexList indexes = select->selectedColumns();
        //QModelIndex index;


        int i,cc=model->columnCount();
        QLineEdit *edits[cc];

//        QString str = model->data(select->selectedRows()[0]).toString();
//        qDebug() << str;


        //qDebug << select->selectedColumns();
        for(i = 0 ; i < cc; i++)
        {
            edits[i]= new QLineEdit("placeholder");
            //edits[i]->setText();
            layout->addRow(new QLabel(model->record().fieldName(i)), edits[i]);
            //layout->addRow();
            qDebug() << model->record().fieldName(i);
        }
                formGroupBox->setLayout(layout);
                this->setLayout(layout);

        mapper = new QDataWidgetMapper;
        mapper->setItemDelegate(new QSqlRelationalDelegate(this));
        mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
        mapper->setModel(model);
        for(i=0;i<cc;i++)
        {
           // edits[i]= new QLineEdit;
            mapper->addMapping(edits[i],i);
        }

        mapper->setCurrentModelIndex(select->currentIndex());
        error = new QLabel("");

        layout->addRow(error);
        QPushButton *button =new QPushButton("Accept");;
        connect(button, SIGNAL(clicked()),this, SLOT(handleButton()));
        layout->addWidget(button);
        QPushButton *button1 =new QPushButton("Reset");;
        connect(button1, SIGNAL(clicked(bool)),this, SLOT(handleButton1()));
        layout->addWidget(button1);


    //this->centralWidget()->setLayout(mainLayout);


}
void editDialog::handleButton()
{

if(!mapper->submit())
 queryNotOK(model->lastError().text());
 else
 this->close();
}



void editDialog::handleButton1()
{
mapper->revert();
qDebug() << model->lastError().text();
//this->close();
}
editDialog::~editDialog()
{

    delete ui;

}

//void editDialog::closeEvent(QCloseEvent *event)
//{


//    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Database",
//                                                                    tr("Are you sure?\n"),
//                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
//                                                                    QMessageBox::Yes);
//        if (resBtn != QMessageBox::Yes) {
//            event->ignore();
//        } else {
//            event->accept();
//        }
//}
void editDialog::queryNotOK(const QString &arg)
{

    QString msg;
    if(arg==NULL) msg="Valid";
    else msg = arg;
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, Qt::red);
    sample_palette.setColor(QPalette::WindowText, Qt::black);
    error->setPalette(sample_palette);
    error->setText(msg);
    fadeOut();

}

void editDialog::fadeOut()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    error->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");

    //start fade
    a->setDuration(7350);
    a->setStartValue(3);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::OutBack);
    //a->pause();
    //QTimer::singleShot(700, a, SLOT(start()));
    a->start(QPropertyAnimation::DeleteWhenStopped);
    //connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));
    //connect(a,SIGNAL(finished()),this,SLOT());
}

#include "createdialog.h"
#include "ui_createdialog.h"
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
#include <QObject>
#include <QGraphicsOpacityEffect>
createDialog::createDialog(QString tablename, QSqlTableModel * model, QItemSelectionModel * select
                           , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDialog)
{

    ui->setupUi(this);

    this->model=model;


    QGroupBox * formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout();

        int i,cc=model->columnCount();
        QLineEdit *edits[cc];

        for(i = 0 ; i < cc; i++)
        {
            edits[i]= new QLineEdit(NULL);
            //edits[i]->setText();
            layout->addRow(new QLabel(model->record().fieldName(i)), edits[i]);
            //layout->addRow();
            qDebug() << model->record().fieldName(i);
        }
        for(i=0;i<cc;i++)
            this->lines[i] = edits[i];
        error = new QLabel("");
        layout->addRow(error);
        formGroupBox->setLayout(layout);
        this->setLayout(layout);

        mapper = new QDataWidgetMapper;
        mapper->setItemDelegate(new QSqlRelationalDelegate(this));
        mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
        mapper->setModel(model);
        //mapper->setCurrentModelIndex(select->currentIndex());

        for(i=0;i<cc;i++)
        {
           // edits[i]= new QLineEdit;
            mapper->addMapping(edits[i],i);
        }
        mapper->setCurrentModelIndex(select->currentIndex());


        QPushButton *button =new QPushButton("Create");
        layout->addWidget(button);
        connect(button, SIGNAL(clicked()),this, SLOT(handleButton()));



}
QString createDialog::handleButton()
{
    QSqlRecord record = model->record();

    int i,cc=model->columnCount();

    for(i=0;i<cc;i++){
        if(this->lines[i]->text() == NULL);
        qDebug () << "NULL";
        if(this->lines[i]->text() == NULL)
            record.setNull(model->record().fieldName(i));
        else
        record.setValue(model->record().fieldName(i),this->lines[i]->text());
        //this->lines[i]->text()
      }
 if(model->insertRecord(-1,record))  this->close() ;
 else
     queryNotOK(model->lastError().text());

}


createDialog::~createDialog()
{
    delete ui;
}
void createDialog::queryNotOK(const QString &arg)
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

void createDialog::fadeOut()
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

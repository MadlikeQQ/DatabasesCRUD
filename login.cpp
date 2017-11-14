#include "login.h"
#include "ui_login.h"
#include <QSqlDatabase>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("microloans");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    QString username,password;

    ussername = ui->lineEdit->text();
    password = ui->lineEdit_2->text();





}

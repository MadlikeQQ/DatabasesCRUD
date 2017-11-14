#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QGraphicsOpacityEffect>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_deleteButton_clicked();


    void on_editButton_clicked();

    void on_createButton_clicked();




    void on_quickSearch_returnPressed();





    void on_extInfo_clicked();

    void on_quickSearch_textEdited(const QString &arg1);


    void on_qry1Btn_clicked();

    void on_qry2Btn_clicked();

    void on_qry3Btn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    void queryOK(const QString &arg);
    void queryNotOK(const QString &arg);
    void fadeOut();
    void checkExtInfo();
    void advancedQueries(QString qry);
    QSqlQueryModel * model;
    QSqlTableModel * tmodel;
};

#endif // MAINWINDOW_H

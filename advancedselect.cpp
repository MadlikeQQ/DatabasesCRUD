#include "advancedselect.h"
#include "ui_advancedselect.h"

advancedSelect::advancedSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::advancedSelect)
{
    ui->setupUi(this);
}

advancedSelect::~advancedSelect()
{
    delete ui;
}

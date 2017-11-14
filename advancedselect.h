#ifndef ADVANCEDSELECT_H
#define ADVANCEDSELECT_H

#include <QDialog>

namespace Ui {
class advancedSelect;
}

class advancedSelect : public QDialog
{
    Q_OBJECT

public:
    explicit advancedSelect(QWidget *parent = 0);
    ~advancedSelect();

private:
    Ui::advancedSelect *ui;
};

#endif // ADVANCEDSELECT_H

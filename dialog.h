#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "selectparametersdialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_createDiagramBtn_clicked();

    void on_selectBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

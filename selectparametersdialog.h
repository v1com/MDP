#ifndef SELECTPARAMETERSDIALOG_H
#define SELECTPARAMETERSDIALOG_H

#include <QDialog>

namespace Ui {
class SelectParametersDialog;
}

class SelectParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectParametersDialog(QWidget *parent = 0);
    ~SelectParametersDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SelectParametersDialog *ui;
};

#endif // SELECTPARAMETERSDIALOG_H

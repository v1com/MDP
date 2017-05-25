#include "selectparametersdialog.h"
#include "ui_selectparametersdialog.h"

SelectParametersDialog::SelectParametersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectParametersDialog)
{
    ui->setupUi(this);
}

SelectParametersDialog::~SelectParametersDialog()
{
    delete ui;
}

void SelectParametersDialog::on_buttonBox_accepted()
{

}

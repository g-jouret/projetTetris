#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"

SetBricsDialog::SetBricsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBricsDialog)
{
    ui->setupUi(this);
}

SetBricsDialog::~SetBricsDialog()
{
    delete ui;
}

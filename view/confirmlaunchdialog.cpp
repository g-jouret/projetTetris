#include "confirmlaunchdialog.h"
#include "ui_confirmlaunchdialog.h"

ConfirmLaunchDialog::ConfirmLaunchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmLaunchDialog)
{
    ui->setupUi(this);
}

ConfirmLaunchDialog::~ConfirmLaunchDialog()
{
    delete ui;
}

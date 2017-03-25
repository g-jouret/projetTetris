#include "view/configdialog.h"
#include "view/ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

std::string ConfigDialog::getName(){
    return ui->leName->text().toStdString();
}

unsigned ConfigDialog::getWidth(){
    return ui->sbWidth->value();
}

unsigned ConfigDialog::getHeight(){
    return ui->sbHeight->value();
}

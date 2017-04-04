#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(unsigned width, unsigned height, unsigned score, unsigned lines, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);

    ui->leName->setMaxLength(15);

    ui->sbWidth->setMinimum(6);
    ui->sbWidth->setMaximum(30);
    ui->sbWidth->setValue(width);

    ui->sbHeight->setMinimum(10);
    ui->sbHeight->setMaximum(50);
    ui->sbHeight->setValue(height);

    ui->sbWinScore->setMinimum(200);
    ui->sbWinScore->setMaximum(2000);
    ui->sbWinScore->setValue(score);

    ui->sbWinLines->setMinimum(5);
    ui->sbWinLines->setMaximum(20);
    ui->sbWinLines->setValue(lines);

    ui->sbLevel->setMaximum(4);
    ui->sbLevel->setValue(0);

}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

std::string ConfigDialog::getName() const{
    return ui->leName->text().toStdString();
}

unsigned ConfigDialog::getWidth() const{
    return ui->sbWidth->value();
}

unsigned ConfigDialog::getHeight() const{
    return ui->sbHeight->value();
}

unsigned ConfigDialog::getLevel() const{
    return ui->sbLevel->value();
}

unsigned ConfigDialog::getWinScore() const{
    return ui->sbWinScore->value();
}

unsigned ConfigDialog::getWinLines() const{
    return ui->sbWinLines->value();
}

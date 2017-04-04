#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(unsigned width, unsigned height, unsigned score,
                           unsigned lines, unsigned time, QWidget *parent) :
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

    ui->timeEdit->setMinimumTime(QTime (0,1));
    ui->timeEdit->setMaximumTime(QTime (0,59,59,999));
    unsigned ms = (time % 1000);
    unsigned sec = ((time/1000) % 60);
    unsigned min = ((time/60000) % 60);
    //unsigned hours = ((time/3600000) % 24);
    ui->timeEdit->setTime(QTime (0, min, sec, ms));

    ui->sbLevel->setMinimum(0);
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

unsigned ConfigDialog::getWinTime() const{
    return ui->timeEdit->time().msecsSinceStartOfDay();
}

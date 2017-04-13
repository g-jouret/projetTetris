#include "configdialog.h"
#include "ui_configdialog.h"
#include "setbricsdialog.h"
#include <QErrorMessage>

using namespace GJ_GW;

ConfigDialog::ConfigDialog(std::string name, std::vector<unsigned> args, QWidget *parent):
    QDialog(parent), ui(new Ui::ConfigDialog){
    ui->setupUi(this);
    keepBag_ = true;
    connect(ui->bricSetter, &QPushButton::clicked, this, &ConfigDialog::setBrics);

    ui->leName->setText(QString::fromStdString(name));
    ui->leName->setMaxLength(args.at(0));

    ui->sbWidth->setMinimum(args.at(1));
    ui->sbWidth->setMaximum(args.at(2));
    ui->sbWidth->setValue(args.at(3));

    ui->sbHeight->setMinimum(args.at(4));
    ui->sbHeight->setMaximum(args.at(5));
    ui->sbHeight->setValue(args.at(6));

    ui->sbWinScore->setMinimum(args.at(7));
    ui->sbWinScore->setMaximum(args.at(8));
    ui->sbWinScore->setValue(args.at(9));

    ui->sbWinLines->setMinimum(args.at(10));
    ui->sbWinLines->setMaximum(args.at(11));
    ui->sbWinLines->setValue(args.at(12));


    ui->timeEdit->setMinimumTime(convertUnsToTime(args.at(13)));
    ui->timeEdit->setMaximumTime(convertUnsToTime(args.at(14)));
    ui->timeEdit->setTime(convertUnsToTime(args.at(15)));

    ui->sbLevel->setMinimum(args.at(16));
    ui->sbLevel->setMaximum(args.at(17));
    ui->sbLevel->setValue(args.at(16));
}

ConfigDialog::~ConfigDialog(){
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

std::vector<Bric> ConfigDialog::getBrics() const{
    return brics_;
}

bool ConfigDialog::isKeepingBag() const{
    return keepBag_;
}

void ConfigDialog::setBrics(){
    SetBricsDialog newBric (this);
    newBric.setWindowTitle("Éditeur de brique");
    int ret = newBric.exec();
    if(ret == QDialog::Rejected) return;
    std::vector<Position> bric = newBric.getSaved();
    try{
        brics_.push_back(Bric(bric, Color(std::vector<unsigned>{29,69,19})));
        keepBag_ = newBric.isKeepingBag();
    } catch(const std::invalid_argument & e){
        QErrorMessage * except = new QErrorMessage(this);
        except->showMessage(e.what());
    }
}

QTime ConfigDialog::convertUnsToTime(unsigned time){
    unsigned ms = (time % 1000);
    unsigned sec = ((time/1000) % 60);
    unsigned min = ((time/60000) % 60);
    unsigned hours = ((time/3600000) % 24);
    return QTime(hours, min, sec, ms);
}

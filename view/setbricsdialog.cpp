#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"
#include <QLabel>
#include <QPushButton>
#include <iostream>

using namespace GJ_GW;

SetBricsDialog::SetBricsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBricsDialog)
{
    ui->setupUi(this);
    ui->checkBox->setText("Voulez-vous conserver le sac de brique actuel?");
    checked_ = std::vector<std::vector<bool>> (6, std::vector<bool>(6,0));
    generateGrid(true);
}

SetBricsDialog::~SetBricsDialog()
{
    delete ui;
}

std::vector<Position> SetBricsDialog::getSaved() const{
    return saved_;
}

bool SetBricsDialog::isKeepingBag() const{
    return ui->checkBox->isChecked();
}

void SetBricsDialog::generateGrid(bool first){
    for(unsigned u {0}; u < 6; ++u){
        for(unsigned v {0}; v < 6; ++v){
            if(first){
                QPushButton * btn = createBtn(btn, u, v);
                if(v != 0){
                    btn->setDisabled(true);
                }
                ui->gridLayout->addWidget(btn, v, u, 1, 1);
            } else{
                if(checked_[v][u]){
                    QLabel * lb = createLb(lb);
                    ui->gridLayout->addWidget(lb, v, u, 1, 1);
                } else{
                    QPushButton * btn = createBtn(btn, u, v);
                    ui->gridLayout->addWidget(btn, v, u, 1, 1);
                }
            }
        }
    }
}

QPushButton *SetBricsDialog::createBtn(QPushButton * btn, unsigned x, unsigned y){
    QString pos {QString::number(x) +"-"+ QString::number(y)};
    btn = new QPushButton(pos, this);
    btn->setObjectName(pos);
    connect(btn, SIGNAL(clicked()), this, SLOT(update()));
    btn->setStyleSheet("QPushButton{"
                       "width: 40px;"
                       "height: 40px;"
                       "background-color: orange;"
                       "}"
                       "QPushButton:disabled{"
                       "background-color: white;"
                       "}");
    return btn;
}

QLabel *SetBricsDialog::createLb(QLabel * lb){
    lb = new QLabel();
    lb->setStyleSheet("Qlabel{"
                      "width: 40px;"
                      "height: 40px;"
                      "background-color : blue;"
                      "}");
    return lb;
}

/*void SetBricsDialog::reset(){
    QLayoutItem *child;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        delete child->widget();
    }
    checked = std::vector<std::vector<bool>> (6, std::vector<bool>(6,0));
    generateGrid(true);
}*/

void SetBricsDialog::save(){
    for(unsigned u {0}; u < 6; ++u){
        for(unsigned v {0}; v < 6; ++v){
            if(checked_[v][u]){
                Position pos = Position(u, v);
                saved_.push_back(pos);
            }
        }
    }
}

void SetBricsDialog::update(){
    QObject *senderObj = sender();
    QString pos = senderObj->objectName();
    unsigned x = pos.at(0).digitValue();
    unsigned y = pos.at(2).digitValue();
    checked_[y][x] = 1;
    QLayoutItem *child;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        delete child->widget();
    }
    generateGrid(false);
}

void SetBricsDialog::accept(){
    save();
    QDialog::accept();
}

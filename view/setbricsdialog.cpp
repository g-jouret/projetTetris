#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"
#include <QLabel>
#include <QPushButton>
#include <iostream>

using namespace GJ_GW;

SetBricsDialog::SetBricsDialog(QWidget *parent): QDialog(parent), ui(new Ui::SetBricsDialog){
    ui->setupUi(this);
    ui->checkBox->setText("Voulez-vous conserver le sac de briques actuel?");
    checked_ = std::vector<std::vector<bool>> (6, std::vector<bool>(6,0));
    generateGrid(true);
}

SetBricsDialog::~SetBricsDialog(){
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
                QPushButton * btn = createBtn(u, v);
                if(v != 0){
                    btn->setDisabled(true);
                }
                ui->gridLayout->addWidget(btn, v, u, 1, 1);
            } else{
                if(checked_[v][u]){
                    QLabel * lb = createLb();
                    ui->gridLayout->addWidget(lb, v, u, 1, 1);
                } else{
                    QPushButton * btn = createBtn(u, v);
                    unsigned count {0};
                    bool ok {0};
                    while(! ok && count < saved_.size()){
                        ok = saved_.at(count).isAdjacent(u, v);
                        ++count;
                    }
                    if(!ok)
                        btn->setDisabled(true);
                    ui->gridLayout->addWidget(btn, v, u, 1, 1);
                }
            }
        }
    }
}

QPushButton *SetBricsDialog::createBtn(unsigned x, unsigned y){
    QString pos {QString::number(x) +"-"+ QString::number(y)};
    QPushButton * btn = new QPushButton(this);
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

QLabel *SetBricsDialog::createLb(){
    QLabel * lb = new QLabel();
    lb->setStyleSheet("Qlabel{"
                      "width: 40px;"
                      "height: 40px;"
                      "background-color : blue;"
                      "}");
    return lb;
}

/* TODO annuler dernier mouvement?
 * void SetBricsDialog::reset(){
    QLayoutItem *child;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        delete child->widget();
    }
    checked = std::vector<std::vector<bool>> (6, std::vector<bool>(6,0));
    generateGrid(true);
}*/

/*void SetBricsDialog::save(){
    for(unsigned u {0}; u < 6; ++u){
        for(unsigned v {0}; v < 6; ++v){
            if(checked_[v][u]){
                Position pos = Position(u, v);
                saved_.push_back(pos);
            }
        }
    }
}*/

void SetBricsDialog::update(){
    QObject *senderObj = sender();
    QString posBtn = senderObj->objectName();
    unsigned x = posBtn.at(0).digitValue();
    unsigned y = posBtn.at(2).digitValue();
    checked_[y][x] = 1;
    Position pos = Position(x, y);
    saved_.push_back(pos);
    QLayoutItem *child;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        delete child->widget();
    }
    generateGrid(false);
}

void SetBricsDialog::accept(){
    //save();
    QDialog::accept();
}

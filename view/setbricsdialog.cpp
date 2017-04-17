#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"
#include <QLabel>
#include <QPushButton>

using namespace GJ_GW;

SetBricsDialog::SetBricsDialog(QWidget *parent): QDialog(parent), ui(new Ui::SetBricsDialog){
    ui->setupUi(this);
    checked_ = std::vector<std::vector<bool>> (6, std::vector<bool>(6,0));
    generateGrid(true);
}

SetBricsDialog::~SetBricsDialog(){
    delete ui;
}

std::vector<Position> SetBricsDialog::getSaved() const{
    return saved_;
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
                       "border-style:outset;"
                       "border-width:10px;"
                       "background-color:orange;"
                       "border-color:orange;}"
                       "QPushButton:disabled{"
                       "background-color: white;"
                       "border-color:rgb(230,255,255);"
                       "}");
    btn->setFixedSize(40,40);
    return btn;
}

QLabel *SetBricsDialog::createLb(){
    QLabel * lb = new QLabel(this);
    lb->setStyleSheet("QLabel{"
                      "background-color: blue;"
                      "border-width:10px;"
                      "border-style:outset;"
                      "border-color:blue;"
                      "}");
    lb->setFixedSize(40,40);
    return lb;
}

void SetBricsDialog::eraseBoard(){
    QLayoutItem *child;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        delete child->widget();
    }
}

void SetBricsDialog::update(){
    QObject *senderObj = sender();
    QString posBtn = senderObj->objectName();
    unsigned x = posBtn.at(0).digitValue();
    unsigned y = posBtn.at(2).digitValue();
    checked_[y][x] = 1;
    Position pos = Position(x, y);
    saved_.push_back(pos);
    eraseBoard();
    generateGrid(false);
}

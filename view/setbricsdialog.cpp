#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"
#include <QLabel>
#include <QPushButton>

SetBricsDialog::SetBricsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBricsDialog)
{
    ui->setupUi(this);
    generateGrid();
}

SetBricsDialog::~SetBricsDialog()
{
    delete ui;
}

void SetBricsDialog::generateGrid(){
    for(unsigned u {0}; u < 6; ++u){
        for(unsigned v {0}; v < 6; ++v){
            QPushButton * btn = new QPushButton();
            QColor color(255,255,255);
            btn->setStyleSheet("QPushButton{"
                              "width: 20px;"
                              "height: 20px;"
                              "background-color : "+ color.name() +";}");
            ui->gridLayout->addWidget(btn, v, u, 1, 1);
        }
    }
}

void SetBricsDialog::reset(){
    /*    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }*/
}

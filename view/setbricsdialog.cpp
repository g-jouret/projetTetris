#include "setbricsdialog.h"
#include "ui_setbricsdialog.h"

SetBricsDialog::SetBricsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBricsDialog)
{
    ui->setupUi(this);
    generateBoard();
}

SetBricsDialog::~SetBricsDialog()
{
    delete ui;
}

void SetBricsDialog::generateBoard(){
    /*for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        lb->setStyleSheet("QLabel[fill=true]{"
                          "background-color : blue;"
                          "}"
                          "QLabel[empty=true]{"
                          "background-color : white;"
                          "}");
        if(it->second){
            lb->setProperty("fill", true);
        } else{
            lb->setProperty("empty", true);
        }
        ui->boardGrid->addWidget(lb, it->first.getY(), it->first.getX(), 1, 1);
    }*/
}

void SetBricsDialog::reset(){
/*    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }*/
}

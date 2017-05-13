#include "confirmlaunchdialog.h"
#include "ui_confirmlaunchdialog.h"
#include "../network/multitetris.h"
#include <QPushButton>

ConfirmLaunchDialog::ConfirmLaunchDialog(GJ_GW::MultiTetris &game, QWidget *parent) :
    QDialog(parent), ui(new Ui::ConfirmLaunchDialog), game_{game}{
    ui->setupUi(this);
    hasConfirm_ = false;
    game_.addObserver(this);
}

ConfirmLaunchDialog::~ConfirmLaunchDialog(){
    delete ui;
}

void ConfirmLaunchDialog::accept(){
    if(game_.isReady()){
        game_.removeObserver(this);
        QDialog::accept();
    } else{
        hasConfirm_ = true;
        ui->buttonBox->button(ui->buttonBox->Yes)->setDisabled(true);
        game_.sendReady();
    }
}

void ConfirmLaunchDialog::reject(){
    if(hasConfirm_){
        hasConfirm_ = false;
        ui->buttonBox->button(ui->buttonBox->Yes)->setDisabled(false);
    } else{
        game_.sendCancel();
        game_.removeObserver(this);
        QDialog::reject();
    }
}

void ConfirmLaunchDialog::update(GJ_GW::Subject *){
    if(game_.isReady() && hasConfirm_){
        game_.removeObserver(this);
        QDialog::accept();
    }
}


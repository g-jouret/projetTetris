#include "mwtetris.h"
#include "ui_mwtetris.h"

MWTetris::MWTetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MWTetris)
{
    ui->setupUi(this);
    connexion();
}

MWTetris::~MWTetris()
{
    delete ui;
}

void MWTetris::connexion(){
    connect(ui->action_Quitter, &QAction::triggered, &QCoreApplication::quit);
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Fermer, &QAction::triggered, this, &MWTetris::closeGame);
    // TODO : aide? cf qtpendu.pdf
}

void MWTetris::createGame(){

}

void MWTetris::closeGame(){

}

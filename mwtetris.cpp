#include "mwtetris.h"
#include "ui_mwtetris.h"
#include "configdialog.h"
#include <QGridLayout>
#include <QLabel>

MWTetris::MWTetris(GJ_GW::Game * game, QWidget *parent) : QMainWindow(parent), game_{game}, ui(new Ui::MWTetris)
{
    ui->setupUi(this);
    connexion();

    setName();
    generateBoard();
}

MWTetris::~MWTetris(){
    delete ui;
}

void MWTetris::connexion(){
    connect(ui->action_Quitter, &QAction::triggered, &QCoreApplication::quit);
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Fermer, &QAction::triggered, this, &MWTetris::closeGame);
    // TODO : aide? cf qtpendu.pdf
}

void MWTetris::createGame(){
    ConfigDialog cd {this};
    auto ret = cd.exec();
    if(ret == QDialog::Rejected) return;

    resetGame();

    std::string name {cd.getName()};
    unsigned width {cd.getWidth()};
    unsigned height {cd.getHeight()};

    if(! name.empty() || width != 0 || height != 0){
        game_->setPlayer(name, width, height);
        setName();

    }
    generateBoard();
    generateBric();
}

void MWTetris::closeGame(){
    delete game_;
    exit(0);
}

void MWTetris::setName(){
    ui->lbPlayerName->setText(QString::fromStdString(game_->getPlayer().getName()));
}

void MWTetris::generateBoard(){
    for(GJ_GW::Position p : game_->getPlayer().getBoard().getGrid()){
        QLabel * lb = new QLabel();

        lb->setStyleSheet("QLabel {background-color : white;}");
                                /*"border-style : solid;"
                                "border-width : 2px;"
                                "border-color : black;}");*/
        ui->boardGrid->addWidget(lb, p.getY(), p.getX(), 1, 1);
    }
}

void MWTetris::resetGame(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
    // TODO : game.reset => remise de toutes les cases en unfilled
    // NOTE : reset => score, nbLines, level & timer remis à 0?
    // WARNING : bug : ne répond plus quand trop grande diminution de la largeur(?)
}

void MWTetris::printFilled(){
// TODO : implémentation
}

void MWTetris::turn(){
    game_->getPlayer().rotateBric();
}

void MWTetris::generateBric(){
    game_->getPlayer().generateBric();
}

void MWTetris::down(){
    game_->getPlayer().moveBric();
}

void MWTetris::drop(){
    game_->getPlayer().moveBric(1);
}

void MWTetris::left(){
    game_->getPlayer().moveBric(2);
}

void MWTetris::right(){
    game_->getPlayer().moveBric(3);
}

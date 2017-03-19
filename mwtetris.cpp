#include "mwtetris.h"
#include "ui_mwtetris.h"
#include "configdialog.h"
#include <QGridLayout>
#include <QLabel>
#include <iostream>

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

    std::string name {cd.getName()};
    unsigned width {cd.getWidth()};
    unsigned height {cd.getHeight()};

    if(! name.empty() || width != 0 || height != 0){
        game_->setPlayer(name, width, height);
        setName();
    }
    generateBric();
    generateBoard();
    down();
    generateBoard();
}

void MWTetris::closeGame(){
    delete game_;
    //exit(0);  pas une bonne idée
    QApplication::quit();
}

void MWTetris::setName(){
    ui->lbPlayerName->setText(QString::fromStdString(game_->getPlayer().getName()));
}

void MWTetris::generateBoard(){
    std::cout << "generateBoard" << std::endl;
    resetBoard();
    std::vector<GJ_GW::Position> theGrid {game_->getPlayer().getBoard().getGrid()};
    /*for(GJ_GW::Position p : game_->getPlayer().getBoard().getGrid()){
        QLabel * lb = new QLabel();
        if(p.isFilled()){
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, p.getY(), p.getX(), 1, 1);
    }*/

    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        if(it->isFilled()){
            std::cout << *it << std::endl;
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, it->getY(), it->getX(), 1, 1);
    }
}

void MWTetris::resetBoard(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
    // WARNING : bug : ne répond plus quand trop grande diminution de la largeur(?)
}

void MWTetris::actualiseBoard(){
    /*QLabel *lb;
    for(GJ_GW::Position p : game_->getPlayer().getBoard().getGrid()){
        lb = ui->boardGrid->itemAtPosition(p.getX(), p.getY());
        if(p.isFilled()){

        }
    }*/
}

void MWTetris::turn(){
    game_->getPlayer().rotateBric();
}

void MWTetris::generateBric(){
    std::cout << "generateBric" << std::endl;
    game_->getPlayer().generateBric();
    std::cout << game_->getPlayer().getCurrentBric()
              << std::endl;
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

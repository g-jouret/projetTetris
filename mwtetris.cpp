#include "mwtetris.h"
#include "ui_mwtetris.h"

MWTetris::MWTetris(QWidget *parent) : QMainWindow(parent), ui(new Ui::MWTetris)
{
    ui->setupUi(this);
    GJ_GW::Game *game = new GJ_GW::Game();
    game_ = game;
    setName();
    generateBoard();
    connexion();

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
        GJ_GW::Game *game = new GJ_GW::Game(name, width, height);
        delete game_;
        game_ = game;
        setName();
        generateBoard();
    }
}

void MWTetris::closeGame(){
    delete game_;
    game_ = nullptr;
}

void MWTetris::setName(){
    ui->lbPlayerName->setText(QString::fromStdString(game_->getPlayer().getName()));
}

void MWTetris::generateBoard(){
    ui->listView->setGridSize(QSize(game_->getPlayer().getBoard().getWidth(), game_->getPlayer().getBoard().getHeight()));
}

void MWTetris::turn(){
    game_->getPlayer().rotateBric();
}

void MWTetris::drop(){
    game_->getPlayer().moveBric(4);
}

void MWTetris::left(){
    game_->getPlayer().moveBric(2);
}

void MWTetris::right(){
    game_->getPlayer().moveBric(3);
}

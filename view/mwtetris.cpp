#include "mwtetris.h"
#include "ui_mwtetris.h"
#include "configdialog.h"
#include "confirmlaunchdialog.h"
#include "../model/gamestate.h"
#include "../model/direction.h"
#include "../network/multitetris.h"
#include "../network/client.h"
#include <sstream>
#include <QElapsedTimer>
#include <QTimer>
#include <QErrorMessage>
#include <QtNetwork>
#include <QProgressDialog>
#include <iostream>

using namespace GJ_GW;

MWTetris::MWTetris(QWidget *parent) : QMainWindow(parent), ui(new Ui::MWTetris){
    ui->setupUi(this);
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Quitter, &QAction::triggered, this, &QCoreApplication::quit);
    connect(ui->btnDown, &QPushButton::clicked, this, &MWTetris::drop);
    connect(ui->btnLeft, &QPushButton::clicked, this, &MWTetris::left);
    connect(ui->btnRight, &QPushButton::clicked, this, &MWTetris::right);
    connect(ui->btnUp, &QPushButton::clicked, this, &MWTetris::rotate);
    connect(ui->btnStart, &QPushButton::clicked, this, &MWTetris::createGame);
    connect(ui->btnPause, &QPushButton::clicked, this, &MWTetris::setPaused);
    ui->btnUp->setDisabled(true);
    ui->btnDown->setDisabled(true);
    ui->btnLeft->setDisabled(true);
    ui->btnRight->setDisabled(true);
    ui->btnPause->setDisabled(true);
    lbEnd_ = 0;
    lbEnd_ = new QLabel(this);
    lbEnd_->hide();
    time_ = new QTimer(this);
    connect(time_, SIGNAL(timeout()), this, SLOT(showTime()));
    game_.initServer();
    game_.addObserver(this);
    update(&game_);
    //connect(ui->btnRetry, &QPushButton::clicked, this, );
    //ui->btnRetry->hide();
    showHostInfo();
}

MWTetris::~MWTetris() noexcept{
    game_.removeObserver(this);
    delete ui;
}

void MWTetris::createGame(){
    game_.initServer();
    showHostInfo();
    setPaused(true);
    //ui->msgConnect->hide();
    std::vector<unsigned> args {15,     //maximum size of player name
                                game_.MINIMUM_WIDTH, game_.MAXIMUM_WIDTH, game_.getBoard().getWidth(),
                                        game_.MINIMUM_HEIGHT, game_.MAXIMUM_HEIGHT, game_.getBoard().getHeight(),
                                        game_.MINIMUM_WIN_SCORE, game_.MAXIMUM_WIN_SCORE, game_.getWinScore(),
                                        game_.MINIMUM_WIN_LINES, game_.MAXIMUM_WIN_LINES, game_.getWinLines(),
                                        game_.MINIMUM_WIN_TIME, game_.MAXIMUM_WIN_TIME, game_.getWinTime(),
                                        0, 5};      //minimum and maximum level

    ConfigDialog cd (game_.getPlayer().getName(), args, (game_.getMode() != GameMode::SOLO), this);
    cd.setWindowTitle("Configuration de la partie");

    int ret = cd.exec();

    if(ret == QDialog::Rejected){
        if(game_.getGameState() == GameState::ON || game_.getGameState() == GameState::NEW_BRIC)
            setPaused(false);
    } else{
        lbEnd_ = nullptr;
        lbEnd_ = new QLabel(this);
        lbEnd_->hide();

        std::string name;
        name = (cd.getName().empty())? game_.getPlayer().getName() : cd.getName();
        try{
            if(cd.isResettingBag()){
                game_.resetBag();
            } else{
                if(cd.getBrics().size() != 0){
                    game_.setBag(cd.getBrics(), cd.isKeepingBag());
                }
            }

            if(!cd.isPlayingDuo()){
                game_.setMode(GameMode::SOLO);
            } else{
                QString hostName = cd.getHostName();
                if(hostName.isEmpty()){
                    throw std::invalid_argument("veuillez entrer un nom d'hôte");
                }
                unsigned port = cd.getPort();
                try{
                    game_.initClient(hostName, port);
                    ui->msgConnect->setText("connexion effectuée");
                    ui->msgConnect->show();
                } catch(const QString & e){
                    ui->msgConnect->setText(e);
                    ui->msgConnect->show();
                    return;
                }
            }
            showHostInfo();
            game_.initGame(name, cd.getWidth(), cd.getHeight(), cd.getWinScore(), cd.getWinLines(), cd.getWinTime(),
                           cd.getLevel(), cd.hasWinByScore(), cd.hasWinByLines(), cd.hasWinByTime());

        } catch(const std::invalid_argument & e){
            QErrorMessage * except = new QErrorMessage(this);
            except->showMessage(e.what());
        }
    }
}

void MWTetris::launchGame(){
    game_.startGame();
    ui->btnStart->hide();
    setPaused(false);
    ui->btnPause->setEnabled(true);
}

void MWTetris::showHostInfo(){
    QString ip;
    switch(game_.getMode()){
    case GameMode::HOST:
        ip = game_.getLocalIP();
        ui->lbHostName->setText(game_.getHostName(ip));
        ui->lbHostName->show();
        ui->lbHost->show();
        ui->lbPortNb->setText(QString::number(game_.getPort()));
        ui->lbPortNb->show();
        ui->lbPort->show();
        ui->msgConnect->show();
        break;
    case GameMode::CLIENT:
        ui->msgConnect->show();
        ui->lbHost->hide();
        ui->lbHostName->hide();
        ui->lbPort->hide();
        ui->lbPortNb->hide();
        break;
    case GameMode::SOLO:
        ui->msgConnect->hide();
        ui->lbHost->hide();
        ui->lbHostName->hide();
        ui->lbPort->hide();
        ui->lbPortNb->hide();
        break;
    }
}

/*void MWTetris::reconnect(){

}*/

void MWTetris::generateBoard(bool end){
    std::map<Position, Color> theGrid {game_.getBoard().getGrid()};
    unsigned width {((30+3)*game_.getBoard().getWidth())-3+40};     //(30px + 3px de spacing) * nombre de cases en largeur - 1 spacing + 2*20px de margin
    unsigned height {((30+3)*game_.getBoard().getHeight())-3+40};   //(30px + 3px de spacing) * nombre de cases en hauteur - 1 spacing + 2*20px de margin
    ui->boardGrid->setSpacing(3);
    ui->boardGrid->setGeometry(QRect(0,0,width,height));
    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel *lb = new QLabel(this);
        QColor color(it->second.getCode().at(0),
                     it->second.getCode().at(1),
                     it->second.getCode().at(2));
        QColor border((it->second.getCode().at(0) <= 30)? 0 : it->second.getCode().at(0)-30,
                      it->second.getCode().at(1),
                      it->second.getCode().at(2));
        setStyleSheet(lb, color.name(), border.name());
        lb->setText(color.name());
        lb->setFixedSize(30,30);
        ui->boardGrid->addWidget(lb, ((it->first.getY() < game_.getBoard().getHeight()/2)? it->first.getY() : it->first.getY()+1), it->first.getX(), 1, 1);
    }
    if(end){
        ui->boardGrid->addWidget(lbEnd_, game_.getBoard().getHeight()/2, 0, 1, game_.getBoard().getWidth(), Qt::AlignCenter);
        lbEnd_->show();
    }
}

void MWTetris::setStyleSheet(QLabel *lb, QString color, QString border){
    QString styleSheet = "QLabel{"
                         "border-style: outset;"
                         "border-width: 5px;"
                         "background-color: %1;"
                         "color: %1;"
                         "border-color: %2;}";
    lb->setStyleSheet(styleSheet.arg(color, border));
}

void MWTetris::refreshBoard(){
    std::map<Position, Color> theGrid {game_.getBoard().getGrid()};
    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel *oldLb = qobject_cast<QLabel*>(ui->boardGrid->itemAtPosition(((it->first.getY() < game_.getBoard().getHeight()/2)? it->first.getY() : it->first.getY()+1), it->first.getX())->widget());
        QColor color(it->second.getCode().at(0),
                     it->second.getCode().at(1),
                     it->second.getCode().at(2));
        if(oldLb->text().compare(color.name())){
            QColor border((it->second.getCode().at(0) <= 30)? 0 : it->second.getCode().at(0)-30,
                          it->second.getCode().at(1),
                          it->second.getCode().at(2));
            QLabel *newLb = new QLabel(this);
            setStyleSheet(newLb, color.name(), border.name());
            newLb->setText(color.name());
            newLb->setFixedSize(30,30);
            ui->boardGrid->replaceWidget(oldLb,newLb);
            delete oldLb;
        }
    }
}

void MWTetris::eraseBoard(QGridLayout * board){
    QLayoutItem *child;
    while((child = board->takeAt(0)) != 0){
        delete child->widget();
    }
}

void MWTetris::showNextBric(){
    //if(game_.getGameState() == GameState::ON){
    Bric theBric = game_.getNextBric();
    unsigned side = theBric.getSide();
    ui->boardNext->setSpacing(3);
    for(unsigned u {0}; u < side; ++u){
        for(unsigned v {0}; v < side; ++v){
            QLabel * lb = new QLabel(this);
            lb->setFixedSize(20,20);
            Position temp = Position(u, v);
            if(theBric.contains(temp)){
                QColor color(theBric.getColor().getCode().at(0),
                             theBric.getColor().getCode().at(1),
                             theBric.getColor().getCode().at(2));
                QColor border((theBric.getColor().getCode().at(0) <= 30)? 0 : theBric.getColor().getCode().at(0)-30,
                              theBric.getColor().getCode().at(1),
                              theBric.getColor().getCode().at(2));
                setStyleSheet(lb, color.name(), border.name());
            } else{
                lb->setHidden(true);
            }
            ui->boardNext->addWidget(lb, v, u, 1, 1);
        }
    }
    //}
}

void MWTetris::left(){
    game_.checkMove(Direction::LEFT);
}

void MWTetris::right(){
    game_.checkMove(Direction::RIGHT);
}

void MWTetris::rotate(){
    game_.checkRotate();
}

void MWTetris::drop(){
    game_.drop();
}

void MWTetris::update(Subject *){
    ui->lbPlayerScore->setText(QString::number(game_.getPlayer().getScore()) + ((game_.hasWinByScore())? "/" + QString::number(game_.getWinScore()) : ""));
    ui->lbPlayerLines->setText(QString::number(game_.getPlayer().getNbLines()) + ((game_.hasWinByLines())? "/" + QString::number(game_.getWinLines()) : ""));
    switch (game_.getGameState()){

    case GameState::NONE:
        if(QString::fromStdString(game_.getPlayer().getName()) != ui->lbPlayerName->text()){
            ui->lbPlayerName->setText(QString::fromStdString(game_.getPlayer().getName()));
        }
        eraseBoard(ui->boardGrid);
        generateBoard();
        break;
    case GameState::INITIALIZED:
        if(game_.getMode() != GameMode::SOLO){
            ConfirmLaunchDialog cld(game_, this);
            cld.setWindowTitle("Confirmation de lancement");
            int ret = cld.exec();

            if(ret == QDialog::Rejected) return;
        }
        if(QString::fromStdString(game_.getPlayer().getName()) != ui->lbPlayerName->text()){
            ui->lbPlayerName->setText(QString::fromStdString(game_.getPlayer().getName()));
        }
        eraseBoard(ui->boardGrid);
        generateBoard();
        launchGame();
        break;
    case GameState::NEW_BRIC:
        eraseBoard(ui->boardNext);
        showNextBric();
        break;
    case GameState::ON:
        /*if(timer != timer_->interval())
            timer_->setInterval(game_.getTimer());*/
        if(QString::number(game_.getLevel()) != ui->lbLevelGame->text()){
            ui->lbLevelGame->setText(QString::number(game_.getLevel()));
        }
        refreshBoard();
        //eraseBoard(ui->boardNext);
        //showNextBric();
        break;
    case GameState::LOOSE:
        lbEnd_->setText("Game over...");
        endGame();
        break;
    case GameState::LINE:
        lbEnd_->setText("Vous êtes un empilateur né!\n"
                        "Vous avez fait assez de ligne pour gagner!");
        endGame();
        break;
    case GameState::SCORE:
        lbEnd_->setText("Quel score! J'ai du mal à suivre!");
        endGame();
        break;
    case GameState::TIME:
        lbEnd_->setText("Vous avez survécu!\n"
                        "Vous avez joué assez longtemps au Tetris");
        endGame();
        break;
    }
}

void MWTetris::endGame(){
    setPaused(true);
    ui->btnPause->setDisabled(true);
    lbEnd_->setStyleSheet("QLabel{font-weight: bold; font-size: 20px;"
                          "background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 176, 0, 69),"
                          "stop:0.375 rgba(255, 223, 0, 69), stop:0.423533 rgba(255, 223, 0, 145),"
                          "stop:0.45 rgba(255, 214, 0, 208), stop:0.477581 rgba(255, 219, 71, 130),"
                          "stop:0.518717 rgba(255, 218, 71, 130), stop:0.547739 rgba(255, 214, 0, 255),"
                          "stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(251, 255, 0, 69),"
                          "stop:1 rgba(255, 242, 0, 69));}");
    lbEnd_->setAlignment(Qt::AlignCenter);
    lbEnd_->adjustSize();
    generateBoard(true);
}

void MWTetris::setPaused(bool checked){
    if(checked){
        game_.pause();
        time_->stop();
        ui->btnUp->setDisabled(true);
        ui->btnDown->setDisabled(true);
        ui->btnLeft->setDisabled(true);
        ui->btnRight->setDisabled(true);
    } else{
        game_.resume();
        time_->start(1000);
        ui->btnUp->setEnabled(true);
        ui->btnDown->setEnabled(true);
        ui->btnLeft->setEnabled(true);
        ui->btnRight->setEnabled(true);
    }
}

void MWTetris::showTime(){
    QString lb;
    unsigned time = (game_.getTimeElapsed());
    unsigned sec = (time % 60);
    unsigned min = ((time/60) % 60);
    unsigned hours = ((time/3600) % 24);
    if(hours != 0){
        lb.append(QString::number(hours));
        lb.append(":");
    }
    if(min < 10)
        lb.append("0");
    lb.append(QString::number(min));
    lb.append(":");
    if(sec < 10)
        lb.append("0");
    lb.append(QString::number(sec));
    ui->lbTime->setText(lb);
}

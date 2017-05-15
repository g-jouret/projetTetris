#include "multitetris.h"
#include "server.h"
#include "client.h"
#include "netmsg.h"
#include "../view/mwtetris.h"
#include <stdexcept>
#include <iostream>

using namespace GJ_GW;

MultiTetris::MultiTetris() : Tetris(){
    server_ = 0;
    client_ = 0;
    mode_ = GameMode::HOST;
    ready_ = false;
}

QString MultiTetris::getHostName(QString &ip) const{
    QHostInfo hostInfo {QHostInfo::fromName(ip)};
    return hostInfo.hostName();
}

QString MultiTetris::getLocalIP() const{
    QHostInfo hostInfo {QHostInfo::fromName(QHostInfo::localHostName())};
    return hostInfo.addresses().first().toString();
}

unsigned MultiTetris::getPort() const {
    return server_->serverPort();
}

GameMode MultiTetris::getMode() const{
    return mode_;
}

bool MultiTetris::isReady() const {
    return ready_;
}

void MultiTetris::setMode(GameMode mode){
    mode_ = mode;
    if((mode_ != GameMode::CLIENT) && client_ != 0){
        client_->close();
        delete client_;
        client_ = 0;
    }
    if((mode_ == GameMode::SOLO || mode_ == GameMode::CLIENT) && server_ != 0){
        server_->close();
        delete server_;
        server_ = 0;
    }
}

void MultiTetris::initServer(){
    if(server_ == 0){
        server_ = new Server(this, this);
        try{
            server_->launch();
            setMode(GameMode::UNCONNECTED);
        } catch(const QString & e){
            setMode(GameMode::SOLO);
            throw;
        }
    }
}

void MultiTetris::initClient(QString hostName, unsigned port){
    if(client_ == 0){
        client_ = new Client(this, this);
        try{
            client_->connectToServer(hostName, port);
            setMode(GameMode::CLIENT);
        } catch(const QString & e){
            setMode(GameMode::UNCONNECTED);
            throw;
        }
    }
}

void MultiTetris::sendReady(){
    NetMsg netMsg(NetMsg::MSG_RDY);
    if(mode_ == GameMode::HOST){
        server_->sendData(netMsg);
    } else if(mode_ == GameMode::CLIENT){
        client_->sendData(netMsg);
    }
}

void MultiTetris::setReady(){
    ready_ = true;
    notifyObservers();
}

void MultiTetris::cancelGame(){
    setGameState(GameState::NONE);
}

void MultiTetris::sendCancel(){
    NetMsg netMsg(NetMsg::MSG_CANCEL);
    if(mode_ == GameMode::HOST){
        server_->sendData(netMsg);
    } else if(mode_ == GameMode::CLIENT){
        client_->sendData(netMsg);
    }
    setGameState(GameState::NONE);
}

void MultiTetris::connectError(){
    setGameState(GameState::NONE);
}

void MultiTetris::initGame(std::string name, unsigned width, unsigned height,
                           unsigned winScore, unsigned winLines, unsigned winTime,
                           unsigned level, bool winByScore, bool winByLines,
                           bool winByTime){
    Tetris::initGame(name, width, height, winScore, winLines, winTime, level,
                     winByScore, winByLines, winByTime);
    (mode_ == GameMode::SOLO)? ready_ = true : ready_ = false;
    if(mode_ == GameMode::CLIENT){
        QList<QString> args;
        args.append(QString::fromStdString("Joueur-2"));
        args.append(QString::number(getBoard().getWidth()));
        args.append(QString::number(getBoard().getHeight()));
        args.append(QString::number(getWinScore()));
        args.append(QString::number(getWinLines()));
        args.append(QString::number(getWinTime()));
        args.append(QString::number(getLevel()));
        args.append(QString::number(hasWinByScore()));
        args.append(QString::number(hasWinByLines()));
        args.append(QString::number(hasWinByTime()));
        NetMsg netMsg(NetMsg::MSG_FIRST, args);
        client_->sendData(netMsg);
    }
}

void MultiTetris::startGame(){
    if(getGameState() == GameState::INITIALIZED){
        generateBric(true);
        Tetris::resume();
    }
}

void MultiTetris::resume(){
    if(isPaused()){
        Tetris::resume();
        NetMsg netMsg(NetMsg::MSG_RESUME);
        if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
        if(mode_ == GameMode::HOST) server_->sendData(netMsg);
    }
}

void MultiTetris::pause(){
    if(!isPaused()){
        Tetris::pause();
        NetMsg netMsg(NetMsg::MSG_PAUSE);
        if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
        if(mode_ == GameMode::HOST) server_->sendData(netMsg);
    }
}

void MultiTetris::setGameState(GameState gameState){
    if(gameState > GameState::ON){
        QList<QString> args;
        args.append(QString::number(gameState*2));
        NetMsg netMsg(NetMsg::MSG_END, args);
        if(mode_ == GameMode::HOST){
            server_->sendData(netMsg);
        } else if(mode_ == GameMode::CLIENT){
            client_->sendData(netMsg);
        }
    }
    Tetris::setGameState(gameState);
}

void MultiTetris::endGame(int endState){
    Tetris::setGameState(static_cast<GameState>(endState));
}

unsigned MultiTetris::checkLines(unsigned top, unsigned dropsCount){
    unsigned linesFilled {Tetris::checkLines(top, dropsCount)};
    if((mode_ == GameMode::CLIENT || mode_ == GameMode::HOST) && linesFilled > 0){
        QList<QString> line;
        std::vector<unsigned> bricY = getCurrentBricY();
        for(unsigned u{0}; u < linesFilled; ++u){
            for(unsigned v{0}; v < getBoard().getWidth(); ++v){
                Position pos(v, bricY.at(u));
                if(!getCurrentBric().contains(pos)){
                    line.append(QString::number(v));
                }
            }
            line.append(QString::number(-1));
        }
        NetMsg netMsg(NetMsg::MSG_LINE, line);
        if(mode_ == GameMode::HOST) server_->sendData(netMsg);
        if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
    }
    return linesFilled;
}

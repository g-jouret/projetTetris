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

            /*NetMsg netMsg(NetMsg::ASK_GAME_SET);
                client_->sendData(netMsg);*/
        } catch(const QString & e){
            setMode(GameMode::UNCONNECTED);
            throw;
        }
    }
}

/* MultiTetris::getNotif() const{
    if(client_ == 0){
        return "";
    }
    return client_->getNotif();
}*/

/*void MultiTetris::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
    //server_->close();
    //connect(socket_, SIGNAL(destroyed(QObject*)), this, SLOT(disconnection()));
    //emit newClient();
}

void MultiTetris::disconnection(){
    std::cout << "déco du client" << std::endl;
    if(socket_ != qobject_cast<QTcpSocket *>(sender())) return;
    std::cout << "test" << std::endl;

    socket_->close();
    socket_ = 0;
    std::cout << "closed" << std::endl;
    setMode(true);
    std::cout << "client détruit" << std::endl;
}

void MultiTetris::dataReception(){
    if(socket_ != qobject_cast<QTcpSocket *>(sender())) return;

    QDataStream in(socket_);
    if(messageSize_ == 0){
        if(socket_->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> messageSize_;
    }
    if(socket_->bytesAvailable() < messageSize_) return;
    QString msg;
    in >> msg;

    std::cout << "server : " << msg.toStdString() << std::endl;

    NetMsg netMsg(msg);
    switch(netMsg.getHeader()){
    case NetMsg::MSG_FIRST:
        reactToFirstMsg(netMsg);
        //extern void MultiTetris::

        //QFuture<void> future = QtConcurrent::run(this->MultiTetris::reactToFirstMsg, netMsg);
        break;
    case NetMsg::ASK_GAME_SET:
        reactToAskSettings();
        //QFuture<void> future = QtConcurrent::run()
        break;
    case NetMsg::MSG_RDY:
        setReady();
        break;
    case NetMsg::MSG_CANCEL:
        break;
    default:
        // TODO : gestion des erreurs de réception de données
        break;
    }
    messageSize_ = 0;
}

void MultiTetris::reactToFirstMsg(NetMsg &netMsg){

    std::cout << netMsg.get(0).toStdString()
              << " "
              << netMsg.get(1).toInt()
              << std::endl;
    if(client_ == 0){
        client_ = new Client(*this);
    }
    QString ip(netMsg.get(0));
    QString host(getHostName(ip));
    std::cout << host.toStdString() << std::endl;
    try{
        client_->connectToServer(host, netMsg.get(1).toInt());
        //QFuture<void> future = QtConcurrent::run(this->client_, &Client::connectToServer, netMsg.get(0), netMsg.get(1).toInt());
        //future.waitForFinished();
        //QList<QString> args;
        //args.append(netMsg.get(1));
        NetMsg asw(NetMsg::ACK_FIRST);//, args);
        sendData(asw);

        NetMsg msg(NetMsg::ASK_GAME_SET);
        client_->sendData(msg);
        host_ = false;
        setMode(false);
    } catch(QString & e){
        NetMsg err(NetMsg::ERR_FIRST);
        sendData(err);
        std::cout << e.toStdString() << std::endl;
        // TODO : gestion des erreurs de réception de données
    }
}

void MultiTetris::reactToAskSettings(){
    // TODO : gestion Serialization pour briques perso
    QList<QString> args;
    args.append(QString::fromStdString(getPlayer().getName()));
    args.append(QString::number(getBoard().getWidth()));
    args.append(QString::number(getBoard().getHeight()));
    args.append(QString::number(getWinScore()));
    args.append(QString::number(getWinLines()));
    args.append(QString::number(getWinTime()));
    args.append(QString::number(getLevel()));
    args.append(QString::number(hasWinByScore()));
    args.append(QString::number(hasWinByLines()));
    args.append(QString::number(hasWinByTime()));
    NetMsg netMsg(NetMsg::ASW_GAME_SET, args);
    sendData(netMsg);
}*/

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
    std::cout << "reinit" << std::endl;
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
        std::cout << "multi resume" << std::endl;
        NetMsg netMsg(NetMsg::MSG_RESUME);
        if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
        if(mode_ == GameMode::HOST) server_->sendData(netMsg);
    }
}

void MultiTetris::pause(){
    if(!isPaused()){
        Tetris::pause();
        std::cout << "multi pause" << std::endl;
        NetMsg netMsg(NetMsg::MSG_PAUSE);
        if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
        if(mode_ == GameMode::HOST) server_->sendData(netMsg);
    }
}

void MultiTetris::setGameState(GameState gameState){
    std::cout << "multi setState" << std::endl;
    if(gameState > GameState::ON){
        QList<QString> args;
        args.append(QString::number(gameState*2));
        /*args.append(QString::number(getPlayer().getScore()));
        args.append(QString::number(getPlayer().getNbLines()));*/
        NetMsg netMsg(NetMsg::MSG_END, args);
        if(mode_ == GameMode::HOST){
            server_->sendData(netMsg);
        } else if(mode_ == GameMode::CLIENT){
            client_->sendData(netMsg);
        }
    }
    Tetris::setGameState(gameState);
}

void MultiTetris::endGame(int endState){//, int score, int nbLines){
    Tetris::setGameState(static_cast<GameState>(endState));
}

unsigned MultiTetris::checkLines(unsigned top, unsigned dropsCount){
    unsigned linesFilled {Tetris::checkLines(top, dropsCount)};
    if(mode_ == GameMode::CLIENT || mode_ == GameMode::HOST){
        QList<QString> line;
        for(unsigned u{0}; u < linesFilled; ++u){
            line.clear();
            for(unsigned v{0}; v < getBoard().getWidth(); ++v){
                Position pos(v, u);
                if(!getCurrentBric().contains(pos)){
                    line.append(QString::number(v));
                }
            }
            NetMsg netMsg(NetMsg::MSG_LINE, line);
            if(mode_ == GameMode::HOST) server_->sendData(netMsg);
            if(mode_ == GameMode::CLIENT) client_->sendData(netMsg);
        }
    }
    return linesFilled;
}

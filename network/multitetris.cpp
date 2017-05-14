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

/*bool MultiTetris::isListening() const{
    if(server_ == 0){
        return false;
    }
    return server_->isListening();
}*/

GameMode MultiTetris::getMode() const{
    return mode_;
}

bool MultiTetris::isReady() const {
    return ready_;
}

/*bool MultiTetris::isClientConnected() const{
    return client_->isConnected();
}*/

/*QString MultiTetris::serverError() const{
    return server_->errorString();
}

QString MultiTetris::clientError() const{
    return client_->errorString();
}*/

void MultiTetris::setMode(GameMode mode){
    mode_ = mode;
    ready_ = (mode_ == GameMode::SOLO);
    if((mode_ == GameMode::SOLO || mode_ == GameMode::HOST) && client_ != 0){
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
            setMode(GameMode::HOST);
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
                //QList<QString> args;
                /*args.append(getLocalIP());
                args.append(QString::number(server_->serverPort()));*/
// TODO : gestion Serialization pour briques perso
                /*args.append(QString::fromStdString(getPlayer().getName()));
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
                client_->sendData(netMsg);*/
                setMode(GameMode::CLIENT);

                /*NetMsg netMsg(NetMsg::ASK_GAME_SET);
                client_->sendData(netMsg);*/
        } catch(const QString & e){
            setMode(GameMode::HOST);
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

void MultiTetris::setGameState(GameState gameState){
    std::cout << "setgamestate"
              << (gameState == GameState::INITIALIZED)
              << std::endl;
    Tetris::setGameState(gameState);
    if(gameState == GameState::INITIALIZED && mode_ == GameMode::CLIENT){
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
        NetMsg netMsg(NetMsg::MSG_FIRST, args);
        client_->sendData(netMsg);
    }
}

/*void MultiTetris::sendData(const NetMsg &msg){
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);
    out << (quint16) 0;
    out << msg.to_QString();
    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));
    if(socket_->write(packet)==-1){
        throw socket_->errorString();
    }
}
*/


#include "server.h"
#include "multitetris.h"
#include "netmsg.h"
#include <stdexcept>
#include <iostream>

using namespace GJ_GW;

Server::Server(MultiTetris *game, QObject *parent) : QObject(parent), game_{game}{
    server_ = 0;
    socket_ = 0;
    messageSize_ = 0;
    //notification_ = "";
}

unsigned Server::serverPort() const{
    return server_->serverPort();
}

bool Server::isListening() const{
    if(server_ == 0){
        return false;
    }
    return server_->isListening();
}

void Server::launch(){
    close();
    server_ = new QTcpServer(this);
    socket_ = new QTcpSocket(this);
    unsigned port {49152};
    while(!server_->listen(QHostAddress(QHostInfo::localHostName()), port) && port <= 65535){
        ++port;
    }
    if(server_->isListening()){
        connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    } else{
        throw server_->errorString();
    }
}

void Server::close(){
    if(socket_ != 0){
        socket_->close();
        delete socket_;
        socket_ = 0;
    }
    if(server_ != 0){
        server_->close();
        delete server_;
        server_ = 0;
    }
    //notification_ = "";
    messageSize_ = 0;
}

void Server::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
}

void Server::disconnection(){
    std::cout << "déco du client" << std::endl;
    if(socket_ != qobject_cast<QTcpSocket *>(sender())) return;
    std::cout << "test" << std::endl;

    /*socket_->close();
    socket_ = 0;
    std::cout << "closed" << std::endl;*/
    close();
    std::cout << "client détruit" << std::endl;
}

void Server::sendData(const NetMsg &msg){
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

void Server::dataReception(){
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
        game_->setReady();
        break;
    case NetMsg::MSG_CANCEL:
        break;
    default:
        // TODO : gestion des erreurs de réception de données
        break;
    }
    messageSize_ = 0;
}

void Server::reactToFirstMsg(NetMsg &netMsg){
    QString ip(netMsg.get(0));
    QString host(game_->getHostName(ip));
    std::cout << host.toStdString() << std::endl;
    try{
        game_->initClient(host, netMsg.get(1).toInt(), false);
        //QFuture<void> future = QtConcurrent::run(this->client_, &Client::connectToServer, netMsg.get(0), netMsg.get(1).toInt());
        //future.waitForFinished();
        //QList<QString> args;
        //args.append(netMsg.get(1));
        NetMsg asw(NetMsg::ACK_FIRST);//, args);
        sendData(asw);

        /*NetMsg msg(NetMsg::ASK_GAME_SET);
        client_->sendData(msg);*/
        game_->setMode(GameMode::CLIENT);
    } catch(QString & e){
        NetMsg err(NetMsg::ERR_FIRST);
        sendData(err);
        std::cout << e.toStdString() << std::endl;
        // TODO : gestion des erreurs de réception de données
    }
}

void Server::reactToAskSettings(){
    // TODO : gestion Serialization pour briques perso
    QList<QString> args;
    args.append(QString::fromStdString(game_->getPlayer().getName()));
    args.append(QString::number(game_->getBoard().getWidth()));
    args.append(QString::number(game_->getBoard().getHeight()));
    args.append(QString::number(game_->getWinScore()));
    args.append(QString::number(game_->getWinLines()));
    args.append(QString::number(game_->getWinTime()));
    args.append(QString::number(game_->getLevel()));
    args.append(QString::number(game_->hasWinByScore()));
    args.append(QString::number(game_->hasWinByLines()));
    args.append(QString::number(game_->hasWinByTime()));
    NetMsg netMsg(NetMsg::ASW_GAME_SET, args);
    sendData(netMsg);
}

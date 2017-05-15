#include "server.h"
#include "multitetris.h"
#include "netmsg.h"
#include <stdexcept>
#include <iostream>
#include <QtConcurrent>

using namespace GJ_GW;

Server::Server(MultiTetris *game, QObject *parent) : QObject(parent), game_{game}{
    server_ = 0;
    socket_ = 0;
    messageSize_ = 0;
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
    messageSize_ = 0;
}

void Server::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
}

void Server::disconnection(){
    if(socket_ != qobject_cast<QTcpSocket *>(sender())) return;
    close();
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
    if(socket_ == qobject_cast<QTcpSocket *>(sender())) readData();
}

void Server::readData(){
    QDataStream in(socket_);
    if(messageSize_ == 0){
        if(socket_->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> messageSize_;
    }
    if(socket_->bytesAvailable() < messageSize_) return;
    QString msg;
    in >> msg;
    NetMsg netMsg(msg);
    switch(netMsg.getHeader()){
    case NetMsg::MSG_FIRST:
        reactToFirstMsg(netMsg);
        break;
    case NetMsg::MSG_RDY:
        game_->setReady();
        break;
    case NetMsg::MSG_CANCEL:
        game_->cancelGame();
        break;
    case NetMsg::MSG_LINE:
        game_->addLine(netMsg.getBody());
        break;
    case NetMsg::MSG_RESUME:
        game_->Tetris::resume();
        break;
    case NetMsg::MSG_PAUSE:
        game_->Tetris::pause();
        break;
    case NetMsg::MSG_END:
        game_->endGame(netMsg.get(0).toInt());
        break;
    default:
        break;
    }
    messageSize_ = 0;
}

void Server::reactToFirstMsg(NetMsg &netMsg){
    try{
        game_->initGame(netMsg.get(0).toStdString(), netMsg.get(1).toUInt(), netMsg.get(2).toUInt(),
                        netMsg.get(3).toUInt(), netMsg.get(4).toUInt(), netMsg.get(5).toUInt(),
                        netMsg.get(6).toUInt(), netMsg.get(7).toInt(),
                        netMsg.get(8).toInt(), netMsg.get(9).toInt());
        NetMsg netMsg(NetMsg::ACK_FIRST);
        sendData(netMsg);
        game_->setMode(GameMode::HOST);
    } catch(QString & e){
        NetMsg err(NetMsg::ERR_FIRST);
        sendData(err);
    }
}

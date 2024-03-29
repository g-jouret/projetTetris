#include "client.h"
#include "multitetris.h"
#include "netmsg.h"
#include <QtConcurrent>
#include <iostream>
#include <stdexcept>

using namespace GJ_GW;

Client::Client(MultiTetris *game, QObject *parent) : QObject(parent), game_{game}{
    socket_ = 0;
    messageSize_ = 0;
}

bool Client::isConnected() const{
    return socket_->state() == QAbstractSocket::ConnectedState;
}

void Client::launch(){
    close();
    socket_ = new QTcpSocket(this);
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(connected()), this, SLOT(connection()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
}

void Client::close(){
    if(socket_ != 0){
        socket_->close();
        delete socket_;
        socket_ = 0;
    }
    messageSize_ = 0;
}

void Client::connectToServer(QString hostName, unsigned port){
    close();
    launch();
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    connect(socket_, SIGNAL(connected()), &loop, SLOT(quit()));
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), &loop, SLOT(quit()));
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    socket_->connectToHost(hostName, port);
    timer.start(5000);
    loop.exec();
    if(!timer.isActive()){
        throw QString("connection timeout");
    }
    if(!isConnected()){
        throw socket_->errorString();
    }
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));
}

void Client::connection(){

}

void Client::disconnection(){
    if(socket_ != qobject_cast<QTcpSocket *>(sender())) return;
    close();
}

void Client::dataReception(){
    if(socket_ == qobject_cast<QTcpSocket *>(sender())) readData();
}

void Client::readData(){
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
    case NetMsg::ACK_FIRST:

        break;
    case NetMsg::ERR_FIRST:
        game_->connectError();
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

void Client::sendData(const NetMsg &msg){
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

void Client::socketError(){
    throw socket_->errorString();
}

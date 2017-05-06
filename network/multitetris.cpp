#include "multitetris.h"
#include <stdexcept>
#include <iostream>
#include "../view/mwtetris.h"

using namespace GJ_GW;

MultiTetris::MultiTetris() : Tetris(){
    server_ = new QTcpServer(this);
    socket_ = new QTcpSocket(this);
    unsigned port {49152};
    while(!server_->listen(QHostAddress(QHostInfo::localHostName()), port) && port <= 65535){
       ++port;
    }
    if(!server_->isListening()){
        closeServer(true);
    } else{
        connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    }
    messageSize_ = 0;
}

void MultiTetris::closeServer(bool soloMode){
    delete server_;
    server_ = 0;
    delete socket_;
    socket_ = 0;
    if(soloMode){
        client_.setSoloMode();
    }
}

QString MultiTetris::getHostName() const{
    return QHostInfo::localHostName();
}

quint16 MultiTetris::getPort() const {
    return server_->serverPort();
}

bool MultiTetris::isListening() const{
    return server_->isListening();
}

bool MultiTetris::isClientConnected() const{
    return client_.isConnected();
}

QString MultiTetris::serverError() const{
    return server_->errorString();
}

QString MultiTetris::clientError() const{
    return client_.errorString();
}

void MultiTetris::initClient(QString hostName, unsigned port){
    try{
        client_.connectToServer(hostName, port);
    } catch(const QString & e){
        throw;
    }
}



void MultiTetris::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));

}

void MultiTetris::disconnection(){
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0) return;
    socket->deleteLater();
}

void MultiTetris::dataReception(){
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0) return;
    QDataStream in(socket);
    if(messageSize_ == 0){
        if(socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> messageSize_;
    }
    if(socket->bytesAvailable() < messageSize_) return;
    QString message;
    in >> message;
    if(message.contains("FIRST")){
        QStringList connectData = message.split('|');
        client_.connectToServer(connectData.at(1), connectData.at(2).toInt());
        answerMessage("ACK");
    }
    messageSize_ = 0;
}

void MultiTetris::answerMessage(const QString &message){
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));
    socket_->write(packet);
}



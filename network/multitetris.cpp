#include "multitetris.h"
#include "netmsg.h"
#include "../view/mwtetris.h"
#include <stdexcept>
#include <iostream>
#include <QtConcurrent>

using namespace GJ_GW;

MultiTetris::MultiTetris() : Tetris(){
    /*server_ = new QTcpServer(this);
    socket_ = new QTcpSocket(this);
    unsigned port {49152};
    while(!server_->listen(QHostAddress(QHostInfo::localHostName()), port) && port <= 65535){
       ++port;
    }
    if(!server_->isListening()){
        closeServer(true);
    } else{
        connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    }*/
    server_ = 0;
    socket_ = 0;
    client_ = 0;
    ready_ = false;
    host_ = true;
    messageSize_ = 0;
}

void MultiTetris::closeServer(bool soloMode){
    ready_ = soloMode;
    delete server_;
    server_ = 0;
    delete socket_;
    socket_ = 0;
    if(soloMode){
        delete client_;
        client_ = 0;
    }
}

void MultiTetris::launchServer(){
    if(server_ == 0){
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
    }
}

QString MultiTetris::getHostName() const{
    QHostInfo hostInfo {QHostInfo::fromName(getIP())};
    return hostInfo.hostName();
}

QString MultiTetris::getIP() const{
    QHostInfo hostInfo {QHostInfo::fromName(QHostInfo::localHostName())};
    return hostInfo.addresses().first().toString();
}

quint16 MultiTetris::getPort() const {
    return server_->serverPort();
}

bool MultiTetris::isListening() const{
    if(server_ == 0){
        return false;
    }
    return server_->isListening();
}

bool MultiTetris::isReady() const {
    return ready_;
}

bool MultiTetris::isClientConnected() const{
    return client_->isConnected();
}

QString MultiTetris::serverError() const{
    return server_->errorString();
}

QString MultiTetris::clientError() const{
    return client_->errorString();
}

void MultiTetris::initClient(QString hostName, unsigned port){
    if(client_ == 0){
        client_ = new Client(*this);
    try{
        client_->connectToServer(hostName, port);
        QList<QString> args;
        //args.append(QHostInfo::localHostName());
        args.append(getIP());
        args.append(QString::number(server_->serverPort()));
        NetMsg msg(NetMsg::MSG_FIRST, args);
        client_->sendData(msg);
    } catch(const QString & e){
        throw;
    }
    }
}

QString MultiTetris::getClientNotif() const{
    return client_->getNotif();
}

void MultiTetris::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
    //emit newClient();
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
    try{
        //client_->connectToServer(netMsg.get(0), netMsg.get(1).toInt());
        QFuture<void> future = QtConcurrent::run(this->client_, &Client::connectToServer, netMsg.get(0), netMsg.get(1).toInt());
        future.waitForFinished();
        //QList<QString> args;
        //args.append(netMsg.get(1));
        NetMsg asw(NetMsg::ACK_FIRST);//, args);
        sendData(asw);

        NetMsg msg(NetMsg::ASK_GAME_SET);
        client_->sendData(msg);
    } catch(QString & e){
        std::cout << "erreur" << std::endl;
        // TODO : gestion des erreurs de réception de données
    }
    host_ = false;
    closeServer(false);
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
}

void MultiTetris::sendReady(){

}

void MultiTetris::sendCancel(){

}

void MultiTetris::sendData(const NetMsg &msg){
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



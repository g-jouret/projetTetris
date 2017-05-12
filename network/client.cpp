#include "client.h"
#include "netmsg.h"
#include <iostream>
#include <stdexcept>
using namespace GJ_GW;

Client::Client() : QObject(){
    socket_ = 0;
    notification_ = "";
    messageSize_ = 0;
    connected_ = 0;
}

QString Client::getNotif() const{
    return notification_;
}

bool Client::isConnected() const{
    return connected_;
}

void Client::reset(){
    delete socket_;
    socket_ = 0;
}

void Client::launchClient(){
    if(socket_ == 0){
        socket_ = new QTcpSocket(this);
        connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
        connect(socket_, SIGNAL(connected()), this, SLOT(connection()));
    }
}

QString Client::errorString() const{
    return socket_->errorString();
}

void Client::connectToServer(QString hostName, unsigned port){
    reset();
    launchClient();
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
    connected_ = 1;
    notification_ = "connexion effectuée";
}

void Client::disconnection(){
    connected_ = 0;
    notification_ = "déconnexion effectuée";
}

void Client::dataReception(){
    QDataStream in(socket_);
    if(messageSize_ == 0){
        if(socket_->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> messageSize_;
    }
    if(socket_->bytesAvailable() < messageSize_) return;
    QString msg;
    in >> msg;

    std::cout << "client : " << msg.toStdString() << std::endl;

    NetMsg netMsg(msg);
    if(netMsg.getHeader() == NetMsg::ACK_FIRST){
        socket_->disconnectFromHost();
        reset();
        //connectToServer("127.0.0.1", netMsg.get(0).toInt());
    }
    messageSize_ = 0;
}

void Client::sendMessage(const NetMsg &msg){
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

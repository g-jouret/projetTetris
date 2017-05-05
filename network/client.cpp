#include "client.h"
#include <iostream>
#include <stdexcept>
using namespace GJ_GW;

Client::Client() : QObject(){
    socket_ = new QTcpSocket(this);
    //connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(connected()), this, SLOT(connection()));
    //connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));*/
    messageSize_ = 0;
}

bool Client::isConnected() const{
    return socket_->isValid();
}

void Client::setSoloMode(){
    delete socket_;
    socket_ = 0;
}

QString Client::errorString() const{
    return socket_->errorString();
}

void Client::connectToServer(QString hostName, unsigned port){
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    connect(socket_, SIGNAL(connected()), &loop, SLOT(quit()));
    //disconnect(socket_,SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), &loop, SLOT(quit()));
    //connect(socket_, SIGNAL(stateChanged(QAbstractSocket::SocketState)), &loop, SLOT(quit()));
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    socket_->connectToHost(hostName, port);
    timer.start(3000);
    loop.exec();
    //disconnect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), &loop, SLOT(quit()));
    //connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));
    if(!timer.isActive()){
        throw QString("connection timeout");
    }
    /*if(socket_->waitForConnected(1000))
        socket_->error();*/
}

void Client::connection(){
    std::cout << "co" << std::endl;
}

void Client::dataReception(){
    QDataStream in(socket_);
    if(messageSize_ == 0){
        if(socket_->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> messageSize_;
    }
    if(socket_->bytesAvailable() < messageSize_) return;
    QString message;
    in >> message;
    if(message == "ACK"){

    }
    messageSize_ = 0;
}

void Client::sendMessage(const QString &message){
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);
    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));
    socket_->write(packet);

}

/*void Client::connection(){
    if(isHostClient_){
        QString msg = "FIRST|"+QHostInfo::localHostName()+'|'+serverPort_;
        sendMessage(msg);
    }

}

void Client::disconnection(){

}*/

void Client::socketError(){
    throw socket_->errorString();
}

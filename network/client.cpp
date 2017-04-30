#include "client.h"

using namespace GJ_GW;

Client::Client(QString hostName, unsigned port, QWidget *parent, bool firstUse) : QWidget(parent){
    socket_ = new QTcpSocket(this);
    socket_->connectToHost(hostName, port);
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    //connect(socket_, SIGNAL(connected()), this, SLOT(connection()));
    //connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
    //connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    if(firstUse){
        sendMessage("first");
    }

    messageSize_ = 0;
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

    // TODO : implementer réaction au message

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

}*/

void Client::disconnection(){

}

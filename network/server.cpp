#include "server.h"
#include <stdexcept>

using namespace GJ_GW;

Server::Server(QWidget *parent) : QWidget(parent){
    server_ = new QTcpServer(this);
    unsigned port {49152};
    while(!server_->listen(QHostAddress(QHostInfo::localHostName()), port) && port <= 65535){
       ++port;
    }
    if(!server_->isListening()){
        throw std::exception();
    }
    connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    messageSize_ = 0;
}

void Server::connection(){
    socket_ = server_->nextPendingConnection();
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnection()));
}

void Server::disconnection(){
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0) return;
    socket->deleteLater();
}

void Server::dataReception(){
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

    answerMessage(message);
    messageSize_ = 0;
}

void Server::answerMessage(const QString &message){
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));
    socket_->write(packet);
}

QString Server::getHostName() const{
    return QHostInfo::localHostName();
}

quint16 Server::getPort() const {
    return server_->serverPort();
}

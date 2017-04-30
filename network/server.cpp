#include "server.h"
#include <stdexcept>

using namespace GJ_GW;

Server::Server(QWidget *parent, QString hostName, unsigned port) : QWidget(parent){
    server_ = new QTcpServer(this);
    if(hostName.isEmpty() && port == 0){
        hostName = QHostInfo::localHostName();
        port = 49200;
    }
    if(!server_->listen(QHostAddress(hostName), 49200)){
        throw std::exception();
    } else{
       connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    }
    messageSize_ = 0;
}

void Server::connection(){
    client_ = server_->nextPendingConnection();

    connect(client_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(client_, SIGNAL(disconnected()), this, SLOT(disconnection()));
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

    sendMessage(message);
    messageSize_ = 0;
}

void Server::sendMessage(const QString &message){
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));
    client_->write(packet);
}

QString Server::getHostName() const{
    return QHostInfo::localHostName();
}

quint16 Server::getPort() const {
    return server_->serverPort();
}

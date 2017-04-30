#include "server.h"
#include <stdexcept>

using namespace GJ_GW;

Server::Server(QWidget *parent/*, QString hostName, unsigned port*/) : QWidget(parent){
    server_ = new QTcpServer(this);
    /*if(hostName.isEmpty() && port == 0){
        hostName = QHostInfo::localHostName();
        port = 49200;
    }*/
    // TODO : implémentation recherche port libre si par défaut occupé
    if(!server_->listen(QHostAddress(QHostInfo::localHostName()), 49200)){
        throw std::exception();
    } else{
        connect(server_, SIGNAL(newConnection()), this, SLOT(connection()));
    }
    messageSize_ = 0;
}

void Server::connection(){
    socket_ = server_->nextPendingConnection();
    //client_ = new Client(this, socket_->peerName(), socket_->peerPort());
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

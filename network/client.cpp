#include "client.h"
#include "multitetris.h"
#include "netmsg.h"
#include <iostream>
#include <stdexcept>

using namespace GJ_GW;

Client::Client(MultiTetris &game) : QObject(), game_{game}{
    socket_ = 0;
    notification_ = "";
    messageSize_ = 0;
    connected_ = 0;
    game_.addObserver(this);
}

/*Client::~Client(){
    game_.removeObserver(this);
    delete socket_;
}*/

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
        //connect(socket_, SIGNAL(destroyed(QObject*)), this, SLOT(disconnection()));
    }
}

QString Client::errorString() const{
    return socket_->errorString();
}

void Client::connectToServer(QString hostName, unsigned port){
    std::cout << "try to connect" << std::endl;
    reset();
    std::cout << "reset" << std::endl;
    launchClient();
    std::cout << "launch" << std::endl;
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    connect(socket_, SIGNAL(connected()), &loop, SLOT(quit()));
    //connect(socket_, SIGNAL(destroyed(QObject*)), &loop, SLOT(quit()));
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
    std::cout << "connected" << std::endl;
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

    switch(netMsg.getHeader()){
    case NetMsg::ACK_FIRST:
        reactToFirstAck();
        break;
    case NetMsg::ERR_FIRST:
        notification_ = "Impossible de se connecter à l'hôte";
        game_.connectError();
        break;
    case NetMsg::ASW_GAME_SET:
        reactToAswSettings(netMsg);
        break;
    case NetMsg::MSG_RDY:
        game_.setReady();
        break;
    case NetMsg::MSG_CANCEL:
        break;
    default:
        // TODO : gestion des erreurs de réception de données
        break;
    }
    messageSize_ = 0;
}

void Client::reactToFirstAck(){
    socket_->close();
    reset();
    //connectToServer("127.0.0.1", netMsg.get(0).toInt());
}

void Client::reactToAswSettings(NetMsg &netMsg){
    // TODO : gestion erreur bad_init | invalid_argument de Tetris
    game_.initGame(netMsg.get(0).toStdString(), netMsg.get(1).toUInt(), netMsg.get(2).toUInt(),
                    netMsg.get(3).toUInt(), netMsg.get(4).toUInt(), netMsg.get(5).toUInt(),
                    netMsg.get(6).toUInt(), netMsg.get(7).toInt(),
                    netMsg.get(8).toInt(), netMsg.get(9).toInt());
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

void Client::update(Subject *){

}

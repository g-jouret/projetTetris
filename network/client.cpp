#include "client.h"
#include "multitetris.h"
#include "netmsg.h"
#include <QtConcurrent>
#include <iostream>
#include <stdexcept>

using namespace GJ_GW;

Client::Client(MultiTetris *game, QObject *parent) : QObject(parent), game_{game}{
    socket_ = 0;
    //notification_ = "";
    messageSize_ = 0;
    //connected_ = 0;
}

/*QString Client::getNotif() const{
    return notification_;
}*/

bool Client::isConnected() const{
    return socket_->state() == QAbstractSocket::ConnectedState;
}

void Client::launch(){
    close();
    socket_ = new QTcpSocket(this);
    connect(socket_, SIGNAL(readyRead()), this, SLOT(dataReception()));
    connect(socket_, SIGNAL(connected()), this, SLOT(connection()));
    //connect(socket_, SIGNAL(destroyed(QObject*)), this, SLOT(disconnection()));
}

void Client::close(){
    if(socket_ != 0){
        socket_->close();
        delete socket_;
        socket_ = 0;
    }
    //notification_ = "";
    messageSize_ = 0;
    //connected_ = 0;
}

/*QString Client::errorString() const{
    return socket_->errorString();
}*/

void Client::connectToServer(QString hostName, unsigned port){
    std::cout << "try to connect" << std::endl;
    close();
    std::cout << "reset" << std::endl;
    launch();
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
    //connected_ = 1;
    //notification_ = "connexion effectuée";
}

void Client::disconnection(){
    //connected_ = 0;
    //notification_ = "déconnexion effectuée";
}

void Client::dataReception(){
    if(socket_ == qobject_cast<QTcpSocket *>(sender())) readData();
        /*QFuture<void> future = QtConcurrent::run(this, &Client::readData);
        future.waitForFinished();*/
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

    std::cout << "client : " << msg.toStdString() << std::endl;

    NetMsg netMsg(msg);
    switch(netMsg.getHeader()){
    case NetMsg::ACK_FIRST:

        break;
    case NetMsg::ERR_FIRST:
        //notification_ = "Impossible de se connecter à l'hôte";
        game_->connectError();
        break;
    //case NetMsg::ASK_GAME_SET:

        /*game_->initGame(netMsg.get(0).toStdString(), netMsg.get(1).toUInt(), netMsg.get(2).toUInt(),
                       netMsg.get(3).toUInt(), netMsg.get(4).toUInt(), netMsg.get(5).toUInt(),
                       netMsg.get(6).toUInt(), netMsg.get(7).toInt(),
                       netMsg.get(8).toInt(), netMsg.get(9).toInt());*/
        //break;
    case NetMsg::MSG_RDY:
        game_->setReady();
        break;
    case NetMsg::MSG_CANCEL:
        break;
    case NetMsg::MSG_RESUME:
        game_->Tetris::resume();
        break;
    case NetMsg::MSG_PAUSE:
        game_->Tetris::pause();
        break;
    case NetMsg::MSG_END:
        game_->endGame(netMsg.get(0).toInt(), netMsg.get(1).toInt(), netMsg.get(2).toInt());
        break;
    default:
        // TODO : gestion des erreurs de réception de données
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

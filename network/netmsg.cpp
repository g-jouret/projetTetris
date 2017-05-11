#include "netmsg.h"
#include <stdexcept>

using namespace GJ_GW;

//NetMsg::NetMsg():QObject(){}

NetMsg::NetMsg(const QString &msg):QObject(){
    QStringList listMsg = msg.split('|');
    msgHeader_ = static_cast<Header>(listMsg.takeFirst().toInt());
    msgBody_ = listMsg;
}

NetMsg::NetMsg(Header header, QList<QString> &listMsg): QObject(),
    msgHeader_{header}, msgBody_{listMsg}{}

NetMsg::Header NetMsg::getHeader() const{
    //return static_cast<Header>(at(0).toInt());
    return msgHeader_;
}

QString NetMsg::get(int index) const{
    if(msgBody_.size() >= index){
        throw std::out_of_range("Le message ne contient pas autant d'arguments");
    }
    return msgBody_.at(index);
}

/*unsigned NetMsg::sizeMsg() const{
    return msgBody_.size();
}*/

QString NetMsg::to_QString() const{
    QString out(msgHeader_+'|');
    out.append(msgBody_.join('|'));
    return out;
}

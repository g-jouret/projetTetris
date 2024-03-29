#include "netmsg.h"
#include <stdexcept>

using namespace GJ_GW;

NetMsg::NetMsg(const QString &msg):QObject(){
    QStringList listMsg = msg.split('|');
    bool noExcept;
    int head = listMsg.takeFirst().toInt(&noExcept, 10);
    msgHeader_ = static_cast<Header>(head);
    msgBody_ = listMsg;
}

NetMsg::NetMsg(Header msgHeader): QObject(), msgHeader_{msgHeader}{}

NetMsg::NetMsg(Header header, QList<QString> &listMsg): QObject(),
    msgHeader_{header}, msgBody_{listMsg}{}

NetMsg::Header NetMsg::getHeader() const{
    return msgHeader_;
}

QList<QString> NetMsg::getBody() const{
    return msgBody_;
}

QString NetMsg::get(int index) const{
    if(msgBody_.size() <= index){
        throw std::out_of_range("Le message ne contient pas autant d'arguments");
    }
    return msgBody_.at(index);
}

QString NetMsg::to_QString() const{
    int head = msgHeader_;
    QString out;
    out.append(QString::number(head));
    out.append('|');
    out.append(msgBody_.join('|'));
    return out;
}

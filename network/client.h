#ifndef CLIENT_H
#define CLIENT_H

#include "../observer/observer.h"
#include <QObject>
#include <QtNetwork>
#include <QString>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class MultiTetris;
class NetMsg;

class Client : public QObject, public Observer{

    Q_OBJECT
    MultiTetris &game_;
    QTcpSocket *socket_;
    QString notification_;
    quint16 messageSize_;
    bool connected_;

public:
    explicit Client(MultiTetris &game);
    //~Client();
    void sendData(const NetMsg &msg);
    void launchClient();
    void connectToServer(QString hostName, unsigned port);
    QString getNotif() const;
    bool isConnected() const;
    void reset();
    QString errorString() const;
    void update(Subject *);

private:
    void reactToFirstAck();
    void reactToAswSettings(NetMsg &netMsg);

private slots:
    void connection();
    void disconnection();
    void dataReception();
    void socketError();
};

} // namespace GJ_GW

#endif // CLIENT_H

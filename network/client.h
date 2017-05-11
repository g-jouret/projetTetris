#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QString>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class NetMsg;

class Client : public QObject{

    Q_OBJECT
    QTcpSocket *socket_;
    QString notification_;
    quint16 messageSize_;
    bool connected_;

public:
    explicit Client();
    void sendMessage(const NetMsg &msg);
    void connectToServer(QString hostName, unsigned port);
    QString getNotif() const;
    bool isConnected() const;
    void setSoloMode();
    QString errorString() const;

private slots:
    void connection();
    void disconnection();
    void dataReception();
    void socketError();
};

} // namespace GJ_GW

#endif // CLIENT_H

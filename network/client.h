#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QString>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class MultiTetris;
class NetMsg;

class Client : public QObject{

    Q_OBJECT
    MultiTetris *game_;
    QTcpSocket *socket_;
    quint16 messageSize_;

public:
    explicit Client(MultiTetris *game, QObject *parent = 0);
    void sendData(const NetMsg &msg);
    void launch();
    void connectToServer(QString hostName, unsigned port);
    bool isConnected() const;
    void close();

private:
    void readData();

private slots:
    void connection();
    void disconnection();
    void dataReception();
    void socketError();
};

} // namespace GJ_GW

#endif // CLIENT_H

#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QString>
/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW {

class MultiTetris;
class NetMsg;

class Server : public QObject{

    Q_OBJECT
    MultiTetris *game_;
    QTcpServer *server_;
    QTcpSocket *socket_;
    quint16 messageSize_;

public:
    explicit Server(MultiTetris *game, QObject *parent = 0);
    unsigned serverPort() const;
    bool isListening() const;
    void launch();
    void close();
    void sendData(const NetMsg &msg);

private:
    void reactToFirstMsg(NetMsg &netMsg);
    void readData();

private slots:
    void dataReception();
    void connection();
    void disconnection();
};

} // namespace GJ_GW

#endif // SERVER_H

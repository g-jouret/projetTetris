#ifndef SERVER_H
#define SERVER_H

#include "../model/tetris.h"
#include "client.h"
#include <QtNetwork>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class NetMsg;

class MultiTetris : public Tetris{
    Q_OBJECT
    QTcpServer *server_;
    QTcpSocket *socket_;
    Client *client_;
    quint16 messageSize_;
    bool host_;
    bool ready_;

public:
    explicit MultiTetris();
    QString getHostName() const;
    QString getIP() const;
    quint16 getPort() const;
    bool isListening() const;
    bool isReady() const;
    void closeServer(bool soloMode);
    void launchServer();
    void initClient(QString hostName, unsigned port);

    QString getClientNotif() const;
    bool isClientConnected() const;
    QString clientError() const;

    void sendReady();
    void sendCancel();
    QString serverError() const;

private:
    void sendData(const NetMsg &msg);
    void reactToFirstMsg(NetMsg &netMsg);
    void reactToAskSettings();

//signals:
    //void newClient();

private slots:
    void connection();
    void disconnection();
    void dataReception();
};

} // namespace GJ_GW

#endif // SERVER_H

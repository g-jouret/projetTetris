#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class Client : public QObject{

    Q_OBJECT
    QTcpSocket *socket_;
    quint16 messageSize_;

public:
    explicit Client();
    void sendMessage(const QString &message);
    void connectToServer(QString hostName, unsigned port);
    bool isConnected() const;
    void setSoloMode();
    QString errorString() const;

private slots:
    void connection();
    //void disconnection();
    void dataReception();
    void socketError();
};

} // namespace GJ_GW

#endif // CLIENT_H

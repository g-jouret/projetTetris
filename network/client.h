#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtNetwork>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class Client : public QWidget{

    Q_OBJECT
    QTcpSocket *socket_;
    quint16 messageSize_;

public:
    explicit Client(QString hostName, unsigned port, QWidget *parent = 0, bool firstUse = 0);
    //void connection();
    void sendMessage(const QString &message);
    void disconnection();

private slots:
    //void connection();
    //void disconnection();
    void dataReception();
};

} // namespace GJ_GW

#endif // CLIENT_H

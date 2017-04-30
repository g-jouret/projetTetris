#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class Server : public QWidget
{
    Q_OBJECT
    QTcpServer *server_;
    QTcpSocket *socket_;
    quint16 messageSize_;

public:
    explicit Server(QWidget *parent = 0/*, QString hostName = "", unsigned port = 0*/);
    QString getHostName() const;
    quint16 getPort() const;
    void answerMessage(const QString &message);

private slots:
    void connection();
    void disconnection();
    void dataReception();
};

} // namespace GJ_GW

#endif // SERVER_H

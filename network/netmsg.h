#ifndef NETMSGHEADERS_H
#define NETMSGHEADERS_H

#include <QObject>
#include <QString>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant les messages entre client et serveur.
 */
class NetMsg : public QObject{
public:
    /*!
     * \brief Énumération fortement typée pour représenter les entêtes des messages
     * entre client et serveur.
     */
    enum Header{
        /*! Entête du message indiquant que l'émetteur est l'hôte de la partie. */
        MSG_FIRST,
        /*! Entête de la confirmation de réception du premier message. */
        ACK_FIRST,
        /*! Entête du message contenant les paramètres de la partie. */
        MSG_GAME_SET,
        /*! Entête de la confirmation de réception du message de paramètrage. */
        ACK_GAME_SET
    };

private:
    Q_OBJECT
    NetMsg::Header msgHeader_;
    QStringList msgBody_;

public:

    //NetMsg();
    NetMsg(const QString &msg);
    NetMsg(Header msgHeader, QList<QString> &msgBody);
    Header getHeader() const;
    QString get(int index) const;
    //unsigned sizeMsg() const;
    QString to_QString() const;
};


} // namespace GJ_GW

#endif // NETMSGHEADERS_H

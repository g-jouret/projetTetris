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
        /*! Entête du message d'erreur indiquant un problème de connexion à l'hôte. */
        ERR_FIRST,
        /*! Entête du message demandant les paramètres de la partie. */
        ASK_GAME_SET,
        /*! Entête de la réponse contenant les paramètres de la partie. */
        ASW_GAME_SET,
        /*! Entête du message indiquant que l'émetteur est prêt à commencer la partie. */
        MSG_RDY,
        /*! Entête du message indiquant que l'émetteur souhaite annuler la partie. */
        MSG_CANCEL,
    };

private:
    Q_OBJECT
    Header msgHeader_;
    QStringList msgBody_;

public:
    NetMsg(const QString &msg);
    NetMsg(Header msgHeader);
    NetMsg(Header msgHeader, QList<QString> &msgBody);
    Header getHeader() const;
    QString get(int index) const;
    QString to_QString() const;
};


} // namespace GJ_GW

#endif // NETMSGHEADERS_H

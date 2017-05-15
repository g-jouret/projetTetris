#ifndef GAMEMODE_H
#define GAMEMODE_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Énumération fortement typée pour représenter les modes de jeu existant.
 */
enum class GameMode{
    /*! Représente le mode un joueur. */
    SOLO,
    /*! Représente le mode deux joueurs dont vous êtes l'hôte. */
    HOST,
    /*! Représente le mode deux joueurs dont vous êtes le client. */
    CLIENT,
    /*! Réprésente le mode où le serveur cherche un client. */
    UNCONNECTED
};

} // namespace GJ_GW

#endif // GAMEMODE_H

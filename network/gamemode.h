#ifndef GAMEMODE_H
#define GAMEMODE_H

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
    UNCONNECTED
};

#endif // GAMEMODE_H

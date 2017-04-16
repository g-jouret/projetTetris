#ifndef GAMESTATE_H
#define GAMESTATE_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Énumération fortement typée pour représenter l'état d'une ligne de la grille de jeu.
 */
enum class GameState{
    /*! Représente le moment où la partie n'a pas encore commencé */
    NONE,
    /*! Représente une partie en cours */
    ON,
    /*! Représente la perte de la partie. */
    LOOSE,
    /*! Représente une victoire par le score. */
    SCORE,
    /*! Représente une victoire grâce au nombre de ligne faite. */
    LINE,
    /*! Représente une victoire grâce au temps rester dans la partie sans perdre */
    TIME
};

} // namespace GJ_GW

#endif // GAMESTATE_H

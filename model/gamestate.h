#ifndef GAMESTATE_H
#define GAMESTATE_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Énumération pour représenter l'état d'une ligne de la grille de jeu.
 */
enum GameState{
    /*! Représente le moment où la partie n'a pas encore commencé */
    NONE,
    /*! Représente le moment où la partie est sur le point de commencer */
    INITIALIZED,
    /*! Représente le moment où une nouvelle brique est générée dans la grille*/
    NEW_BRIC,
    /*! Représente une partie en cours */
    ON,
    /*! Représente la perte de la partie. */
    LOOSE,
    /*! Représente une victoire par le score. */
    SCORE,
    /*! Représente une victoire grâce au nombre de ligne faite. */
    LINE,
    /*! Représente une victoire grâce au temps rester dans la partie sans perdre */
    TIME,
    /*! Représente la perte de la partie par votre adversaire. */
    OTHER_LOOSE = LOOSE*2,
    /*! Représente une victoire par le score de votre adversaire. */
    OTHER_SCORE = SCORE*2,
    /*! Représente une victoire grâce au nombre de ligne faite par votre adversaire. */
    OTHER_LINE = LINE*2
};

} // namespace GJ_GW

#endif // GAMESTATE_H

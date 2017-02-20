#ifndef GAME_H
#define GAME_H

#include <vector>
#include "board.h"
#include "player.h"

/*! \mainpage Une classe pour représenter les paramètres du jeu
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref g40853.
 *
 */

/*!
 * \brief Espace de nom de Guillaume Jouret.
 */
namespace g40853{

/*!
 * \brief Classe déterminant le fonctionnement d'une partie de Tetris.
 */
class Game
{
    // TODO : game contient les options du timer (approche itérative), les vérifications de victoire, les étapes du jeu et autres paramétrages
public:
    constexpr static unsigned MINIMUM_TIMER {100};
    /*!< Valeur minimale acceptée pour le timer. */
    constexpr static unsigned MAXIMUM_TIMER {500};
    /*!< Valeur maximale acceptée pour le timer. */

private:
    unsigned level_;
    /*!< Le niveau de difficulté.
     *
     * Il représente l'accroissement de la difficulté du jeu au fur et à mesure de la partie, il augmente en fonction du score.
     */

    unsigned timer_;
    /*!< Le timer.
     *
     * Il représente le temps entre chaque mouvement de brique, il se réduit en fonction du niveau de difficulté.
     *
     * Sa valeur est en milliseconde et peut aller de \ref MINIMUM_TIMER à \ref MAXIMUM_MONTH.
     */

    Board board_;
    /*!< La grille de jeu. */

    std::vector<Player> players_;
    /*!< Les joueurs. */

    // TODO : mode de jeu, condition de victoire

    /* NOTE : option possible
    unsigned step_;
    /*!< L'étape en cours.
     *
     * Il y a 3 étapes dans le déroulement d'une itération :
     *  - le tirage d'une nouvelle brique courante ;
     *  - la chute de la brique courante ;
     *  - l'arrêt de la brique courante et la résolution du nouvel état de la grille.
     */

public:

    /*!
     * \brief Constructeur sans argument de \ref Game.
     */
    Game();

    /*!
     * \brief Destructeur de \ref Game.
     */
    ~Game();

private:
    unsigned validateTimer(unsigned);

};

//implémentations inline

//fonctions inline

//méthodes inline

}

#endif // GAME_H

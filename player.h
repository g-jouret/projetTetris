#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"
#include "bricsBag.h"

/*! \mainpage Une classe pour représenter un joueur
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
 * \brief Classe représentant un joueur.
 */
class Player{

    std::string name_;
    /*!< Le nom du joueur. */

    unsigned score_;
    /*!< le score du joueur.
     *
     * Augmente au fur et à mesure que le joueur rempli des lignes de la grille.
     */

    Board board_;

    BricsBag bag_;

public:

    /*!
     * \brief Constructeur sans argument de \ref Player.
     *
     * Le nom du joueur est remplacé par un numéro.
     */
    // NOTE : sans doute inutile : valeur par défaut peut-être initialisée lors de la construction, plus efficace puisque numéro
    //Player();

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur.
     */
    Player(std::string name, unsigned width, unsigned height, std::vector<Bric> brics);
    // WARNING DB : lié à l'initialisation par DEFAULT_BRICS
    //Player(std::string name, unsigned width, unsigned height, std::vector<unsigned> brics);

    /*!
     * \brief Destructeur de \ref Player.
     */
    // TODO : ~Player();

    /*!
     * \brief Accesseur en lecture du nom du joueur.
     *
     * \return le nom du joueur
     */
    inline std::string getName();

    /*!
     * \brief Accesseur en lecture du score du joueur.
     *
     * \return le score du joueur
     */
    inline unsigned getScore();

    void checkLines();
};

//implémentations inline

//fonctions inline

//méthodes inline
std::string Player::getName(){
    return name_;
}

unsigned Player::getScore(){
    return score_;
}

}

#endif // PLAYER_H

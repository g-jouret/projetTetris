#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ostream>
#include <iomanip>
#include "board.h"
#include "bric.h"
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
    /*!< Le score du joueur.
     *
     * Augmente au fur et à mesure que le joueur rempli des lignes de la grille.
     */

    Board board_;
    /*!< La grille de jeu du joueur. */

    BricsBag bag_;
    /*!< Le sac de briques du joueur. */

    Bric currentBric_;
    /*!< TODO */

    unsigned nbLine_;
    /*!< TODO */

public:

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     * \param brics les briques à mettre dans le sac
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

    /*! TODO
     * \brief
     * \return
     */
    inline Bric getCurrentBric();

    /*! TODO
     * \brief
     * \return
     */
    inline Board getBoard();

    /*! TODO
     * \brief getNbLine
     */
    inline unsigned getNbLine();

    /*!
     * \brief Méthode vérifiant que des lignes ont été remplies.
     *
     * Augmente le score du joueur si c'est le cas.
     */
    void checkLines();

    /*! TODO
     * \brief rotateBric
     */
    void rotateBric();

    // NOTE : sert aussi à générer la nouvelle brique?
    /*! TODO
     * \brief
     */
    void moveBric();

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Player & in);
};
//prototypes
std::ostream & operator<<(std::ostream & out, const Player & in);
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

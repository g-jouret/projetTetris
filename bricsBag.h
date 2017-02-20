#ifndef BRICSBAG_H
#define BRICSBAG_H

#include <vector>
#include "bric.h"

/*! \mainpage Une classe pour représenter le sac de briques
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref g40853.
 *
 */

/*!
 * \brief Espace de nom de Guillaume Jouret.
 */
namespace g40853{

// TODO : forme : I, O, T, L, J, S, Z

/*!
 * \brief Classe représentant le sac de briques générée pour jouer.
 */
class BricsBag{
    std::vector<Bric> brics_;
    /*!< Les briques contenue dans le sac.
     *
     * Représente l'ensemble des briques utilisables en jeu.
     */

public:

    /*!
     * \brief Constructeur sans argument de \ref BricsBag.
     */
    BricsBag();

    /*!
     * \brief Destructeur de \ref BricsBag.
     */
    ~BricsBag();

    /*!
     * \brief Accesseur en lecture du sac de briques.
     *
     * \return le sac de briques
     */
    inline std::vector<Bric> getBrics();

    /*!
     * \brief Méthode permettant de tirer la prochaine brique du sac.
     *
     * \return la brique au sommet du sac
     */
    inline Bric getNextBric();

    /*!
     * \brief Méthode mélangeant les briques dans le sac.
     */
    void rearrange();
};

//implémentations inline

//fonctions inline

//méthodes inline
std::vector<Bric> BricsBag::getBrics(){
    return brics_;
}

Bric BricsBag::getNextBric(){
    return brics_.at(0);
}

}

#endif // BRICSBAG_H

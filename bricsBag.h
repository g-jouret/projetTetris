#ifndef BRICSBAG_H
#define BRICSBAG_H

#include <vector>
#include "bric.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant le sac de briques générée pour jouer.
 */
class BricsBag{

    // NOTE : peut-être mieux une map ou un set : brique retrouvables par clé?
    std::vector<Bric> brics_;
    /*!< Les briques contenue dans le sac.
     *
     * Représente l'ensemble des briques utilisables en jeu.
     */

public:

    BricsBag(std::vector<Bric> brics);

    /*!
     * \brief Destructeur de \ref BricsBag.
     */
    // TODO : ~BricsBag();

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

    /* NOTE : quelle méthode choisir?
     * aléatoire à chaque pioche en ignorant la dernière brique
     * compteur et réagencement du sac quand à utilisé toute les briques
     * destruction du sac => attribut de save du "sac originel"
     */
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

#ifndef BRICSBAG_H
#define BRICSBAG_H

#include "bric.h"
#include <vector>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

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

    /*! TODO doc
     * \brief BricsBag
     */
    BricsBag();

    /*!
     * \brief Constructeur de \ref BricsBag.
     *
     * \param brics les briques du sac
     */
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
    std::vector<Bric> getBrics();

    /*!
     * \brief Méthode permettant de tirer la prochaine brique du sac.
     *
     * \return la brique au sommet du sac
     */
    Bric getNextBric();

    /* NOTE : quelle méthode choisir?
     * aléatoire à chaque pioche en ignorant la dernière brique qui est mise à la fin
     * on ne réarrange pas la dernière brique.
     */
    /*!
     * \brief Méthode mélangeant les briques dans le sac.
     */
    void rearrange();
};

}

#endif // BRICSBAG_H

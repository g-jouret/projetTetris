#ifndef BRICSBAG_H
#define BRICSBAG_H

#include "model/bric.h"
#include <vector>

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
    explicit BricsBag(std::vector<Bric> &brics);

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

    /* TODO : implémentation
     * aléatoire à chaque pioche en ignorant la dernière brique qui est mise à la fin
     * on ne réarrange pas la dernière brique.
     */
    /*!
     * \brief Méthode mélangeant les briques dans le sac.
     */
    void shuffle();
};

#endif // BRICSBAG_H

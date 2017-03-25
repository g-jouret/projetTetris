#ifndef BRICSBAG_H
#define BRICSBAG_H

#include "model/bric.h"
#include <vector>
#include <cstdlib>

/*!
 * \brief Classe représentant le sac de briques du joueur.
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
     *
     * Il initialise le sac avec les 7 \ref Bric par défaut.
     */
    BricsBag();

    /*!
     * \brief Constructeur de \ref BricsBag.
     *
     * \param brics les briques du sac
     */
    explicit BricsBag(std::vector<Bric> &brics);

    /*!
     * \brief Accesseur en lecture du sac de briques.
     *
     * \return le sac de briques du joueur
     */
    std::vector<Bric> getBrics() const;

    /*!
     * \brief Accesseur en lecture de la prochaine brique du sac.
     *
     * \return la brique au sommet du sac
     */
    Bric getNextBric() const;

    /*!
     * \brief Méthode mélangeant les briques dans le sac.
     *
     * Elle mélange les \ref Bric du sac à l'exception de la
     * dernière brique jouée qui est mise en dernière position.
     */
    void shuffle();
};

#endif // BRICSBAG_H

#ifndef BRICSBAG_H
#define BRICSBAG_H

#include "bric.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant le sac de briques du joueur.
 */
class BricsBag{
    std::vector<Bric> brics_;
    /*!< Les briques contenues dans le sac.
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
     * \brief Méthode ajoutant de nouvelles \ref Bric au \ref BricsBag.
     * \param newBrics les nouvelles briques
     */
    void add(std::vector<Bric> &newBrics);

    /*!
     * \brief Accesseur en lecture de la \ref Bric courante.
     * \return la brique au sommet du sac
     */
    Bric getCurrentBric() const;

    /*!
     * \brief Accesseur en lecture de la prochaine \ref Bric courante.
     * \return la seconde brique du sac.
     */
    Bric getNextBric() const;

    /*!
     * \brief Méthode mélangeant les \ref Bric dans le sac.
     *
     * Si c'est la 1ère fois qu'elle est appelée, elle mélange toutes
     * les briques du sac.
     * Sinon elle place l'ancienne brique courante au début du sac
     * et la nouvelle à la fin, puis mélange les autres briques du sac.
     */
    void shuffle(bool first);
};

} // namespace GJ_GW

#endif // BRICSBAG_H

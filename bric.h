#ifndef BRIC_H
#define BRIC_H

#include <vector>
#include "position.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant une brique de Tetris.
 *
 * Son attribut est la forme d'une brique.
 */
class Bric{

    std::vector<Position> shape_;
    /*!< La forme de la brique.
     *
     * Représente l'ensemble des cases qui sont remplie par la brique.
     */

    // NOTE : pour plus tard : couleur

public:

    /*!
     * \brief Constructeur de \ref Bric.
     *
     * Construit une brique à partir des positions couverte par la briques
     * dans un repère quadrillé.
     *
     * \param shape les \ref Position remplies
     */
    Bric(std::vector<Position> shape);

    /*!
     * \brief Destructeur de \ref Bric.
     */
    // TODO : ~Bric();

    /*!
     * \brief Accesseur en lecture de la forme de la brique.
     *
     * Cette méthode est nécessaire à la génération des briques
     * sur la grille.
     *
     * \return la forme de la brique
     */
    inline std::vector<Position> getShape();

    /*!
     * \brief Méthode qui tourne la brique.
     *
     * Si l'on imagine la brique comme étant dans un carré de case :
     * tourne les positions des cases de ce carrée de 45°.
     */
    // NOTE : réarrange le vecteur de positions dans l'ordre voulu
    void turn();

    /*!
     * \brief Méthode déplaçant la brique dans une direction.
     *
     * les directions possibles sont 1 : bas, 2 : gauche et 3 : droite.
     *
     * \param direction le numéro de la direction choisie
     */
    void move(unsigned direction);
};

//implémentations inline

//fonctions inline

//méthodes inline
std::vector<Position> Bric::getShape(){
    return shape_;
}

}
#endif // BRIC_H

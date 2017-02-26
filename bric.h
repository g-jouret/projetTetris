#ifndef BRIC_H
#define BRIC_H

#include <vector>
#include <array>
#include "position.h"

/*! \mainpage Une classe pour représenter une brique
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
 * \brief Classe représentant une brique de Tetris.
 *
 * Son attribut est la forme d'une brique.
 */
class Bric{
    std::vector<Position> shape_;
    /*!< La forme de la brique.
     *
     * Représente l'ensemble des cases que remplissent la brique.
     */

    // NOTE : pour plus tard : couleur

public:

    /*!
     * \brief Bric
     * \param shape
     */
    Bric(std::vector<Position> shape);

    /*!
     * \brief Destructeur de \ref Bric.
     */
    // TODO : ~Bric();

    /*!
     * \brief Accesseur en lecture de la forme de la brique.
     *
     * \return la forme de la brique
     */
    inline std::vector<Position> getShape();

    /*!
     * \brief Méthode qui tourne la brique.
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

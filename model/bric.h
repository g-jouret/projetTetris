#ifndef BRIC_H
#define BRIC_H

#include "model/position.h"
#include <vector>
#include <algorithm>

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

    unsigned side_;
    /*!< La taille de côté de la brique en nombre de positions. */

    // NOTE : pour plus tard : couleur

public:

    /*! TODO doc
     * \brief Bric
     */
    Bric();

    /*!
     * \brief Constructeur de \ref Bric.
     *
     * Construit une brique à partir des positions couverte par la briques
     * dans un repère quadrillé.
     *
     * \param shape les \ref Position remplies
     */
    explicit Bric(std::vector<Position> shape);

    //Bric(const Bric & other);
    // NOTE : à voir si utile

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
    std::vector<Position> getShape();

    unsigned getSide();

    /*!
     * \brief Méthode qui tourne la brique.
     *
     * Si l'on imagine la brique comme étant dans un carré de case :
     * tourne les positions des cases de ce carrée de 45°.
     */
    // NOTE : la brique est dans un repère carrée, c'est le repère qui tourne, pas seulement la brique
    void rotate();

    /*!
     * \brief Méthode déplaçant la brique dans une direction.
     *
     * les directions possibles sont 1 : bas, 2 : gauche et 3 : droite, 4 : drop (tout en bas).
     *
     * \param direction le numéro de la direction choisie
     */
    void move(unsigned direction);

    bool isIn(Position &toCheck);

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Bric & in);
};

//prototypes
std::ostream & operator<<(std::ostream & out, const Bric & in);

#endif // BRIC_H
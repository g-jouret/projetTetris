#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "position.h"
#include "bric.h"

/*! \mainpage Une classe pour représenter la grille de jeu.
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
 * \brief Classe représentant la grille de jeu.
 *
 * Ses attributs sont :
 *
 * - sa hauteur ;
 * - sa largeur ;
 * - sa grille de cases.
 */
class Board{

    // NOTE : la hauteur et la largeur devraient peut-être être dans Game au lieu de Board car ce sont des paramètres de la parties servant à valider les Positions

    const unsigned width_;
    /*!< La largeur.
     *
     * Cet attribut est constant.
     *
     * Elle est entière et positive.
     */

    const unsigned height_;
    /*!< La hauteur.
     *
     * Cet attribut est constant.
     *
     * Elle est entière et positive.
     */

    const std::vector<Position> grid_;
    /*!< La grille de case.
     *
     * Cet attribut est constant.
     *
     * Elle est composée de cases représentées par leur position.
     */

public:

    /*!
     * \brief Constructeur de \ref Board.
     *
     * Pour ce qui concerne la validation :
     * un zéro est considéré comme la valeur par défaut de l'attribut.
     *
     * \param height la hauteur de la grille en nombre de cases.
     * \param width la largeur de la grille en nombre de cases.
     */
    Board(unsigned width, unsigned height);

    /*!
     * \brief Destructeur de \ref Board.
     */
    // TODO : ~Board();

    /*!
     * \brief Accesseur en lecture de \ref width_.
     *
     * \return la largeur
     */
    inline unsigned getWidth();

    /*!
     * \brief Accesseur en lecture de \ref height_.
     *
     * \return la hauteur
     */
    inline unsigned getHeight();

    /*!
     * \brief Accesseur en lecture de \ref grid_.
     *
     * \return la grille de cases
     */
    inline std::vector<Position> getGrid();

    /*!
     * \brief Méthode vérifiant si une(des) ligne(s) a(ont) été remplie(s).
     *
     * \return les numéros (les ordonnées) des lignes remplies
     */
    std::vector<unsigned> checkLines();

    /*!
     * \brief Méthode gérant les lignes remplies.
     *
     * Une ligne remplie est effacée et augmente le score du joueur l'ayant complétée.
     *
     * \param lineNum le numéro de la ligne à traiter
     */
    void line(unsigned lineNum);

private:

    /*!
     * \brief Méthode privée de validation de la largeur et de la hauteur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \param def la valeur par défaut si l'argument est égal à 0
     *
     * \return la valeur validée
     */
    unsigned validate(unsigned value, unsigned def);
};

//prototypes

//implémentations inline

//fonctions inline

//méthodes inline
unsigned Board::getWidth(){
    return width_;
}

unsigned Board::getHeight(){
    return height_;
}

// TODO : renvoyer référence : copie défensive
std::vector<Position> Board::getGrid(){
    return grid_;
}

}

#endif // BOARD_H

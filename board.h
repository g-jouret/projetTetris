#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <iomanip>
#include <vector>
#include "position.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

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

    const unsigned width_;
    /*!< La largeur de la grille.
     *
     * Cet attribut sert à construire la grille.
     *
     * Cet attribut est constant.
     */

    const unsigned height_;
    /*!< La hauteur de la grille.
     *
     * Cet attribut sert à construire la grille.
     *
     * Cet attribut est constant.
     */

    std::vector<Position> grid_;
    /*!< La grille de case.
     *
     * Elle est composée de cases représentées par leur position.
     */

public:

    /*!
     * \brief Constructeur de \ref Board.
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
     * \brief Accesseur en lecture de \ref grid_.
     *
     * Cette méthode fait partie de la façade de cette classe.
     *
     * \return la grille de cases
     */
    inline std::vector<Position> getGrid();

    /*!
     * \brief Accesseur en lecture de \ref height_.
     *
     * \return le nombre de lignes de la grille
     */
    inline unsigned getHeight();

    /*!
     * \brief Méthode vérifiant l'état d'une ligne de la grille de jeu.
     *
     * Cette méthode analyse l'état des Positions d'une ligne et renvoit sont état.
     *
     * \param line la ligne à analyse
     * \return 0 si la ligne est vide, 1 si elle est remplie et 2 autrement
     */
    unsigned checkLine(std::vector<Position> getLine);

    /*!
     * \brief Méthode sélectionnant une ligne de la grille de jeu.
     *
     * \param lineNum le numéro de la ligne à sélectionner
     * \return la ligne sélectionnée
     */
    std::vector<Position> getLine(unsigned lineNum);

    /*!
     * \brief Méthode vérifiant que la brique courante peut se déplacer.
     *
     * Si cette méthode renvoie faux, les vérifications de fin de partie
     * et de lignes remplies sont lancées.
     *
     * \return si la brique courante peut effectuer son mouvement ou non
     */
    Position *getCase(Position destination);

    /*!
     * \brief Méthode changeant l'état de toutes les Positions d'une ligne.
     *
     * Cette Méthode est utilisée uniquement pour vider les lignes remplies.
     *
     * \param line la ligne à modifié
     */
    void swapLine(std::vector<Position> getLine);

    /*!
     * \brief Méthode qui actualise la grille de jeu après l'effacement d'une ligne remplies.
     *
     * \param lineNum le numéro de la ligne
     */
    void gridActualisation(unsigned lineNum);

    void swapFill(Position &toSwap);

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Board & in);


};

//prototypes

std::ostream & operator<<(std::ostream & out, const Board & in);

//implémentations inline

//fonctions inline

//méthodes inline
std::vector<Position> Board::getGrid(){
    return grid_;
}

unsigned Board::getHeight(){
    return height_;
}

}

#endif // BOARD_H

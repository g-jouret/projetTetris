#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <iomanip>
#include <vector>
#include "position.h"
#include "bric.h"

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
     * \brief Méthode vérifiant si une(des) ligne(s) a(ont) été remplie(s).
     *
     * Cette méthode est appelée lorsque la brique courante ne peut plus se déplacer
     * (sauf dans le cas de la défaite du joueur) et renvoie les numéro des lignes
     * remplies
     *
     * \return les numéros (les ordonnées) des lignes remplies
     */
    std::vector<unsigned> checkLines();

    /*!
     * \brief Méthode gérant les lignes remplies.
     *
     * Une ligne remplie est effacée.
     *
     * \param lineNum le numéro de la ligne à traiter
     */
    void line(unsigned lineNum);

    /*!
     * \brief Méthode vérifiant que la brique courante peut se déplacer.
     *
     * Si cette méthode renvoie faux, les vérifications de fin de partie
     * et de lignes remplies sont lancées.
     *
     * \return si la brique courante peut effectuer son mouvement ou non
     */
    bool checkCase(Position destination) const;

    /*!
     * \brief Méthode qui actualise la grille de jeu après l'effacement d'une ligne remplies.
     *
     * \param lineNum le numéro de la ligne
     */
    void gridActualisation(unsigned lineNum);

    void swapFill(std::vector<Position> bric);

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Board & in);


};

//prototypes

std::ostream & operator<<(std::ostream & out, const Board & in);

//implémentations inline

//fonctions inline

//méthodes inline

// TODO : renvoyer référence : copie défensive
std::vector<Position> Board::getGrid(){
    return grid_;
}

}

#endif // BOARD_H

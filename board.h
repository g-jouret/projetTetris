#ifndef BOARD_H
#define BOARD_H

#include "position.h"
#include <vector>
#include <utility>

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

public:
    constexpr static unsigned DEFAULT_WIDTH {10u};
    /*!< Valeur par défaut de la largeur de la grille. */

    constexpr static unsigned DEFAULT_HEIGHT {20u};
    /*!< Valeur par défaut de la hauteur de la grille. */

    // NOTE : indice du board : 0 en haut, MAX en bas : plus facile pour la génération de brique sur le board

private:
    unsigned width_;
    /*!< La largeur de la grille.
     *
     * Cet attribut sert à construire la grille.
     *
     * Cet attribut est constant.
     */

    unsigned height_;
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

    Board();

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
    std::vector<Position> getGrid();

    /*!
     * \brief Accesseur en lecture de \ref height_.
     *
     * \return le nombre de lignes de la grille
     */
    unsigned getHeight();

    /*!
     * \brief Accesseur en lecture de \ref width_.
     *
     * \return le nombre de colonnes de la grille
     */
    unsigned getWidth();

    bool checkCase(Position pos);

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
    std::vector<Position> getLine(unsigned lineNum) const;

    /*!
     * \brief Méthode vérifiant que la brique courante peut se déplacer.
     *
     * Si cette méthode renvoie faux, les vérifications de fin de partie
     * et de lignes remplies sont lancées.
     *
     * \return si la brique courante peut effectuer son mouvement ou non
     */
    Position * getCase(Position destination);

    /*!
     * \brief Méthode changeant l'état de toutes les Positions d'une ligne.
     *
     * Cette Méthode est utilisée uniquement pour vider les lignes remplies.
     *
     * \param line la ligne à modifié
     */
    void swapLine(std::vector<Position> getLine);

    /*!
     * \brief Méthode qui copie toutes les postions qui sont pleine dans un vecteur.
     *
     * \param line ligne de position remplie
     */
    void moveLine(std::vector<Position> getLine, unsigned lineNb);

    /*!
     * \brief Méthode qui actualise la grille de jeu après l'effacement d'une ligne remplies.
     *
     * \param lineNum le numéro de la ligne
     */
    unsigned gridActualisation(unsigned lineNum);

    void swapCase(Position toSwap);

    //inline Board& operator=(Board&& other) noexcept;

    //std::string to_string() const;

    //friend std::ostream & operator<<(std::ostream & out, const Board & in);


};

//prototypes
//std::ostream & operator<<(std::ostream & out, const Board & in);

//implémentation inline
//méthodes inline
/*Board& Board::operator =(Board&& other) noexcept{
    if(this != & other){
        grid_ = std::move(other.grid_);
        width_ = std::move(other.width_);
        height_ = std::move(other.height_);
    }
    return *this;
}*/

}

#endif // BOARD_H

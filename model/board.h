#ifndef BOARD_H
#define BOARD_H

#include "model/position.h"
#include <vector>

/*!
 * \brief Classe représentant la grille de jeu.
 *
 * Elle est composée de \ref Position et sa taille
 * est délimité par sa largeur et sa hauteur.
 */
class Board{

public:
    constexpr static unsigned DEFAULT_WIDTH {10u};
    /*!< Valeur par défaut de la largeur de la grille. */

    constexpr static unsigned DEFAULT_HEIGHT {20u};
    /*!< Valeur par défaut de la hauteur de la grille. */

private:
    unsigned width_;
    /*!< La largeur de la grille.
     *
     * Cet attribut sert à construire la grille.
     */

    unsigned height_;
    /*!< La hauteur de la grille.
     *
     * Cet attribut sert à construire la grille.
     */

    std::vector<Position> grid_;
    /*!< La grille de case.
     *
     * Elle est composée de cases représentées par des \ref Position.
     */

public:

    /*!
     * \brief Constructeur sans argument de \ref Board.
     *
     * Il initialise la largeur et la hauteur de la grille avec leur valeur par défaut.
     */
    Board();

    /*!
     * \brief Constructeur de \ref Board.
     *
     * \param height la hauteur de la grille en nombre de cases.
     * \param width la largeur de la grille en nombre de cases.
     */
    Board(unsigned width, unsigned height);

    /*!
     * \brief Accesseur en lecture de .
     *
     * Cette méthode fait partie de la façade de cette classe.
     *
     * \return la grille de cases
     */
    std::vector<Position> getGrid() const;

    /*!
     * \brief Accesseur en lecture de \ref height_.
     *
     * \return le nombre de lignes de la grille
     */
    unsigned getHeight() const;

    /*!
     * \brief Accesseur en lecture de \ref width_.
     *
     * \return le nombre de colonnes de la grille
     */
    unsigned getWidth() const;

    /*!
     * \brief Méthode verifie si la case est pleine
     *
     * \param pos la localistation de la position
     * \return vrais si la case est pleine
     */
    bool checkCaseFilled(Position &pos);

    /*!
     * \brief Méthode qui renvoi vrais si la position donnée est dans \ref grid_.
     *
     * \param pos la localistation de la position
     * \return
     */
    bool isIn(Position &pos);

    /*!
     * \brief Méthode vérifiant l'état d'une ligne de la grille de jeu.
     *
     * Cette méthode analyse l'état des Positions d'une ligne et renvoit sont état.
     *
     * \param line la ligne à analyse
     * \return 0 si la ligne est vide, 1 si elle est remplie et 2 autrement
     */
    unsigned checkLine(std::vector<Position> line);

    /*!
     * \brief Méthode sélectionnant une ligne de la grille de jeu.
     *
     * \param lineNum le numéro de la ligne à sélectionner
     * \return la ligne sélectionnée
     */
    std::vector<Position> getLine(unsigned lineNum) const;

    /*!
     * \brief Methode qui récuperant la position donnée dans \ref grid_
     *
     * \param destination la localisation de la position à renvoyer
     * \return position de la grille
     */
    Position &getCase(Position &destination);

    /*!
     * \brief Méthode changeant l'état de toutes les Positions d'une ligne.
     *
     * Cette Méthode est utilisée uniquement pour vider les lignes remplies.
     *
     * \param line la ligne à modifié
     */
    void swapLine(std::vector<Position> line);

    /*!
     * \brief Methode qui
     *
     * \param getLine
     * \param lineNb
     */
    void moveLine(std::vector<Position> getLine, unsigned lineNb);

    /*!
     * \brief Méthode qui actualise la grille de jeu après l'effacement d'une ligne remplies.
     *
     * \param lineNum le numéro de la ligne
     */
    unsigned gridActualisation(unsigned lineNum);

    /*!
     * \brief Méthode qui rend la case remplie si elle est vide et à vide si elle est remplie.
     *
     * \param toSwap la position à swap
     */
    void swapCase(Position &toSwap);

    //inline Board& operator=(Board&& other) noexcept;

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Board & in);


};

//prototypes
std::ostream & operator<<(std::ostream & out, const Board & in);

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

#endif // BOARD_H

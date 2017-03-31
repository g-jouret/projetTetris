#ifndef BOARD_H
#define BOARD_H

#include "position.h"
#include "linestate.h"
#include <map>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant la grille de jeu.
 *
 * Elle est composée de \ref Position et sa taille
 * est délimitée par sa largeur et sa hauteur.
 */
class Board{
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

    std::map<Position, bool> grid_;
    /*!< La grille de case.
     *
     * Elle est composée d'éléments dont les clés sont des \ref Position
     * et qui peuvent être soit plein soit vide.
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
     * \brief Accesseur en lecture de la grille de jeu.
     *
     * \return la grille de cases
     */
    std::map<Position, bool> getGrid() const;

    /*!
     * \brief Accesseur en lecture de la hauteur de la grille.
     *
     * \return le nombre de lignes de la grille
     */
    unsigned getHeight() const;

    /*!
     * \brief Accesseur en lecture de la largeur de la grille.
     *
     * \return le nombre de colonnes de la grille
     */
    unsigned getWidth() const;

    /*!
     * \brief Méthode vérifiant si une case donnée est une destination valide pour un déplacement.
     *
     * Une case est valide si elle est incluse dans la grille de jeu et qu'elle n'est pas pleine.
     *
     * \param pos la localisation de la position
     * \return true si la case est valide, false sinon
     */
    bool checkCase(Position &pos) const;

    /*!
     * \brief Méthode faisant passer une case remplie à vide, et à remplie si elle était vide.
     *
     * \param pos la position à modifier
     */
    void swapCase(Position &pos);

    /*!
     * \brief Accesseur en lecture d'une ligne de la grille de jeu.
     *
     * \param lineNum le numéro de la ligne à sélectionner
     * \return la ligne sélectionnée
     */
    //std::map<Position, bool> getLine(unsigned lineNum) const;

    /*!
     * \brief Méthode vérifiant l'état d'une ligne de la grille de jeu.
     *
     * Cette méthode vérifie si les \ref Position d'une ligne de la grille
     * sont pleines ou non et renvoie son état.
     *
     * \return 0 si la ligne est vide, 1 si elle est remplie et 2 autrement // NOTE : peut être remplacé par une énumération si besoin
     */
    unsigned checkColumn(unsigned y = 0);

    /*!
     * \brief Méthode qui vide les lignes remplies et ré-aligne la grille de jeu.
     *
     * \param lineNum le numéro de la première ligne remplie
     * \return le nombre de lignes remplies traitées
     */
    unsigned gridActualisation(unsigned lineNum);

    /*!
     * \brief Méthode convertissant un \ref Board en std::string.
     *
     * \return une représentation de la grille de jeu sous la forme d'une std::string
     */
    std::string to_string() const;

    // amis

    friend std::ostream & operator<<(std::ostream & out, const Board & in);

private:
    //bool contains(unsigned & x, unsigned & y) const;
    /*!
     * \brief Méthode vérifiant si la position donnée est incluse dans la grille de jeu.
     *
     * \param pos la localisation de la position
     * \return true si la position est comprise dans la grille, false sinon
     */
    bool contains(Position &pos) const;

    bool checkCase(unsigned & x, unsigned & y) const;

    LineState checkRow(unsigned x, unsigned &y, LineState &state);

    /*!
     * \brief Méthode changeant l'état de toutes les \ref Position d'une ligne.
     *
     * Cette Méthode est utilisée principalement pour vider les lignes remplies,
     * mais pourrait servir à remplir ou juste à inverser une ligne.
     *
     * \param line la ligne à modifier
     */
    void swapRow(unsigned y);

    /*!
     * \brief Méthode descendant une ligne d'un nombre de cases donné.
     *
     * \param line la ligne à traiter
     * \param lineNb le nombre de case que la ligne doit descendre
     */
    void moveLine(unsigned y, unsigned lineNb);

};

//prototypes

/*!
 * \brief Opérateur d'injection d'un \ref Board dans un flux en sortie.
 *
 * \param out le flux en sortie
 * \param in le \ref Board à injecter
 * \return le flux après l'injection
 */
std::ostream & operator<<(std::ostream & out, const Board & in);

} // namespace GJ_GW

#endif // BOARD_H

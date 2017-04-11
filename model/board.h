#ifndef BOARD_H
#define BOARD_H

#include "position.h"
#include "color.h"
#include <map>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

enum class LineState;

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

    std::map<Position, Color> grid_;
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
    std::map<Position, Color> getGrid() const;

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
    void swapCase(Position &pos, Color color);

    /*!
     * \brief Méthode vérifiant l'état d'une ligne de la grille de jeu.
     *
     * Cette méthode vérifie si les \ref Position d'une ligne de la grille
     * sont pleines ou non et renvoie son état.
     *
     * \param la ligne jusqu'à laquelle il faut effectuer les vérifications
     * \return le nombre de lignes remplies
     */
    unsigned checkColumn(unsigned y = 0);

private:
    /*!
     * \brief Méthode qui vide les lignes remplies et ré-aligne la grille de jeu.
     *
     * \param lineNum le numéro de la première ligne remplie
     * \return le nombre de lignes remplies traitées
     */
    unsigned gridActualisation(unsigned lineNum);

    /*!
     * \brief Méthode vérifiant si la position donnée est incluse dans la grille de jeu.
     *
     * \param pos la localisation de la position
     * \return true si la position est comprise dans la grille, false sinon
     */
    bool contains(Position &pos) const;

    bool checkCase(unsigned & x, unsigned & y) const;

    LineState checkRow(unsigned &y);

    /*!
     * \brief Méthode changeant l'état de toutes les \ref Position d'une ligne.
     *
     * Cette Méthode est utilisée principalement pour vider les lignes remplies,
     * mais pourrait servir à remplir ou juste à inverser une ligne.
     *
     * \param line la ligne à modifier
     */
    void EmptyRow(unsigned y);

    /*!
     * \brief Méthode descendant une ligne d'un nombre de cases donné.
     *
     * \param line la ligne à traiter
     * \param lineNb le nombre de case que la ligne doit descendre
     */
    void moveLine(unsigned y, unsigned lineNb);
};

} // namespace GJ_GW

#endif // BOARD_H

#ifndef BOARD_H
#define BOARD_H

#include "model/position.h"
#include <vector>

/*!
 * \brief Classe représentant la grille de jeu.
 *
 * Elle est composée de \ref Position et sa taille
 * est délimitée par sa largeur et sa hauteur.
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
    std::vector<Position> getGrid() const;

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
     * \brief Méthode vérifiant si une case donnée est pleine ou non.
     *
     * \param pos la localisation de la position
     * \return true si la case est pleine, false sinon
     */
    bool checkCaseFilled(Position &pos);

    /*!
     * \brief Méthode vérifiant si la position donnée est incluse dans la grille de jeu.
     *
     * \param pos la localistation de la position
     * \return true si la position est comprise dans la grille, false sinon
     */
    bool isIn(Position &pos);

    /*!
     * \brief Méthode vérifiant l'état d'une ligne de la grille de jeu.
     *
     * Cette méthode analyse l'état des \ref Position d'une ligne et renvoie son état.
     *
     * \param line la ligne à analyser
     * \return 0 si la ligne est vide, 1 si elle est remplie et 2 autrement
     */
    unsigned checkLine(std::vector<Position> line);

    /*!
     * \brief Accesseur en lecture d'une ligne de la grille de jeu.
     *
     * \param lineNum le numéro de la ligne à sélectionner
     * \return la ligne sélectionnée
     */
    std::vector<Position> getLine(unsigned lineNum) const;

    /*!
     * \brief Méthode permettant de retrouver la case de la grille correspondant à une \ref Position donnée.
     *
     * \param pos la localisation de la position à renvoyer
     * \return la case correspondante
     */
    Position &getCase(Position &pos);

    /*!
     * \brief Méthode qui efface les lignes remplies et ré-aligne la grille de jeu.
     *
     * \param lineNum le numéro de la première ligne remplie
     * \return le nombre de lignes remplies traitées
     */
    unsigned gridActualisation(unsigned lineNum);

    /*!
     * \brief Méthode faisant passer une case remplie à vide et à remplie si elle est vide.
     *
     * \param pos la position à modifier
     */
    void swapCase(Position &pos);

    /*!
     * \brief Méthode convertissant un \ref Board en std::string.
     *
     * \return une représentation de la grille de jeu sous la forme d'une std::string
     */
    std::string to_string() const;

    // amis

    friend std::ostream & operator<<(std::ostream & out, const Board & in);

private:

    /*!
     * \brief Méthode changeant l'état de toutes les \ref Position d'une ligne.
     *
     * Cette Méthode est utilisée principalement pour vider les lignes remplies,
     * mais pourrait servir à remplir ou juste à inverser une ligne.
     *
     * \param line la ligne à modifier
     */
    void swapLine(std::vector<Position> line);

    /*!
     * \brief Méthode descendant une ligne d'un nombre de cases donné.
     *
     * \param line la ligne à traiter
     * \param lineNb le nombre de case que la ligne doit descendre
     */
    void moveLine(std::vector<Position> line, unsigned lineNb);

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

#endif // BOARD_H

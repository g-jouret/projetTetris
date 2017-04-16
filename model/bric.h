#ifndef BRIC_H
#define BRIC_H

#include "position.h"
#include "color.h"
#include <vector>
#include <string>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

enum class Direction;

/*!
 * \brief Classe représentant une brique de Tetris.
 *
 * La forme de la brique est représentée par un ensemble de \ref Position,
 * elle possède une \ref Color, un milieu et peut être paire ou impaire.
 */
class Bric{
    constexpr static unsigned MAXIMUM_SIDE {6};

    std::vector<Position> shape_;
    /*!< La forme de la brique.
     *
     * Représente l'ensemble des cases qui sont remplies par la brique.
     */

    Color color_;
    /*!< La couleur de la brique. */

    Position middle_;
    /*!< Le point central du carré entourant la brique. */

    bool even_;
    /*!< La parité de la brique.
     *
     * Vrai si la brique a une taille de côté paire, faux sinon.
     */

public:
    /*!
     * \brief Constructeur sans argument de \ref Bric.
     *
     * Il initialise la brique avec une \ref Position par défaut.
     */
    Bric();

    /*!
     * \brief Constructeur de \ref Bric.
     *
     * Construit une brique à partir des \ref Position couvertes par la brique
     * dans un repère carré.
     *
     * \param shape les \ref Position remplies
     */
    explicit Bric(std::vector<Position> &shape, Color color);

    /*!
     * \brief Accesseur en lecture de la forme de la \ref Bric.
     * \return la forme de la brique
     */
    std::vector<Position> getShape() const;

    /*!
     * \brief Accesseur en lecture du milieu du carré entourant la brique.
     * \return la \ref Position occupant le milieu
     */
    Position getMiddle() const;

    /*!
     * \brief Accesseur en lecture de la \ref Color de la \ref Bric.
     * \return la couleur de brique.
     */
    Color getColor() const;

    /*!
     * \brief Accesseur en lecture de parité de la \ref Bric.
     * \return vrai si la taille de côté de la brique est paire, faux sinon
     */
    bool isEven() const;

    /*!
     * \brief Méthode trouvant l'ordonnée de la \ref Position la plus haute de la brique.
     * \return l'ordonnée du point le plus haut de la brique
     */
    unsigned getHigherY();

    /*!
     * \brief Méthode qui tourne la \ref Bric.
     *
     * Si l'on imagine la brique comme étant dans un carré de case :
     * tourne les \ref Position des cases de ce carrée de 90°.
     */
    void rotate();

    /*!
     * \brief Méthode déplaçant la \ref Bric dans une \ref Direction.
     * \param dir la direction choisie
     */
    void move(Direction dir);

    /*!
     * \brief Méthode vérifiant qu'une \ref Position fait partie de la \ref Bric.
     *
     * \param pos la localisation de la position à vérifier
     * \return true si la brique occupe la position, false sinon
     */
    bool contains(Position &pos) const;

private:
    /*!
     * \brief Méthode qui vérifie si une forme de \ref Bric est valide.
     *
     * Pour qu'une brique soit valide elle doit :
     * - Être créée horizontalement.
     * - Toutes ses cases doivent être adjacentes à au moins une autre case
     * de la brique.
     * - Avoir une taille de côté ne dépassant pas \ref MAXIMUM_SIDE.
     * - Toucher le haut du repère.
     *
     * \param shape la forme à valider
     * \return la forme valide
     */
    std::vector<Position> validate(std::vector<Position> shape);

    /*!
     * \brief Méthode permettant de recadrer une forme de \ref Bric mal positionnée.
     * \param shape la forme à recadrer
     * \param xMin l'abscisse de la \ref Position la plus à gauche de la forme
     */
    void adjustPositions(std::vector<Position> &shape, unsigned xMin);

    /*!
     * \brief Méthode qui vérifie si les cases d'une \ref Bric sont adjacentes
     * à au moins une autre case de la brique.
     *
     * \param tested les cases de \ref Bric déjà testées
     * \param pos la \ref Position à tester
     * \return vrai si elle est valide, faux sinon
     */
    bool isAdjacent(std::vector<Position> &tested, Position &pos) const;

    /*!
     * \brief Méthode générant un message d'erreur en fonction de l'exception rencontrée.
     * \param exception l'exception rencontrée
     * \return le message d'erreur
     */
    std::string message(std::__cxx11::string exception) const;
};

} // namespace GJ_GW

#endif // BRIC_H

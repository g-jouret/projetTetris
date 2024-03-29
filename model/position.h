#ifndef POSITION_H
#define POSITION_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant la \ref Position d'une case du \ref Board.
 *
 * Une position est atteignable par son abscisse et son ordonnée.
 */
class Position{
    friend class Bric;

    unsigned x_;
    /*!< L'abscisse de la position. */

    unsigned y_;
    /*!< L'ordonnée de la position. */

public:

    /*!
     * \brief Constructeur sans argument de \ref Position.
     *
     * Il initialise la position à la localisation par défaut.
     */
    Position();

    /*!
     * \brief Constructeur de \ref Position.
     *
     * Une position nouvellement créée est toujours vide.
     *
     * \param x l'abscisse de la position
     * \param y l'ordonnée de la position
     */
    Position(unsigned x, unsigned y);

    /*!
     * \brief Accesseur en lecture de l'abscisse.
     *
     * \return l'abscisse de la \ref Position
     */
    inline unsigned getX() const;

    /*!
     * \brief Accesseur en lecture de l'ordonnée.
     *
     * \return l'ordonnée de la \ref Position
     */
    inline unsigned getY() const;

    /*!
     * \brief Méthode permettant de savoir si une \ref Position
     * est adjacente à une autre selon son abscisse et son ordonnée.
     *
     * \param x l'abscisse de la position
     * \param y l'ordonnée de la position
     * \return vrai si les positions sont adjacentes, faux sinon
     */
    bool isAdjacent(const unsigned & x, const unsigned & y) const;

private:
    /*!
     * \brief Accesseur en écriture de l'abscisse.
     * \param x la nouvelle abscisse de la \ref Position
     */
    void setX(int x);

    /*!
     * \brief Accesseur en écriture de l'ordonnée.
     * \param y la nouvelle ordonnée de la \ref Position
     */
    void setY(int y);

    /*!
     * \brief Méthode permettant de savoir si une \ref Position
     * est adjacente à une autre position.
     *
     * \param other l'autre position
     * \return vrai si les positions sont adjacentes, faux sinon
     */
    bool isAdjacent(const Position & other) const;
};

//prototypes

/*!
 * \brief Opérateur de test d'égalité de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si les deux membres de la comparaison sont égaux, false sinon
 */
inline bool operator==(const Position & lhs, const Position & rhs);

/*!
 * \brief Opérateur de test d'inégalité de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si les deux membres de la comparaison sont différents, false sinon
 */
inline bool operator!=(const Position & lhs, const Position & rhs);

/*!
 * \brief Opérateur de comparaison de deux \ref Position.
 *
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si le membre de gauche est strictement inférieur au membre de droite, false sinon
 */
inline bool operator<(const Position & lhs, const Position & rhs);

/*!
 * \brief Opérateur de comparaison de deux \ref Position.
 *
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si le membre de gauche est strictement supérieur au membre de droite, false sinon
 */
inline bool operator>(const Position & lhs, const Position & rhs);

//implémentations inline
//fonctions inline
bool operator==(const Position & lhs, const Position & rhs){
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

bool operator!=(const Position & lhs, const Position & rhs){
    return ! (lhs == rhs);
}

bool operator<(const Position & lhs, const Position & rhs){
    return lhs.getY() < rhs.getY() || (lhs.getY() == rhs.getY() && lhs.getX() < rhs.getX());
}

bool operator>(const Position & lhs, const Position & rhs){
    return rhs < lhs;
}

//méthodes inline
unsigned Position::getX() const{
    return x_;
}

unsigned Position::getY() const{
    return y_;
}

} // namespace GJ_GW

#endif // POSITION_H

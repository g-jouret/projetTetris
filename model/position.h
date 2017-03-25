#ifndef POSITION_H
#define POSITION_H

#include <iostream>

/*!
 * \brief Classe représentant la \ref Position d'une case du \ref Board.
 *
 * Une position est atteignable par son abscisse et son ordonnée,
 * elle peut être vide ou pleine.
 */
class Position
{
    unsigned x_;
    /*!< L'abscisse de la position. */

    unsigned y_;
    /*!< L'ordonnée de la position. */

    bool filled_;
    /*!< L'état de la position. */

public:

    /*!
     * \brief Constructeur sans argument de \ref Position.
     *
     * Il initialise la \ref Position à la localisation par défaut.
     */
    Position();

    /*!
     * \brief Constructeur de \ref Position.
     *
     * Une \ref Position nouvellement créée est toujours vide.
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
     * \brief Accesseur en lecture de l'état d'une position sur la grille.
     *
     * \return true si la case à cette position est pleine, false sinon
     */
    bool isFilled() const;

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
     * \brief Méthode changeant l'état de la \ref Position.
     */
    void swapFilled();

    /*!
     * \brief Méthode convertissant une \ref Position en std::string.
     *
     * \return une représentation d'une position sous la forme d'une std::string
     */
    std::string to_string() const;

    // amis

    friend std::ostream & operator<<(std::ostream & out, const Position & in);

};

//prototypes

/*!
 * \brief Opérateur de comparaison de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si les deux membres de la comparaison sont égaux, false sinon
 */
inline bool operator==(const Position & lhs, const Position & rhs);

/*!
 * \brief Opérateur de comparaison d'inégalité de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si les deux membres de la comparaison sont différents, false sinon
 */
inline bool operator!=(const Position & lhs, const Position & rhs);

/*!
 * \brief Opérateur d'injection d'une \ref Position dans un flux en sortie.
 *
 * \param out le flux en sortie
 * \param in la \ref Position à injecter
 * \return le flux après l'injection
 */
std::ostream & operator<<(std::ostream & out, const Position & in);

//implémentations inline
//fonctions inline
bool operator==(const Position & lhs, const Position & rhs){
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

bool operator!=(const Position & lhs, const Position & rhs){
    return ! (lhs == rhs);
}

//méthodes inline
inline unsigned Position::getX() const{
    return x_;
}

inline unsigned Position::getY() const{
    return y_;
}

#endif // POSITION_H

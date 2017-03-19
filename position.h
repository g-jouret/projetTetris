#ifndef POSITION_H
#define POSITION_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
//namespace GJ_GW{

/*!
 * \brief Classe représentant la position d'une case de la grille de jeu.
 *
 * Une position est atteignable par son abscisse et son ordonnée,
 * elle peut être vide ou pleine si une brique est dessus.
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
     */
    Position();

    /*!
     * \brief Constructeur de \ref Position.
     *
     * Pour ce qui concerne la validation :
     *  - x doit être compris entre 0 et la largeur-1 de la grille ;
     *  - y doit être compris entre 0 et la hauteur-1 de la grille.
     *
     * \param x l'abscisse de la position.
     * \param y l'ordonnée de la position.
     */
    Position(unsigned x, unsigned y);

    /*!
     * \brief Destructeur de \ref Position.
     */
    // TODO : ~Position();

    /*!
     * \brief Accesseur en lecture de l'abscisse.
     *
     * \return l'abscisse
     */
    inline unsigned getX() const;

    /*!
     * \brief Accesseur en lecture de l'ordonnée.
     *
     * \return l'ordonnée
     */
    inline unsigned getY() const;

    /*!
     * \brief Accesseur en lecture de l'état d'une position sur la grille.
     *
     * Cette méthode est nécessaire à la vérification
     *
     * \return si la case à cette position est pleine ou non
     */
    bool isFilled();

    void setX(int x);

    void setY(int y);

    /*!
     * \brief Méthode changeant la valeur du booléen.
     */
    void swapFilled();

    //std::string to_string() const;

    //friend std::ostream & operator<<(std::ostream & out, const Position & in);

};

//prototypes
inline bool operator==(const Position & lhs, const Position & rhs);
inline bool operator!=(const Position & lhs, const Position & rhs);
//std::ostream & operator<<(std::ostream & out, const Position & in);

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

//} //namespace GJ_GW

#endif // POSITION_H

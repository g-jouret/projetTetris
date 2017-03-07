#ifndef POSITION_H
#define POSITION_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

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
    inline bool isFilled() const;

    inline void setX(int x);

    inline void setY(int y);

    /*!
     * \brief Méthode changeant la valeur du booléen.
     */
    void swapFilled();

    /*! NOTE : inutile : c'est la brique qui bouge, pas la position
     * \brief Méthode permettant de changer la position en indiquant de combien on veut incrémenter chacun des attributs.
     *
     * \param x valeur à ajouter à \ref x_
     * \param y valeur à ajouter à \ref y_
     */
    //void move(unsigned x, unsigned y);

//private:
// NOTE : semble inutile car vérification en amont
    /*!
     * \brief Méthode privée de validation de x et y.
     *
     * Cette méthode vérifie que la valeur de son argument n'est ni inférieure zéro ni supérieure ou égale à la limite de la grille.
     *
     * \param value la valeur à valider
     * \param limit la limite correspondante de la grille
     *
     * \return la valeur validée
     *
     * \throw std::invalid_argument si value est inférieure à 0 ou supérieure ou égale à la limite de la grille
     */
    //unsigned validate(unsigned value, unsigned limit);
};

//prototypes
inline bool operator==(const Position & lhs, const Position & rhs);

//implémentations inline

//fonctions inline
bool operator==(const Position & lhs, const Position & rhs)
{
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

//méthodes inline
unsigned Position::getX() const{
    return x_;
}

unsigned Position::getY() const{
    return y_;
}

bool Position::isFilled() const{
    return filled_;
}

void Position::setX(int x){
    x_ += x;
}

void Position::setY(int y){
    y_ += y;
}

}

#endif // POSITION_H

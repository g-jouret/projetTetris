#ifndef POSITION_H
#define POSITION_H

/*! \mainpage Une classe pour représenter une position sur le plateau.
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref g40853.
 *
 */

/*!
 * \brief Espace de nom de Guillaume Jouret.
 */
namespace g40853{

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
    inline unsigned getX();

    /*!
     * \brief Accesseur en lecture de l'ordonnée.
     *
     * \return l'ordonnée
     */
    inline unsigned getY();

    /*!
     * \brief Accesseur en lecture de l'état d'une position sur la grille.
     *
     * \return si la case à cette position est pleine ou non
     */
    inline bool isFilled();

    /*!
     * \brief Méthode permettant de changer la position en indiquant de combien on veut incrémenter chacun des attributs.
     *
     * \param x valeur à ajouter à \ref x_
     * \param y valeur à ajouter à \ref y_
     */
    void move(unsigned x, unsigned y);

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

//implémentations inline

//fonctions inline

//méthodes inline
unsigned Position::getX(){
    return x_;
}

unsigned Position::getY(){
    return y_;
}

bool Position::isFilled(){
    return filled_;
}

}

#endif // POSITION_H

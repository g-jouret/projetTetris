#ifndef COLOR_H
#define COLOR_H

#include <vector>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant la couleur d'une case de la grille.
 */
class Color{
    std::vector<unsigned> code_;
    /*!< le code couleur RGB de la couleur.
     *
     * R, G et B sont des unsigned allant de 0 à 255 et
     * représentant le taux de rouge, de vert et de bleu
     * de la couleur.
     */

public:
    /*!
     * \brief Constructeur sans argument de \ref Color.
     *
     * Il initialise la couleur à blanc.
     */
    Color();

    /*!
     * \brief Constructeur de \ref Color.
     * \param code le code RGB de la couleur
     */
    explicit Color(std::vector<unsigned> &code);

    /*!
     * \brief Accesseur en lecture du code RGB de la \ref Color.
     * \return le code RGB de la couleur
     */
    std::vector<unsigned> getCode() const;
};

//prototypes

/*!
 * \brief Opérateur de test d'égalité de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return vrai si les deux membres de la comparaison sont égaux, faux sinon
 */
inline bool operator==(const Color & lhs, const Color & rhs);

//implémentations inline
//fonctions inline
bool operator==(const Color & lhs, const Color & rhs){
    return lhs.getCode() == rhs.getCode();
}

} // namespace GJ_GW

#endif // COLOR_H

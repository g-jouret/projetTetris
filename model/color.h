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

public:
    Color();

    explicit Color(std::vector<unsigned> code);

    std::vector<unsigned> getCode() const;
};

//prototypes

/*!
 * \brief Opérateur de test d'égalité de deux \ref Position.
 * \param lhs le membre de gauche
 * \param rhs le membre de droite
 * \return true si les deux membres de la comparaison sont égaux, false sinon
 */
inline bool operator==(const Color & lhs, const Color & rhs);

//implémentations inline
//fonctions inline
bool operator==(const Color & lhs, const Color & rhs){
    return lhs.getCode() == rhs.getCode();
}

} // namespace GJ_GW

#endif // COLOR_H

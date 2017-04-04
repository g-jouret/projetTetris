#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant un joueur.
 *
 * Un joueur a un nom, un score et un compteur du nombre de lignes
 * qu'il a rempli au cours de la partie
 */
class Player{

    std::string name_;
    /*!< Le nom du joueur. */

    unsigned score_;
    /*!< Le score du joueur.
     *
     * Augmente au fur et à mesure que le joueur remplit des lignes de la grille.
     */

    unsigned nbLines_;
    /*!< Le nombre de lignes réalisées par le joueur */

public:

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur
     */
    explicit Player(std::string name);

    /*!
     * \brief Accesseur en lecture du nom du joueur.
     *
     * \return le nom du joueur
     */
    std::string getName() const;

    /*!
     * \brief Accesseur en lecture du score du joueur.
     *
     * \return le score du joueur
     */
    unsigned getScore() const;

    /*!
     * \brief Accesseur en lecture du nombre de lignes remplies par le joueur.
     *
     * \return le nombre de lignes remplies par le joueur depuis le début de la partie
     */
    unsigned getNbLines() const;

    /*!
     * \brief Accesseur en écriture du nom du joueur.
     * \param name le nouveau nom du joueur
     */
    void setName(std::string name);

    /*!
     * \brief Accesseur en écriture d'initialisation du score du joueur.
     * \param score le score sauvegardé précédemment
     */
    void setScore(unsigned score);

    /*!
     * \brief Accesseur en écriture d'incrémentation du score du joueur.
     * \param dropsCount le nombre de lignes parcourue en drop lors du dernier mouvement
     * \param linesCount le nombre de lignes remplies lors du dernier mouvement
     */
    void setScore(unsigned dropsCount, unsigned linesCount);

    /*!
     * \brief Accesseur en écriture du nombre de lignes remplies par le joueur.
     * \param linesCount le nombre de lignes remplies lors du dernier mouvement
     */
    bool setNbLines(unsigned linesCount);

    void reset();

    /*!
     * \brief Méthode de remise à 0 du compteur de lignes remplies par le joueur.
     */
    void resetNbLines();

};

} // namespace GJ_GW

#endif // PLAYER_H

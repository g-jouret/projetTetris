#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ostream>
#include <iomanip>
#include "board.h"
#include "bric.h"
#include "bricsBag.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe représentant un joueur.
 */
class Player{

    std::string name_;
    /*!< Le nom du joueur. */

    unsigned score_;
    /*!< Le score du joueur.
     *
     * Augmente au fur et à mesure que le joueur rempli des lignes de la grille.
     */

    Board board_;
    /*!< La grille de jeu du joueur. */

    BricsBag bag_;
    /*!< Le sac de briques du joueur. */

    Bric currentBric_;
    /*!< La brique courante.
     *
     * Celle que contrôle le joueur.
     */

    unsigned nbLine_;
    /*!< Le nombre de ligne réalisée par le joueur */

public:

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     */
    Player(std::string name, unsigned width, unsigned height);

    /*!
     * \brief Destructeur de \ref Player.
     */
    // TODO : ~Player();

    /*!
     * \brief Accesseur en lecture du nom du joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return le nom du joueur
     */
    inline std::string getName() const;

    /*!
     * \brief Accesseur en lecture du score du joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return le score du joueur
     */
    inline unsigned getScore() const;

    /*!
     * \brief Accesseur en lecture de la brique courante.
     *
     * \return la brique courante
     */
    inline Bric getCurrentBric() const;

    /*!
     * \brief Accesseur en lecture de la grille de jeu.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return la grille de jeu
     */
    inline Board getBoard() const;

    /*!
     * \brief Accesseur en lecture du nombre de ligne remplies par le joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return le nombre de lignes remplies par le joueur
     */
    inline unsigned getNbLine();

    /*!
     * \brief Méthode vérifiant que des lignes ont été remplies.
     *
     * Augmente le score du joueur si c'est le cas.
     */
    void checkLines();

    /*!
     * \brief Méthode permettant de tourner la brique courante de 45°.
     *
     * Cette méthode vérifie que le mouvement peut se faire avant de l'exécuter.
     */
    void rotateBric();

    // NOTE : sert aussi à générer la nouvelle brique?
    // NOTE : direction vers le bas : différence entre descente auto et drop du player (toute la hauteur)
    /*!
     * \brief Méthode permettant une translation de la brique courante dans une direction donnée.
     *
     * Cette méthode vérifie que le mouvement peut se faire avant de l'exécuter.
     *
     * \param direction la direction vers laquelle la pièce est bougée
     */
    void moveBric(unsigned direction);

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Player & in);
};
//prototypes

std::ostream & operator<<(std::ostream & out, const Player & in);

//implémentations inline

//fonctions inline

//méthodes inline
std::string Player::getName() const{
    return name_;
}

unsigned Player::getScore() const{
    return score_;
}

Bric Player::getCurrentBric() const{
    return currentBric_;
}

Board Player::getBoard() const{
    return board_;
}

}

#endif // PLAYER_H

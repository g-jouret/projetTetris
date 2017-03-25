#ifndef GAME_H
#define GAME_H

#include "model/player.h"
#include "observer/subject.h"
#include <vector>

/*! \mainpage Le jeu de Tetris multijoueur, projet de c++ 2016-2017
 *
 * Projet réalisé dans le cadre du cours de c++ de l'ESI
 * par Guillaume Jouret et Guillaume Walravens.
 */

/*!
 * \brief Classe déterminant le fonctionnement d'une partie de Tetris.
 */
class Game : public Subject{
public:
    constexpr static unsigned MINIMUM_TIMER {500};
    /*!< Valeur minimale acceptée pour le timer. */

    constexpr static unsigned MAXIMUM_TIMER {2000};
    /*!< Valeur maximale acceptée pour le timer. */

private:
    unsigned level_;
    /*!< Le niveau de difficulté.
     *
     * Il représente l'accroissement de la difficulté du jeu au fur et à mesure de la partie, il augmente en fonction du score.
     */

    unsigned timer_;
    /*!< Le timer.
     *
     * Il représente le temps entre chaque mouvement de brique, il se réduit en fonction du niveau de difficulté.
     *
     * Sa valeur est en milliseconde et peut aller de \ref MINIMUM_TIMER à \ref MAXIMUM_MONTH.
     */

    //std::vector<Player> players_;     pour plus tard
    Player player_;
    /*!< Les joueurs, leur grille et leur sac de pièces. */

    // NOTE : peut-être mieux d'utiliser un pair, vu que 2 joueurs max?

public:

    /*!
     * \brief Constructeur sans argument de \ref Game.
     */
    Game();

    //Game(std::string name, unsigned width, unsigned height);

    /*!
     * \brief Destructeur de \ref Game.
     */
    // TODO : ~Game();

    // TODO : implémentation de la génération de briques perso
    /* NOTE : choix perso : changement dans les "settings" du joueur possible qu'une seule fois:
     * avant de commencer la partie : choix entre paramètres par défaut ou paramètres perso
     * => plus facile pour implémentation : suffit de refaire appel au constructeur de Player
     * => Player = classe immutable
    */

    /*!
     * \brief Méthode permettant de changer les paramètres de jeux :
     *
     * les noms des joueurs, la taille de la grille // et bientôt les pièces personnalisées
     *
     * \param name le nom du joueur
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     */
    void setPlayer(std::string name, unsigned width, unsigned height);

    const Player &getPlayer() const;

    void generateBric();

    void command(unsigned cmdId);

    void reset();

    /*!
     * \brief Méthode vérifiant qu'aucune condition de fin de partie n'a été remplie.
     *
     * Si un des joueurs perds ou gagne, elle arrête la partie et affiche le résultat.
     *  - Un joueur perd si la brique suivante ne peut être mise en jeu par manque de place ;
     *  - Un joueur gagne s'il atteint un score suffisant ;
     *  - Un joueur gagne s'il réussi à remplir suffisamment de lignes ;
     *  - la partie s'arrête après un certain temps, le joueur ayant alors le plus haut score l'emporte.
     */
    bool endGame();

    //std::string to_string() const;

    //friend std::ostream & operator<<(std::ostream & out, const Game & in);

private:
    /*!
     * \brief Méthode privée de validation du nom du joueur.
     *
     * Cette méthode vérifie que le nouveau nom du joueur n'est pas une chaine vide.
     *
     * \param name le nom à valider
     * \return le nom validé
     */
    std::string validateName(std::string name);

    /*!
     * \brief Méthode privée de validation de la hauteur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \return la valeur validée
     */
    unsigned validateHeight(unsigned value);

    /*!
     * \brief Méthode privée de validation de la largeur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \return la valeur validée
     */
    unsigned validateWidth(unsigned value);

    /*!
     * \brief Méthode privée de validation du timer.
     *
     * Le timer doit être compris entre MAXIMUM_TIMER et MINIMUM_TIMER.
     *
     * \param time la valeur du timer à vérifier
     *
     * \return la valeur validée
     */
    unsigned validateTimer(unsigned time);
};

//prototypes

//std::ostream & operator<<(std::ostream & out, const Game & in);

#endif // GAME_H

/* TODO Principal :
 * rotation des briques
 * Gestion du niveau de difficulté & itératif
 * vérification de fin de partie (le endgame gère tout)
 * couleur des briques
 */

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
 *
 * Elle fournit à la vue les données du modèle nécessaires à son bon fonctionnement.
 */
class Tetris : public Subject{
public:
    constexpr static unsigned MINIMUM_TIMER {500};
    /*!< Valeur minimale acceptée pour le timer. */

    constexpr static unsigned MAXIMUM_TIMER {2000};
    /*!< Valeur maximale acceptée pour le timer. */

private:
    unsigned level_;
    /*!< Le niveau de difficulté.
     *
     * Il représente l'accroissement de la difficulté du jeu au fur et à mesure de la partie, il augmente en fonction du nombre
     * de lignes remplies par le joueur.
     */

    unsigned timer_;
    /*!< Le timer.
     *
     * Il représente le temps entre chaque mouvement automatique de la \ref Bric courante,
     * il se réduit en fonction du niveau de difficulté.
     *
     * Sa valeur est en milliseconde et peut aller de \ref MINIMUM_TIMER à \ref MAXIMUM_MONTH.
     */

    bool gameOver_;
    /*!< L'état de la partie.
     *
     * En cours ou arrêtée.
     */

    Player player_;
    /*!< Le \ref Player, sa \ref Board et son \ref BricsBag. */

public:

    /*!
     * \brief Constructeur sans argument de \ref Tetris.
     *
     * Il initialise la partie avec les paramètres par défaut
     * et crée un \ref Player par défaut.
     */
    Tetris();

    /*!
     * \brief Constructeur de \ref Tetris.
     *
     * Il initialise la partie avec les paramètres par défaut
     * et crée un \ref Player avec les paramètres reçu.
     *
     * \param name le nom du joueur
     * \param width la largeur du \ref Board
     * \param height la hauteur du \ref Board
     */
    Tetris(std::string name, unsigned width, unsigned height);

    // TODO : implémentation des paramètre perso de partie
    // TODO : implémentation de la génération de briques perso

    /*!
     * \brief Accesseur en lecture du \ref Player.
     * \return le joueur
     */
    const Player &getPlayer() const;

    /*!
     * \brief Méthode vérifiant l'état de la partie.
     * \return true si la partie est terminée, false sinon
     */
    bool isGameOver() const;

    /*!
     * \brief Méthode transmettant la commande d'action de la vue au \ref Player.
     * \param cmdId l'identifiant de la commande
     * \see Player::action().
     */
    void command(unsigned cmdId);


    //void reset(); inutilisé pour le moment

private:

    /*!
     * \brief Méthode permettant de changer les paramètres du \ref Player,
     *
     * le nom du joueur, la taille de la grille // et bientôt les briques personnalisées
     *
     * \param name le nom du joueur
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     */
    void setPlayer(std::string name, unsigned width, unsigned height);

    /*!
     * \brief Méthode vérifiant qu'aucune condition de fin de partie n'a été remplie.
     *
     * Si un joueur perd ou gagne, elle arrête la partie et affiche le résultat.
     *  - Un joueur perd si la brique suivante ne peut être mise en jeu par manque de place ;
     *  - Un joueur gagne s'il atteint un score suffisant ;
     *  - Un joueur gagne s'il réussi à remplir suffisamment de lignes ;
     *  - la partie s'arrête après un certain temps, le joueur ayant alors le plus haut score l'emporte.
     */
    void endGame();

    /*!
     * \brief Méthode de validation du nom du joueur.
     *
     * Cette méthode vérifie que le nouveau nom du joueur n'est pas une chaine vide.
     *
     * \param name le nom à valider
     * \return le nom validé
     */
    std::string validateName(std::string name);

    /*!
     * \brief Méthode de validation de la hauteur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \return la valeur validée
     */
    unsigned validateHeight(unsigned value);

    /*!
     * \brief Méthode de validation de la largeur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \return la valeur validée
     */
    unsigned validateWidth(unsigned value);

    /*!
     * \brief Méthode de validation du timer.
     *
     * Le timer doit être compris entre \ref MAXIMUM_TIMER et \ref MINIMUM_TIMER.
     *
     * \param time la valeur du timer à vérifier
     *
     * \return la valeur validée
     */
    unsigned validateTimer(unsigned time);
};

#endif // GAME_H

/* TODO Principal :
 * rotation des briques
 * Gestion du niveau de difficulté & itératif
 * vérification de fin de partie (le endgame gère tout)
 * implémentation de la gestion des collisions en mouvement
 * renforcement du random de getNextBric
 * couleur des briques
 */

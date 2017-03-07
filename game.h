#ifndef GAME_H
#define GAME_H

#include <vector>
#include <array>
#include <ostream>
#include <iomanip>
#include <chrono>
#include "player.h"
#include "bricsBag.h"
#include "bric.h"
#include "board.h"

/*! \mainpage Le jeu de Tetris multijoueur, projet de c++ 2016-2017
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref GJ_GW.
 *
 */

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe déterminant le fonctionnement d'une partie de Tetris.
 */
class Game
{
public:
    constexpr static unsigned MINIMUM_TIMER {500};
    /*!< Valeur minimale acceptée pour le timer. */

    constexpr static unsigned MAXIMUM_TIMER {2000};
    /*!< Valeur maximale acceptée pour le timer. */

    constexpr static unsigned DEFAULT_WIDTH {10};
    /*!< Valeur par défaut de la largeur de la grille. */

    constexpr static unsigned DEFAULT_HEIGHT {20};
    /*!< Valeur par défaut de la hauteur de la grille. */

    // NOTE : indice du board : 0 en haut, MAX en bas : plus facile pour la génération de brique sur le board

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
     * \param name1 le nom du joueur 1
     * \param name2 le nom du joueur 2
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     */
    //void setPlayer(std::string name1, std::string name2, unsigned width, unsigned height);

    //inline std::vector<Player> getPlayers();  pour plus tard
    inline Player getPlayer();

    /*!
     * \brief Méthode vérifiant qu'aucune condition de fin de partie n'a été remplie.
     *
     * Si un des joueurs perds ou gagne, elle arrête la partie et affiche le résultat.
     *  - Un joueur perd si la brique suivante ne peut être mise en jeu par manque de place ;
     *  - Un joueur gagne s'il atteint un score suffisant ;
     *  - Un joueur gagne s'il réussi à remplir suffisamment de lignes ;
     *  - la partie s'arrête après un certain temps, le joueur ayant alors le plus haut score l'emporte.
     */
    void endGame();

    std::string to_string() const;

    friend std::ostream & operator<<(std::ostream & out, const Game & in);

private:

    /*!
     * \brief Méthode privée de validation de la largeur et de la hauteur.
     *
     * Cette méthode vérifie que la valeur de l'attribut n'est pas égale à zéro.
     *
     * \param value la valeur à valider
     * \param def la valeur par défaut si l'argument est égal à 0
     *
     * \return la valeur validée
     */
    unsigned validate(unsigned value, unsigned def);

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
    /*!
     * \brief Méthode privée qui augmente le niveau de dificutlée.
     *
     * Il y a 4 niveau de dificulté et il commence au niveau 0.
     * Et augmente toutes les 5 ligne supprimée.
     *
     * \param lvl le niveau de dificultée
     * \param lineDel le nombre de ligne supprimées
     */
    unsigned upDificulty(unsigned lvl,unsigned lineDel);
    /*!
     * \brief Méthode privée qui diminue le temps entre chaque
     *  mouvement de brique.
     *
     * Selon le niveau de dificultée le timer va diminuer de 0.5s.
     *
     * \param lvl le niveau de dificultée
     * \param timer temps de decente de la brique
     */
    unsigned upTimer(unsigned lvl, unsigned timer);
    //TODO
    static inline void initializeBric ();
};

//prototypes

std::ostream & operator<<(std::ostream & out, const Game & in);

//implémentations inline

//fonctions inline

//méthodes inline
Player Game::getPlayer(){
        return player_;
    }

}

#endif // GAME_H

/* TODO Principal :
 * les destructeurs & constructeurs + copies défensives                     DUO
 * génération de la brique courrante                                        GJ
 * gestion des lignes après suppression                                     GW
 * vérification de fin de partie (le endgame gère tout)                     DUO
 * rearrange du bricsbag                                                    GJ
 * Gestion du niveau de difficulté & itératif                               GW + DUO
 * réfléchir à un moins grand couplage (Player association Board | BricsBag | Bric plutot que composition?) DUO VOCAL
 * réfléchir héritage?                                                      DUO VOCAL
 * couleur des briques                                                      SI FINI
 */

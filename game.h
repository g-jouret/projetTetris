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

/*! \mainpage Une classe pour représenter les paramètres du jeu
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
 * \brief Classe déterminant le fonctionnement d'une partie de Tetris.
 */
class Game
{
    // NOTE : discuter de l'utilité des getters
public:
    constexpr static unsigned MINIMUM_TIMER {100};
    /*!< Valeur minimale acceptée pour le timer. */

    constexpr static unsigned MAXIMUM_TIMER {500};
    /*!< Valeur maximale acceptée pour le timer. */

    constexpr static unsigned DEFAULT_WIDTH {10};
    /*!< Valeur par défaut de la largeur de la grille. */

    constexpr static unsigned DEFAULT_HEIGHT {20};
    /*!< Valeur par défaut de la hauteur de la grille. */

    // NOTE : indice du board : 0 en haut, MAX en bas : plus facile pour la génération de brique sur le board
    /* WARNING DB : faut trouver un moyen d'initialiser les briques par défaut !
    constexpr static std::vector<unsigned> DEFAULT_BRICS {
        {0,0 , 0,1 , 0,2 , 0,3,    //I
        0,0 , 1,0 , 0,1 , 1,1,    //O
        1,0 , 0,1 , 1,1 , 2,1,    //T
        1,0 , 1,1 , 0,2 , 1,2,    //J
        0,0 , 0,1 , 0,2 , 1,2,    //L
        0,0 , 1,0 , 1,1 , 2,1,    //Z
        1,0 , 2,0 , 0,1 , 1,1}     //S
    };
*/
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
    // TODO : mode de jeu, condition de victoire

    /* NOTE : option possible
    unsigned step_;*/
    /*!< L'étape en cours.
     *
     * Il y a 3 étapes dans le déroulement d'une itération :
     *  - le tirage d'une nouvelle brique courante ;
     *  - la chute de la brique courante ;
     *  - l'arrêt de la brique courante et la résolution du nouvel état de la grille.
     */

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
 * les destructeurs & constructeurs + copies défensives /!\ debug requis!
 * génération de la brique courrante
 * vérification de fin de partie (le endgame gère tout)
 * rearrange du bricsbag
 * Gestion du niveau de difficulté & itératif
 * couleur des briques
 */

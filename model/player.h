#ifndef PLAYER_H
#define PLAYER_H

#include "model/board.h"
#include "model/bric.h"
#include "model/bricsBag.h"
#include <string>

/*!
 * \brief Classe représentant un joueur.
 *
 * Elle contient les informations utiles à l'identification du joueur
 * et contrôle les éléments jouables du \ref Tetris.
 */
class Player{

    std::string name_;
    /*!< Le nom du joueur. */

    Board board_;
    /*!< La grille de jeu du joueur. */

    BricsBag bag_;
    /*!< Le sac de briques du joueur. */

    Bric currentBric_;
    /*!< La brique courante.
     *
     * Celle que contrôle le joueur.
     */

    unsigned score_;
    /*!< Le score du joueur.
     *
     * Augmente au fur et à mesure que le joueur rempli des lignes de la grille.
     */

    unsigned nbLine_;
    /*!< Le nombre de lignes réalisées par le joueur */

public:

    /*!
     * \brief Constructeur sans argument de \ref Player.
     *
     * Il initialise le joueur avec le nom et le \ref Board par défaut.
     */
    Player();

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur
     * \param width la largeur du \ref Board
     * \param height la hauteur du \ref Board
     */
    Player(std::string name, unsigned width, unsigned height);

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
     * \brief Accesseur en lecture de la brique courante.
     *
     * \return la brique courante
     */
    Bric getCurrentBric() const;

    /*!
     * \brief Accesseur en lecture du \ref Board.
     *
     * \return la grille de jeu
     */
    Board getBoard() const;

    /*!
     * \brief Accesseur en lecture du nombre de ligne remplies par le joueur.
     *
     * \return le nombre de lignes remplies par le joueur depuis le début de la partie
     */
    unsigned getNbLine() const;

    /*!
     * \brief Accesseur en écriture du nom du joueur.
     * \param name le nouveau nom du joueur
     */
    void setName(std::string name);

    /*!
     * \brief Accesseur en écriture du \ref Board.
     *
     * Il recrée une grille avec les nouveaux paramètres.
     *
     * \param width la largeur de la grille de jeu
     * \param height la hauteur de la grille de jeu
     */
    void setBoard(unsigned width, unsigned height);

    /*!
     * \brief Méthode vérifiant que des lignes ont été remplies.
     *
     * Elle est lancée à chaque fois que la \ref Bric courrante
     * ne peut plus descendre.
     *
     * \param dropCount le nombre de cases traversées par un drop
     */
    void checkLines(unsigned dropCount);

    /*!
     * \brief Méthode plaçant une nouvelle \ref Bric en haut du \ref Board.
     */
    void generateBric();

    /*!
     * \brief Méthode de préparation au mouvement ou à la rotation de la \ref Bric courante.
     *
     * \param direction la direction vers laquelle la brique est déplacée
     */
    void action(unsigned direction);

    /*!
     * \brief Méthode vérifiant que le mouvement de la \ref Bric courante est valide.
     *
     * Elle crée un fantome de brique à la destination du mouvement
     * se termine dans une zone inoccupée de la grille de jeu.  // gestion des collisions à venir
     *
     * \param direction la direction vers laquelle la brique est déplacée
     * \return true si le mouvement peut être effectué, false sinon
     */
    bool checkMove(unsigned direction);

    /*!
     * \brief Méthode vérifiant que la rotation de la \ref Bric courante est valide.
     *
     * Elle crée un fantome de brique à la destination du mouvement
     * se termine dans une zone inoccupée de la grille de jeu.  // gestion des collisions à venir
     */
    void checkRotate();

    /*!
     * \brief Méthode permettant de tourner la brique courante de 45°.
     */
    void rotateBric();

    /*!
     * \brief Méthode permettant une translation de la brique courante dans une direction donnée.
     *
     * \param direction la direction vers laquelle la brique est déplacée
     */
    void moveBric(unsigned direction);

};

#endif // PLAYER_H

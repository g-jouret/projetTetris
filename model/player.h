#ifndef PLAYER_H
#define PLAYER_H

#include "model/board.h"
#include "model/bric.h"
#include "model/bricsBag.h"
#include <string>

/*!
 * \brief Classe représentant un joueur.
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
    /*!< Le nombre de ligne réalisée par le joueur */

public:

    Player();

    /*!
     * \brief Constructeur de \ref Player.
     *
     * \param name le nom du joueur
     * \param width la largeur de la grille
     * \param height la hauteur de la grille
     */
    Player(std::string name, unsigned width, unsigned height);

    /*!
     * \brief Accesseur en lecture du nom du joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return le nom du joueur
     */
    std::string getName() const;

    /*!
     * \brief Accesseur en lecture du score du joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
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
     * \brief Accesseur en lecture de la grille de jeu.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return la grille de jeu
     */
    Board getBoard() const;

    void setName(std::string name);

    void setBoard(unsigned width, unsigned height);

    /*!
     * \brief Accesseur en lecture du nombre de ligne remplies par le joueur.
     *
     * Cette méthode fait partie de la façade de la classe.
     *
     * \return le nombre de lignes remplies par le joueur
     */
    unsigned getNbLine();

    /*!
     * \brief Méthode vérifiant que des lignes ont été remplies.
     *
     * Augmente le score du joueur si c'est le cas.
     */
    void checkLines(unsigned dropCount);

    void generateBric();

    /*!
     * \brief Méthode permettant de tourner la brique courante de 45°.
     *
     * Cette méthode vérifie que le mouvement peut se faire avant de l'exécuter.
     */
    void rotateBric();

    void move(unsigned direction);

    bool checkMove(unsigned direction);

    /*!
     * \brief Méthode permettant une translation de la brique courante dans une direction donnée.
     *
     * Cette méthode vérifie que le mouvement peut se faire avant de l'exécuter.
     *
     * \param direction la direction vers laquelle la pièce est bougée
     */
    void moveBric(unsigned direction);



    //std::string to_string() const;

    //friend std::ostream & operator<<(std::ostream & out, const Player & in);

};

//prototypes

//std::ostream & operator<<(std::ostream & out, const Player & in);

//inline Player& operator=(Player&& other) noexcept;

//implémentations inline
//fonctions inline
/*Player& operator=(Player&& other) noexcept{
    if(this != &other){
        delete bag_;
        delete board_;
        delete currentBric_;
        delete[] name_;

    }
    return *this;
}*/

#endif // PLAYER_H
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "bricsBag.h"
#include "gamestate.h"
#include "../observer/subject.h"
#include <QObject>
#include <QElapsedTimer>

/*! \mainpage Le jeu de Tetris multijoueur, projet de c++ 2016-2017
 *
 * Projet réalisé dans le cadre du cours de c++ de l'ESI
 * par Guillaume Jouret et Guillaume Walravens.
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref GJ_GW.
 */

class QTimer;

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Classe déterminant le fonctionnement d'une partie de Tetris.
 *
 * Elle fournit à la vue les données du modèle nécessaires à son bon fonctionnement
 * et implémente \ref Subject.
 */
class Tetris : public QObject, public Subject{
    Q_OBJECT
public:
    constexpr static unsigned MINIMUM_WIDTH {6};
    /*!< Valeur minimale acceptée pour la largeur. */

    constexpr static unsigned MAXIMUM_WIDTH {12};
    /*!< Valeur maximale acceptée pour la largeur. */

    constexpr static unsigned MINIMUM_HEIGHT {12};
    /*!< Valeur minimale acceptée pour la hauteur. */

    constexpr static unsigned MAXIMUM_HEIGHT {24};
    /*!< Valeur maximale acceptée pour la hauteur. */

    constexpr static unsigned MINIMUM_WIN_SCORE {1000};
    /*!< Valeur minimale acceptée pour le score de victoire. */

    constexpr static unsigned MAXIMUM_WIN_SCORE {25000};
    /*!< Valeur maximale acceptée pour le score de victoire. */

    constexpr static unsigned MINIMUM_WIN_LINES {20};
    /*!< Valeur minimale acceptée pour le nombe de lignes de victoire. */

    constexpr static unsigned MAXIMUM_WIN_LINES {100};
    /*!< Valeur maximale acceptée pour le nombe de lignes de victoire. */

    constexpr static unsigned MINIMUM_WIN_TIME {60000};
    /*!< Valeur minimale acceptée pour le temps de victoire. */

    constexpr static unsigned MAXIMUM_WIN_TIME {3599000};
    /*!< Valeur maximale acceptée pour le temps de victoire. */

private:
    constexpr static int MINIMUM_TIMER {150};
    /*!< Valeur minimale acceptée pour le timer. */

    constexpr static int MAXIMUM_TIMER {1200};
    /*!< Valeur maximale acceptée pour le timer. */

    unsigned level_;
    /*!< Niveau de difficulté au démarrage de la partie. */

    //unsigned timer_;
    /*!< Le timer.
     *
     * Il représente le temps entre chaque mouvement automatique de la \ref Bric courante,
     * il se réduit en fonction du niveau de difficulté.
     *
     * Sa valeur est en milliseconde et peut aller de \ref MINIMUM_TIMER à \ref MAXIMUM_TIMER.
     */

    unsigned winScore_;
    /*!< Le score de victoire.
     *
     * Il représente le score à atteindre pour gagner une partie.
     *
     * Sa valeur peut aller de \ref MINIMUM_WIN_SCORE à \ref MAXIMUM_WIN_SCORE.
     */

    unsigned winLines_;
    /*!< Le nombre de lignes de victoire.
     *
     * Il représente le nombre de lignes à remplir pour gagner une partie.
     *
     * Sa valeur peut aller de \ref MINIMUM_WIN_LINES à \ref MAXIMUM_WIN_LINES.
     */

    unsigned winTime_;
    /*!< Le temps de victoire.
     *
     * Il représente le temps de jeu à atteindre pour gagner une partie.
     *
     * Sa valeur peut aller de \ref MINIMUM_WIN_TIME à \ref MAXIMUM_WIN_TIME.
     */

    GameState gameState_;
    /*!< L'état de la partie. */

    Player player_;
    /*!< Le joueur. */

    Board board_;
    /*!< La grille de jeu. */

    BricsBag bag_;
    /*!< Le sac de briques. */

    Bric currentBric_;
    /*!< La brique courante.
     *
     * Celle que contrôle le joueur.
     */

    bool winByScore_;
    /*!< La victoire par score est-elle activée. */

    bool winByLines_;
    /*!< La victoire par lignes est-elle activée. */

    bool winByTime_;
    /*!< La victoire par temps est-elle activée. */

    QElapsedTimer chrono_;
    unsigned savedTime_;
    QTimer * timer_;

public:
    /*!
     * \brief Constructeur sans argument de \ref Tetris.
     *
     * Il initialise la partie avec les paramètres par défaut,
     * crée un \ref Player, un \ref Board et un \ref BricsBag par défaut.
     */
    explicit Tetris();

    /*!
     * \brief Méthode permettant d'initialiser des \ref Bric personnalisées.
     * \param newBag les briques que le joueur souhaite créer
     * \param keepBag indique si le joueur souhaite ajouter ses briques au
     * sac déjà existant ou s'il souhaite créer un nouveau sac de briques.
     */
    void setBag(std::vector<Bric> newBag, bool keepBag = true);

    /*!
     * \brief Méthode réinitialisant le \ref BricsBag à sa valeur par défaut.
     */
    void resetBag();

    /*!
     * \brief Méthode permettant de lancer une partie de \ref Tetris.
     *
     * Elle ré-initialise la partie avec les paramètres donnés et lance le jeu.
     *
     * \param name le nom du joueur
     * \param width la largeur du \ref Board
     * \param height la hauteur du \ref Board
     * \param winScore le score de victoire
     * \param winLines le nombre de lignes de victoire
     * \param winTime le temps de victoire
     * \param level le niveau de difficulté de départ
     * \param winByScore si la victoire au score est activée ou non
     * \param winByLines si la victoire aux lignes est activée ou non
     * \param winByTime si la victoire au temps est activée ou non
     */
    void startGame(std::string name, unsigned width, unsigned height, unsigned winScore,
                   unsigned winLines, unsigned winTime, unsigned level,
                   bool winByScore, bool winByLines, bool winByTime);

    /*!
     * \brief Accesseur en lecture du niveau de difficulté.
     * \return le niveau de difficulté
     */
    unsigned getLevel() const;

    /*!
     * \brief Accesseur en lecture du timer.
     * \return le timer
     */
    //unsigned getTimer() const;

    /*!
     * \brief Accesseur en lecture du score de victoire.
     * \return le score de victoire
     */
    unsigned getWinScore() const;

    /*!
     * \brief Accesseur en lecture du nombre de lignes de victoire.
     * \return le nombre de lignes de victoire
     */
    unsigned getWinLines() const;

    /*!
     * \brief Accesseur en lecture du temps de victoire.
     * \return le temps de victoire
     */
    unsigned getWinTime() const;

    /*!
     * \brief Accesseur en lecture du \ref Player.
     * \return le joueur
     */
    Player getPlayer() const;

    /*!
     * \brief Accesseur en lecture du \ref Board.
     * \return la grille de jeu
     */
    Board getBoard() const;

    /*!
     * \brief Accesseur en lecture de la prochaine \ref Bric courante.
     * \return la prochaine brique courante
     */
    Bric getNextBric() const;

    /*!
     * \brief Accesseur en lecture du \ref GameState.
     * \return l'état du jeu
     */
    GameState getGameState() const;

    unsigned getTimeElapsed() const;

    /*!
     * \brief Accesseur en lecture de l'état d'activation de la victoire au score.
     * \return vrai si la victoire au score est activée, faux sinon
     */
    bool hasWinByScore() const;

    /*!
     * \brief Accesseur en lecture de l'état d'activation de la victoire par lignes.
     * \return vrai si la victoire par lignes est activée, faux sinon
     */
    bool hasWinByLines() const;

    /*!
     * \brief Méthode permettant d'effectuer autant de déplacement
     * de la \ref Bric courante vers le bas que possible.
     */
    void drop();

    /*!
     * \brief Méthode vérifiant que le mouvement de la \ref Bric courante est valide.
     *
     * Elle crée un fantome de brique à la destination du mouvement et vérifie que le fantôme
     * se trouve dans une zone inoccupée de la grille de jeu.
     *
     * \param dir la direction vers laquelle la brique est déplacée
     * \param dropsCount le nombre de drop effectué, si la méthode a été appelée par un drop
     * \return true si le mouvement peut être effectué, false sinon
     */
    bool checkMove(Direction dir);

    /*!
     * \brief Méthode vérifiant que la rotation de la \ref Bric courante est valide.
     *
     * Elle crée un fantome de brique à la destination du mouvement et vérifie que le fantôme
     * se trouve dans une zone inoccupée de la grille de jeu.
     */
    void checkRotate();

    void resume();
    void pause();

private:
    /*!
     * \brief Méthode de validation de la largeur.
     *
     * Cette méthode vérifie que la valeur de l'attribut est comprise entre
     * \ref MINIMUM_WIDTH et \ref MAXIMUM_WIDTH.
     *
     * \param width la valeur à valider
     * \return la valeur validée
     * \throw std::invalid_argument si
     *              width \f$\notin\f$ [\ref MINIMUM_WIDTH,
     *                                          \ref MAXIMUM_WIDTH]
     */
    static unsigned validateWidth(unsigned width);

    /*!
     * \brief Méthode de validation de la hauteur.
     *
     * Cette méthode vérifie que la valeur de l'attribut est comprise entre
     * \ref MINIMUM_HEIGHT et \ref MAXIMUM_HEIGHT.
     *
     * \param height la valeur à valider
     * \return la valeur validée
     * \throw std::invalid_argument si
     *              height \f$\notin\f$ [\ref MINIMUM_HEIGHT,
     *                                          \ref MAXIMUM_HEIGHT]
     */
    static unsigned validateHeight(unsigned height);

    /*!
     * \brief Méthode de validation du score de victoire.
     *
     * Cette méthode vérifie que la valeur de l'attribut est comprise entre
     * \ref MINIMUM_WIN_SCORE et \ref MAXIMUM_WIN_SCORE.
     *
     * \param winScore la valeur à valider
     * \return la valeur validée
     * \throw std::invalid_argument si
     *              winScore \f$\notin\f$ [\ref MINIMUM_WIN_SCORE,
     *                                          \ref MAXIMUM_WIN_SCORE]
     */
    static unsigned validateWinScore(unsigned winScore);

    /*!
     * \brief Méthode de validation du nombre de lignes de victoire.
     *
     * Cette méthode vérifie que la valeur de l'attribut est comprise entre
     * \ref MINIMUM_WIN_LINES et \ref MAXIMUM_WIN_LINES.
     *
     * \param winLines la valeur à valider
     * \return la valeur validée
     * \throw std::invalid_argument si
     *              winLines \f$\notin\f$ [\ref MINIMUM_WIN_LINES,
     *                                          \ref MAXIMUM_WIN_LINES]
     */
    static unsigned validateWinLines(unsigned winLines);

    /*!
     * \brief Méthode de validation du temps de victoire.
     *
     * Cette méthode vérifie que la valeur de l'attribut est comprise entre
     * \ref MINIMUM_WIN_TIME et \ref MAXIMUM_WIN_TIME.
     *
     * \param winTime la valeur à valider
     * \return la valeur validée
     * \throw std::invalid_argument si
     *              winTime \f$\notin\f$ [\ref MINIMUM_WIN_TIME,
     *                                          \ref MAXIMUM_WIN_TIME]
     */
    static unsigned validateWinTime(unsigned winTime);

    /*!
     * \brief Méthode générant un message d'erreur en fonction de l'exception
     * rencontrée.
     *
     * \param label le label du paramètre invalide
     * \param value la valeur du paramètre invalide
     * \param min la valeur minimale de l'attribut
     * \param max la valeur maximale de l'attribut
     * \return le message d'erreur
     */
    static std::string message(const std::string & label, unsigned value, unsigned min, unsigned max);

    /*!
     * \brief Méthode plaçant une nouvelle \ref Bric en haut du \ref Board.
     *
     * \param first indique s'il s'agit de la 1ère génération de brique de la partie
     */
    void generateBric(bool first = false);

    /*!
     * \brief Méthode permettant une translation de la \ref Bric courante dans une \ref Direction donnée.
     *
     * \param direction la direction vers laquelle la brique est déplacée
     */
    void moveBric(Direction dir);

    /*!
     * \brief Méthode permettant de tourner la \ref Bric courante de 90°.
     */
    void rotateBric();

    /*!
     * \brief Méthode vérifiant que des lignes ont été remplies.
     *
     * Elle est lancée à chaque fois que la \ref Bric courrante
     * ne peut plus descendre.
     *
     * \param dropCount le nombre de cases traversées par un drop
     */
    void checkLines(unsigned top, unsigned dropsCount);

    /*!
     * \brief Méthode modifiant le \ref GameState et notifiant la vue.
     *
     * Cette méthode est appelée lorsque :
     *  - La partie s'initialise ;
     *  - La partie commence ;
     *  - Un joueur perd, si la brique suivante ne peut être mise en jeu par manque de place ;
     *  - Un joueur gagne, s'il atteint un score suffisant ;
     *  - Un joueur gagne, s'il réussi à remplir suffisamment de lignes ;
     *  - La partie s'arrête, après un certain temps, le joueur ayant alors le plus haut score l'emporte.
     *
     * \param gameState le nouvel état de la partie
     */
    void setGameState(GameState gameState);

    /*!
     * \brief Méthode modifiant le temps entre chaque itération en fonction
     * du niveau de difficulté.
     */
    void setTimer();

    /*!
     * \brief Méthode modifiant le niveau de difficulté en fonction du nombre de lignes remplies par le joueur.
     */
    void setLevel();

    /*!
     * \brief Méthode amie de \ref Board, changeant la couleur d'une case.
     *
     * Si elle passe à blanc, la case est considérée comme vide.
     *
     * \param pos la position à modifier
     * \param color la couleur à appliquer
     */
    void boardSwapCase(Position &pos, Color color);

private slots:
    /*!
     * \brief Méthode lançant une nouvelle itération du jeu.
     *
     * Une itération de \ref Tetris comprend un mouvement automatique
     * de la \ref Bric courante vers le bas ou la génération d'une
     * nouvelle brique courante si la précédente ne pouvait plus
     * descendre.
     * Si le temps écoulé depuis le début de la partie dépasse
     * le winTime la partie est gagnée
     */
    void next();
};

} // namespace GJ_GW

#endif // GAME_H

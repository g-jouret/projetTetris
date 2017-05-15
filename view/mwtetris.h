#ifndef MWTETRIS_H
#define MWTETRIS_H

#include "../observer/observer.h"
#include "../network/multitetris.h"
#include <QMainWindow>
#include <QElapsedTimer>
#include <QGridLayout>
#include <QLabel>

/*!
 * Namespace contenant la vue du \ref Tetris.
 */
namespace Ui {
class MWTetris;
class QTimer;
}

/*!
 * \brief Classe représentant la fenêtre principale du \ref Tetris.
 */
class MWTetris : public QMainWindow, public GJ_GW::Observer{
    Q_OBJECT
    Ui::MWTetris *ui;
    GJ_GW::MultiTetris game_;
    QLabel * lbEnd_;
    /*QElapsedTimer chrono_;
    unsigned savedTime_;
    QTimer * timer_;*/
    QTimer * time_;

public:
    /*!
     * \brief Constructeur de \ref MWTetris.
     * \param game la partie de \ref Tetris
     * \param parent fenêtre ayant lancé cette fenêtre (ici, aucune)
     */
    explicit MWTetris(QWidget *parent = 0);

    /*!
     * \brief Méthode rafraichissant les données affichables en fonction
     * des données envoyées par le sujet d'observation.
     *
     * \param le sujet d'observation
     */
    void update(GJ_GW::Subject *);

    ~MWTetris() noexcept;

private:
    void showHostInfo();

    /*!
     * \brief Méthode générant et affichant un \ref Board correspondant
     * à celle de \ref Tetris.
     *
     * Elle affiche le message de fin de partie au sein de la grille.
     *
     * \param end vrai si la partie est finie, faux sinon
     */
    void generateBoard(bool end = 0);

    void refreshBoard();

    void setStyleSheet(QLabel *lb, QString color, QString border);

    /*!
     * \brief Méthode permettant d'appeler les destructeurs des éléments
     * contenu dans un QGridLayout.
     *
     * \param board le QGridLayout
     */
    void eraseBoard(QGridLayout * board);

    /*!
     * \brief Méthode permettant d'afficher la prochaine \ref Bric courante.
     */
    void showNextBric();

    /*!
     * \brief Méthode gèrant les effets de la fin de partie sur l'affichage.
     */
    void endGame();

    /*!
     * \brief Méthode permettant de mettre la partie en pause.
     */
    //void pause();

    /*!
     * \brief Méthode permettant de reprendre le cours de la partie.
     */
    //void resume();

private slots:
    /*!
     * \brief Méthode lançant la procédure de création de partie.
     *
     * Cette procédure comprend :
     *  - l'ouverture d'une fenêtre de configuration de partie \ref ConfigDialog ;
     *  - la création d'une partie de \ref Tetris avec les paramètres configurés ;
     *  - le démarrage de la partie.
     */
    void createGame();

    void launchGame();
    //void reconnect();

    /*!
     * \brief Méthode permettant de demander au \ref Tetris de tourner la \ref Bric courante.
     */
    void rotate();

    /*!
     * \brief Méthode permettant de demander au \ref Tetris de dropper la \ref Bric courante.
     */
    void drop();

    /*!
     * \brief Méthode permettant de demander au \ref Tetris de déplacer la \ref Bric courante
     * sur la gauche.
     */
    void left();

    /*!
     * \brief Méthode permettant de demander au \ref Tetris de déplacer la \ref Bric courante
     * sur la droite.
     */
    void right();

    /*!
     * \brief Méthode permettant de mettre la pause ou de reprendre suivant l'état du bouton.
     * \param checked l'état du bouton
     */
    void setPaused();

    /*!
     * \brief Méthode permettant d'afficher le temps écoulé hors pause depuis le début de la partie.
     */
    void showTime();

    /*!
     * \brief Méthode permettant de demander au \ref Tetris de lancer une nouvelle itération.
     */
    //void next();
};

#endif // MWTETRIS_H

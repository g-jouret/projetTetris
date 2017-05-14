#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "../model/bric.h"
#include <QDialog>

/*!
 * Namespace contenant la vue du \ref Tetris.
 */
namespace Ui {
class ConfigDialog;
}

/*!
 * \brief Classe représentant la fenêtre de configuration de la partie de \ref Tetris.
 */
class ConfigDialog : public QDialog
{
    Q_OBJECT
    Ui::ConfigDialog *ui;
    std::vector<GJ_GW::Bric> brics_;

public:
    /*!
     * \brief Constructeur de \ref ConfigDialog
     *
     * \param name nom du \ref Player
     * \param args les différents arguments numériques
     * \param parent fenêtre ayant lancé \ref ConfigDialog
     */
    explicit ConfigDialog(std::vector<unsigned> args, bool netOk, QWidget *parent = 0);

    ~ConfigDialog();

    /*!
     * \brief Accesseur en lecture du nom du \ref Player.
     *
     * \return name nom du joueur
     */
    std::string getName() const;

    /*!
     * \brief Accesseur en lecture de la largeur du \ref Board.
     *
     * \return la largeur de la grille de jeu
     */
    unsigned getWidth() const;

    /*!
     * \brief Accesseur en lecture de la hauteur du \ref Board.
     *
     * \return la hauteur de la grille de jeu
     */
    unsigned getHeight() const;

    /*!
     * \brief Accesseur en lecture du score nécessaire pour gagner.
     *
     * \return le score nécessaire pour gagner
     */
    unsigned getWinScore() const;

    /*!
     * \brief Accesseur en lecture du nombre de lignes nécessaires pour gagner.
     *
     * \return Le nombre de lignes nécessaires pour gagner
     */
    unsigned getWinLines() const;

    /*!
     * \brief Accesseur en lecture du temps nécessaire pour gagner.
     *
     * \return Le temps nécessaire pour gagner
     */
    unsigned getWinTime() const;

    /*!
     * \brief Accesseur en lecture du niveau de difficulté en début de partie.
     *
     * \return le niveaux de difficulté
     */
    unsigned getLevel() const;

    /*!
     * \brief Accesseur en lecture de la nouvelle \ref Bric créée.
     *
     * \return la forme de la brique créée
     */
    std::vector<GJ_GW::Bric> getBrics() const;

    /*!
     * \brief Accesseur en lecture du nom d'host.
     * \return le nom d'host
     */
    QString getHostName() const;

    /*!
     * \brief Accesseur en lecture du numéro de port.
     * \return le numéro de port
     */
    unsigned getPort() const;

    /*!
     * \brief Accesseur en lecture de l'utilisation ou non de l'ancien \ref BricsBag.
     *
     * \return vrai si l'ancien sac de briques est conservé, faux sinon
     */
    bool isKeepingBag() const;

    /*!
     * \brief Accesseur en lecture de l'état de réinitialisation du \ref BricsBag.
     *
     * \return vrai si le sac de briques est réinitialisé à sa valeur par défaut, faux sinon
     */
    bool isResettingBag() const;

    /*!
     * \brief Accesseur en lecture du multijoueur.
     * \return vrai si le joueur veut jouer en duo, faux sinon
     */
    bool isPlayingDuo() const;

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
     * \brief Accesseur en lecture de l'état d'activation de la victoire au temps.
     * \return vrai si la victoire au temps est activée, faux sinon
     */
    bool hasWinByTime() const;

private:
    /*!
     * \brief Méthode de conversion d'un unsigned (ms) en QTime (h:m:s:ms).
     * \param time la valeur de temps en millisecondes
     * \return le temps en heures, minutes, secondes et millisecondes
     */
    QTime convertUnsToTime(unsigned time);

private slots:
    /*!
     * \brief Méthode permettant de créer une \ref Bric personnalisée.
     *
     * Elle lance une exception si la brique est invalide
     */
    void setBrics();

    /*!
     * \brief Méthode permettant de cacher ou non le bouton du créateur de \ref Bric
     * en fonction de l'état de la QCheckBox.
     *
     * \param checked l'état de la QCheckBox
     */
    void hideSetBrics(bool checked);

    /*!
     * \brief Méthode permettant de cacher ou non les informations de connexion en duo
     * en fonction de l'état de la QCheckBox.
     *
     * \param checked l'état de la QCheckBox
     */
    void hideDuo(bool checked);

    /*!
     * \brief Méthode désactivant l'édition du score de victoire si cette condition de victoire est désactivée.
     *
     * \param checked vrai si la condition de victoire est activée, faux sinon
     */
    void toggleScore(bool checked);

    /*!
     * \brief Méthode désactivant l'édition du nombre de lignes de victoire si cette condition de victoire est désactivée.
     *
     * \param checked vrai si la condition de victoire est activée, faux sinon
     */
    void toggleLines(bool checked);

    /*!
     * \brief Méthode désactivant l'édition du temps de victoire si cette condition de victoire est désactivée.
     *
     * \param checked vrai si la condition de victoire est activée, faux sinon
     */
    void toggleTime(bool checked);
};

#endif // CONFIGDIALOG_H

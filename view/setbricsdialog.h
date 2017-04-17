#ifndef SETBRICSDIALOG_H
#define SETBRICSDIALOG_H

#include "../model/position.h"
#include <vector>
#include <QDialog>
#include <QLabel>

/*!
 * Namespace contenant la vue du \ref Tetris.
 */
namespace Ui {
    class SetBricsDialog;
}

/*!
 * \brief Classe représentant l'éditeur de \ref Bric personnalisées.
 */
class SetBricsDialog : public QDialog
{
    Q_OBJECT
    Ui::SetBricsDialog *ui;
    std::vector<GJ_GW::Position> saved_;
    std::vector<std::vector<bool>> checked_;

public:
    /*!
     * \brief Constructeur de \ref SetBricsDialog.
     * \param parent fenêtre ayant lancé cette fenêtre
     */
    explicit SetBricsDialog(QWidget *parent = 0);

    ~SetBricsDialog();

    /*!
     * \brief Accesseur en lecture de la forme de la \ref Bric personnalisée.
     *
     * \return la forme de la brique personnalisée
     */
    std::vector<GJ_GW::Position> getSaved() const;

private:
    /*!
     * \brief Méthode générant et affichant une grille de cases cliquables servant à créer une \ref Bric personnalisée.
     *
     * \param first vrai s'il s'agit de la 1ère génération, faux sinon
     */
    void generateGrid(bool first);

    /*!
     * \brief Méthode créant les QPushButton de la grille.
     *
     * \param x l'abscisse de la grille
     * \param y l'ordonnée de la grille
     * \return le QPushButton
     */
    QPushButton *createBtn(unsigned x, unsigned y);

    /*!
     * \brief Méthode créant les QLabel de la grille.
     *
     * Les QLabel correspondent aux QPushButton ayant été pressé.
     *
     * \return le QLabel
     */
    QLabel *createLb();

    /*!
     * \brief Méthode permettant d'appeler les destructeurs des éléments
     * contenu dans la grille.
     */
    void eraseBoard();

private slots:
    /*!
     * \brief Méthode permettant de rafraichir la grille après avoir cliqué sur un QPushButton.
     */
    void update();
};

#endif // SETBRICSDIALOG_H

#ifndef CONFIRMLAUNCHDIALOG_H
#define CONFIRMLAUNCHDIALOG_H

#include "../observer/observer.h"
#include <QDialog>

/*!
 * Namespace contenant la vue du \ref Tetris.
 */
namespace Ui {
class ConfirmLaunchDialog;
}

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{
class MultiTetris;
}
/*!
 * \brief Class représentant la fenêtre de confirmation que les 2 joueurs sont prêt
 */
class ConfirmLaunchDialog : public QDialog, public GJ_GW::Observer{
    Q_OBJECT
    Ui::ConfirmLaunchDialog *ui;
    GJ_GW::MultiTetris &game_;
    bool hasConfirm_;

public:
    /*!
     * \brief Constructeur de la fenêtre de \ref ConfirmLaunchDialog
     * \param game représente tétris permet de notify l'observer
     * \param parent QWidget qui permet d'utiliser QDialog
     */
    explicit ConfirmLaunchDialog(GJ_GW::MultiTetris &game, QWidget *parent = 0);

    /*!
     * \brief Destructeur de \ref ConfirmLaunchDialog
     */
    ~ConfirmLaunchDialog() noexcept;

    /*!
     * \brief permet de notify l'observer
     */
    void update(GJ_GW::Subject *);

private slots:
    /*!
     * \brief Méthode qui permet de notfié quand le joueur est ready quand le joueur
     * dis que il est pret le buton \ref yes se grise
     */
    void accept();

    /*!
     * \brief Méthode qui permet de notfié quand un joueur n'est pas pret et donc qui
     * cancel la fenêtre.
     */
    void reject();
};

#endif // CONFIRMLAUNCHDIALOG_H

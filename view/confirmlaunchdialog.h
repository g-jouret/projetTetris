#ifndef CONFIRMLAUNCHDIALOG_H
#define CONFIRMLAUNCHDIALOG_H

#include "../observer/observer.h"
#include <QDialog>

namespace Ui {
class ConfirmLaunchDialog;
}

namespace GJ_GW{
class MultiTetris;
}

class ConfirmLaunchDialog : public QDialog, public GJ_GW::Observer{
    Q_OBJECT
    Ui::ConfirmLaunchDialog *ui;
    GJ_GW::MultiTetris &game_;
    bool hasConfirm_;

public:
    explicit ConfirmLaunchDialog(GJ_GW::MultiTetris &game, QWidget *parent = 0);
    ~ConfirmLaunchDialog() noexcept;
    void update(GJ_GW::Subject *);

private slots:
    void accept();
    void reject();
};

#endif // CONFIRMLAUNCHDIALOG_H

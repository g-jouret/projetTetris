#ifndef CONFIRMLAUNCHDIALOG_H
#define CONFIRMLAUNCHDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmLaunchDialog;
}

class ConfirmLaunchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmLaunchDialog(QWidget *parent = 0);
    ~ConfirmLaunchDialog();

private:
    Ui::ConfirmLaunchDialog *ui;
};

#endif // CONFIRMLAUNCHDIALOG_H

#ifndef SETBRICSDIALOG_H
#define SETBRICSDIALOG_H

#include <QDialog>

namespace Ui {
class SetBricsDialog;
}

class SetBricsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetBricsDialog(QWidget *parent = 0);
    ~SetBricsDialog();

private:
    Ui::SetBricsDialog *ui;
};

#endif // SETBRICSDIALOG_H

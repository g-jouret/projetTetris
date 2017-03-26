#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = 0);
    ~ConfigDialog();

    std::string getName();
    unsigned getWidth();
    unsigned getHeight();
    unsigned getLevel();

private:
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H

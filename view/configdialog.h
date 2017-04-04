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
    explicit ConfigDialog(std::vector<unsigned> args, QWidget *parent = 0);
    ~ConfigDialog();

    std::string getName() const;
    unsigned getWidth() const;
    unsigned getHeight() const;
    unsigned getWinScore() const;
    unsigned getWinLines() const;
    unsigned getWinTime() const;
    unsigned getLevel() const;

private:
    Ui::ConfigDialog *ui;
    QTime convertUnsToTime(unsigned time);
};

#endif // CONFIGDIALOG_H

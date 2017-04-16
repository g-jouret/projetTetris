#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include "../model/bric.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
    std::vector<GJ_GW::Bric> brics_;

public:
    explicit ConfigDialog(std::string name, std::vector<unsigned> args, QWidget *parent = 0);
    ~ConfigDialog();
    std::string getName() const;
    unsigned getWidth() const;
    unsigned getHeight() const;
    unsigned getWinScore() const;
    unsigned getWinLines() const;
    unsigned getWinTime() const;
    unsigned getLevel() const;
    std::vector<GJ_GW::Bric> getBrics() const;
    bool isKeepingBag() const;
    bool isResettingBag() const;

private:
    Ui::ConfigDialog *ui;
    QTime convertUnsToTime(unsigned time);

private slots:
    void setBrics();
    void hideSetBrics(bool checked);
};

#endif // CONFIGDIALOG_H

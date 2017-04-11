#ifndef SETBRICSDIALOG_H
#define SETBRICSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <vector>
#include <model/position.h>

namespace Ui {
class SetBricsDialog;
}

using namespace GJ_GW;

class SetBricsDialog : public QDialog
{
    Q_OBJECT
    std::vector<Position> saved_;
    std::vector<std::vector<bool>> checked_;

public:
    explicit SetBricsDialog(QWidget *parent = 0);
    ~SetBricsDialog();
    std::vector<Position> getSaved() const;
    bool isKeepingBag() const;

private:
    Ui::SetBricsDialog *ui;
    void generateGrid(bool first);
    QPushButton *createBtn(QPushButton * btn, unsigned x, unsigned y);
    QLabel *createLb(QLabel * lb);


private slots:
    void update();
    void accept();
    void save();
    //void reset();
};

#endif // SETBRICSDIALOG_H

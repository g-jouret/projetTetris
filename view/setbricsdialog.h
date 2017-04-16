#ifndef SETBRICSDIALOG_H
#define SETBRICSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <vector>
#include <model/position.h>

namespace Ui {
class SetBricsDialog;
}

class SetBricsDialog : public QDialog
{
    Q_OBJECT
    std::vector<GJ_GW::Position> saved_;
    std::vector<std::vector<bool>> checked_;

public:
    explicit SetBricsDialog(QWidget *parent = 0);
    ~SetBricsDialog();
    std::vector<GJ_GW::Position> getSaved() const;

private:
    Ui::SetBricsDialog *ui;
    void generateGrid(bool first);
    QPushButton *createBtn(unsigned x, unsigned y);
    QLabel *createLb();


private slots:
    void update();
    void accept();
    //void save();
    //void reset();
};

#endif // SETBRICSDIALOG_H

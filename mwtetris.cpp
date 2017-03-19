#include "mwtetris.h"
#include "ui_mwtetris.h"

MWTetris::MWTetris(/*GJ_GW::*/Game * game, QWidget *parent) : QMainWindow(parent), game_{game}, ui(new Ui::MWTetris){
    ui->setupUi(this);

    connexion();

    game_->addObserver(this);

    time();

    update(game_);
}

MWTetris::~MWTetris() noexcept{
    game_->removeObserver(this);
    delete ui;
}

void MWTetris::connexion(){
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Quitter, &QAction::triggered, this, &MWTetris::quitGame);
    // TODO : aide? cf qtpendu.pdf
    connect(ui->btnDown, &QPushButton::clicked, this, &MWTetris::down);
    connect(ui->btnLeft, &QPushButton::clicked, this, &MWTetris::left);
    connect(ui->btnRight, &QPushButton::clicked, this, &MWTetris::right);
}

void MWTetris::createGame(){
    ConfigDialog cd {this};
    cd.setWindowTitle("Configuration de la partie");
    int ret = cd.exec();

    if(ret == QDialog::Rejected) return;

    /*std::string name {cd.getName()};
    unsigned width {cd.getWidth()};
    unsigned height {cd.getHeight()};

    if(! name.empty() || width != 0 || height != 0){
        game_->setPlayer(name, width, height);
    }*/
    game_->setPlayer(cd.getName(), cd.getWidth(), cd.getHeight());

    ui->lbEnd->hide();
    update(game_);

    //version test manuelle
    generateBric();
    update(game_);
}

void MWTetris::quitGame(){
    //delete game_; // bug? si présent le application::quit() ne fonctionne pas, double delete?
    //exit(0); // pas une bonne idée
    QApplication::quit();
}

void MWTetris::generateBoard(){
    std::vector</*GJ_GW::*/Position> theGrid {game_->getPlayer().getBoard().getGrid()};
    /*for(GJ_GW::Position p : game_->getPlayer().getBoard().getGrid()){
        QLabel * lb = new QLabel();
        if(p.isFilled()){
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, p.getY(), p.getX(), 1, 1);
    }*/

    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        if(it->isFilled()){
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, it->getY(), it->getX(), 1, 1);
    }
}

void MWTetris::resetBoard(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
    // WARNING : bug : ne répond plus quand trop grande diminution de la largeur(?)
}

void MWTetris::generateBric(){
    game_->getPlayer().generateBric();
}

void MWTetris::down(){
    game_->command(0);
}

void MWTetris::left(){
    game_->command(1);
}

void MWTetris::right(){
    game_->command(2);
}

void MWTetris::drop(){
    game_->command(3);
}

void MWTetris::turn(){
    game_->command(4);
}

void MWTetris::update(Subject *){
    if(QString::fromStdString(game_->getPlayer().getName()) != ui->lbPlayerName->text()){
        ui->lbPlayerName->setText(QString::fromStdString(game_->getPlayer().getName()));
    }
    resetBoard();
    generateBoard();
    if(game_->endGame()){
        ui->lbEnd->show();
    }
}

void MWTetris::time(){
    QString lb;
    unsigned time = (timer_.elapsed() / 1000);
    unsigned sec = (time % 60);
    unsigned min = ((time/60) % 60);
    unsigned hours = ((time/3600) % 24);
    lb.append(QString::number(hours));
    lb.append(":");
    if(min < 10)
        lb.append("0");
    lb.append(QString::number(min));
    lb.append(":");
    if(sec < 10)
        lb.append("0");
    lb.append(QString::number(sec));

    ui->lbTime->setText(lb);
}

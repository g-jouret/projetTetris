#include "mwtetris.h"
#include "ui_mwtetris.h"

MWTetris::MWTetris(Tetris * game, QWidget *parent) : QMainWindow(parent), game_{game}, ui(new Ui::MWTetris){
    ui->setupUi(this);
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Quitter, &QAction::triggered, this, &MWTetris::quitGame);
    // TODO : aide? cf qtpendu.pdf
    game_->addObserver(this);
    update(game_);

    time();
}

MWTetris::~MWTetris() noexcept{
    game_->removeObserver(this);
    delete ui;
}

void MWTetris::createGame(){
    ConfigDialog cd {this};
    cd.setWindowTitle("Configuration de la partie");
    int ret = cd.exec();

    if(ret == QDialog::Rejected) return;
    /*Tetris * game = new Tetris(cd.getName(), cd.getWidth(), cd.getHeight());
    game_->removeObserver(this);
    delete game_;
    game_ = game;
    game_->addObserver(this);
    update(game_);*/
    game_->startGame(cd.getName(), cd.getWidth(), cd.getHeight(), cd.getLevel());

    connect(ui->btnDown, &QPushButton::clicked, this, &MWTetris::drop);
    connect(ui->btnLeft, &QPushButton::clicked, this, &MWTetris::left);
    connect(ui->btnRight, &QPushButton::clicked, this, &MWTetris::right);
    connect(ui->btnUp, &QPushButton::clicked, this, &MWTetris::rotate);
    ui->lbEnd->hide();
}

void MWTetris::quitGame(){
    //delete game_; // bug? si présent le application::quit() ne fonctionne pas, double delete?
    //exit(0); // pas une bonne idée
    QApplication::quit();
}

void MWTetris::generateBoard(){
    /*std::vector<Position> theGrid {game_->getPlayer().getBoard().getGrid()};

    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        if(it->isFilled()){
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, it->getY(), it->getX(), 1, 1);
    }*/
}

void MWTetris::resetBoard(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
    // WARNING : bug : ne répond plus quand trop grande diminution de la largeur(?)
}

void MWTetris::left(){
    game_->checkMove(Direction::LEFT);
}

void MWTetris::right(){
    game_->checkMove(Direction::RIGHT);
}

void MWTetris::rotate(){
    game_->checkRotate();
}

void MWTetris::drop(){
    game_->drop();
}

void MWTetris::update(Subject *){
    if(QString::fromStdString(game_->getPlayer().getName()) != ui->lbPlayerName->text()){
        ui->lbPlayerName->setText(QString::fromStdString(game_->getPlayer().getName()));
    }
    if(QString::number(game_->getPlayer().getScore()) != ui->lbPlayerScore->text()){
        ui->lbPlayerScore->setText(QString::number(game_->getPlayer().getScore()));
    }
    resetBoard();
    generateBoard();
    if(game_->isGameOver()){
        ui->lbEnd->show();
    }
}

// WARNING : incorrect
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

#include "mwtetris.h"
#include "ui_mwtetris.h"

MWTetris::MWTetris(Tetris game, QWidget *parent) : QMainWindow(parent), game_{game}, ui(new Ui::MWTetris){
    ui->setupUi(this);
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Quitter, &QAction::triggered, this, &MWTetris::quitGame);
    // TODO : aide? cf qtpendu.pdf
    connect(ui->btnDown, &QPushButton::clicked, this, &MWTetris::drop);
    connect(ui->btnLeft, &QPushButton::clicked, this, &MWTetris::left);
    connect(ui->btnRight, &QPushButton::clicked, this, &MWTetris::right);
    connect(ui->btnUp, &QPushButton::clicked, this, &MWTetris::rotate);
    ui->btnUp->setDisabled(true);
    ui->btnDown->setDisabled(true);
    ui->btnLeft->setDisabled(true);
    ui->btnRight->setDisabled(true);
    game_.addObserver(this);
    update(&game_);

    time();
}

MWTetris::~MWTetris() noexcept{
    game_.removeObserver(this);
    delete ui;
}

void MWTetris::createGame(){
    ConfigDialog cd {this};
    cd.setWindowTitle("Configuration de la partie");
    int ret = cd.exec();

    if(ret == QDialog::Rejected) return;

    std::string name;
    unsigned score, width, height;
    name = (cd.getName().empty())? game_.getPlayer().getName() : cd.getName();
    score = (cd.getName().empty())? game_.getPlayer().getScore() : 0;
    width = (cd.getWidth() == 0)? game_.getBoard().getWidth() : cd.getWidth();
    height = (cd.getHeight() == 0)? game_.getBoard().getHeight() : cd.getHeight();

    game_.startGame(name, score, width, height, cd.getLevel());

    ui->lbEnd->hide();
    ui->btnUp->setEnabled(true);
    ui->btnDown->setEnabled(true);
    ui->btnLeft->setEnabled(true);
    ui->btnRight->setEnabled(true);
}

void MWTetris::quitGame(){
    QApplication::quit();
}

void MWTetris::generateBoard(){
    std::map<Position, bool> theGrid {game_.getBoard().getGrid()};

    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        if(it->second){
            lb->setStyleSheet("QLabel {background-color : blue;}");
        } else{
            lb->setStyleSheet("QLabel {background-color : white;}");
        }
        ui->boardGrid->addWidget(lb, it->first.getY(), it->first.getX(), 1, 1);
    }
}

void MWTetris::resetBoard(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
    // WARNING : bug : ne répond plus quand trop grande diminution de la largeur(?)
}

void MWTetris::left(){
    game_.checkMove(Direction::LEFT);
}

void MWTetris::right(){
    game_.checkMove(Direction::RIGHT);
}

void MWTetris::rotate(){
    game_.checkRotate();
}

void MWTetris::drop(){
    game_.drop();
}

void MWTetris::update(Subject *){
    switch (game_.getGameState()){
    case GameState::NONE:
        if(QString::fromStdString(game_.getPlayer().getName()) != ui->lbPlayerName->text()){
            ui->lbPlayerName->setText(QString::fromStdString(game_.getPlayer().getName()));
        }
    case GameState::ON:
        if(QString::number(game_.getPlayer().getScore()) != ui->lbPlayerScore->text()){
            ui->lbPlayerScore->setText(QString::number(game_.getPlayer().getScore()));
        }
        resetBoard();
        generateBoard();
        break;
    case GameState::LOOSE:
        ui->lbEnd->setText(QString::fromStdString("Vous avez PERDU"));
        endGame();
        break;
    case GameState::LINE:
        ui->lbEnd->setText(QString::fromStdString("Vous avez gagné LIGNE"));
        endGame();
        break;
    case GameState::SCORE:
        ui->lbEnd->setText(QString::fromStdString("Vous avez gagné SCORE"));
        endGame();
    break;
    case GameState::TIME:
        ui->lbEnd->setText(QString::fromStdString("Vous avez gagné TEMPS"));
        endGame();
        break;
    default:
        break;
    }
}

void MWTetris::endGame(){
    /*disconnect(ui->btnDown, 0, 0, 0);
    disconnect(ui->btnLeft, 0, 0, 0);
    disconnect(ui->btnRight, 0, 0, 0);
    disconnect(ui->btnUp, 0, 0, 0);*/
    ui->btnUp->setDisabled(true);
    ui->btnDown->setDisabled(true);
    ui->btnLeft->setDisabled(true);
    ui->btnRight->setDisabled(true);
    ui->lbEnd->show();
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

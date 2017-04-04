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
    time_ = new QTimer(this);
    connect(time_, SIGNAL(timeout()), this, SLOT(time()));
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(next()));

    game_.addObserver(this);
    update(&game_);
}

MWTetris::~MWTetris() noexcept{
    game_.removeObserver(this);
    delete ui;
}

void MWTetris::createGame(){
    std::vector<unsigned> args {game_.MAXIMUM_SIZE_NAME,
        game_.MINIMUM_WIDTH, game_.MAXIMUM_WIDTH, game_.getBoard().getWidth(),
        game_.MINIMUM_HEIGHT, game_.MAXIMUM_HEIGHT, game_.getBoard().getHeight(),
        game_.MINIMUM_WIN_SCORE, game_.MAXIMUM_WIN_SCORE, game_.getWinScore(),
        game_.MINIMUM_WIN_LINES, game_.MAXIMUM_WIN_LINES, game_.getWinLines(),
        game_.MINIMUM_WIN_TIME, game_.MAXIMUM_WIN_TIME, game_.getWinTime(),
        game_.MINIMUM_LEVEL, game_.MAXIMUM_LEVEL};
    ConfigDialog cd (game_.getPlayer().getName(), args, this);
    cd.setWindowTitle("Configuration de la partie");
    int ret = cd.exec();

    if(ret == QDialog::Rejected) return;

    std::string name;
    //unsigned score;
    name = (cd.getName().empty())? game_.getPlayer().getName() : cd.getName();
    //score = (name == game_.getPlayer().getName())? game_.getPlayer().getScore() : 0;

    game_.startGame(name, /*score,*/ cd.getWidth(), cd.getHeight(),
                    cd.getWinScore(), cd.getWinLines(), cd.getWinTime(),
                    cd.getLevel());

    chrono_.start();
    time_->start(1000);
    timer_->start(game_.getTimer());

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
    ui->boardGrid->setSpacing(2);
    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();
        lb->setStyleSheet("QLabel[fill=true]{"
                          "background-color : blue;"
                          "}"
                          "QLabel[empty=true]{"
                          "background-color : white;"
                          "}");
        if(it->second){
            lb->setProperty("fill", true);
        } else{
            lb->setProperty("empty", true);
        }
        ui->boardGrid->addWidget(lb, it->first.getY(), it->first.getX(), 1, 1);
    }

}

void MWTetris::resetBoard(){
    QLayoutItem *child;
    while((child = ui->boardGrid->takeAt(0)) != 0){
        delete child->widget();
    }
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
        ui->lbPlayerScore->setText(QString::number(game_.getPlayer().getScore()) + "/" + QString::number(game_.getWinScore()));
        ui->lbPlayerLines->setText(QString::number(game_.getPlayer().getNbLines()) + "/" + QString::number(game_.getWinLines()));
        if(timer_->interval() != game_.getTimer())
            timer_->setInterval(game_.getTimer());
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
    time_->stop();
    timer_->stop();
    ui->lbEnd->show();
}

void MWTetris::time(){
    QString lb;
    unsigned time = (chrono_.elapsed() / 1000);
    unsigned sec = (time % 60);
    unsigned min = ((time/60) % 60);
    //unsigned hours = ((time/3600) % 24);
    //lb.append(QString::number(hours));
    //lb.append(":");
    if(min < 10)
        lb.append("0");
    lb.append(QString::number(min));
    lb.append(":");
    if(sec < 10)
        lb.append("0");
    lb.append(QString::number(sec));

    ui->lbTime->setText(lb);
}

void MWTetris::next(){
    game_.next(chrono_.elapsed());
}

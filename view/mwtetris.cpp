#include "mwtetris.h"
#include "ui_mwtetris.h"
#include "model/direction.h"
#include "configdialog.h"
#include <sstream>
#include <QTimer>
#include <QErrorMessage>
#include "display.h"

MWTetris::MWTetris(Tetris game, QWidget *parent) : QMainWindow(parent), game_{game}, ui(new Ui::MWTetris){
    ui->setupUi(this);
    this->resize(640,640);
    initLang();
    connect(ui->action_Nouveau, &QAction::triggered, this, &MWTetris::createGame);
    connect(ui->action_Quitter, &QAction::triggered, this, &MWTetris::quitGame);
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
    timer_->stop();
    std::vector<unsigned> args {15,     //maximum size of player name
                                game_.MINIMUM_WIDTH, game_.MAXIMUM_WIDTH, game_.getBoard().getWidth(),
                                        game_.MINIMUM_HEIGHT, game_.MAXIMUM_HEIGHT, game_.getBoard().getHeight(),
                                        game_.MINIMUM_WIN_SCORE, game_.MAXIMUM_WIN_SCORE, game_.getWinScore(),
                                        game_.MINIMUM_WIN_LINES, game_.MAXIMUM_WIN_LINES, game_.getWinLines(),
                                        game_.MINIMUM_WIN_TIME, game_.MAXIMUM_WIN_TIME, game_.getWinTime(),
                                        0, 8};      //minimum and maximum level
    ConfigDialog cd (game_.getPlayer().getName(), args, this);
    cd.setWindowTitle("Configuration de la partie");
    int ret = cd.exec();
    if(ret == QDialog::Rejected){
        timer_->start(game_.getTimer());
    } else{
        std::string name;
        name = (cd.getName().empty())? game_.getPlayer().getName() : cd.getName();
        try{
            game_.startGame(name, cd.getWidth(), cd.getHeight(),
                            cd.getWinScore(), cd.getWinLines(), cd.getWinTime(),
                            cd.getLevel());
            chrono_.restart();
            time_->start(1000);
            timer_->start(game_.getTimer());

            ui->lbEnd->hide();
            ui->btnUp->setEnabled(true);
            ui->btnDown->setEnabled(true);
            ui->btnLeft->setEnabled(true);
            ui->btnRight->setEnabled(true);
        } catch(const std::invalid_argument & e){
            QErrorMessage * except = new QErrorMessage(this);
            except->showMessage(e.what());
        }
    }
}

void MWTetris::quitGame(){
    QApplication::quit();
}

void MWTetris::initLang(){
    ui->lbName->setText("Joueur :");
    ui->lbScore->setText("Score :");
    ui->lbLines->setText("Nombre de lignes :");
    ui->lbTimer->setText("Temps écoulé :");
    /*ui->btnUp->setText("Haut");
    ui->btnDown->setText("Bas");
    ui->btnLeft->setText("Gauche");
    ui->btnRight->setText("Droite");    /!\ bug avec les shortcuts => redéfinition en code
    //ui->lbName->setText(QString(lang[FR][LBNAME]));
    /*ui->lbScore->setText(Display::lbScore::fr);
    ui->lbLines->setText(Display::lbLines::fr);
    ui->lbTimer->setText(Display::lbTimer::fr);
    ui->btnUp->setText(Display::btnUp::fr);
    ui->btnDown->setText(Display::btnDown::fr);*/
}

void MWTetris::generateBoard(){
    std::map<Position, Color> theGrid {game_.getBoard().getGrid()};
    for(auto it = theGrid.begin(); it != theGrid.end(); ++it){
        QLabel * lb = new QLabel();

        /*std::stringstream stream;
        stream << "#" << std::hex;
        if(it->second.getCode().at(0)/10 == 0)
            stream << 0;
        stream << it->second.getCode().at(0);
        if(it->second.getCode().at(1)/10 == 0)
            stream << 0;
        stream << it->second.getCode().at(1);
        if(it->second.getCode().at(2)/10 == 0)
            stream << 0;
        stream << it->second.getCode().at(2);*/
        QColor color(it->second.getCode().at(0),
                     it->second.getCode().at(1),
                     it->second.getCode().at(2));
        lb->setStyleSheet("QLabel{"
                          "width: 20px;"
                          "height: 20px;"
                          //"background-color : "+ QString::fromStdString(stream.str()) +";"
                          "background-color : "+ color.name() +";}");
        ui->boardGrid->addWidget(lb, it->first.getY(), it->first.getX(), 1, 1);
    }
}

void MWTetris::resetBoard(QGridLayout * board){
    QLayoutItem *child;
    while((child = board->takeAt(0)) != 0){
        delete child->widget();
    }
}

void MWTetris::showNextBric(){
    Bric theBric = game_.getNextBric();
    unsigned side = (theBric.isEven())? (theBric.getMiddle().getX()*2)+2 : (theBric.getMiddle().getX()*2)+1;
    for(unsigned u {0}; u < side; ++u){
        for(unsigned v {0}; v < side; ++v){
            QLabel * lb = new QLabel();

            /*std::stringstream stream;
            stream << "#" << std::hex;
            Position temp = Position(u, v);
            if(theBric.contains(temp)){
                if(theBric.getColor().getCode().at(0)/10 == 0)
                    stream << 0;
                stream << theBric.getColor().getCode().at(0);
                if(theBric.getColor().getCode().at(1)/10 == 0)
                    stream << 0;
                stream << theBric.getColor().getCode().at(1);
                if(theBric.getColor().getCode().at(2)/10 == 0)
                    stream << 0;
                stream << theBric.getColor().getCode().at(2);
            } else{
                stream << 0xffffff;
            }*/
            Position temp = Position(u, v);
            QColor color;
            if(theBric.contains(temp)){
                color = QColor(theBric.getColor().getCode().at(0),
                               theBric.getColor().getCode().at(1),
                               theBric.getColor().getCode().at(2));
            } else{
                color= QColor(255,255,255);
            }
            lb->setStyleSheet("QLabel{"
                              "width: 20px;"
                              "height: 20px;"
                              //"background-color : "+ QString::fromStdString(stream.str()) +";"
                              "background-color : "+ color.name() +";}");
            ui->boardNext->addWidget(lb, v, u, 1, 1);
        }
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
    unsigned width;
    unsigned height;
    switch (game_.getGameState()){
    case GameState::NONE:
        if(QString::fromStdString(game_.getPlayer().getName()) != ui->lbPlayerName->text()){
            ui->lbPlayerName->setText(QString::fromStdString(game_.getPlayer().getName()));
        }
        width = (23)*game_.getBoard().getWidth();
        height = (23)*game_.getBoard().getHeight() + ui->menuBar->height();
        ui->boardGrid->setGeometry(QRect (0, 0, width, height));
        ui->infoBox->setGeometry(QRect (width, 0, 350, 650));
        //width += 350;
        //height = (height > 650)? height : 650;
        //ui->centralWidget->resize(width,height);
        //this->resize(width,height);
    case GameState::ON:
        ui->lbPlayerScore->setText(QString::number(game_.getPlayer().getScore()) + "/" + QString::number(game_.getWinScore()));
        ui->lbPlayerLines->setText(QString::number(game_.getPlayer().getNbLines()) + "/" + QString::number(game_.getWinLines()));
        if(timer_->interval() != game_.getTimer())
            timer_->setInterval(game_.getTimer());
        resetBoard(ui->boardGrid);
        resetBoard(ui->boardNext);
        generateBoard();
        showNextBric();
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

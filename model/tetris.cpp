#include "tetris.h"
#include "direction.h"
#include "linestate.h"
#include <stdexcept>
#include <QTimer>
#include <iostream>
#include <algorithm>

using namespace GJ_GW;

Tetris::Tetris(): QObject(), level_ {0}, winScore_{validateWinScore(3000)},
    winLines_{validateWinLines(50)}, winTime_{validateWinTime(300000)},
    gameState_{GameState::NONE}, board_{Board(validateWidth(10), validateHeight(20))},
    winByScore_{1}, winByLines_{1}, winByTime_{1}, paused_{1}{
    savedTime_ = 0;
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(next()));
}

unsigned Tetris::getLevel() const{
    unsigned lvl = level_ + (player_.nbLines_/10);
    return (lvl > 6)? 6 : lvl;
}

bool Tetris::isPaused() const{
    return paused_;
}

unsigned Tetris::getWinScore() const{
    return winScore_;
}

unsigned Tetris::getWinLines() const{
    return winLines_;
}

unsigned Tetris::getWinTime() const{
    return winTime_;
}

Player Tetris::getPlayer() const{
    return player_;
}

Bric Tetris::getNextBric() const{
    return bag_.getNextBric();
}

Board Tetris::getBoard() const{
    return board_;
}

GameState Tetris::getGameState() const{
    return gameState_;
}

unsigned Tetris::getTimeElapsed() const{
    if(paused_) return savedTime_/1000;
    return (savedTime_ + chrono_.elapsed())/1000;
}

bool Tetris::hasWinByScore() const{
    return winByScore_;
}

bool Tetris::hasWinByLines() const{
    return winByLines_;
}

bool Tetris::hasWinByTime() const{
    return winByTime_;
}

void Tetris::setBag(std::vector<Bric> newBag, bool keepBag){
    if(keepBag){
        bag_.add(newBag);
    } else{
        bag_ = BricsBag(newBag);
    }
}

void Tetris::resetBag(){
    bag_ = BricsBag();
}

void Tetris::initGame(std::string name, unsigned width, unsigned height,
                      unsigned winScore, unsigned winLines, unsigned winTime,
                      unsigned level, bool winByScore, bool winByLines,
                      bool winByTime){
    player_.setPlayer(name);
    board_ = Board(validateWidth(width), validateHeight(height));
    winScore_ = validateWinScore(winScore);
    winLines_ = validateWinLines(winLines);
    winTime_ = validateWinTime(winTime);
    winByScore_ = winByScore;
    winByLines_ = winByLines;
    winByTime_ = winByTime;
    level_ = level;
    timer_->setInterval(MAXIMUM_TIMER);
    for(unsigned u {0}; u < level; ++u){
        setTimer();
    }
    savedTime_ = 0;
    paused_ = 1;
    gameState_ = GameState::INITIALIZED;
}

void Tetris::startGame(){
    if(gameState_ == GameState::INITIALIZED){
        generateBric(true);
        resume();
    }
}

unsigned Tetris::validateWidth(unsigned width){
    if(width < MINIMUM_WIDTH || width > MAXIMUM_WIDTH){
        throw std::invalid_argument(message("largeur", width, MINIMUM_WIDTH, MAXIMUM_WIDTH));
    }
    return width;
}

unsigned Tetris::validateHeight(unsigned height){
    if(height < MINIMUM_HEIGHT || height > MAXIMUM_HEIGHT){
        throw std::invalid_argument(message("hauteur", height, MINIMUM_HEIGHT, MAXIMUM_HEIGHT));
    }
    return height;
}

unsigned Tetris::validateWinScore(unsigned winScore){
    if(winScore < MINIMUM_WIN_SCORE || winScore > MAXIMUM_WIN_SCORE){
        throw std::invalid_argument(message("score de victoire", winScore, MINIMUM_WIN_SCORE, MAXIMUM_WIN_SCORE));
    }
    return winScore;
}

unsigned Tetris::validateWinLines(unsigned winLines){
    if(winLines < MINIMUM_WIN_LINES || winLines > MAXIMUM_WIN_LINES){
        throw std::invalid_argument(message("nombre de lignes de victoire", winLines, MINIMUM_WIN_LINES, MAXIMUM_WIN_LINES));
    }
    return winLines;
}

unsigned Tetris::validateWinTime(unsigned winTime){
    if(winTime < MINIMUM_WIN_TIME || winTime > MAXIMUM_WIN_TIME){
        throw std::invalid_argument(message("temps de victoire", winTime, MINIMUM_WIN_TIME, MAXIMUM_WIN_TIME));
    }
    return winTime;
}

std::string Tetris::message(const std::string &label, unsigned value, unsigned min, unsigned max){
    return label +" non valide : "+ std::to_string(value) +" n'est pas compris entre "+ std::to_string(min) +" et "+ std::to_string(max);
}

void Tetris::generateBric(bool first){
    bool ok {1};
    unsigned count{0};
    bag_.shuffle(first);
    currentBric_ = bag_.getCurrentBric();
    unsigned midBoard = board_.width_/2;
    unsigned midBric = currentBric_.middle_.getX() + 1;

    for(unsigned u {0}; u < midBoard-midBric; ++u){
        currentBric_.move(Direction::RIGHT);
    }
    while(ok && count < currentBric_.shape_.size()){
        ok = board_.checkCase(currentBric_.shape_.at(count));
        ++count;
    }

    if(ok){
        for(Position p : currentBric_.shape_){
            boardSwapCase(p, currentBric_.color_);
        }
        setGameState(GameState::NEW_BRIC);
    } else{
        setGameState(GameState::LOOSE);
    }
}

void Tetris::drop(){
    unsigned count {0};
    bool ok {1};
    while(ok){
        ok = checkMove(Direction::DOWN);
        ++count;
    }
    checkLines(currentBric_.getHigherY(), count);
    notifyObservers();
}

bool Tetris::checkMove(Direction dir){
    bool ok {1};
    unsigned count {0};
    Bric destination = currentBric_;
    destination.move(dir);
    while(ok && count < destination.shape_.size()){
        if(! currentBric_.contains(destination.shape_.at(count))){
            ok = board_.checkCase(destination.shape_.at(count));
        }
        ++count;
    }
    if(ok)
        moveBric(dir);
    return ok;
}

void Tetris::checkRotate(){
    bool ok {1};
    unsigned count {0};
    Bric destination = currentBric_;
    destination.rotate();
    while(ok && count < destination.shape_.size()){
        if(! currentBric_.contains(destination.shape_.at(count))){
            ok = board_.checkCase(destination.shape_.at(count));
        }
        ++count;
    }
    if(ok){
        rotateBric();
    }
}

void Tetris::rotateBric(){
    for(Position p : currentBric_.shape_){
        boardSwapCase(p, Color());
    }
    currentBric_.rotate();
    for(Position p : currentBric_.shape_){
        boardSwapCase(p, currentBric_.color_);
    }
    notifyObservers();
}

void Tetris::moveBric(Direction dir){
    for(Position p : currentBric_.shape_){
        boardSwapCase(p, Color());
    }
    currentBric_.move(dir);
    for(Position p : currentBric_.shape_){
        boardSwapCase(p, currentBric_.color_);
    }
    if(dir != Direction::DOWN)
        notifyObservers();
}

unsigned Tetris::checkLines(unsigned top, unsigned dropsCount){
    unsigned linesFilled;
    linesFilled = board_.checkColumn(top);
    if(player_.setNbLines(linesFilled))
        setLevel();
    player_.setScore(dropsCount, linesFilled);
    if(player_.score_ >= winScore_){
        if(winByScore_)
            setGameState(GameState::SCORE);
    } else if(player_.nbLines_ >= winLines_){
        if(winByLines_)
            setGameState(GameState::LINE);
    }
    return linesFilled;
}

void Tetris::setGameState(GameState gameState){
    gameState_ = gameState;
    if(gameState_ > GameState::ON){
        pause();
    } else{
        notifyObservers();
    }
    if(gameState_ == GameState::NEW_BRIC){
        setGameState(GameState::ON);
    }
}

void Tetris::next(){
    unsigned timeElapsed {getTimeElapsed()};
    if(timeElapsed < winTime_ || !winByTime_){
        if(! checkMove(Direction::DOWN)){
            checkLines(currentBric_.getHigherY(), 0);
            if(gameState_ == GameState::ON){
                generateBric();
            }
        }
        notifyObservers();
    } else{
        if(winByTime_)
            setGameState(GameState::TIME);
    }
}

void Tetris::pause(){
    if(!paused_){
        savedTime_ += chrono_.elapsed();
        timer_->stop();
        paused_ = 1;
        notifyObservers();
    }
}

void Tetris::resume(){
    if(paused_){
        chrono_.restart();
        timer_->start();
        paused_ = 0;
        notifyObservers();
    }
}

void Tetris::setLevel(){
    timer_->setInterval(MAXIMUM_TIMER);
    for(unsigned u {0}; u < level_+(player_.nbLines_/10); ++u){
        if(timer_->interval() > MINIMUM_TIMER)
            setTimer();
    }
}

void Tetris::setTimer(){
    timer_->setInterval(timer_->interval()-200);
    if(timer_->interval() < MINIMUM_TIMER)
        timer_->setInterval(MINIMUM_TIMER);
}



void Tetris::boardSwapCase(Position &pos, Color color){
    board_.swapCase(pos, color);
}

Bric Tetris::getCurrentBric() const{
    return currentBric_;
}

std::vector<unsigned> Tetris::getCurrentBricY() const{
    std::vector<unsigned> tempY;
    for(Position p : currentBric_.shape_){
        tempY.push_back(p.getY());
    }
    std::sort(tempY.begin(), tempY.end(), std::greater<int>());
    tempY.erase(std::unique(tempY.begin(), tempY.end()), tempY.end());
    return tempY;
}

void Tetris::addLine(QList<QString> line){
    std::vector<unsigned> grey{128,128,128};
    Color greyColor(grey);
    for(int i{0}; i < line.count(QString::number(-1)); ++i){
        for(unsigned u {0}; u < board_.getHeight(); ++u){
            LineState state {board_.checkRow(u)};
            if(state != LineState::EMPTY) {
                board_.moveLine(u,-1, currentBric_);
            }
        }
        unsigned count = 0;
        while(count < board_.getWidth() && line.at(count).toInt() != -1){
            Position pos(line.at(count).toInt(), (board_.getHeight()-1));
            boardSwapCase(pos, greyColor);
            ++count;
        }
    }
}

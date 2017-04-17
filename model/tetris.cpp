#include "tetris.h"
#include "direction.h"
#include <stdexcept>

using namespace GJ_GW;

Tetris::Tetris(std::string &name): level_ {0}, timer_ {MAXIMUM_TIMER}, winScore_{validateWinScore(3000)},
    winLines_{validateWinLines(50)}, winTime_{validateWinTime(300000)}, gameState_{GameState::NONE},
    player_{Player(name)}, board_{Board(validateWidth(10), validateHeight(20))}
{}

unsigned Tetris::getLevel() const{
    unsigned lvl = level_ + (player_.nbLines_/10);
    return (lvl > 6)? 6 : lvl;
}

unsigned Tetris::getTimer() const{
    return timer_;
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

void Tetris::startGame(std::string name, unsigned width, unsigned height,
                       unsigned winScore, unsigned winLines, unsigned winTime,
                       unsigned level){
    level_ = level;
    timer_ = MAXIMUM_TIMER;
    for(unsigned u {0}; u < level; ++u){
        setTimer();
    }
    player_.setPlayer(name);
    board_ = Board(validateWidth(width), validateHeight(height));
    winScore_ = validateWinScore(winScore);
    winLines_ = validateWinLines(winLines);
    winTime_ = validateWinTime(winTime);
    setGameState(GameState::NONE);
    generateBric(true);
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
        if(first)
            setGameState(GameState::ON);
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

void Tetris::checkLines(unsigned top, unsigned dropsCount){
    unsigned linesFilled;
    linesFilled = board_.checkColumn(top);
    if(player_.setNbLines(linesFilled))
        setLevel();
    player_.setScore(dropsCount, linesFilled);
    if(player_.score_ >= winScore_){
        setGameState(GameState::SCORE);
    } else if(player_.nbLines_ >= winLines_){
        setGameState(GameState::LINE);
    }
}

void Tetris::setGameState(GameState gameState){
    gameState_ = gameState;
    notifyObservers();
}

void Tetris::next(unsigned timeElapsed){
    if(timeElapsed < winTime_){
        if(! checkMove(Direction::DOWN)){
            checkLines(currentBric_.getHigherY(), 0);
            generateBric();
        }
        notifyObservers();
    } else{
        setGameState(GameState::TIME);
    }
}

void Tetris::setLevel(){
    timer_ = MAXIMUM_TIMER;

    for(unsigned u {0}; u < level_+(player_.nbLines_/10); ++u){
        setTimer();
    }
}

void Tetris::setTimer(){
    if(timer_ > MINIMUM_TIMER)
        timer_ -= 200;
    if(timer_ < MINIMUM_TIMER)
        timer_ = MINIMUM_TIMER;
}

void Tetris::boardSwapCase(Position &pos, Color color){
    board_.swapCase(pos, color);
}

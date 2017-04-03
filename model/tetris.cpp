#include "tetris.h"

using namespace GJ_GW;

Tetris::Tetris(): timer_ {MAXIMUM_TIMER}, gameOver_{1}, player_{Player("Joueur")},
    board_{Board(10u, 20u)}
{}

/*Tetris::Tetris(std::string name, unsigned width, unsigned height):
{

    generateBric();
}*/

Player Tetris::getPlayer() const{
    return player_;
}

Bric Tetris::getCurrentBric() const{
    return currentBric_;
}

Board Tetris::getBoard() const{
    return board_;
}

bool Tetris::isGameOver() const{
    return gameOver_;
}

void Tetris::setBag(bool keepDefault){
    // TODO : implémentation de la génération de briques perso
}

void Tetris::startGame(std::string name, unsigned width, unsigned height, unsigned level){
    timer_ = MAXIMUM_TIMER;
    for(unsigned u {0}; u < level; ++u){
        setTimer();
    }
    gameOver_ = 0;
    if(! name.empty())
        player_.setName(name);
    player_.resetNbLines();
    setBoard(validateWidth(width), validateHeight(height));
    bag_.shuffle(true);
    //currentBric_ = bag_.getNextBric();
    generateBric();
}

void Tetris::setBoard(unsigned width, unsigned height){
    board_ = Board(width, height);
}

unsigned Tetris::validateWidth(unsigned value){
    return (value == 0)? board_.getWidth() : value;
}

unsigned Tetris::validateHeight(unsigned value){
    return (value == 0)? board_.getHeight() : value;
}

void Tetris::generateBric(){
    currentBric_ = bag_.getNextBric();
    bool ok {1};
    unsigned count{0};
    unsigned midBoard = board_.getWidth()/2;
    unsigned midSide = currentBric_.getSide()/2;

    for(unsigned i = 0; i < midBoard-midSide; ++i){
        currentBric_.move(Direction::RIGHT);
    }
    while(ok && count < currentBric_.getShape().size()){
        ok = board_.checkCase(currentBric_.getShape().at(count));
        ++count;
    }

    if(ok){
        for(Position p : currentBric_.getShape()){
            board_.swapCase(p);
        }
    } else{
        endGame(/* status : loose */);
    }
    notifyObservers();
}

void Tetris::drop(){
    unsigned count {0};
    bool ok {1};
    while(ok){
        ok = checkMove(Direction::DOWN, count);
        ++count;
    }
    //checkLines(count);
}

bool Tetris::checkMove(Direction dir, unsigned dropsCount){
    bool ok {1};
    unsigned count {0};
    Bric destination = currentBric_;
    destination.move(dir);
    while(ok && count < destination.getShape().size()){
        if(! currentBric_.contains(destination.getShape().at(count))){
            ok = board_.checkCase(destination.getShape().at(count));
        }
        ++count;
    }
    if(ok)
        moveBric(dir);
    if(! ok && dir == Direction::DOWN){
        checkLines(currentBric_.getHigherY(), dropsCount);
        bag_.shuffle();
        //currentBric_ = bag_.getNextBric();
        generateBric();
    }
    return ok;
}

void Tetris::checkRotate(){
    bool ok {1};
    unsigned count {0};
    Bric destination = currentBric_;
    destination.rotate();
    while(ok && count < destination.getShape().size()){
        if(! currentBric_.contains(destination.getShape().at(count))){
            ok = board_.checkCase(destination.getShape().at(count));
        }
        ++count;
    }
    if(ok)
        rotateBric();
}

void Tetris::rotateBric(){
    currentBric_.rotate();
    notifyObservers();
}

void Tetris::moveBric(Direction dir){
    for(Position p : currentBric_.getShape()){
        board_.swapCase(p);
    }
    currentBric_.move(dir);
    for(Position p : currentBric_.getShape()){
        board_.swapCase(p);
    }
    if(dir != Direction::DOWN)
        notifyObservers();
}

void Tetris::checkLines(unsigned top, unsigned dropsCount){
    unsigned linesFilled;
    linesFilled = board_.checkColumn(top);
    player_.setNbLines(linesFilled);
    player_.setScore(dropsCount, linesFilled);
    if(player_.getScore() >= 200){
        endGame(/* score */);
    } else if(player_.getNbLines() >= 2){
        endGame(/* nbLines */);
    }
    notifyObservers();
}

void Tetris::endGame(){
    // TODO : implémentation time
    gameOver_ = 1;
    notifyObservers();
}

void Tetris::next(){
    // TODO : implémentation itératif
    checkMove(Direction::DOWN);
    notifyObservers();
}

void Tetris::setLevel(){
    if(player_.getNbLines()%5 == 0)
        setTimer();
}

void Tetris::setTimer(){
    if(timer_ > MINIMUM_TIMER)
        timer_ -= 500;
    if(timer_ < MINIMUM_TIMER)
        timer_ = MINIMUM_TIMER;
}

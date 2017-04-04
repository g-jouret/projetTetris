#include "tetris.h"

using namespace GJ_GW;

Tetris::Tetris(): timer_ {MAXIMUM_TIMER}, gameState_{GameState::NONE}, player_{Player("Joueur")},
    board_{Board(10u, 20u)}
{}

Player Tetris::getPlayer() const{
    return player_;
}

Bric Tetris::getCurrentBric() const{
    return currentBric_;
}

Board Tetris::getBoard() const{
    return board_;
}

GameState Tetris::getGameState() const{
    return gameState_;
}

void Tetris::setBag(bool keepDefault){
    // TODO : implémentation de la génération de briques perso
}

void Tetris::startGame(std::string name, unsigned score, unsigned width, unsigned height, unsigned level){
    gameState_ = GameState::NONE;
    timer_ = MAXIMUM_TIMER;
    for(unsigned u {0}; u < level; ++u){
        setTimer();
    }
    player_.setName(name);
    player_.setScore(score);
    player_.resetNbLines();
    setBoard(validateWidth(width), validateHeight(height));
    notifyObservers();
    generateBric(true);
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

void Tetris::generateBric(bool first){
    bool ok {1};
    unsigned count{0};
    bag_.shuffle(first);
    currentBric_ = bag_.getCurrentBric();
    unsigned midBoard = board_.getWidth()/2;
    unsigned midSide = currentBric_.getMiddle().getX();

    for(unsigned u {0}; u < midBoard-midSide; ++u){
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
        setGameState(GameState::ON);
    } else{
        setGameState(GameState::LOOSE);
    }
}

void Tetris::drop(){
    unsigned count {0};
    bool ok {1};
    while(ok){
        ok = checkMove(Direction::DOWN, count);
        ++count;
    }
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
        generateBric();
    }
    return ok;
}

// NOTE : à enlever si non utilisé
void Tetris::relocate(Bric & origin, Bric & destination){
    int distance = destination.getShape().at(0).getX() - origin.getShape().at(0).getX();
    if(distance >= 0){
        for (int i {0}; i < distance; ++i){
            origin.move(Direction::RIGHT);
        }
    } else{
        for (int i {0}; i > distance; --i){
            origin.move(Direction::LEFT);
        }
    }
    distance = destination.getShape().at(0).getY() - origin.getShape().at(0).getY();
    if(distance >= 0){
        for (int i {0}; i < distance; ++i){
            origin.move(Direction::DOWN);
        }
    } else{
        for (int i {0}; i > distance; --i){
            origin.move(Direction::UP);
        }
    }
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
    if(ok){
        rotateBric();
    }
}

void Tetris::rotateBric(){
    for(Position p : currentBric_.getShape()){
        board_.swapCase(p);
    }

    currentBric_.rotate();

    for(Position p : currentBric_.getShape()){
        board_.swapCase(p);
    }
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
    if(player_.getScore() >= 400){
        setGameState(GameState::SCORE);
    } else if(player_.getNbLines() >= 2){
        setGameState(GameState::LINE);
    } else{
        notifyObservers();
    }
}

void Tetris::setGameState(GameState gameState){
    gameState_ = gameState;
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

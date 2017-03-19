#include "player.h"

//namespace GJ_GW{

Player::Player(): Player("Joueur", board_.DEFAULT_WIDTH, board_.DEFAULT_HEIGHT)
{}

Player::Player(std::string name, unsigned width, unsigned height):
    name_ {name}, board_{Board(width, height)}, bag_{BricsBag()}, currentBric_{bag_.getNextBric()}, score_{0}, nbLine_{0}
  // TODO : rearrange avant getnextbric
{}

std::string Player::getName(){
    return name_;
}

unsigned Player::getScore(){
    return score_;
}

Bric Player::getCurrentBric(){
    return currentBric_;
}

Board Player::getBoard(){
    return board_;
}

void Player::setName(std::string name){
    name_ = name;
}

void Player::setBoard(unsigned width, unsigned height){
    board_ = Board(width, height);
}

void Player::checkLines(unsigned dropCount){
    unsigned points, linesFilled {0};
    for(unsigned i {board_.getHeight()-1}; i != 0; --i){
        if(board_.checkLine(board_.getLine(i)) == 1){
            linesFilled += board_.gridActualisation(i);
        }
    }
    nbLine_ += linesFilled;
    switch (linesFilled) {
        case 0:
        case 1:
            points = 40;
            break;
        case 2:
            points = 100;
            break;
        case 3:
            points = 300;
            break;
        case 4:
            points = 1200;
            break;
        default:
            points = linesFilled*500;   // multiplicateur pour les briques perso de + de 4 cases de hauteur
            break;
    }


    std::cout << points
              << " * "
              << linesFilled
              << " + "
              << dropCount
              << std::endl;


    score_ += points * linesFilled + dropCount;
}

void Player::generateBric(){
    bool ok {1};
    unsigned count{0};
    unsigned midBoard = board_.getWidth()/2;
    unsigned midSide = currentBric_.getSide()/2;

    for(unsigned i = 0; i < midBoard-midSide; ++i){
        currentBric_.move(2);
    }
    while(ok && count < currentBric_.getShape().size()){
        ok = ! board_.checkCase(currentBric_.getShape().at(count));
        ++count;
    }

    if(ok){
        for(Position p : currentBric_.getShape()){
            Position & toSwap {board_.getCase(p)};
            board_.swapCase(toSwap);
        }
    }
}

void Player::rotateBric(){

}

void Player::move(unsigned direction){
    unsigned count {0};
    bool ok {1};
    if(direction == 3){
        while(ok){
            ok = checkMove(0);
            ++count;
        }
    } else{
        checkMove(direction);
    }
    checkLines(count);
}

bool Player::checkMove(unsigned direction){
    bool ok {1};
    unsigned count {0};
    Bric destination = currentBric_;
    destination.move(direction);
    while(ok && count < destination.getShape().size()){
        if(! currentBric_.isIn(destination.getShape().at(count))){
            ok = (! board_.checkCase(destination.getShape().at(count))) && board_.isIn(destination.getShape().at(count));
        }
        ++count;
    }
    if(ok)
        moveBric(direction);
    if(! ok && direction == 0){
        currentBric_ = bag_.getNextBric();
        generateBric();
    }
    return ok;
}

void Player::moveBric(unsigned direction){
    for(Position p : currentBric_.getShape()){
        Position & toSwap {board_.getCase(p)};
        board_.swapCase(toSwap);
    }
    currentBric_.move(direction);
    for(Position p : currentBric_.getShape()){
        Position & toSwap {board_.getCase(p)};
        board_.swapCase(toSwap);
    }
}



// TODO : next currentBric_ + show next bric

/*std::string Player::to_string() const{
    return board_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & in){
    out << in.to_string();
    return out;
}*/

//} //namespace GJ_GW

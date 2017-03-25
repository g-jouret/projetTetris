#include "model/tetris.h"

Tetris::Tetris(): level_ {0}, timer_ {MAXIMUM_TIMER}{}

Tetris::Tetris(std::string name, unsigned width, unsigned height):Tetris(){
    setPlayer(name, width, height);
    player_.generateBric();
}

const Player &Tetris::getPlayer() const{
    return player_;
}

void Tetris::setPlayer(std::string name, unsigned width, unsigned height){
    player_.setName(validateName(name));
    player_.setBoard(validateWidth(width), validateHeight(height));
}

std::string Tetris::validateName(std::string name){
    return (name.empty())? player_.getName() : name;
}

unsigned Tetris::validateHeight(unsigned value){
    return (value == 0)? player_.getBoard().getHeight() : value;
}

unsigned Tetris::validateWidth(unsigned value){
    return (value == 0)? player_.getBoard().getWidth() : value;
}

void Tetris::command(unsigned cmdId){
    if(cmdId == 4)
        player_.rotateBric();
    else
        player_.move(cmdId);
    notifyObservers();
}

void Tetris::reset(){
    level_ = 0;
    timer_ = MAXIMUM_TIMER;
    setPlayer("Joueur", 10, 20);
    notifyObservers();
}

bool Tetris::endGame(){
    return false;
}

/*unsigned Game::upDificulty(unsigned lvl,unsigned lineDel){
    if(lineDel == 5 | 10 | 15) lvl+=1;
    return lvl;
}
//NOTE Pas d'idée de nom
unsigned Game::upTimer(unsigned lvl, unsigned timer){
    switch ( lvl ){
       case 0:
        timer=2000;
       case 1:
        timer=1500;
        break;
       case 2:
        timer=1000;
       case 3:
        timer=500;
       default  :
        //TODO Exception
        break;
    }
    return timer;
}
*/

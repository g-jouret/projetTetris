#include "game.h"

//namespace GJ_GW {

Game::Game(): level_ {0}, timer_ {MAXIMUM_TIMER}
  //players_ {std::vector<Player> {   pour plus tard
  //player_ {Player("Joueur1", DEFAULT_WIDTH, DEFAULT_HEIGHT)}
{
    notifyObservers();
}

/*Game::Game(std::string name, unsigned width, unsigned height):
    level_ {0}, timer_ {MAXIMUM_TIMER},
    player_ {Player(name, width, height)}
{}*/

const Player &Game::getPlayer(){
    return player_;
}

void Game::setPlayer(std::string & name, unsigned width, unsigned height){
    player_.setName(validateName(name));
    player_.setBoard(validateWidth(width), validateHeight(height));
    notifyObservers();
}

std::string Game::validateName(std::string name){
    return (name.empty())? player_.getName() : name;
}

unsigned Game::validateHeight(unsigned value){
    return (value == 0)? player_.getBoard().getHeight() : value;
}

unsigned Game::validateWidth(unsigned value){
    return (value == 0)? player_.getBoard().getWidth() : value;
}

void Game::reset(){
    level_ = 0;
    timer_ = MAXIMUM_TIMER;
    setPlayer("Joueur", 10, 20);
    notifyObservers();
}

bool Game::endGame(){
    return false;
}

// WARNING : revoir les constructeur de copies / destructeurs etc

/*std::string Game::to_string() const{
    return player_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Game & in){
    out << in.to_string();
    return out;
}*/
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

//} //namespace GJ_GW

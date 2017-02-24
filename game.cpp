#include "game.h"
#include <vector>
#include <ostream>
#include <iomanip>

namespace g40853 {

Game::Game():
    level_ {0}, timer_ {MAXIMUM_TIMER},
    //players_ {std::vector<Player> {   pour plus tard
              // WARNING DB : initialisation avec DEFAULT_BRICS
             player_ {Player("Joueur1", DEFAULT_WIDTH, DEFAULT_HEIGHT,
                     std::vector<Bric> {
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                         Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                         Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                         Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})     //S
                     })}
              /*Player("Joueur2", DEFAULT_WIDTH, DEFAULT_HEIGHT,
                     std::vector<Bric> {
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                         Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                         Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                         Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})})}} */  //S
{}

unsigned Game::validate(unsigned value, unsigned def){
    return (value == 0)? def : value;
}
/* WARNING : revoir les constructeur de copies / destructeurs etc
void Game::setPlayer(std::string name1, std::string name2, unsigned width, unsigned height){
    players_.emplace(players_.begin()-1,
            Player(name1, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                   std::vector<Bric> {
                       Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                       Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                       Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                       Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                       Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                       Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                       Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})     //S
                   }));
            players_.emplace_back(
                Player(name2, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                       std::vector<Bric> {
                           Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                           Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                       Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                       Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                       Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                       Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})   //S
                   }));

}
*/

std::string Game::to_string() const{
    return player_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Game & in){
    out << in.to_string();
    return out;
}

}

#include "game.h"
#include <vector>
#include <ostream>
#include <iomanip>

namespace GJ_GW {

Game::Game():
    level_ {0}, timer_ {MAXIMUM_TIMER},
    //players_ {std::vector<Player> {   pour plus tard
    // WARNING DB : initialisation avec DEFAULT_BRICS
    player_ {Player("Joueur1", DEFAULT_WIDTH, DEFAULT_HEIGHT, brics)}
                    /*std::vector<Position>{{
                        Position(0,0), Position(1,0), Position(2,0), Position(3,0),    //I
                        Position(0,0), Position(1,0), Position(0,1), Position(1,1),    //O
                        Position(1,0), Position(0,1), Position(1,1), Position(2,1),    //T
                        Position(0,0), Position(1,0), Position(2,0), Position(2,1),    //J
                        Position(0,0), Position(1,0), Position(2,0), Position(0,1),    //L
                        Position(0,0), Position(1,0), Position(1,1), Position(2,1),    //Z
                        Position(1,0), Position(2,0), Position(0,1), Position(1,1)}})}  //S*/

  /*Player("Joueur2", DEFAULT_WIDTH, DEFAULT_HEIGHT,
                       std::vector<Bric> {
                                               Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(3,0)}),    //I
                                               Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                                               Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                                               Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(2,1)}),    //J
                                               Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(0,1)}),    //L
                                               Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                                               Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})})}  //S*/
{

    /*std::vector<Bric> brics;
    std::vector<Position> positions;
    for(int i = 0; i < DEFAULT_BRICS.size();++i){   // WARNING : /!\ problème possible: prend la mauvaise taille du tab 2D DB
        for(int j = 0; j < DEFAULT_BRICS.at(i).size();j+2){
            positions.push_back(Position(DEFAULT_BRICS.at(i).at(j),DEFAULT_BRICS.at(i).at(++j)));
        }
        brics.push_back(Bric(std::vector{positions.at(0),
                             positions.at(1),
                                         positions.at(2),
                                         positions.at(3)
                             }));
            /*Position(DEFAULT_BRICS.at(i).at(2),DEFAULT_BRICS.at(i).at(3)),
            Position(DEFAULT_BRICS.at(i).at(4),DEFAULT_BRICS.at(i).at(5)),
            Position(DEFAULT_BRICS.at(i).at(6),DEFAULT_BRICS.at(i).at(7))
    }};*/

}
/*
unsigned Game::validate(unsigned value, unsigned def){
    return (value == 0)? def : value;
}
/* WARNING : revoir les constructeur de copies / destructeurs etc
void Game::setPlayer(std::string name1, std::string name2, unsigned width, unsigned height){
    players_.emplace(players_.begin()-1,
            Player(name1, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                   std::vector<Bric> {
                                             Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(3,0)}),    //I
                                             Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                                             Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                                             Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(2,1)}),    //J
                                             Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(0,1)}),    //L
                                             Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                                             Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})})}  //S
                   }));
            players_.emplace_back(
                Player(name2, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                       std::vector<Bric> {
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(3,0)}),    //I
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                           Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(2,1)}),    //J
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(2,0), Position(0,1)}),    //L
                           Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                           Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})})}  //S
                   }));

}
*/

/*std::string Game::to_string() const{
    return player_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Game & in){
    out << in.to_string();
    return out;
}*/

}

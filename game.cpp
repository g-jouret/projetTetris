#include "game.h"
#include <vector>

namespace g40853 {

Game::Game():
    level_ {0}, timer_ {MAXIMUM_TIMER},
    players_ {std::vector<Player> {
              // WARNING DB : initialisation avec DEFAULT_BRICS
              Player("Joueur1", DEFAULT_WIDTH, DEFAULT_HEIGHT,
                     std::vector<Bric> {
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                         Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                         Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                         Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})     //S
                     }),
              Player("Joueur2", DEFAULT_WIDTH, DEFAULT_HEIGHT,
                     std::vector<Bric> {
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(0,3)}),    //I
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(0,1), Position(1,1)}),    //O
                         Bric(std::vector<Position> {Position(1,0), Position(0,1), Position(1,1), Position(2,1)}),    //T
                         Bric(std::vector<Position> {Position(1,0), Position(1,1), Position(0,2), Position(1,2)}),    //J
                         Bric(std::vector<Position> {Position(0,0), Position(0,1), Position(0,2), Position(1,2)}),    //L
                         Bric(std::vector<Position> {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}),    //Z
                         Bric(std::vector<Position> {Position(1,0), Position(2,0), Position(0,1), Position(1,1)})})}}   //S
{}

}

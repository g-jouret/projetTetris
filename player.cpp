#include "player.h"
#include <vector>

namespace g40853{

Player::Player(std::string name, unsigned width, unsigned height, std::vector<Bric> brics):
    name_ {name}, board_{Board(width, height)}, bag_ {brics}
   /* WARNING DB : piste pour implémentation de DEFAULT_BRICS
    bag_{BricsBag(std::vector<Bric> {
                  Bric(std::vector<Position> {
                      Position(brics.at(0),brics.at(1)),   //I
                       Position(brics.at(2),brics.at(3)),
                       Position(brics.at(4),brics.at(5)),
                       Position(brics.at(6),brics.at(7))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(8),brics.at(9)),   //O
                       Position(brics.at(10),brics.at(11)),
                       Position(brics.at(12),brics.at(13)),
                       Position(brics.at(14),brics.at(15))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(16),brics.at(17)),   //T
                       Position(brics.at(18),brics.at(19)),
                       Position(brics.at(20),brics.at(21)),
                       Position(brics.at(22),brics.at(23))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(24),brics.at(25)),   //J
                       Position(brics.at(26),brics.at(27)),
                       Position(brics.at(28),brics.at(29)),
                       Position(brics.at(30),brics.at(31))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(32),brics.at(33)),   //L
                       Position(brics.at(34),brics.at(35)),
                       Position(brics.at(36),brics.at(37)),
                       Position(brics.at(38),brics.at(39))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(40),brics.at(41)),   //Z
                       Position(brics.at(42),brics.at(43)),
                       Position(brics.at(44),brics.at(45)),
                       Position(brics.at(46),brics.at(47))}),

                  Bric(std::vector<Position> {
                      Position(brics.at(48),brics.at(49)),   //S
                       Position(brics.at(50),brics.at(51)),
                       Position(brics.at(52),brics.at(53)),
                       Position(brics.at(54),brics.at(55))})})}

*/
{}

void Player::checkLines(){
    std::vector<unsigned> lines {board_.checkLines()};
    score_ += lines.size();
}

}

#include "player.h"

using namespace GJ_GW;

Player::Player(): name_ {"Joueur"}, score_{0}, nbLines_{0}
{}

std::string Player::getName() const{
    return name_;
}

unsigned Player::getScore() const{
    return score_;
}

unsigned Player::getNbLines() const{
    return nbLines_;
}

void Player::setPlayer(std::string &name){
    name_ = name;
    reset();
}

bool Player::setNbLines(unsigned linesCount){
    nbLines_ += linesCount;
    return linesCount;
}

void Player::reset(){
    nbLines_ = 0;
    score_ = 0;
}

void Player::setScore(unsigned dropsCount, unsigned linesCount){
    unsigned points;
    switch (linesCount) {
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
        points = linesCount*500;   // multiplicateur pour les briques perso de + de 4 cases de hauteur
        break;
    }
    score_ += points * linesCount + dropsCount;
}

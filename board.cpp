#include "board.h"
#include <stdexcept>

namespace g40853{

Board::Board(unsigned width, unsigned height):
width_{width}, height_{height}
{}



std::vector<unsigned> Board::checkLines(){
    std::vector<unsigned> filledLines;
    unsigned check {0}, y {0};
    for(Position p : grid_){
        if(y = p.getY()){
            if(p.isFilled()){
                ++check;
                if(check = width_){
                    filledLines.push_back(p.getY());
                }
            }
        } else{
            check = 0;
        }
    }
}

void Board::line(unsigned lineNum){

}

}

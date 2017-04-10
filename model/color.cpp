#include "color.h"

using namespace GJ_GW;

Color::Color(): Color(std::vector<unsigned> {0xff, 0xff, 0xff})  //white
{}

Color::Color(std::vector<unsigned> code): code_{code}
{}

std::vector<unsigned> Color::getCode() const{
    return code_;
}

/*unsigned Color::white(){
    return 0xffffff;
}

unsigned Color::blue() const{
    return 0x0000ff;
}

unsigned Color::cyan() const{
    return 0x00ffff;
}

unsigned Color::green() const{
    return 0x008000;
}

unsigned Color::yellow() const{
    return 0xffff00;
}

unsigned Color::orange() const{
    return 0xffa500;
}

unsigned Color::red() const{
    return 0xff0000;
}

unsigned Color::purple() const{
    return 0x800080;
}
*/

#include "color.h"

using namespace GJ_GW;

Color::Color(): code_{255, 255, 255}
{}

Color::Color(std::vector<unsigned> &code): code_{code}
{}

std::vector<unsigned> Color::getCode() const{
    return code_;
}

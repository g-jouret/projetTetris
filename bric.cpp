#include "bric.h"

#include <ostream>

namespace GJ_GW{

Bric::Bric():shape_{NULL}
{}

Bric::Bric(std::vector<Position> shape): shape_ {shape}
{}

}

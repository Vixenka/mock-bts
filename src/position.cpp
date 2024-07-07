#include "position.hpp"
#include <cmath>

float mbts::Position::DistanceTo(Position other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

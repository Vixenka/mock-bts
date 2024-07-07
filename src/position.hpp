#pragma once

namespace mbts {
    struct Position {
        float x;
        float y;

        Position(float x, float y) : x(x), y(y) {}

        float DistanceTo(Position other);
    };
}

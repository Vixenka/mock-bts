#pragma once

#include <cstdint>
#include "../position.hpp"

namespace mbts::network {
    class Receiver {
        int32_t number;
        Position position;

        public:
            Receiver(int32_t number, Position position);

            int32_t GetNumber();
            void ListenBTS();
    };
}

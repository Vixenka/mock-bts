#include "receiver.hpp"
#include <cstdint>

mbts::network::Receiver::Receiver(int32_t number, Position position) : number(number), position(position) {
}

int32_t mbts::network::Receiver::GetNumber() {
    return number;
}

#include "network/manager.hpp"

using namespace mbts::network;

int main() {
    NetworkManager manager = NetworkManager();
    manager.RegisterBTS(BTS({0, 0}));

    return 0;
}

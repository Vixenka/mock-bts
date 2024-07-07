#pragma once

#include <thread>
#include "../position.hpp"

namespace mbts::network {
    struct BTSInner {
        Position position;
        int serverSocket = -1;
        bool listening = false;
        std::thread listenThread;

        BTSInner(Position position);
        ~BTSInner();

        BTSInner(const BTSInner& other) = delete;
        BTSInner& operator=(const BTSInner& other) = delete;
        BTSInner(BTSInner&& other) = delete;
        BTSInner& operator=(BTSInner&& other) = delete;
    };
}

namespace std {
    string to_string(const mbts::network::BTSInner& inner);
}

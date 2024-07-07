#include "bts_inner.hpp"
#include "../logger/log.hpp"
#include <string>

namespace mbts::network {
    BTSInner::BTSInner(Position position) : position(position) {
    }

    BTSInner::~BTSInner() {
        if (serverSocket >= 0) {
            close(serverSocket);
            logger::Trace(std::to_string(*this) + " closed");
        }

        if (listening) {
            listening = false;
            listenThread.join();
            logger::Trace(std::to_string(*this) + " listen thread joined");
        }
    }
}

namespace std {
    string to_string(const mbts::network::BTSInner& inner) {
        return "BTS at " + std::to_string(inner.position.x) + ", " + std::to_string(inner.position.y);
    }
}

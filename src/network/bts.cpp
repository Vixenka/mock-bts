#include <cerrno>
#include <memory>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <system_error>
#include <thread>
#include <unistd.h>
#include <utility>

#include "bts.hpp"
#include "../logger/log.hpp"
#include "bts_inner.hpp"

namespace mbts::network {
    BTS::BTS(Position position) : inner(std::shared_ptr<BTSInner>(new BTSInner {
        position
    })) {
        logger::Trace(std::to_string(*this) + " created");
    }

    Position& BTS::GetPosition() const noexcept {
        return inner->position;
    }

    void BTS::Init() {
        inner->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (inner->serverSocket < 0) {
            throw std::system_error(errno, std::generic_category(), "Failed to create server socket");
        }

        sockaddr_in serverAddress;
        bzero((char*)&serverAddress, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

        int bindResult = bind(inner->serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
        if (bindResult < 0) {
            throw std::system_error(errno, std::generic_category(), "Failed to bind server socket");
        }

        // Create a new thread to handle incoming connections
        inner->listening = true;
        inner->listenThread = std::thread {[self = *this] () mutable { self.ListenWorker(); }};

        logger::Trace(std::to_string(*this) + " intialized");
    }

    void BTS::ListenWorker() {
        logger::Trace("what2 " + std::to_string(inner->listening));

        while (inner->listening) {
            // Accept incoming connections
            sockaddr_in newSockAddr{};
            socklen_t newSockAddrSize = sizeof(newSockAddr);

            int clientSocket = accept(inner->serverSocket, (sockaddr *)&newSockAddr, &newSockAddrSize);

            logger::Trace("what");
        }
    }
}

namespace std {
    string to_string(const mbts::network::BTS& bts) {
        return "BTS at " + std::to_string(bts.GetPosition().x) + ", " + std::to_string(bts.GetPosition().y);
    }
}

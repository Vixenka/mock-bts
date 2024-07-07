#include "manager.hpp"
#include "../logger/log.hpp"
#include "bts.hpp"
#include <vector>

namespace mbts::network {
    NetworkManager::NetworkManager() {
        this->btsList = std::vector<BTS>();

        logger::Trace("NetworkManager created");
    }

    void NetworkManager::RegisterBTS(BTS bts) {
        logger::Trace(std::to_string(bts) + " registered");
        
        bts.Init();
        btsList.push_back(std::move(bts));
    }
}

#include "bts.hpp"
#include <vector>

namespace mbts::network {
    class NetworkManager {
        std::vector<BTS> btsList;

        public:
            NetworkManager();
            
            void RegisterBTS(BTS bts);
    };
}

#pragma once

#include "../position.hpp"
#include "bts_inner.hpp"
#include <memory>
#include <string>

namespace mbts::network {
    class BTS {
        public:
            BTS(Position position);

            Position& GetPosition() const noexcept;

            void Init();

        private:
            std::shared_ptr<BTSInner> inner;

            void ListenWorker();
    };
}

namespace std {
    string to_string(const mbts::network::BTS& bts);
}

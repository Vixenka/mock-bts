#include "log.hpp"
#include <iostream>

void mbts::logger::Trace(std::string message) {
    std::cout << "[TRACE] " << message << std::endl;
}

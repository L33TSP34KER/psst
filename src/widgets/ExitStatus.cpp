#include "widgets/ExitStatus.hpp"
#include "widgets/general.hpp"

std::string ExitStatus::render() {
    if (config::status == 0) {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return "!" + std::to_string(config::status);
}

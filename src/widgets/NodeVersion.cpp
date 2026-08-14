#include "widgets/NodeVersion.hpp"
#include "widgets/general.hpp"
#include <cstdlib>

std::string NodeVersion::render() {
    const char *version = std::getenv("NODE_VERSION");
    if (!version || version[0] == '\0') {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return "node " + std::string(version);
}

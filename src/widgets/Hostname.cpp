#include "widgets/Hostname.hpp"
#include "widgets/general.hpp"
#include <cstdlib>

std::string Hostname::render() {
    const char *hostname = std::getenv("HOSTNAME");
    if (!hostname || hostname[0] == '\0') {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return hostname;
}

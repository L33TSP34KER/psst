#include "widgets/SSHSession.hpp"
#include "widgets/general.hpp"
#include <cstdlib>

std::string SSHSession::render() {
    const char *connection = std::getenv("SSH_CONNECTION");
    if (!connection || connection[0] == '\0') {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return "ssh";
}

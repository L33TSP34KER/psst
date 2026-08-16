#include "widgets/Tmux.hpp"
#include "widgets/general.hpp"
#include <cstdlib>

std::string Tmux::render() {
    const char *tmux = std::getenv("TMUX");
    if (!tmux || tmux[0] == '\0') {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return "tmux";
}

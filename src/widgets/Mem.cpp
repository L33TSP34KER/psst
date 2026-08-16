#include "widgets/Mem.hpp"
#include "widgets/general.hpp"
#include <cstdlib>
#include <fstream>
#include <string>

std::string Mem::render() {
    std::ifstream file("/proc/meminfo");
    std::string line;
    long total = -1;
    long available = -1;

    while ((total < 0 || available < 0) && std::getline(file, line)) {
        if (total < 0 && line.compare(0, 9, "MemTotal:") == 0)
            total = strtol(line.c_str() + 9, nullptr, 10);
        else if (available < 0 && line.compare(0, 13, "MemAvailable:") == 0)
            available = strtol(line.c_str() + 13, nullptr, 10);
    }

    if (total <= 0 || available < 0 || available > total) {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return std::to_string((total - available) * 100 / total) + "%";
}

#include "widgets/CMake.hpp"
#include "widgets/general.hpp"
#include <sys/stat.h>

std::string CMake::render() {
    struct stat st;
    if (stat("CMakeLists.txt", &st) != 0) {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return label;
}

#include "widgets/Cargo.hpp"
#include "widgets/general.hpp"
#include <sys/stat.h>

std::string Cargo::render() {
    struct stat st;
    if (stat("Cargo.toml", &st) != 0) {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return label;
}

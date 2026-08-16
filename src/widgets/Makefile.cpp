#include "widgets/Makefile.hpp"
#include "widgets/general.hpp"
#include <sys/stat.h>

std::string Makefile::render() {
    struct stat st;
    if (stat("Makefile", &st) != 0 && stat("makefile", &st) != 0) {
        config::print = 0;
        return "";
    }
    config::print = 1;
    return label;
}

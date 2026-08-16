#include "widgets/Project.hpp"
#include "widgets/general.hpp"
#include <sys/stat.h>

static bool exists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0;
}

std::string Project::render() {
    std::string result;

    if (exists("Cargo.toml"))
        result = rust_label;
    else if (exists("CMakeLists.txt"))
        result = cmake_label;
    else if (exists("Makefile") || exists("makefile"))
        result = make_label;

    config::print = !result.empty();
    return result;
}

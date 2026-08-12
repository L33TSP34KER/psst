#include "widgets/ShortPath.hpp"
#include "widgets/general.hpp"

ShortPath::~ShortPath() {
}

std::string ShortPath::render() {
    config::print = 1;
    std::string path = std::getenv("PWD");
    std::string final_string;
    int last_index = 0;

    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/') {
            last_index = i + 1;
        }
    }

    for (int i = last_index; path[i] != '\0'; i++) {
        final_string.push_back(path[i]);
    }

    return final_string;
}

#pragma once

#include <string>
#include <vector>
namespace Parser {
    std::vector<std::string> parse_file(std::string file);
    std::string convert(std::string file);
}

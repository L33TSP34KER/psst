#pragma once

#include "widgets/IWidget.hpp"
#include <string>

class Project : public IWidget {
private:
    std::string rust_label;
    std::string cmake_label;
    std::string make_label;

public:
    Project(const std::string& rust = "rust",
            const std::string& cmake = "cmake",
            const std::string& make = "make")
        : rust_label(rust), cmake_label(cmake), make_label(make) {}

    std::string render() override;
};

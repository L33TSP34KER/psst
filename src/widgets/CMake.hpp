#pragma once

#include "widgets/IWidget.hpp"
#include <string>

class CMake : public IWidget {
private:
    std::string label;

public:
    explicit CMake(const std::string& label = "cmake") : label(label) {}

    std::string render() override;
};

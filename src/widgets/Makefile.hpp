#pragma once

#include "widgets/IWidget.hpp"
#include <string>

class Makefile : public IWidget {
private:
    std::string label;

public:
    explicit Makefile(const std::string& label = "make") : label(label) {}

    std::string render() override;
};

#pragma once

#include "widgets/IWidget.hpp"
#include <string>

class Cargo : public IWidget {
private:
    std::string label;

public:
    explicit Cargo(const std::string& label = "rust") : label(label) {}

    std::string render() override;
};

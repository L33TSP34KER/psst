#pragma once

#include "widgets/IWidget.hpp"

class Charging : public IWidget {
private:
    std::string indicator;

public:
    explicit Charging(const std::string &text = "charging") : indicator(text) {}
    std::string render() override;
};

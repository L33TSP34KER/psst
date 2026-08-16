#pragma once

#include "widgets/IWidget.hpp"

class Mem : public IWidget {
public:
    std::string render() override;
};

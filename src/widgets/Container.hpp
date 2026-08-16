#pragma once

#include "widgets/IWidget.hpp"

class Container : public IWidget {
public:
    std::string render() override;
};

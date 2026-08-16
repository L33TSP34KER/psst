#pragma once

#include "widgets/IWidget.hpp"

class Project : public IWidget {
public:
    std::string render() override;
};

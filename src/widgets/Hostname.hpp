#pragma once

#include "widgets/IWidget.hpp"

class Hostname : public IWidget {
public:
    std::string render() override;
};

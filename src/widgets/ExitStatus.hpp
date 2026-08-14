#pragma once

#include "widgets/IWidget.hpp"

class ExitStatus : public IWidget {
public:
    std::string render() override;
};

#pragma once

#include "widgets/IWidget.hpp"

class Tmux : public IWidget {
public:
    std::string render() override;
};

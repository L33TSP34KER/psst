#pragma once

#include "widgets/IWidget.hpp"

class NodeVersion : public IWidget {
public:
    std::string render() override;
};

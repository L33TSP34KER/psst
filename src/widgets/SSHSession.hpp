#pragma once

#include "widgets/IWidget.hpp"

class SSHSession : public IWidget {
public:
    std::string render() override;
};

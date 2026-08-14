#pragma once

#include "widgets/IWidget.hpp"

class PythonVenv : public IWidget {
public:
    std::string render() override;
};

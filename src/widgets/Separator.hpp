#pragma once

#include "IWidget.hpp"
#include <string>

class Separator : public IWidget {
private:
    std::string separator;
    
public:
    Separator(const std::string& sep = " ") : separator(sep) {}
    
    std::string render() {
        return separator;
    }
};

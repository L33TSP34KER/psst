#pragma once

#include "IWidget.hpp"
#include "general.hpp"
#include <string>

class Separator : public IWidget {
private:
    std::string separator;
    int care_last_print;
    
public:
    Separator(const std::string& sep = " ", const int do_i_care = 1) : separator(sep),care_last_print(do_i_care) {}
    
    std::string render() {
        if (config::print || !care_last_print)
            return separator;
        return "";
    }
};

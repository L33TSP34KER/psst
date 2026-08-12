#include "widgets/Battery.hpp"
#include "widgets/general.hpp"

Battery::~Battery() {
}

std::string Battery::render() {
    std::string final_str;
	std::ifstream git_file("/sys/class/power_supply/BAT1/capacity");
    config::print = 1;
	if (!git_file.is_open()) {
        config::print = 0;
		return final_str;
	}
	std::getline(git_file, final_str);
    if (final_str.length() < 1){
        config::print = 0;
    }
	return final_str + "%";
}

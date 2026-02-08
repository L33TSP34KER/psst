#include "widgets/Bat.hpp"

Bat::~Bat() {
}

std::string Bat::render() {
	std::string final_str;
	std::ifstream git_file("/sys/class/power_supply/BAT1/capacity");
	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, final_str);
	return final_str + "%";
}

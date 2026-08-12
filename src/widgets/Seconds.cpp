#include "widgets/Seconds.hpp"
#include "widgets/general.hpp"

Seconds::~Seconds() {
}

std::string Seconds::render() {
	std::string final_str;
	std::ifstream git_file(".git/refs/heads/main");
    config::print = 1;
	if (!git_file.is_open()) {
        config::print = 0;
		return final_str;
	}
	std::getline(git_file, final_str);
    if (final_str.length() < 1){
        config::print = 0;
    }
	return "S " + final_str.substr(0, 4);
}

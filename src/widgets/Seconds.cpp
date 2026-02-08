#include "widgets/Seconds.hpp"

Seconds::~Seconds() {
}

std::string Seconds::render() {
	std::string final_str;
	std::ifstream git_file(".git/refs/heads/main");
	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, final_str);
	return "S " + final_str.substr(0, 4);
}

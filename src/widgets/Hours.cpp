#include "widgets/Hours.hpp"

Hours::~Hours() {
}

std::string Hours::render() {
	std::string final_str;
	std::ifstream git_file(".git/refs/heads/main");
	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, final_str);
	return "H " + final_str.substr(0, 4);
}

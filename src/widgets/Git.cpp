#include "widgets/Git.hpp"

Git::~Git() {
}

std::string Git::render() {
	std::string final_str;
	std::ifstream git_file(".git/refs/heads/main");
	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, final_str);
	return final_str.substr(0, 4);
}

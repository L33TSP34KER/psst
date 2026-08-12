#include "widgets/GitBranch.hpp"
#include "widgets/Separator.hpp"

GitBranch::~GitBranch() {
}

std::string GitBranch::render() {
	std::string final_str;
	std::string temp_str;
	std::ifstream git_file(".git/HEAD");
    int counter = 0;
    config::print = 1;

	if (!git_file.is_open()) {
        config::print = 0;
		return final_str;
	}
	std::getline(git_file, temp_str);
    for (int i = 0; temp_str[i] != '\0'; i++){
        if (counter >= 2) final_str.push_back(temp_str[i]);
        if (temp_str[i] == '/') counter++;
    }
    if (final_str.length() < 1){
        config::print = 0;
    }

	return final_str;
}

#include "widgets/Git.hpp"

Git::~Git() {
}

std::string get_git_branch() {
    std::string final_str;
	std::string temp_str;
	std::ifstream git_file(".git/HEAD");
    int counter = 0;

	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, temp_str);
    for (int i = 0; temp_str[i] != '\0'; i++){
        if (counter >= 2) final_str.push_back(temp_str[i]);
        if (temp_str[i] == '/') counter++;
    }
	return final_str;
}

std::string Git::render() {
	std::string final_str;
	std::ifstream git_file(".git/refs/heads/" + get_git_branch());
	if (!git_file.is_open()) {
		return final_str;
	}
	std::getline(git_file, final_str);
	return final_str.substr(0, max_chars);
}

#include "parser.hpp"
#include <cstdlib>
#include <sstream>
#include <iostream>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return true;
}

std::vector<std::string> Parser::parse_file(std::string file) {
    std::vector<std::string> splited_string;
	std::string tmp; 
	std::stringstream ss(file);
	while(getline(ss, tmp, ',')){
	    splited_string.push_back(tmp);
	}

	return splited_string;
};

std::string Parser::convert(std::string file) {
    replace(file, "\"", "\"");
    replace(file, "|", "|");
    return file;
};

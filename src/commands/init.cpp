#include <algorithm>
#include "commands/commands.hpp"
#include "parser.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "shells/Bash.hpp"
#include "shells/Fish.hpp"
#include "shells/EShell.hpp"
#include "shells/IShell.hpp"
#include "widgets/general.hpp"
#include "config.hpp"

std::string get_shell(std::string s) {
	std::vector<std::string> splited_string;
	std::string tmp; 
	std::stringstream ss(s);
	while(getline(ss, tmp, '/')){
	    splited_string.push_back(tmp);
	}
	return splited_string[splited_string.size() - 1];
}
std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        ++start;
    }

    auto end = str.end();
    do {
        --end;
    } while (end != start && std::isspace(*end));

    return std::string(start, end + 1);
}

int commands::init(int status) {
	if (!std::getenv("SHELL")) return 1;
	config::status = status;
	std::string shell_str = get_shell(std::getenv("SHELL"));
	std::unique_ptr<IShell> shell = std::make_unique<Shell::Bash>();

	switch (EShells::from_str(shell_str)) {
		case Shells::Unknow:
			std::cerr << "Shell not supported" << std::endl;
			return 1;
		case Shells::Bash:
			shell = std::make_unique<Shell::Bash>();
			break;
		case Shells::Zsh:
			shell = std::make_unique<Shell::Bash>();
			break;
		case Shells::Fish:
			shell = std::make_unique<Shell::Fish>();
			break;
	}
    for (auto &a : default_config()) {
        shell->addWidget(a);
    }
    std::string result = shell->exportPrompt();
    std::cout << trim(Parser::convert(result)) << std::endl;
    return 0;
}

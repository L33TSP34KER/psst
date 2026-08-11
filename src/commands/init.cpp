#include <algorithm>
#include "commands/commands.hpp"
#include "parser.hpp"
#include "widgets/Battery.hpp"
#include "widgets/Git.hpp"
#include "widgets/GitBranch.hpp"
#include "widgets/Hours.hpp"
#include "widgets/IWidget.hpp"
#include "widgets/Minute.hpp"
#include "widgets/Path.hpp"
#include "widgets/RootSymol.hpp"
#include "widgets/Separator.hpp"
#include "widgets/User.hpp"
#include "widgets/colors/Cyan.hpp"
#include "widgets/colors/Bold.hpp"
#include "widgets/colors/Red.hpp"
#include "widgets/colors/Purple.hpp"
#include "widgets/colors/Reset.hpp"
#include "shells/Bash.hpp"
#include "shells/Fish.hpp"
#include "shells/EShell.hpp"
#include "shells/IShell.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <sstream>

std::string get_shell(std::string s) {
	std::vector<std::string> splited_string;
	std::string tmp; 
	std::stringstream ss(s);
	while(getline(ss, tmp, '/')){
	    splited_string.push_back(tmp);
	}
	return splited_string[splited_string.size() - 1];
}

std::vector<std::shared_ptr<IWidget>> default_config() {
    return {
        std::make_unique<Separator>("\n\n"),
        std::make_unique<Cyan>(),
        std::make_unique<User>(),
        std::make_unique<Reset>(),

        std::make_unique<Separator>(" "),
        std::make_unique<Path>(),
        
        std::make_unique<Separator>(" "),
        std::make_unique<Red>(),
        std::make_unique<Git>(),
        std::make_unique<Separator>(" "),
        std::make_unique<GitBranch>(),
        std::make_unique<Reset>(),

        std::make_unique<Separator>(" "),
        std::make_unique<Battery>(),
        std::make_unique<Separator>("\n"),
        
        std::make_unique<Purple>(),
        std::make_unique<Bold>(),
        std::make_unique<Separator>(" "),
        std::make_unique<Reset>(),
        std::make_unique<Separator>(" ")
    };
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

void commands::init() {
	if (!std::getenv("SHELL")) return;
	Red red;
	Reset reset;
	std::string shell_str = get_shell(std::getenv("SHELL"));
	std::unique_ptr<IShell> shell = std::make_unique<Shell::Bash>();

	switch (EShells::from_str(shell_str)) {
		case Shells::Unknow:
			std::cerr << "Shell not supported" << std::endl;
			return;
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
}

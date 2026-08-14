#include "widgets/Git.hpp"
#include "widgets/Bat.hpp"
#include "shells/Bash.hpp"
#include "commands/commands.hpp"
#include <cstdlib>

int main(int argc, char** argv) {
	std::string shelltarget;
	for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--help") return commands::help_menu();
		if (std::string(argv[i]) == "init") {
			int status = 0;
			if (i + 1 < argc)
				status = std::atoi(argv[i + 1]);
			return commands::init(status);
		}
	}
	return 0;
}

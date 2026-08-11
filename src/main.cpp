#include "widgets/Git.hpp"
#include "widgets/Bat.hpp"
#include "shells/Bash.hpp"
#include "commands/commands.hpp"

int main(int argc, char** argv) {
	std::string shelltarget;
	for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--help") return commands::help_menu();
		if (std::string(argv[i]) == "init")   return commands::init();
	}
	return 0;
}

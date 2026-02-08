#include "widgets/Git.hpp"
#include "widgets/Bat.hpp"
#include "shells/Bash.hpp"
#include "commands/commands.hpp"

int main(int argc, char** argv) {
	std::string shelltarget;
	for (int i = 0; i < argc; i++) {
		if (std::string(argv[i]) == "init") {
			commands::init();
		}
	}
	return 0;
}

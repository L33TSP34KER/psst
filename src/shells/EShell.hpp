#pragma once
#include <string>

enum Shells {
	Fish,
	Bash,
	Zsh,
	Unknow,
};

namespace EShells {
	Shells from_str(std::string base);
}

#include "widgets/User.hpp"
#include "widgets/Separator.hpp"
#include <cstdlib>

User::~User() {
}

std::string User::render() {
    config::print = 1;
	return std::getenv("USER");
}

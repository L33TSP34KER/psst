#include "widgets/User.hpp"
#include <cstdlib>

User::~User() {
}

std::string User::render() {
	return std::getenv("USER");
}

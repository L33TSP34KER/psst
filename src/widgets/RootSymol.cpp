#include "widgets/RootSymol.hpp"
#include <unistd.h> // getuid

RootSymol::~RootSymol() {
}

std::string RootSymol::render() {
	if (!getuid()) return "# ";
	return "~ ";
}

#include "widgets/RootSymol.hpp"
#include "widgets/general.hpp"
#include <unistd.h> // getuid

RootSymol::~RootSymol() {
}

std::string RootSymol::render() {
    config::print = 1;
	if (!getuid()) return "# ";
	return "~ ";
}

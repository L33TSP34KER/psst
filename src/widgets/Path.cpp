#include "widgets/Path.hpp"
#include "widgets/general.hpp"

Path::~Path() {
}

std::string Path::render() {
    config::print = 1;
	return std::getenv("PWD");
}

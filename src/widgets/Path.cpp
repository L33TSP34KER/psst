#include "widgets/Path.hpp"

Path::~Path() {
}

std::string Path::render() {
	return std::getenv("PWD");
}

#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Git : public IWidget {
private:
    const int max_chars = 4;
public:
    Git(const int max_chars = 4) : max_chars(max_chars) {}
	~Git();
	std::string render();
};

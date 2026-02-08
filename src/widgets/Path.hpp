#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Path : public IWidget {
public:
	~Path();
	std::string render();
};

#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Git : public IWidget {
public:
	~Git();
	std::string render();
};

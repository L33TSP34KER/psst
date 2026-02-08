#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class User : public IWidget {
public:
	~User();
	std::string render();
};

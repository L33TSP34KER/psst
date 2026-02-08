#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Minute : public IWidget {
public:
	~Minute();
	std::string render();
};

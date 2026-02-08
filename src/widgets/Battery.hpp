#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Battery : public IWidget {
public:
	~Battery();
	std::string render();
};

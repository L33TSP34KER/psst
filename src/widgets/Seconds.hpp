#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Seconds : public IWidget {
public:
	~Seconds();
	std::string render();
};

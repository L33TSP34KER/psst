#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class Hours : public IWidget {
public:
	~Hours();
	std::string render();
};

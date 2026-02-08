#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class RootSymol : public IWidget {
public:
	~RootSymol();
	std::string render();
};

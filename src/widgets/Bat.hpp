#pragma once

#include "widgets/IWidget.hpp"

class Bat : public IWidget {
public:
	~Bat();
	std::string render();
};

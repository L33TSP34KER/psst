#pragma once
#include "widgets/IWidget.hpp"

class Bold : public IWidget {
public:
	~Bold();
	std::string render();
};

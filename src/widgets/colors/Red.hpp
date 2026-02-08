#pragma once
#include "widgets/IWidget.hpp"

class Red : public IWidget {
public:
	~Red();
	std::string render();
};

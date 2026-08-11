#pragma once
#include "widgets/IWidget.hpp"

class ShortPath : public IWidget {
public:
	~ShortPath();
	std::string render();
};

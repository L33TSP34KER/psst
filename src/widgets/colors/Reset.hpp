#pragma once
#include "widgets/IWidget.hpp"

class Reset : public IWidget {
public:
	~Reset() {};
	std::string render();
};

#pragma once
#include "widgets/IWidget.hpp"
#include <fstream>

class GitBranch : public IWidget {
public:
	~GitBranch();
	std::string render();
};

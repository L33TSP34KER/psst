#pragma once
#include "widgets/IWidget.hpp"
#include <vector>
#include <iostream>
#include <memory>

class IShell {
public:
	~IShell(){};
	virtual std::string exportPrompt() = 0;
	virtual void addWidget(std::shared_ptr<IWidget> widget) = 0;
};

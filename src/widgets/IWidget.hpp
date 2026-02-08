#pragma once
#include <iostream>
#include <fstream>

class IWidget {
public:
	~IWidget(){};
	virtual std::string render() = 0;
};

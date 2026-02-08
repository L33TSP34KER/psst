#pragma once
#include "shells/IShell.hpp"

namespace Shell {
	class Bash : public IShell{
	public:
		~Bash(){};
		std::string exportPrompt();
		void addWidget(std::shared_ptr<IWidget> widget);
	private:
		std::vector<std::shared_ptr<IWidget>> list;
	};
}

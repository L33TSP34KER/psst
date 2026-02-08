#include "shells/Bash.hpp"

void Shell::Bash::addWidget(std::shared_ptr<IWidget> widget) {
	list.push_back(widget);
}

std::string Shell::Bash::exportPrompt() {
	std::string base = "export PS1=\"";
	for (std::shared_ptr<IWidget> w : list) {
		base += w->render();
	}

	return base + "\"";
}

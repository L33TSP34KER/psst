#include "shells/Fish.hpp"

void Shell::Fish::addWidget(std::shared_ptr<IWidget> widget) {
	list.push_back(widget);
}

std::string Shell::Fish::exportPrompt() {
	std::string base;
	for (std::shared_ptr<IWidget> w : list) {
		base += w->render();
	}

	return base;
}

#include "shells/Bash.hpp"

void Shell::Bash::addWidget(std::shared_ptr<IWidget> widget) {
	list.push_back(widget);
}

static std::string escape_prompt(const std::string& s) {
	std::string out;
	out.reserve(s.size());
	for (char c : s) {
		switch (c) {
		case '\\': out += "\\\\"; break;
		case '\'': out += "'\\''"; break;
		default:   out += c;
		}
	}
	return out;
}

std::string Shell::Bash::exportPrompt() {
	std::string base = "shopt -u promptvars; export PS1='";
	for (std::shared_ptr<IWidget> w : list) {
		base += escape_prompt(w->render());
	}

	return base + "'";
}

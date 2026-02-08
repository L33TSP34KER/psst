#include "EShell.hpp"

Shells EShells::from_str(std::string base){
	if(base == "fish") return Shells::Fish;
	if(base == "bash") return Shells::Bash;
	if(base == "Zsh") return Shells::Zsh;
	return Shells::Unknow;
}

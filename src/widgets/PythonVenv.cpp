#include "widgets/PythonVenv.hpp"
#include "widgets/general.hpp"
#include <cstdlib>

std::string PythonVenv::render() {
    const char *virtual_env = std::getenv("VIRTUAL_ENV");
    if (!virtual_env || virtual_env[0] == '\0') {
        config::print = 0;
        return "";
    }

    std::string path(virtual_env);
    const std::size_t slash = path.find_last_of('/');
    const std::string name = slash == std::string::npos
        ? path
        : path.substr(slash + 1);

    config::print = !name.empty();
    return name.empty() ? "" : "(" + name + ")";
}

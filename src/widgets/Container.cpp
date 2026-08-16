#include "widgets/Container.hpp"
#include "widgets/general.hpp"
#include <cstdlib>
#include <sys/stat.h>

static bool container_marker(const char *path) {
    struct stat st;
    return stat(path, &st) == 0;
}

std::string Container::render() {
    std::string result;

    if (container_marker("/run/.containerenv"))
        result = "podman";
    else if (container_marker("/.dockerenv"))
        result = "docker";
    else {
        const char *env = std::getenv("container");
        if (env && env[0] != '\0')
            result = env;
    }

    config::print = !result.empty();
    return result;
}

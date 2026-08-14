#include "widgets/Charging.hpp"
#include "widgets/general.hpp"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <system_error>

static std::string read_status(const std::filesystem::path &path) {
    std::ifstream file(path);
    std::string status;
    if (file.is_open())
        std::getline(file, status);
    return status;
}

#ifdef __APPLE__
static bool macos_is_charging() {
    FILE *pipe = popen("pmset -g batt", "r");
    if (!pipe)
        return false;

    char buffer[256];
    std::string output;
    while (fgets(buffer, sizeof(buffer), pipe))
        output += buffer;
    pclose(pipe);
    return output.find("charging") != std::string::npos;
}
#endif

std::string Charging::render() {
    bool charging = false;
#ifdef __APPLE__
    charging = macos_is_charging();
#else
    std::error_code error;
    for (const auto &entry : std::filesystem::directory_iterator("/sys/class/power_supply", error)) {
        if (read_status(entry.path() / "type") == "Battery") {
            charging = read_status(entry.path() / "status") == "Charging";
            break;
        }
    }
#endif
    config::print = charging;
    return charging ? this->indicator : "";
}

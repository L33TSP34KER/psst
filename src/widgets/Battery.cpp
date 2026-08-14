#include "widgets/Battery.hpp"
#include "widgets/general.hpp"
#include <cstdio>
#include <filesystem>
#include <system_error>

static std::string read_file(const std::filesystem::path &path) {
    std::ifstream file(path);
    std::string value;
    if (file.is_open())
        std::getline(file, value);
    return value;
}

#ifdef __APPLE__
static std::string macos_battery() {
    FILE *pipe = popen("pmset -g batt", "r");
    if (!pipe)
        return "";

    char buffer[256];
    std::string output;
    while (fgets(buffer, sizeof(buffer), pipe))
        output += buffer;
    pclose(pipe);

    const std::size_t percent = output.find('%');
    if (percent == std::string::npos)
        return "";
    const std::size_t start = output.rfind('\n', percent);
    const std::size_t value_start = output.find_first_of("0123456789", start == std::string::npos ? 0 : start);
    if (value_start == std::string::npos)
        return "";
    const bool charging = output.find("charging", value_start) < percent + 1 ||
        output.find("AC Power", 0) != std::string::npos;
    return (charging ? "+" : "") + output.substr(value_start, percent - value_start + 1);
}
#endif

Battery::~Battery() {
}

std::string Battery::render() {
    std::string result;
#ifdef __APPLE__
    result = macos_battery();
#else
    std::error_code error;
    for (const auto &entry : std::filesystem::directory_iterator("/sys/class/power_supply", error)) {
        if (read_file(entry.path() / "type") != "Battery")
            continue;
        const std::string capacity = read_file(entry.path() / "capacity");
        if (!capacity.empty())
            result = capacity + "%";
        break;
    }
#endif
    config::print = !result.empty();
    return result;
}

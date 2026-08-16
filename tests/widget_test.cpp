#include "widgets/Hostname.hpp"
#include "widgets/Container.hpp"
#include "widgets/ExitStatus.hpp"
#include "widgets/Mem.hpp"
#include "widgets/NodeVersion.hpp"
#include "widgets/PythonVenv.hpp"
#include "widgets/SSHSession.hpp"
#include "widgets/general.hpp"
#include <cassert>
#include <cstdlib>
#include <sys/stat.h>

int main() {
    PythonVenv venv;
    unsetenv("VIRTUAL_ENV");
    assert(venv.render().empty());
    setenv("VIRTUAL_ENV", "/tmp/.venvs/testenv", 1);
    assert(venv.render() == "(testenv)");

    Hostname hostname;
    setenv("HOSTNAME", "thinkpad", 1);
    assert(hostname.render() == "thinkpad");
    unsetenv("HOSTNAME");
    assert(hostname.render().empty());

    SSHSession ssh;
    unsetenv("SSH_CONNECTION");
    assert(ssh.render().empty());
    setenv("SSH_CONNECTION", "192.0.2.1 12345 192.0.2.2 22", 1);
    assert(ssh.render() == "ssh");

    ExitStatus exit_status;
    config::status = 0;
    assert(exit_status.render().empty());
    config::status = 127;
    assert(exit_status.render() == "!127");

    NodeVersion node;
    unsetenv("NODE_VERSION");
    assert(node.render().empty());
    setenv("NODE_VERSION", "v22.0.0", 1);
    assert(node.render() == "node v22.0.0");

    Mem mem;
    const std::string used = mem.render();
    if (!used.empty()) {
        assert(used.back() == '%');
        const int percent = std::stoi(used);
        assert(percent >= 0 && percent <= 100);
    } else {
        assert(config::print == 0);
    }

    Container container;
    unsetenv("container");
    struct stat st;
    if (stat("/run/.containerenv", &st) == 0)
        assert(container.render() == "podman");
    else if (stat("/.dockerenv", &st) == 0)
        assert(container.render() == "docker");
    else {
        assert(container.render().empty());
        setenv("container", "systemd-nspawn", 1);
        assert(container.render() == "systemd-nspawn");
        unsetenv("container");
    }
}

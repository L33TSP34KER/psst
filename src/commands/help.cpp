#include "commands/commands.hpp"
#include <iostream>
#include <ostream>

static void print_usage() {
	std::cout << "USAGE" << std::endl;
	std::cout << "     psst [--help] [command]" << std::endl;
	std::cout << std::endl;
	std::cout << "COMMANDS" << std::endl;
	std::cout << "     init" << std::endl;
	std::cout << "             Generate the prompt for the current shell and print" << std::endl;
	std::cout << "             it to standard output." << std::endl;
	std::cout << std::endl;
	std::cout << "OPTIONS" << std::endl;
	std::cout << "     -h, --help" << std::endl;
	std::cout << "             Show this help message and exit." << std::endl;
	std::cout << std::endl;
	std::cout << "EXIT STATUS" << std::endl;
	std::cout << "     0       Success." << std::endl;
	std::cout << "     1       Failure (e.g. unsupported shell or missing $SHELL)." << std::endl;
	std::cout << std::endl;
}

int commands::help_menu() {

    std::cout << "      .-.               " << std::endl;
    std::cout << "     [.-''-.,           " << std::endl;
    std::cout << "     |  //`~\\)          " << std::endl;
    std::cout << "     (<| 0\\0|>_     - prompter (psst)    " << std::endl;
    std::cout << "     \";\\  _\"/        " << std::endl;
    std::cout << "    __\\|'._/_    " << std::endl;
    std::cout << std::endl;

    print_usage();

    return 0;
}

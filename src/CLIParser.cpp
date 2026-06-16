#include "CLIParser.h"

#include <iostream>
#include <stdexcept>
#include <string>

CLIOptions CLIParser::parse(int argc, char* argv[]) {
    CLIOptions options;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            options.showHelp = true;
        } else if (arg == "--sort") {
            if (i + 1 >= argc) {
                throw std::runtime_error("--sort requires a value");
            }

            options.sortBy = argv[++i];

            if (options.sortBy != "pid" &&
                options.sortBy != "name" &&
                options.sortBy != "state" &&
                options.sortBy != "mem") {
                throw std::runtime_error("invalid sort option: " + options.sortBy);
            }
        } else if (arg == "--filter-name") {
            if (i + 1 >= argc) {
                throw std::runtime_error("--filter-name requires a value");
            }

            options.nameFilter = argv[++i];
        } else if (arg == "--filter-state") {
            if (i + 1 >= argc) {
                throw std::runtime_error("--filter-state requires a value");
            }

            options.stateFilter = argv[++i];

            if (options.stateFilter.size() != 1) {
                throw std::runtime_error("--filter-state must be a single process state character");
            }
        } else {
            throw std::runtime_error("unknown option: " + arg);
        }
    }

    return options;
}

void CLIParser::printHelp() {
    std::cout
        << "C++ Linux Process Monitor\n\n"
        << "Usage:\n"
        << "  procmon [options]\n\n"
        << "Options:\n"
        << "  -h, --help                  Show this help message\n"
        << "  --sort pid                  Sort by process ID\n"
        << "  --sort name                 Sort by process name\n"
        << "  --sort state                Sort by process state\n"
        << "  --sort mem                  Sort by memory usage, highest first\n"
        << "  --filter-name <name>        Show processes whose names contain <name>\n"
        << "  --filter-state <state>      Show processes with a specific state\n\n"
        << "Examples:\n"
        << "  procmon\n"
        << "  procmon --sort mem\n"
        << "  procmon --filter-name bash\n"
        << "  procmon --filter-state R\n";
}

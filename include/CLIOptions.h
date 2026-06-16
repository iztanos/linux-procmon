#ifndef CLI_OPTIONS_H
#define CLI_OPTIONS_H

#include <string>

struct CLIOptions {
    std::string sortBy = "pid";
    std::string nameFilter;
    std::string stateFilter;
    bool showHelp = false;
};

#endif

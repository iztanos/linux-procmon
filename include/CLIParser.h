#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include "CLIOptions.h"

class CLIParser {
public:
    static CLIOptions parse(int argc, char* argv[]);
    static void printHelp();
};

#endif

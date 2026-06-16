#include "CLIParser.h"
#include "Formatter.h"
#include "ProcReader.h"
#include "ProcessTable.h"

#include <exception>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    try {
        CLIOptions options = CLIParser::parse(argc, argv);

        if (options.showHelp) {
            CLIParser::printHelp();
            return 0;
        }

        ProcReader reader;
        std::vector<ProcessInfo> processes = reader.readAllProcesses();

        ProcessTable::applyOptions(processes, options);
        Formatter::printTable(processes);

        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        std::cerr << "Use --help to see available options.\n";
        return 1;
    }
}

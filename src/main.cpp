#include "Formatter.h"
#include "ProcReader.h"

#include <exception>
#include <iostream>
#include <vector>

int main() {
    try {
        ProcReader reader;
        std::vector<ProcessInfo> processes = reader.readAllProcesses();

        Formatter::printTable(processes);

        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
}

#include "Formatter.h"

#include <iomanip>
#include <iostream>
#include <string>

void Formatter::printTable(const std::vector<ProcessInfo>& processes) {
    std::cout << std::left
              << std::setw(8) << "PID"
              << std::setw(25) << "NAME"
              << std::setw(8) << "STATE"
              << std::setw(12) << "MEM(KB)"
              << '\n';

    std::cout << std::string(53, '-') << '\n';

    for (const ProcessInfo& process : processes) {
        std::cout << std::left
                  << std::setw(8) << process.pid
                  << std::setw(25) << process.name
                  << std::setw(8) << process.state
                  << std::setw(12) << process.memoryKb
                  << '\n';
    }
}

#ifndef PROCESS_TABLE_H
#define PROCESS_TABLE_H

#include "CLIOptions.h"
#include "ProcessInfo.h"

#include <string>
#include <vector>

class ProcessTable {
public:
    static void applyOptions(std::vector<ProcessInfo>& processes, const CLIOptions& options);

private:
    static void filterByName(std::vector<ProcessInfo>& processes, const std::string& nameFilter);
    static void filterByState(std::vector<ProcessInfo>& processes, const std::string& stateFilter);
    static void sortProcesses(std::vector<ProcessInfo>& processes, const std::string& sortBy);
};

#endif

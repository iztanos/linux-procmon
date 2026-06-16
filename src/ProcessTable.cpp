#include "ProcessTable.h"

#include <algorithm>

void ProcessTable::applyOptions(std::vector<ProcessInfo>& processes, const CLIOptions& options) {
    if (!options.nameFilter.empty()) {
        filterByName(processes, options.nameFilter);
    }

    if (!options.stateFilter.empty()) {
        filterByState(processes, options.stateFilter);
    }

    sortProcesses(processes, options.sortBy);
}

void ProcessTable::filterByName(std::vector<ProcessInfo>& processes, const std::string& nameFilter) {
    processes.erase(
        std::remove_if(
            processes.begin(),
            processes.end(),
            [&nameFilter](const ProcessInfo& process) {
                return process.name.find(nameFilter) == std::string::npos;
            }),
        processes.end());
}

void ProcessTable::filterByState(std::vector<ProcessInfo>& processes, const std::string& stateFilter) {
    processes.erase(
        std::remove_if(
            processes.begin(),
            processes.end(),
            [&stateFilter](const ProcessInfo& process) {
                return process.state != stateFilter;
            }),
        processes.end());
}

void ProcessTable::sortProcesses(std::vector<ProcessInfo>& processes, const std::string& sortBy) {
    if (sortBy == "pid") {
        std::sort(
            processes.begin(),
            processes.end(),
            [](const ProcessInfo& a, const ProcessInfo& b) {
                return a.pid < b.pid;
            });
    } else if (sortBy == "name") {
        std::sort(
            processes.begin(),
            processes.end(),
            [](const ProcessInfo& a, const ProcessInfo& b) {
                return a.name < b.name;
            });
    } else if (sortBy == "state") {
        std::sort(
            processes.begin(),
            processes.end(),
            [](const ProcessInfo& a, const ProcessInfo& b) {
                return a.state < b.state;
            });
    } else if (sortBy == "mem") {
        std::sort(
            processes.begin(),
            processes.end(),
            [](const ProcessInfo& a, const ProcessInfo& b) {
                return a.memoryKb > b.memoryKb;
            });
    }
}

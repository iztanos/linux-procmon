#include "ProcReader.h"

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <sstream>

std::vector<ProcessInfo> ProcReader::readAllProcesses() const {
    std::vector<ProcessInfo> processes;

    for (const auto& entry : std::filesystem::directory_iterator("/proc")) {
        if (!entry.is_directory()) {
            continue;
        }

        std::string filename = entry.path().filename().string();

        if (!isNumeric(filename)) {
            continue;
        }

        int pid = 0;

        try {
            pid = std::stoi(filename);
        } catch (...) {
            continue;
        }

        std::optional<ProcessInfo> process = readProcess(pid);

        if (process.has_value()) {
            processes.push_back(process.value());
        }
    }

    return processes;
}

std::optional<ProcessInfo> ProcReader::readProcess(int pid) const {
    std::string path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream file(path);

    if (!file.is_open()) {
        return std::nullopt;
    }

    ProcessInfo info;
    info.pid = pid;
    info.memoryKb = 0;

    std::string line;

    while (std::getline(file, line)) {
        if (line.rfind("Name:", 0) == 0) {
            info.name = trimLeading(line.substr(5));
        } else if (line.rfind("State:", 0) == 0) {
            std::string stateText = trimLeading(line.substr(6));

            if (!stateText.empty()) {
                info.state = stateText.substr(0, 1);
            }
        } else if (line.rfind("VmRSS:", 0) == 0) {
            info.memoryKb = parseMemoryKb(line);
        }
    }

    if (info.name.empty()) {
        return std::nullopt;
    }

    return info;
}

bool ProcReader::isNumeric(const std::string& value) const {
    if (value.empty()) {
        return false;
    }

    return std::all_of(value.begin(), value.end(), [](unsigned char ch) {
        return std::isdigit(ch);
    });
}

std::string ProcReader::trimLeading(const std::string& value) const {
    size_t start = value.find_first_not_of(" \t");

    if (start == std::string::npos) {
        return "";
    }

    return value.substr(start);
}

long ProcReader::parseMemoryKb(const std::string& line) const {
    std::istringstream iss(line);

    std::string key;
    long value = 0;
    std::string unit;

    iss >> key >> value >> unit;

    return value;
}

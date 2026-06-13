#ifndef PROC_READER_H
#define PROC_READER_H

#include "ProcessInfo.h"

#include <optional>
#include <string>
#include <vector>

class ProcReader {
public:
    std::vector<ProcessInfo> readAllProcesses() const;

private:
    bool isNumeric(const std::string& value) const;
    std::optional<ProcessInfo> readProcess(int pid) const;
    std::string trimLeading(const std::string& value) const;
    long parseMemoryKb(const std::string& line) const;
};

#endif

#ifndef FORMATTER_H
#define FORMATTER_H

#include "ProcessInfo.h"

#include <vector>

class Formatter {
public:
    static void printTable(const std::vector<ProcessInfo>& processes);
};

#endif

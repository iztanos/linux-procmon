#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include <string>

struct ProcessInfo {
    int pid = 0;
    std::string name;
    std::string state;
    long memoryKb = 0;
};

#endif

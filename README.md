# C++ Linux Procmon

A command-line Linux process monitor written in C++.

The program reads process information from the Linux `/proc` virtual filesystem and displays running processes in a table.

## Features

- Scans `/proc` for running processes
- Detects numeric process directories
- Reads `/proc/<pid>/status`
- Displays:
  - PID
  - process name
  - process state
  - memory usage in KB
- Handles processes that disappear while being read
- Supports sorting by PID, name, state, and memory usage
- Supports filtering by process name
- Supports filtering by process state

## Build

```bash
make
```

## Usage

```bash
./procmon
./procmon --help
./procmon --sort mem
./procmon --sort name
./procmon --filter-name bash
./procmon --filter-state R
```

Or:

```bash
make run
```

## Example Output

```text
PID     NAME                     STATE   MEM(KB)
-----------------------------------------------------
1       systemd                  S       12800
1045    bash                     S       5120
2088    procmon                  R       1900
```

## Requirements

- Linux
- C++17 compiler
- GNU Make

## Notes

This project currently uses `/proc/<pid>/status` because it is easier to parse than `/proc/<pid>/stat`.

Future phases will add sorting, filtering, refresh mode, CPU usage, user names, and process tree display.

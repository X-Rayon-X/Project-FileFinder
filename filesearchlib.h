#ifndef FILESEARCHLIB_H
#define FILESEARCHLIB_H

#include <vector>
#include <string>

namespace FileSearchLib {
    // Function for searching files by name in the specified directory and its subdirectories
    std::vector<std::string> searchFiles(const std::string& directory, const std::string& fileName);
}

#endif


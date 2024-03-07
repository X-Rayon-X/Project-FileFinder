#include "filesearchlib.h"
#include <iostream>
#include <cstring>
#include <dirent.h>

namespace FileSearchLib {
    std::vector<std::string> searchFiles(const std::string& directory, const std::string& fileName) {
        std::vector<std::string> files;
        DIR* dir = opendir(directory.c_str());

        if (dir) {
            struct dirent* entry;
            while ((entry = readdir(dir)) != nullptr) {
                std::string fullPath = directory + "\\" + entry->d_name;
                if (entry->d_type == DT_REG && entry->d_name == fileName) {
                    std::cout << "File found: " << fullPath << std::endl;
                    files.push_back(fullPath);
                }
                else if (entry->d_type == DT_DIR && std::strcmp(entry->d_name, ".") != 0 && std::strcmp(entry->d_name, "..") != 0) {
                    std::vector<std::string> subfiles = searchFiles(fullPath, fileName);
                    files.insert(files.end(), subfiles.begin(), subfiles.end());
                }
            }
            closedir(dir);
        }
        else {
            std::cerr << "Error opening directory " << directory << std::endl;
        }

        return files;
    }
}

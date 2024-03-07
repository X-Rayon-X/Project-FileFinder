#include "filesearchlib.h"

int main() {
    // Specify the name of the file to be found
    std::string fileName = "example.txt";

    // Calling the file search function from the beginning of the drive "C:\"
    FileSearchLib::searchFiles("C:\\", fileName);

    return 0;
}


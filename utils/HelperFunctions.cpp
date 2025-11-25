#include "HelperFunctions.h"
#include <fstream> // Required for file operations
#include <sstream> // Required for string stream operations

namespace HelperFunctions {
    void print_users(const std::vector<int>& users) {
        io.outputstring("[");
        if (!users.empty()) {
            io.outputint(users.front());
            io.outputstring("-");
            io.outputint(users.back());
        }
        io.outputstring("]");
    }

    std::map<std::string, std::string> readConfigFile(const std::string& filename) {
        std::map<std::string, std::string> config;
        std::ifstream file(filename);

        if (!file.is_open()) {
            io.outputstring("Error: Could not open configuration file: ");
            io.outputstring(filename);
            io.terminate();
            return config; // Return empty map on error
        }

        std::string line;
        while (std::getline(file, line)) {
            // Skip empty lines and comments
            if (line.empty() || line[0] == '#') {
                continue;
            }

            std::istringstream iss(line);
            std::string key;
            if (std::getline(iss, key, '=')) {
                std::string value;
                if (std::getline(iss, value)) {
                    config[key] = value;
                }
            }
        }
        file.close();
        return config;
    }
}
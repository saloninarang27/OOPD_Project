#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <vector>
#include <string>
#include <map> // Include for std::map
#include "basicIO.h"

// This file declares helper functions that can be used across the project.
// These are general-purpose utilities that don't belong to a specific class.

namespace HelperFunctions {
    // Prints a list of user IDs to the console in a formatted way.
    void print_users(const std::vector<int>& users);

    // Reads a configuration file and returns a map of key-value pairs.
    std::map<std::string, std::string> readConfigFile(const std::string& filename);
}

#endif // HELPER_FUNCTIONS_H

#include "FiveGNetwork.h"
#include "../utils/Constants.h"
#include <numeric>

// The 5G-specific implementation of calculateUserCapacity.
// This logic uses Massive MIMO (a large number of antennas) to calculate capacity.
int FiveGNetwork::calculateUserCapacity() {
    int num_channels = Constants::FIVE_G_TOTAL_BANDWIDTH / 1000000; // Number of 1MHz channels
    return num_channels * Constants::FIVE_G_USERS_PER_MHZ * Constants::FIVE_G_ANTENNAS;
}

// The 5G-specific implementation for getting the users on the first channel.
std::vector<int> FiveGNetwork::getFirstChannelUsers() {
    std::vector<int> users(Constants::FIVE_G_USERS_PER_MHZ);
    std::iota(users.begin(), users.end(), 1);
    return users;
}

// Returns the network type as a string.
std::string FiveGNetwork::getNetworkType() const {
    return "5G";
}

// This method is specific to the FiveGNetwork class and provides information
// related to the Massive MIMO feature of 5G.
int FiveGNetwork::getRequiredCores() {
    return Constants::FIVE_G_ANTENNAS;
}

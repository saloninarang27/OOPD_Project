#include "FourGNetwork.h"
#include "../utils/Constants.h"
#include <numeric>

// The 4G-specific implementation of calculateUserCapacity.
// This logic includes factors like the number of antennas (MIMO), which is unique to 4G/5G.
int FourGNetwork::calculateUserCapacity() {
    int num_channels = Constants::THREE_G_TOTAL_BANDWIDTH / Constants::FOUR_G_CHANNEL_BANDWIDTH;
    return num_channels * Constants::FOUR_G_USERS_PER_CHANNEL * Constants::FOUR_G_ANTENNAS;
}

// The 4G-specific implementation for getting the users on the first channel.
std::vector<int> FourGNetwork::getFirstChannelUsers() {
    std::vector<int> users(Constants::FOUR_G_USERS_PER_CHANNEL);
    std::iota(users.begin(), users.end(), 1);
    return users;
}

// Returns the network type as a string.
std::string FourGNetwork::getNetworkType() const {
    return "4G";
}

// This is a method unique to the FourGNetwork class. It is not part of the
// polymorphic interface of CellularNetwork. It provides information specific
// to the 4G technology standard.
int FourGNetwork::getRequiredCores() {
    return Constants::FOUR_G_ANTENNAS;
}

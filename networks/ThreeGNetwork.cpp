#include "ThreeGNetwork.h"
#include "../utils/Constants.h"
#include <numeric>

// The 3G-specific implementation of calculateUserCapacity.
// This method provides the unique logic for 3G, as required by the base class contract.
int ThreeGNetwork::calculateUserCapacity() {
    int num_channels = Constants::THREE_G_TOTAL_BANDWIDTH / Constants::THREE_G_CHANNEL_BANDWIDTH;
    return num_channels * Constants::THREE_G_USERS_PER_CHANNEL;
}

// The 3G-specific implementation for getting the users on the first channel.
std::vector<int> ThreeGNetwork::getFirstChannelUsers() {
    std::vector<int> users(Constants::THREE_G_USERS_PER_CHANNEL);
    std::iota(users.begin(), users.end(), 1);
    return users;
}

// Returns the network type as a string, fulfilling the base class contract.
std::string ThreeGNetwork::getNetworkType() const {
    return "3G";
}

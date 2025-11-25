#include "TwoGNetwork.h"
#include "../utils/Constants.h"
#include <numeric>

// This is the concrete implementation of calculateUserCapacity for a 2G network.
// It fulfills the contract established by the pure virtual function in the CellularNetwork base class.
// This is a key part of polymorphism: the base class defines "what" to do, and this derived class defines "how" to do it for 2G.
int TwoGNetwork::calculateUserCapacity() {
    int num_channels = Constants::TWO_G_TOTAL_BANDWIDTH / Constants::TWO_G_CHANNEL_BANDWIDTH;
    return num_channels * Constants::TWO_G_USERS_PER_CHANNEL;
}

// This is the 2G-specific implementation for getting the users on the first channel.
std::vector<int> TwoGNetwork::getFirstChannelUsers() {
    std::vector<int> users(Constants::TWO_G_USERS_PER_CHANNEL);
    std::iota(users.begin(), users.end(), 1); // Fills the vector with user IDs from 1 to N.
    return users;
}

// Returns the network type as a string. This is another part of the contract from the base class.
std::string TwoGNetwork::getNetworkType() const {
    return "2G";
}

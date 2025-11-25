#include "CellTower.h"
#include <numeric> // For std::accumulate
#include<cstddef>

// Constructor: Initializes the CellTower object with a unique ID.
// This is a fundamental part of an object's lifecycle.
CellTower::CellTower(int id) : id(id) {}

// This method enforces the business logic of the simulation.
// It checks if a new user can be added to a frequency band based on its capacity.
// This is part of the behavior aspect of encapsulation.
bool CellTower::canConnectUser(int frequency, int capacity_per_frequency) const {
    auto it = connected_users.find(frequency);
    if (it != connected_users.end()) {
        return it->second.size() < static_cast<size_t>(capacity_per_frequency);
    }
    return true; // No users on this frequency yet, so connection is possible.
}

// This method modifies the state of the CellTower by adding a user.
// It uses canConnectUser to ensure that the state remains valid.
bool CellTower::connectUser(const UserDevice& user, int frequency, int capacity_per_frequency) {
    if (canConnectUser(frequency, capacity_per_frequency)) {
        connected_users[frequency].push_back(user);
        return true;
    }
    return false;
}

// This method provides read-only access to the list of users on a specific frequency.
// By returning a const reference, it prevents external modification of the internal state,
// thus upholding encapsulation.
const std::vector<UserDevice>& CellTower::getUsersByFrequency(int frequency) const {
    auto it = connected_users.find(frequency);
    if (it != connected_users.end()) {
        return it->second;
    }
    static std::vector<UserDevice> empty_vector;
    return empty_vector;
}

// This method calculates a value based on the internal state of the object.
// It iterates over the encapsulated 'connected_users' map to compute the total.
int CellTower::getTotalConnectedUsers() const {
    int total = 0;
    for (const auto& pair : connected_users) {
        total += pair.second.size();
    }
    return total;
}

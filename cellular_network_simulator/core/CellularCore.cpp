#include "CellularCore.h"
#include "../utils/basicIO.h" // For io.outputstring
#include <numeric> // For std::accumulate

// Constructor: Initializes the CellularCore object with a unique ID.
CellularCore::CellularCore(int id) : id(id) {}

// This method modifies the state of the CellularCore by adding a tower.
// This is a key part of managing the aggregated CellTower objects.
void CellularCore::addTower(const CellTower& tower) {
    towers.push_back(tower);
}

// This method demonstrates the core's responsibility to orchestrate actions across its towers.
// It iterates through its collection of towers to calculate a network-wide value.
int CellularCore::calculateTotalMessages(int messages_per_user) const {
    int total_messages = 0;
    // The core communicates with the tower objects through their public interface.
    for (const auto& tower : towers) {
        total_messages += tower.getTotalConnectedUsers() * messages_per_user;
    }
    return total_messages;
}

// This method simulates a complex process by coordinating with the aggregated tower objects.
// It shows how the core acts as a central controller in the network simulation.
void CellularCore::simulateUserConnections(int num_users_to_connect, int capacity_per_frequency, int messages_per_user) {
    io.outputstring("Simulating user connections for ");
    io.outputint(num_users_to_connect);
    io.outputstring(" users with capacity ");
    io.outputint(capacity_per_frequency);
    io.outputstring(" per frequency and ");
    io.outputint(messages_per_user);
    io.outputstring(" messages/user.\n");

    int connected_count = 0;
    for (int i = 0; i < num_users_to_connect; ++i) {
        UserDevice user(i + 1); // Creates a UserDevice object.
        bool connected = false;
        // The core iterates through its towers to find a suitable connection point for the user.
        for (auto& tower : towers) {
            for (int freq = 1; freq <= 3; ++freq) {
                // It uses the public interface of the CellTower to attempt a connection.
                if (tower.connectUser(user, freq, capacity_per_frequency)) {
                    connected_count++;
                    connected = true;
                    break;
                }
            }
            if (connected) {
                break;
            }
        }
    }
    io.outputstring("Total users connected: ");
    io.outputint(connected_count);
    io.terminate();
}

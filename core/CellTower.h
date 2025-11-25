#ifndef CELL_TOWER_H
#define CELL_TOWER_H

#include "UserDevice.h"
#include <vector>
#include <map>

// OOP Principle: Encapsulation and Abstraction
// The CellTower class encapsulates the data and behavior of a cell tower.
// It provides a clear, abstract interface to interact with a tower without exposing
// the underlying implementation details of how users are managed.
class CellTower {
private:
    // OOP Principle: Data Hiding
    // The 'id' and 'connected_users' members are private to prevent direct,
    // uncontrolled access from outside the class. This is a core aspect of encapsulation.
    int id;
    std::map<int, std::vector<UserDevice>> connected_users;

public:
    // Constructor to initialize a CellTower with a specific ID.
    CellTower(int id);

    // Public methods providing controlled access to the tower's functionality.
    // This is the public interface of the class.
    bool connectUser(const UserDevice& user, int frequency, int capacity_per_frequency);
    bool canConnectUser(int frequency, int capacity_per_frequency) const;
    const std::vector<UserDevice>& getUsersByFrequency(int frequency) const;
    int getTotalConnectedUsers() const;
};

#endif // CELL_TOWER_H

#ifndef CELLULAR_CORE_H
#define CELLULAR_CORE_H

#include "CellTower.h"
#include <vector>

// OOP Principle: Encapsulation and Aggregation
// The CellularCore class encapsulates the management of multiple cell towers.
// It demonstrates aggregation, as it "has-a" collection of CellTower objects.
class CellularCore {
private:
    // OOP Principle: Data Hiding
    // The 'id' and 'towers' vector are private, ensuring that they cannot be
    // manipulated directly from outside the class.
    int id;
    std::vector<CellTower> towers; // Aggregation: CellularCore contains CellTower objects.

public:
    // Constructor to initialize the core with a specific ID.
    CellularCore(int id);

    // Public interface for managing the core network.
    void addTower(const CellTower& tower);
    int calculateTotalMessages(int messages_per_user) const;
    void simulateUserConnections(int num_users_to_connect, int capacity_per_frequency, int messages_per_user);
};

#endif // CELLULAR_CORE_H

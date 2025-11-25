#ifndef THREE_G_NETWORK_H
#define THREE_G_NETWORK_H

#include "CellularNetwork.h"

// OOP Principle: Inheritance
// Like TwoGNetwork, the ThreeGNetwork class inherits from the CellularNetwork base class.
// It provides its own 3G-specific implementations for the functions defined in the
// abstract base class, demonstrating the "is-a" relationship (a 3G network "is-a" cellular network).
class ThreeGNetwork : public CellularNetwork {
public:
    // Overriding the base class's virtual functions with 3G-specific logic.
    int calculateUserCapacity() override;
    std::vector<int> getFirstChannelUsers() override;
    std::string getNetworkType() const override;
};

#endif // THREE_G_NETWORK_H

#ifndef FIVE_G_NETWORK_H
#define FIVE_G_NETWORK_H

#include "CellularNetwork.h"

// OOP Principle: Inheritance
// The FiveGNetwork class is the final derived class in this hierarchy.
// It inherits from CellularNetwork and provides the most advanced set of features.
class FiveGNetwork : public CellularNetwork {
public:
    // Overriding the base class's virtual functions with 5G-specific logic.
    int calculateUserCapacity() override;
    std::vector<int> getFirstChannelUsers() override;
    std::string getNetworkType() const override;

    // Like 4G, the 5G network has its own specific methods that are not
    // part of the base class interface, representing technology-specific features.
    int getRequiredCores();
};

#endif // FIVE_G_NETWORK_H

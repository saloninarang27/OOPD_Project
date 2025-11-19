#ifndef TWO_G_NETWORK_H
#define TWO_G_NETWORK_H

#include "CellularNetwork.h"

// OOP Principle: Inheritance
// The TwoGNetwork class is a "concrete" class that inherits from the abstract
// base class CellularNetwork. It provides specific implementations for the
// pure virtual functions defined in the base class.
class TwoGNetwork : public CellularNetwork {
public:
    // The 'override' keyword is used to indicate that these functions are meant to
    // override virtual functions from a base class. This helps catch errors at compile-time.

    // Provides the 2G-specific implementation for calculating user capacity.
    int calculateUserCapacity() override;

    // Provides the 2G-specific implementation for getting users on the first channel.
    std::vector<int> getFirstChannelUsers() override;

    // Provides the 2G-specific network type.
    std::string getNetworkType() const override;
};

#endif // TWO_G_NETWORK_H

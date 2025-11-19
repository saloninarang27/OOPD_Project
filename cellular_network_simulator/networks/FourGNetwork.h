#ifndef FOUR_G_NETWORK_H
#define FOUR_G_NETWORK_H

#include "CellularNetwork.h"

// OOP Principle: Inheritance
// The FourGNetwork class continues the pattern of inheriting from CellularNetwork.
// It provides 4G-specific implementations for the common interface.
class FourGNetwork : public CellularNetwork {
public:
    // Overriding the base class's virtual functions with 4G-specific logic.
    int calculateUserCapacity() override;
    std::vector<int> getFirstChannelUsers() override;
    std::string getNetworkType() const override;

    // This is an example of extending the functionality of the base class.
    // This method is specific to FourGNetwork and is not part of the
    // general CellularNetwork interface.
    int getRequiredCores();
};

#endif // FOUR_G_NETWORK_H

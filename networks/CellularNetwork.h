#ifndef CELLULAR_NETWORK_H
#define CELLULAR_NETWORK_H

#include <vector>
#include <string>

// OOP Principle: Abstraction and Polymorphism
// This is an abstract base class that defines a common interface for all cellular network types (2G, 3G, etc.).
// It uses pure virtual functions to enforce that any concrete (derived) network class must implement
// a specific set of behaviors. This is a powerful abstraction technique.
class CellularNetwork {
public:
    // A virtual destructor is crucial in a polymorphic base class.
    // It ensures that the destructor of the derived class is called when an object
    // is deleted through a base class pointer, preventing resource leaks.
    virtual ~CellularNetwork() = default;

    // OOP Principle: Polymorphism via Pure Virtual Functions
    // These functions define the interface of the CellularNetwork. By being "pure" (= 0),
    // they have no implementation in the base class and MUST be overridden by derived classes.
    // This allows us to treat objects of different network types uniformly (e.g., in a container)
    // and call these methods, with the correct derived class version being executed at runtime.

    // Calculates the total user capacity of the network.
    virtual int calculateUserCapacity() = 0;

    // Gets the list of users on the first channel of the network.
    virtual std::vector<int> getFirstChannelUsers() = 0;

    // Gets the type of the network (e.g., "2G", "3G").
    virtual std::string getNetworkType() const = 0;
};

#endif // CELLULAR_NETWORK_H

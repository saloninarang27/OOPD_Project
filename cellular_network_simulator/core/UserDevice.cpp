#include "UserDevice.h"
#include <iostream>

// Constructor: Initializes the UserDevice object with a unique ID.
UserDevice::UserDevice(int id) : id(id) {}

// Getter method for the device ID.
// This is an example of an "accessor" method. It provides controlled, read-only
// access to the private 'id' member, which is a key aspect of encapsulation.
int UserDevice::getId() const {
    return id;
}

// This method simulates a behavior of the UserDevice.
// In a more complex simulation, this could be a virtual function to allow
// different types of user devices to generate traffic differently (polymorphism).
int UserDevice::generateTraffic() const {
    // For now, it returns a fixed value, but it represents an action
    // that the object can perform.
    return 10; // Generic message count
}

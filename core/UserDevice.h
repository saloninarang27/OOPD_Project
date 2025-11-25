#ifndef USER_DEVICE_H
#define USER_DEVICE_H

// OOP Principle: Encapsulation
// The UserDevice class encapsulates the data and behavior of a single user's device.
// It holds the device's ID and provides methods to interact with it.
class UserDevice {
private:
    // OOP Principle: Data Hiding
    // The 'id' is private, meaning it can only be accessed through the class's
    // public methods. This prevents external code from arbitrarily changing it.
    int id;

public:
    // Constructor to initialize the UserDevice with a specific ID.
    UserDevice(int id);

    // Public getter method (accessor) to provide controlled, read-only access
    // to the private 'id' member. This is a key part of encapsulation.
    int getId() const;

    // Simulates the user device generating network traffic.
    int generateTraffic() const;
};

#endif // USER_DEVICE_H

# Cellular Network Simulator

## Project Objective

This project is a C++ simulation of a cellular network, designed to demonstrate key Object-Oriented Programming (OOP) principles. It models different generations of cellular technology (2G, 3G, 4G, 5G) and their respective behaviors, such as user capacity, frequency allocation, and network hierarchy.

## OOP Principles Used

*   **Abstraction:** The `CellularNetwork` class serves as an abstract base class, defining a common interface for all network types. It uses pure virtual functions like `calculateUserCapacity()` and `getFirstChannelUsers()` to enforce a contract that all derived classes must follow.
*   **Inheritance:** The `TwoGNetwork`, `ThreeGNetwork`, `FourGNetwork`, and `FiveGNetwork` classes inherit from the `CellularNetwork` base class, reusing common functionality and extending it with generation-specific logic.
*   **Encapsulation:** All classes encapsulate their data by keeping member variables private or protected. Public methods are provided to interact with the objects' state in a controlled manner.
*   **Polymorphism:** The `main` function uses a base class pointer (`CellularNetwork*`) to interact with objects of derived classes. This allows for writing generic code that can work with any network type, demonstrating runtime polymorphism.

## How to Compile and Run

You can compile and run the simulation using a C++ compiler like g++.

### Prerequisites

*   g++ (or another C++17 compatible compiler)
*   make (optional, for using the provided Makefile)

### Compilation

To compile the project, navigate to the `cellular_network_simulator` directory and run the following command:

```bash
g++ -std=c++17 -I. core/*.cpp networks/*.cpp main.cpp -o simulator
```

### Running the Simulation

After successful compilation, you can run the simulator with:

```bash
./simulator
```

# CELLULAR NETWORK SIMULATOR
## OOPD Project - Monsoon 2025

## Project Description
This project implements a cellular network simulator that models 2G, 3G, 4G, and 5G communication technologies. It demonstrates various object-oriented programming concepts including inheritance, polymorphism, data abstraction, templates, and exception handling.

## Files Included
1. `CellularNetwork.h`      - Header file with class declarations
2. `CellularNetwork.cpp`    - Implementation of cellular network classes
3. `main.cpp`               - Main program entry point
4. `basicIO.h`              - Basic I/O interface (provided)
5. `basicIO.cpp`            - Basic I/O implementation (provided)
6. `syscall.s`              - Assembly code for system calls
7. `Makefile`               - Build automation file
8. `README.txt`             - This file

## Build Instructions

### Prerequisites
*   g++ compiler with C++17 support
*   GNU Make
*   Linux/Unix environment (for syscall.s)

### Building the Project

1.  To build both debug and release versions:
    ```bash
    $ mingw32-make all
    ```
2.  To build only the debug version:
    ```bash
    $ mingw32-make debug
    ```
3.  To build only the release (optimized) version:
    ```bash
    $ mingw32-make release
    ```
4.  To clean all build artifacts:
    ```bash
    $ mingw32-make clean
    ```

### Output Binaries
*   Debug version: `cellular_network_debug`
*   Release version: `cellular_network`

## Running the Simulator

1.  Run the debug version:
    ```bash
    $ mingw32-make run-debug
    ```
    OR
    ```bash
    $ ./cellular_network_debug
    ```
2.  Run the release version:
    ```bash
    $ mingw32-make run
    ```
    OR
    ```bash
    $ ./cellular_network
    ```

The simulator will automatically run all four simulations (2G, 3G, 4G, 5G) and display the results.

## Input File Format
This version of the simulator does not require input files. All simulation parameters are hardcoded according to the project specifications:

### 2G Simulation:
*   Bandwidth: 1 MHz
*   Channel size: 200 kHz
*   Users per channel: 16
*   Messages per user: 20 (5 data + 15 voice)

### 3G Simulation:
*   Bandwidth: 1 MHz
*   Channel size: 200 kHz
*   Users per channel: 32
*   Messages per user: 10

### 4G Simulation:
*   Bandwidth: 1 MHz
*   Channel size: 10 kHz
*   Users per channel: 30
*   Antennas: 4
*   Messages per user: 10

### 5G Simulation:
*   Primary bandwidth: 1 MHz
*   Additional bandwidth: 10 MHz at 1800 MHz
*   Channel size: 10 kHz (primary), 1 MHz (1800 MHz band)
*   Users per channel: 30 (10 kHz), 30 per MHz (1800 MHz)
*   Antennas: 16 (Massive MIMO)
*   Messages per user: 10

## Output Description
For each generation (2G, 3G, 4G, 5G), the simulator displays:
1.  Technology details (TDMA, CDMA, OFDM, etc.)
2.  Bandwidth configuration
3.  Total capacity (number of users supported)
4.  Users occupying the first channel
5.  Number of cellular cores needed

## Object-Oriented Features Demonstrated

The project extensively uses Object-Oriented Programming (OOP) principles to model the cellular network.

1.  **Inheritance:**
    *   `UserDevice` is a base class. `User2G`, `User3G`, `User4G`, `User5G` inherit from `UserDevice`.
    *   `CellTower` is a base class. `Tower2G`, `Tower3G`, `Tower4G`, `Tower5G` inherit from `CellTower`.
    *   `TwoGNetwork`, `ThreeGNetwork`, `FourGNetwork`, and `FiveGNetwork` classes inherit from the `CellularNetwork` base class, reusing common functionality and extending it with generation-specific logic.

2.  **Polymorphism:**
    *   Virtual function `getMessagesGenerated()` in `UserDevice` is overridden in all derived user classes.
    *   Virtual function `getTotalCapacity()` in `CellTower`.
    *   The `main` function uses a base class pointer (`CellularNetwork*`) to interact with objects of derived classes. This allows for writing generic code that can work with any network type, demonstrating runtime polymorphism.

3.  **Data Abstraction & Encapsulation:**
    *   Private member variables with public getter methods.
    *   Protected members in base classes.
    *   All classes encapsulate their data by keeping member variables private or protected. Public methods are provided to interact with the objects' state in a controlled manner.

4.  **Data Hiding:**
    *   Private members not accessible outside class.
    *   Public interface through methods.

5.  **Templates:**
    *   `NetworkContainer<T>` template class for type-safe collections.

6.  **Exception Handling:**
    *   `NetworkException` base class.
    *   `CapacityExceededException` for capacity violations.
    *   `InvalidConfigurationException` for configuration errors.
    *   Try-catch blocks in simulator.

## Code Attribution
*   `basicIO.h`, `basicIO.cpp`: Provided by course instructor
*   `syscall.s`: Standard x86-64 system call wrapper
*   All other code: Original implementation for this project

## Known Limitations
1.  User assignment to channels is simplified for demonstration.
2.  Cellular core overhead calculation uses simplified model.
3.  No persistent storage of simulation state.
4.  Fixed simulation parameters (not configurable via input files).

## Testing
The program has been tested with:
*   Compilation on g++ with `-std=c++17`
*   Both debug and release builds
*   Exception handling scenarios
*   Capacity validation

## Compilation Flags

### Debug build:
```
-std=c++17 -Wall -Wextra -g -O0 -DDEBUG
```

### Release build:
```
-std=c++17 -Wall -Wextra -O3 -DNDEBUG
```

## Troubleshooting

### If you encounter build errors:
1.  Ensure g++ supports C++17 (g++ --version should show >= 7.0)
2.  Make sure all files are in the same directory (This might be specific to the original project setup; for the current project, files are in subdirectories, so this point might need adjustment or clarification. For now, I'll keep it as is, as it's from the reference)
3.  Check that `syscall.s` is compatible with your architecture (x86-64)
4.  Try cleaning and rebuilding: `mingw32-make clean && mingw32-make all`

### For runtime errors:
1.  Use the debug build for better error messages
2.  Check that basic I/O operations are working correctly
3.  Verify system call compatibility on your platform

## Team
Saloni Narang,Suman Moond,Aastha Kalbhor
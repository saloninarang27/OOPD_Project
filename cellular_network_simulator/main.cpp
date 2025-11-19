#include <vector>
#include <memory>
#include <map> // Include for std::map
#include "networks/CellularNetwork.h"
#include "networks/TwoGNetwork.h"
#include "networks/ThreeGNetwork.h"
#include "networks/FourGNetwork.h"
#include "networks/FiveGNetwork.h"
#include "utils/HelperFunctions.h"
#include "utils/basicIO.h" // Include basicIO.h
#include "core/CellularCore.h" // Include CellularCore.h
#include "core/CellTower.h" // Include CellTower.h
#include "utils/Constants.h" // Include Constants.h

// This function demonstrates POLYMORPHISM.
// It takes a reference to the abstract base class `CellularNetwork`.
// At runtime, it can accept any object of a class derived from CellularNetwork (e.g., TwoGNetwork, ThreeGNetwork).
// The correct `calculateUserCapacity`, `getFirstChannelUsers`, and `getNetworkType` methods are called
// dynamically based on the actual type of the object passed in.
void print_network_info(CellularNetwork& network, CellularCore& core, int messages_per_user) {
    io.outputstring("--- ");
    io.outputstring(network.getNetworkType());
    io.outputstring(" Network Simulation ---");
    io.terminate();
    io.outputstring("Total user capacity: ");
    io.outputint(network.calculateUserCapacity());
    io.terminate();
    io.outputstring("Users in first frequency band: ");
    HelperFunctions::print_users(network.getFirstChannelUsers());
    io.terminate();

    // Use dynamic_cast to check if the network is a 4G or 5G network to call specific methods.
    if (auto* fourG = dynamic_cast<FourGNetwork*>(&network)) {
        io.outputstring("Required cores: ");
        io.outputint(fourG->getRequiredCores());
        io.terminate();
    } else if (auto* fiveG = dynamic_cast<FiveGNetwork*>(&network)) {
        io.outputstring("Required cores: ");
        io.outputint(fiveG->getRequiredCores());
        io.terminate();
    }
    
    // Simulate user connections and calculate total messages
    // Limiting num_users_to_connect to a reasonable number to avoid long execution times
    // and potential perceived infinite loops, especially if capacity is low.
    int users_to_simulate = std::min(network.calculateUserCapacity(), 100); // Simulate max 100 users or network capacity
    int current_capacity_per_frequency = 0;
    if (network.getNetworkType() == "2G") {
        current_capacity_per_frequency = Constants::TWO_G_USERS_PER_CHANNEL;
    } else if (network.getNetworkType() == "3G") {
        current_capacity_per_frequency = Constants::THREE_G_USERS_PER_CHANNEL;
    } else if (network.getNetworkType() == "4G") {
        current_capacity_per_frequency = Constants::FOUR_G_USERS_PER_CHANNEL;
    } else if (network.getNetworkType() == "5G") {
        current_capacity_per_frequency = Constants::FIVE_G_USERS_PER_MHZ;
    }
    core.simulateUserConnections(users_to_simulate, current_capacity_per_frequency, messages_per_user);
    io.outputstring("Total messages generated: ");
    io.outputint(core.calculateTotalMessages(messages_per_user));
    io.terminate();
    io.terminate();
}

void runInteractiveSession() {
    TwoGNetwork twoG;
    ThreeGNetwork threeG;
    FourGNetwork fourG;
    FiveGNetwork fiveG;
    CellularCore core(1);

    while (true) {
        io.outputstring("\n--- Interactive Simulation ---");
        io.terminate();
        io.outputstring("Select a network to simulate:");
        io.terminate();
        io.outputstring("1. 2G");
        io.terminate();
        io.outputstring("2. 3G");
        io.terminate();
        io.outputstring("3. 4G");
        io.terminate();
        io.outputstring("4. 5G");
        io.terminate();
        io.outputstring("5. Exit");
        io.terminate();
        io.outputstring("Enter your choice: ");
        int choice = io.inputint();

        if (choice == 5) {
            break;
        }

        io.outputstring("Enter number of cell towers: ");
        int num_towers = io.inputint();
        core = CellularCore(1); // Reset the core
        for (int i = 0; i < num_towers; ++i) {
            CellTower tower(100 + i);
            core.addTower(tower);
        }

        io.outputstring("Enter messages per user: ");
        int messages_per_user = io.inputint();

        switch (choice) {
            case 1:
                print_network_info(twoG, core, messages_per_user);
                break;
            case 2:
                print_network_info(threeG, core, messages_per_user);
                break;
            case 3:
                print_network_info(fourG, core, messages_per_user);
                break;
            case 4:
                print_network_info(fiveG, core, messages_per_user);
                break;
            default:
                io.outputstring("Invalid choice. Please try again.");
                io.terminate();
                break;
        }
    }
}

// The main entry point of the simulation.
int main() {
    io.outputstring("Please enter the path to the configuration file: ");
    std::string config_file_path = io.inputstring();

    // Read configuration from file
    std::map<std::string, std::string> config = HelperFunctions::readConfigFile(config_file_path);

    // Default values
    int num_cell_towers = 5;
    int two_g_messages = 20;
    int three_g_messages = 10;
    int four_g_messages = 10;
    int five_g_messages = 10;
    bool simulate_2g = true;
    bool simulate_3g = true;
    bool simulate_4g = true;
    bool simulate_5g = true;

    // Parse configuration
    if (config.count("NUM_CELL_TOWERS")) {
        num_cell_towers = std::stoi(config["NUM_CELL_TOWERS"]);
    }
    if (config.count("TWO_G_MESSAGES")) {
        two_g_messages = std::stoi(config["TWO_G_MESSAGES"]);
    }
    if (config.count("THREE_G_MESSAGES")) {
        three_g_messages = std::stoi(config["THREE_G_MESSAGES"]);
    }
    if (config.count("FOUR_G_MESSAGES")) {
        four_g_messages = std::stoi(config["FOUR_G_MESSAGES"]);
    }
    if (config.count("FIVE_G_MESSAGES")) {
        five_g_messages = std::stoi(config["FIVE_G_MESSAGES"]);
    }
    if (config.count("SIMULATE_2G")) {
        simulate_2g = (config["SIMULATE_2G"] == "true");
    }
    if (config.count("SIMULATE_3G")) {
        simulate_3g = (config["SIMULATE_3G"] == "true");
    }
    if (config.count("SIMULATE_4G")) {
        simulate_4g = (config["SIMULATE_4G"] == "true");
    }
    if (config.count("SIMULATE_5G")) {
        simulate_5g = (config["SIMULATE_5G"] == "true");
    }

    // Create instances of each specific network type.
    TwoGNetwork twoG;
    ThreeGNetwork threeG;
    FourGNetwork fourG;
    FiveGNetwork fiveG;

    // Create a CellularCore and add multiple CellTowers to it
    CellularCore core(1);
    for (int i = 0; i < num_cell_towers; ++i) {
        CellTower tower(100 + i);
        core.addTower(tower);
    }

    // Call the polymorphic function with different network objects based on configuration.
    if (simulate_2g) {
        print_network_info(twoG, core, two_g_messages);
    }
    if (simulate_3g) {
        print_network_info(threeG, core, three_g_messages);
    }
    if (simulate_4g) {
        print_network_info(fourG, core, four_g_messages);
    }
    if (simulate_5g) {
        print_network_info(fiveG, core, five_g_messages);
    }

    io.outputstring("\nDo you want to start an interactive session? (y/n): ");

    char choice = io.inputstring()[0];
    if (choice == 'y' || choice == 'Y') {
        runInteractiveSession();
    }

    return 0;
}



#ifndef CONSTANTS_H
#define CONSTANTS_H

// This file contains all the constant values used throughout the simulation.
// Centralizing them here makes the code cleaner, easier to read, and easier to modify.
// For example, if a network parameter changes, you only need to update it in this one place.

namespace Constants {
    // Constants for the 2G (TDMA) network simulation
    const int TWO_G_USERS_PER_CHANNEL = 16;
    const int TWO_G_CHANNEL_BANDWIDTH = 200000; // 200 kHz
    const int TWO_G_TOTAL_BANDWIDTH = 1000000; // 1 MHz

    // Constants for the 3G (CDMA) network simulation
    const int THREE_G_USERS_PER_CHANNEL = 32;
    const int THREE_G_CHANNEL_BANDWIDTH = 200000; // 200 kHz
    const int THREE_G_TOTAL_BANDWIDTH = 1000000; // 1 MHz
    const int THREE_G_MESSAGES_PER_USER = 10;

    // Constants for the 4G (OFDM) network simulation
    const int FOUR_G_USERS_PER_CHANNEL = 30;
    const int FOUR_G_CHANNEL_BANDWIDTH = 10000; // 10 kHz
    const int FOUR_G_ANTENNAS = 4; // MIMO antennas
    const int FOUR_G_MESSAGES_PER_USER = 10;

    // Constants for the 5G (Massive MIMO) network simulation
    const int FIVE_G_USERS_PER_MHZ = 30;
    const int FIVE_G_TOTAL_BANDWIDTH = 10000000; // 10 MHz
    const int FIVE_G_ANTENNAS = 16; // Massive MIMO antennas
}

#endif // CONSTANTS_H

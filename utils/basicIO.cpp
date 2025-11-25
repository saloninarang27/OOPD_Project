#include "basicIO.h"
#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

basicIO io;

void basicIO::activateInput() {
    // No specific action needed for std::cin activation in this simplified version
}

int basicIO::inputint() {
    int number;
    std::cin >> number;
    return number;
}

std::string basicIO::inputstring() {
    std::string line;
    std::getline(std::cin >> std::ws, line); // std::ws consumes leading whitespace
    return line;
}

void basicIO::outputint(int number) {
    std::cout << number;
}

void basicIO::outputstring(const std::string& text) {
    std::cout << text;
}

void basicIO::terminate() {
    std::cout << std::endl;
}

void basicIO::errorstring(const std::string& text) {
    std::cerr << text;
}

void basicIO::errorint(int number) {
    std::cerr << number;
}


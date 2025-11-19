#ifndef BASIC_IO_H
#define BASIC_IO_H

#include <string>

class basicIO {
public:
    void activateInput();
    int inputint();
    std::string inputstring(); // Returns std::string
    void outputint(int number);
    void outputstring(const std::string& text); // Accepts const std::string&
    void terminate();
    void errorstring(const std::string& text); // Accepts const std::string&
    void errorint(int number);
};

extern basicIO io;

#endif // BASIC_IO_H

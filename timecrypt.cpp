#include <iostream>
#include <string>
#include "timecrypt.h" // Core library

// Main
int main()
{
    std::cout << "--| Timecrypt v1\n--| Hello! Your current key is: " << otime;
    endl(2);

    while (true) {
        std::string command;

        std::cout << "--| Menu\n--| Choose the mode:\n--| Encrypt | Decrypt | Exit\n--| (e | d | ex)" << std::endl;

        do {
            std::cin >> command;
            command = tc::toLower(command);
        } while (command != "ex" && command != "e" && command != "d");

        if (command == "ex")
            break;
        else if (command == "e") {
            endl();
            tc::encrypt();
        }
        else if (command == "d") {
            endl(1);
            tc::decrypt();
        }

        endl();
    }

    return 0;
}
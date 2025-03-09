#include <iostream>
#include <string>
#include "timecrypt.h" // core library

// menu
int main()
{
    std::cout << "--| Timecrypt v1.2\n--| Hello! Your current key is: " << otime;
    

    while (true) {
        std::string command;

        std::cout << "\n\n--| Menu\n--| Choose the mode:\n--| Encrypt | Decrypt | Exit\n--| (e | d | ex)\n";

        do {
            std::cin >> command;
            command = tc::toLower(command);
        } while (command != "ex" && command != "e" && command != "d");

        if (command == "ex")
            break;
        else if (command == "e") {
            tc::encrypt();
        }
        else if (command == "d") {
            tc::decrypt();
        }
    }

    return 0;
}
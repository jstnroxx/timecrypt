#include <iostream>
#include <string>
#include <fstream>

// [32 - 126] ASCII Range

int otime = (time(0) % 94) + 1;

// endls
void endl(int n) {
    for (int c = 0; c < n; c++)
        std::cout << std::endl;
}

void endl() {
    std::cout << std::endl;
}

namespace tc {

    //utility
    std::string toLower(std::string sentence) {
        for (int c = 0; c < sentence.length(); c++)
            if (isalpha(sentence[c]))
                sentence[c] = tolower(sentence[c]);
        return sentence;
    }

    std::string intToString(int n) {
        std::string sentence = "";

        do {
            sentence.insert(sentence.begin(), char((n % 10) + '0'));
            n /= 10;
        } while (n > 0);

        return sentence;
    }

    bool isStringAlphabetic(std::string sentence) {
        for (int c = 0; c < sentence.length(); c++)
            if (!(isalpha(sentence[c])))
                return 0;
        
        return 1;
    }

    // algorithms
    std::string caesarAlgo(std::string text, int key, bool enc) {
        if (enc) {
            std::string encrypted = text;

            for (int c = 0; c < text.length(); c++) {
                encrypted[c] = char(((int(encrypted[c]) + key - 32) % 95) + 32);
            }

            return encrypted;
        }
        else {
            std::string decrypted = text;

            for (int c = 0; c < text.length(); c++) {
                decrypted[c] = char(((int(decrypted[c]) - key - 32 + 95) % 95) + 32);
            }
            
            return decrypted;
        }
    }

    std::string vigenereAlgo(std::string text, std::string key, bool enc) {
        if (enc) {
            std::string encrypted = text;

            // ENCRYPTION ALGO HERE

            return encrypted;
        }
        else {
            std::string decrypted = text;

            // DECRYPTION ALGO HERE

            return decrypted;
        }
    }

    std::string decryptKeybase(std::string encryptedData) {
        std::string decryptedkey = "";
        int key = (encryptedData[0] - '0') * 10 + (encryptedData[1] - '0');

        // for (int c = 2; c < encryptedData.length(); c++) {
        //     if (char(((int(encryptedData[c]) - key - 32 + 95) % 95) + 32) == ' ');
        //         break;

        //     decryptedkey.insert(decryptedkey.begin(), char(c + '0'));
        // }                FINISH!!!!!!!!!
        
        return decryptedkey;
    }

    // GUIs and rest
    void caesarEnc(int key) {
        std::string command;
        std::string plaintext;

        while (true) {
            std::cout << "------| Caesar Encryption\n------| Enter your plaintext:" << std::endl;
                    
            std::cin.ignore();
            std::getline(std::cin, plaintext);

            endl();
            std::cout << "------| Caesar Encryption\n------| Your encrypted string is:\n------| " << '"' << caesarAlgo(plaintext, key, 1) << '"' << "\n------| (key: " << key << ')' << std::endl;
            endl();
            std::cout << "------| Caesar Encryption\n------| Would you like to encrypt another string?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");

            if (command == "y") {
                endl();
                continue;
            }
            else if (command == "n") {
                return;
            }
        }
    }

    void caesarDec(int key) {
        std::string command;
        std::string text;

        while (true) {
            std::cout << "------| Caesar Decryption\n------| Enter your encrypted string:" << std::endl;
                    
            std::cin.ignore();
            std::getline(std::cin, text);

            endl();
            std::cout << "------| Caesar Decryption\n------| Your decrypted string is:\n------| " << '"' << caesarAlgo(text, key, 0) << '"' << "\n------| (key: " << '"' << key << ')' << std::endl;
            endl();
            std::cout << "------| Caesar Decryption\n------| Would you like to decrypt another string?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");

            if (command == "y") {
                endl();
                continue;
            }
            else if (command == "n") {
                return;
            }
        }
    }

    void vigenereEnc(std::string key) {
        std::string command;
        std::string plaintext;

        while (true) {
            std::cout << "------| Vigenere Encryption\n------| Enter your plaintext:" << std::endl;
                    
            std::cin.ignore();
            std::getline(std::cin, plaintext);

            endl();
            std::cout << "------| Vigenere Encryption\n------| Your encrypted string is:\n------| " << '"' << vigenereAlgo(plaintext, key, 1) << '"' << "\n------| (key: " << key << ')' << std::endl;
            endl();
            std::cout << "------| Vigenere Encryption\n------| Would you like to encrypt another string?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");

            if (command == "y") {
                endl();
                continue;
            }
            else if (command == "n") {
                return;
            }
        }
    }

    void vigenereDec(std::string key) {
        std::string command;
        std::string text;

        while (true) {
            std::cout << "------| Vigenere Decryption\n------| Enter your encrypted string:" << std::endl;
                    
            std::cin.ignore();
            std::getline(std::cin, text);

            endl();
            std::cout << "------| Vigenere Decryption\n------| Your decrypted string is:\n------| " << '"' << vigenereAlgo(text, key, 0) << '"' << "\n------| (key: " << key << ')' << std::endl;
            endl();
            std::cout << "------| Vigenere Decryption\n------| Would you like to decrypt another string?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");

            if (command == "y") {
                endl();
                continue;
            }
            else if (command == "n") {
                return;
            }
        }
    }

    void caesar(bool enc) {
        int key;
        std::string command;

        if (enc) {
            std::cout << "------| Caesar Encryption\n------| Would you like to use your own key?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");
    
            if (command == "y") {
                endl();
                std::cout << "------| Caesar Encryption\n------| Enter your key (1-94):" << std::endl;

                do {
                    std::cin >> key;
                } while (key < 1 || key > 94);

                endl();
                std::cout << "------| Caesar Encryption\n------| Key successfully set!\n------| (" << key << ')' << std::endl;

                endl();
                caesarEnc(key);
            }
            else if (command == "n") {
                endl();
                caesarEnc(otime);
            }
    
            endl();
        }
        else {
            std::cout << "------| Caesar Decryption\n------| Is there a specific key?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");
    
            if (command == "y") {
                endl();
                std::cout << "------| Caesar Decryption\n------| Enter your key (1-94):" << std::endl;

                do {
                    std::cin >> key;
                } while (key < 1 || key > 94);

                endl();
                std::cout << "------| Caesar Decryption\n------| Key successfully set!\n------| (" << key << ')' << std::endl;

                endl();
                caesarDec(key);
            }
            else if (command == "n") {
                endl();
                caesarDec(otime);
            }
    
            endl();
        }
    }

    void vigenere(bool enc) {
        std::string key;
        std::string command;

        if (enc) {
            std::cout << "------| Vigenere Encryption\n------| Would you like to use your own key?\n------| (y | n)" << std::endl;

            do {
                std::cin >> command;
                command = toLower(command);
            } while (command != "y" && command != "n");
    
            if (command == "y") {
                endl();
                std::cout << "------| Vigenere Encryption\n------| What key should the text be encrypted with?\n------| (any word)" << std::endl;

                std::fstream kbase;
                kbase.open("keybase.txt", std::fstream::in | std::fstream::out | std::fstream::app);

                do {
                    std::cin >> key;
                } while (!isStringAlphabetic(key));

                key = toLower(key);

                if (kbase.is_open()) {
                    kbase << (intToString(otime / 10) + intToString(otime % 10) + caesarAlgo(key + " ", otime, 1));
                }
                kbase.close();

                endl();
                std::cout << "------| Vigenere Encryption\n------| Key successfully set!\n------| (" << key << ')' << std::endl;

                endl();
                vigenereEnc(key);
            }
            else if (command == "n") {

                // FINISH!!!!!!!!!!!!!!!!!!!!!!!!!!

                endl();
                vigenereEnc(key);
            }
    
            endl();
        }
        else {
            std::cout << "------| Vigenere Decryption\n------| What key should the text be decrypted with?\n------| (a word)" << std::endl;

            do {
                std::cin >> key;
            } while (!isStringAlphabetic(key));

            key = toLower(key);

            endl();
            std::cout << "------| Vigenere Decryption\n------| Key successfully set!\n------| (" << key << ')' << std::endl;

            endl();
            vigenereDec(key);
    
            endl();
        }
    }

    void encrypt() {
        std::string command;
        std::cout << "----| Encryption\n----| Choose the mode:\n----| Caesar | Vigenere | Exit\n----| (c | v | ex)" << std::endl;

        do {
            std::cin >> command;
            command = toLower(command);
        } while (command != "ex" && command != "c" && command != "v");

        if (command == "ex")
            return;
        else if (command == "c") {
            endl();
            caesar(1);
        }
        else if (command == "v") {
            endl();
            vigenere(1);
        }

        endl();
    }

    void decrypt() {
        std::string command;
        std::cout << "----| Decryption\n----| Choose the mode:\n----| Caesar | Vigenere | Exit\n----| (c | v | ex)" << std::endl;

        do {
            std::cin >> command;
            command = toLower(command);
        } while (command != "ex" && command != "c" && command != "v");

        if (command == "ex")
            return;
        else if (command == "c") {
            endl();
            caesar(0);
        }
        else if (command == "v") {
            endl();
            vigenere(0);
        }

        endl();
    }
}

    

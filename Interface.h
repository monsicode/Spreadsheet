#pragma once

#include "Commands.h"

class Interface : public Commands {
public:

    Interface(const MyString &fileName) : Commands(fileName) {}

    void showCommands() {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Command options:\n";
        std::cout << "'print' - will print your current table\n";
        std::cout << "'edit' - to edit you enter the new value of a cell and her coordinates\n";
        std::cout << "'save' - will save all your changes into a new file\n";
        std::cout << "'exit' - this command will close your table and finish the program\n";
        std::cout << std::endl;
        std::cout << std::endl;

    }

    void interface() {
        showCommands();
        std::cout << '\n';
        std::cout << "Enter command\n";
        std::cout << "> ";
        MyString command;
        std::cin >> command;

        while (command != "exit") {
            if (command == "print") {
                print();
            } else if (command == "edit") {
                edit();
            } else if (command == "saveAs") {
                saveAs();
            } else if (command == "save") {
                save();
            }

            std::cout << "Enter command:\n";
            std::cout << "> ";
            std::cin >> command;
        }

    }
};



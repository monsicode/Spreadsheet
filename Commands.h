#pragma once

#include "MyString.h"
#include "DataCellFactory.h"
#include "Table.h"


class Commands {
    Table table;
    MyString fileName;
public:

    Commands(const MyString &fileName) : table(fileName) {
        this->fileName = fileName;
    }

    void saveAs() {
        std::cout << "Enter new name\n";
        std::cout << ">";
        MyString newFileName;
        std::cin >> newFileName;
        table.saveRowsInTable(newFileName);
    }

    void edit() {
        std::cout << "Enter new data for the cell\n";
        std::cout << ">";
        MyString newData, cell;
        std::cin.ignore();
        getLine(std::cin, newData, 1024, '\n');

        std::cout << std::endl;

        std::cout << "Enter coordinates\n";
        std::cout << ">";
        std::cin >> cell;
        table.edit(newData, cell);
    }

    void print() const {
        table.printTable();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void save()
    {
       table.saveRowsInTable(fileName);
        std::cout << "Table saved successfully!";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void exit(){
        //save();
        return;
    }


};



#include <iostream>
//#include "MyString.h"
//#include "Vector.hpp"
//#include "DataCell.h"
//#include "DataCellFactory.h"
//#include "SharedPtr.hpp"
//#include "Numbers.hpp"
//#include "Table.h"
//#include "Commands.h"
#include "Interface.h"

int main()

try {
    std::cout << "Enter file name\n";
    std::cout << ">";
    MyString fileName;
    std::cin >> fileName;
    Interface it(fileName);
    it.interface();
}catch(std::out_of_range r) {
    std::cout << r.what() << '\n';
}catch(std::logic_error le) {
    std::cout << le.what() << '\n';
}



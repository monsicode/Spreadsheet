#pragma once
#include<fstream>
#include<sstream>
#include<iostream>
#include "DataCell.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "DataCellFactory.h"


class Row
{
    Vector<SharedPtr<DataCell>> row;
    int countCell = 0;

public:

    Row() = default;

    int getCountCell() const;

    void read(const MyString& line);
    void saveRow(std::ofstream& file) const;

    const SharedPtr<DataCell>& operator[](int col) const;
    SharedPtr<DataCell>& operator[](int col);

};


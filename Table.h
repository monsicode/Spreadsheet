#pragma once

#include "Row.h"
#include "MyString.h"


class Table {
    Vector<Row> table;
    int maxCell = 0;

    void putRowsInTable(const MyString &fileName);

    int extractRow(std::stringstream &ss) const;

    int extractCol(std::stringstream &ss) const;

    bool isOperator(char op);

    MyString doubleToString(double num);

    MyString transformCoordinatesIntoVal(const MyString &data, const Table &table);

public:
    Table() {}

    Table(const MyString &fileName);

    void saveRowsInTable(const MyString &fileName) const;

    void edit(const MyString &newData, const MyString &coord);

    void printTable() const;

    const SharedPtr<DataCell> &getData(const MyString &cor) const;

    bool checkCoordinates(const MyString &coordinates) const;

};


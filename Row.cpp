#include "Row.h"

int Row::getCountCell() const {
    return countCell;
}

void Row::read(const MyString &line) {
    std::stringstream s(line.c_str());
    MyString cellValue;

    while (!s.eof()) {
        getLine(s, cellValue, 1024, ',');
        if (cellValue == " " || cellValue == "") {
            SharedPtr<DataCell> loadedObj = DataCellFactory::creat(" ");
            row.pushBack(loadedObj);
        }
        else {
            std::stringstream ss(cellValue.c_str());
            ss >> cellValue;
            SharedPtr<DataCell> loadedObj = DataCellFactory::creat(cellValue);
            row.pushBack(loadedObj);
        }
        countCell++;
    }

    s.clear();
}

void Row::saveRow(std::ofstream &file) const {
    size_t sizeRow = row.getSize();

    row[0]->saveIn(file);

    for (int i = 1; i < sizeRow; i++)
    {
        file << ",";

        row[i]->saveIn(file);
    }
}

const SharedPtr<DataCell> &Row::operator[](int col) const {
    return row[col];
}

SharedPtr<DataCell> &Row::operator[](int col) {
    return row[col];
}

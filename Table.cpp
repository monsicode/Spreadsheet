#include "Table.h"

void Table::putRowsInTable(const MyString &fileName) {
    std::ifstream file(fileName.c_str(), std::ios::app);

    if (!file.is_open()) {
        std::cout << "Could not open the output file" << std::endl;
        return;
    }


    while (!file.eof()) {
        MyString line;
        getLine(file, line, 1024, '\n');

        Row r;
        r.read(line);
        table.pushBack(r);

        int countCurCell = r.getCountCell();

        if (maxCell < countCurCell) {
            maxCell = countCurCell;
        }
    }

    std::cout << "Table loaded successfully!\n";
    file.close();
}

int Table::extractRow(std::stringstream &ss) const {
    char a;
    ss >> a;
    if (a != 'R') {
        throw std::invalid_argument("The coordinate is not valid!");
    }

    int row;
    ss >> row;
    if (row < 0 || row > table.getSize()) {
        throw std::out_of_range("Too big number");
    }

    return row;
}

int Table::extractCol(std::stringstream &ss) const {
    char a;
    ss >> a;
    if (a != 'C') {
        throw std::invalid_argument("The coordinate is not valid!");
    }
    int col;
    ss >> col;
    if (col < 0 || col > maxCell) {
        throw std::out_of_range("Too big number");
    }
    return col;
}

bool Table::isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

MyString Table::doubleToString(double num) {
    std::stringstream ss;
    ss << num;
    char buff[1024]{'\0'};
    ss >> buff;

    MyString res(buff);

    return res;
}

MyString Table::transformCoordinatesIntoVal(const MyString &data, const Table &table) {
    MyString formula(data);

    std::stringstream s(formula.c_str());

    MyString expression;

    while (!s.eof()) {
        MyString word;
        getLine(s, word, 1024, ' ');

        if (isOperator(word[0])) {
            expression += (word + " ");
        } else if (word == "=") {
            expression += "= ";
        } else {
            MyString token = doubleToString(table.getData(word)->valueForFormula());
            expression += (token + " ");
        }
    }
    return expression;
}

Table::Table(const MyString &fileName) {
    putRowsInTable(fileName);
}

void Table::saveRowsInTable(const MyString &fileName) const {
    std::ofstream file(fileName.c_str(), std::ios::out);

    if (!file.is_open()) {
        std::cout << "Could not open the output file" << std::endl;
        return;
    }

    for (int i = 0; i < table.getSize() - 1; i++) {
        table[i].saveRow(file);
        file << '\n';
    }

    table[table.getSize() - 1].saveRow(file);

    file.close();
}

void Table::edit(const MyString &newData, const MyString &coord) {
    std::stringstream ss(coord.c_str());
    int row = extractRow(ss);
    int col = extractCol(ss);

    table[row - 1][col - 1].~SharedPtr<DataCell>();
    table[row - 1][col - 1] = nullptr;

    if (newData[0] == '=') {
        MyString formula = transformCoordinatesIntoVal(newData, *this);
        table[row - 1][col - 1] = DataCellFactory::creat(formula);
    } else
        table[row - 1][col - 1] = DataCellFactory::creat(newData);
}

void Table::printTable() const {

    for (int i = 0; i < table.getSize() ; i++) {
        for (int j = 0; j < table[i].getCountCell(); j++)
            table[i][j]->print();

        std::cout << std::endl;
    }
}

const SharedPtr<DataCell> &Table::getData(const MyString &cor) const {
    std::stringstream ss(cor.c_str());
    int row = extractRow(ss);
    int col = extractCol(ss);

    return table[row - 1][col - 1];
}

#include "Text.h"

Text::Text(const MyString &data) {
    this->data = data;
}

void Text::saveIn(std::ostream &file) const {
    file << data;
}

Text::Text(const Text &other) {
    data = other.data;
}

//int Text::toInt() const {
//    return data.stringToInt();
//}

void Text::print() const {
    MyString text(data.substr(1, data.length() - 2));
    std::cout << text << " | ";
}

double Text::valueForFormula() const {
    MyString text(data.substr(1, data.length() - 2));
    return text.stringToDouble();
}

std::ostream &operator<<(std::ostream &os, const Text &txt) {
    return os << txt;
}


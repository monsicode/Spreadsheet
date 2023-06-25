#include "MyString.h"
#include <fstream>

MyString::MyString(size_t capacity) {
    _length = capacity - 1;
    _data = new char[capacity];
}

bool MyString::isDigit(char ch) const {
    return (ch >= '0' && ch <= '9');
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    MyString result(lhs._length + rhs._length + 1);

    result[0] = '\0';
    strcat(result._data, lhs._data);
    strcat(result._data, rhs._data);

    return result;
}

MyString &MyString::operator+=(const MyString &other) {
    char *result = new char[(_length += other._length) + 1];
    result[0] = '\0';
    strcpy(result, _data);
    strcat(result, other._data);

    free();
    _data = result;
    return *this;
}

MyString::MyString() : MyString(1) {
    _data[0] = '\0';
}

//MyString::MyString(const char* data) : MyString(strlen(data) + 1)
//{
//	strcpy(_data, data);
//}

MyString::MyString(const MyString &other) {
    copyFrom(other);
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}


void MyString::free() {
    if (_data) {
        delete[] _data;
        _data = nullptr;
    }
}

//MyString::~MyString()
//{
//	free();
//}

size_t MyString::length() const {
    return _length;
}

void MyString::copyFrom(const MyString &other) {
    _length = other._length;
    _data = new char[_length + 1];
    strcpy(_data, other._data);
}

void MyString::move(MyString &&other) {
    _data = other._data;
    other._data = nullptr;
    _length = other._length;
}

MyString::MyString(MyString &&other) noexcept {
    move(std::move(other));
}

MyString &MyString::operator=(MyString &&other) noexcept {
    if (this != &other) {
        free();
        move(std::move(other));
    }
    return *this;
}

char &MyString::operator[](size_t index) {
    return _data[index];
}

char MyString::operator[](size_t index) const {
    return _data[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const {
    if (begin + howMany > _length)
        throw std::length_error("Error, Substr out of range");


    MyString res(howMany + 1);
    for (int i = 0; i < howMany; i++)
        res._data[i] = _data[begin + i];
    res[howMany] = '\0';
    return res;
}

const char *MyString::c_str() const {
    return _data;
}


bool MyString::isFunction() const {
    return _data[0] == '=';
}

bool MyString::isInteger() const {
    if (_data == nullptr)
        return false;

    for (size_t i = 0; i < _length ; i++) {
        if (!isDigit(_data[i]))
            return false;
    }

    return true;
}

bool MyString::isDouble() const {
    if (_data == nullptr)
        return false;

    bool hasDecimalPoint = false;
    bool hasDigitBefore = false;
    bool hasDigitAfter = false;

    for (size_t i = 0; i < _length; i++) {
        if (isDigit(_data[i])) {
            if (!hasDecimalPoint) {
                hasDigitBefore = true;
            } else {
                hasDigitAfter = true;
            }
        } else if (_data[i] == '.') {
            if (hasDecimalPoint) {
                return false;
            }
            hasDecimalPoint = true;
        } else if (_data[i] != '+' && _data[i] != '-') {
            return false;
        }
    }

    return hasDigitBefore && hasDigitAfter;
}

int MyString::stringToInt() const {
    if (isInteger()) {
        std::stringstream s(_data);
        int number = 0;
        s >> number;
        return number;
    }
    return 0;
}

double MyString::stringToDouble() const {
    if (isDouble() || isInteger()) {
        std::stringstream s(_data);
        double number = 0;
        int num2 = 0;
        s >> number;
        s>>num2;
        number+=num2;
        return number;
    }
    return 0;
}


std::ifstream &getLine(std::ifstream &s, MyString &str, int size, char separator) {
    char buff[1024];
    s.getline(buff, 1024, separator);
    // s >> buff;
    str = MyString(buff);
    return s;
}

std::stringstream &getLine(std::stringstream &s, MyString &str, int size, char separator) {
    char buff[1024];
    s.getline(buff, 1024, separator);

//    delete[] str._data;
//    str._length = strlen(buff);
//    str._data = new char[str._length + 1];
//    strcpy(str._data, buff);

    str = MyString(buff);
    return s;
}


std::ostream &operator<<(std::ostream &os, const MyString &str) {
    return os << str.c_str();
}

std::istream &operator>>(std::istream &is, MyString &str) {
    char buff[1024]{'\0'};
    is >> buff; //
    //is.getline(buff, 1024);

    delete[] str._data;
    str._length = strlen(buff);
    str._data = new char[str._length + 1];
    strcpy(str._data, buff);
    return is;

}

bool operator<(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

std::istream &getLine(std::istream &s, MyString &str, int size, char separator) {
    char buff[1024];
    s.getline(buff, 1024, separator);
    str = MyString(buff);
    return s;;
}


#pragma once

#include <iostream>
#include <sstream>
#include <cstring>

#pragma warning(disable:4996)

class MyString {
    char *_data;
    size_t _length;

    void copyFrom(const MyString &data);

    void move(MyString &&other);

    void free();

    explicit MyString(size_t capacity);


public:

    MyString();

    MyString(const char *data) : MyString(strlen(data) + 1) {
        strcpy(_data, data);
    }

    MyString(const MyString &other);

    MyString &operator=(const MyString &other);

    ~MyString() {
        free();
    }

    MyString(MyString &&other) noexcept;

    MyString &operator=(MyString &&other) noexcept;

    size_t length() const;

    MyString &operator+=(const MyString &other);

//operator+= for char
    MyString &operator+=(char ch) {
        char *result = new char[(_length + 1) + 1];

        strcpy(result, _data);
        result[_length] = ch;
        result[_length + 1] = '\0';

        delete[] _data;
        _data = result;
        result = nullptr;
        return *this;
    }


    MyString substr(size_t begin, size_t howMany) const;

    char &operator[](size_t index);

    char operator[](size_t index) const;

    const char *c_str() const;

    char *c_str() {
        return _data;
    }

    bool isDigit(char ch) const;

    bool isEmpty() const {
        return _length == 0;
    }

    bool isFunction() const;

    bool isInteger() const;

    bool isDouble() const;

    int stringToInt() const;

    double stringToDouble() const;

    friend std::ifstream &getLine(std::ifstream &s, MyString &str, int size, char separator);

    friend std::stringstream &getLine(std::stringstream &s, MyString &str, int size, char separator);

    friend MyString operator+(const MyString &lhs, const MyString &rhs);

    friend std::istream &operator>>(std::istream &, MyString &str);
};

std::ostream &operator<<(std::ostream &os, const MyString &str);

std::ifstream &getLine(std::ifstream &s,  MyString &str, int size, char separator);

std::stringstream &getLine(std::stringstream &s,  MyString &str, int size, char separator);

std::istream &getLine(std::istream &s,  MyString &str, int size, char separator);

bool operator<(const MyString &lhs, const MyString &rhs);

bool operator<=(const MyString &lhs, const MyString &rhs);

bool operator>=(const MyString &lhs, const MyString &rhs);

bool operator>(const MyString &lhs, const MyString &rhs);

bool operator==(const MyString &lhs, const MyString &rhs);

bool operator!=(const MyString &lhs, const MyString &rhs);



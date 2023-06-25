#pragma once

#include "DataCell.h"
#include "Numbers.hpp"
#include "Function.h"

class DataCellFactory {
public:

    static DataCell *creat(const MyString &value) {
        if (value.isInteger()) {
            return new Numbers<int>(value.stringToInt());
        } else if (value.isDouble()) {
            return new Numbers<double>(value.stringToDouble());
        } else if (value.isFunction()) {
            return new Numbers<double>(value);
        } else
            return new Text(value);
    }
};



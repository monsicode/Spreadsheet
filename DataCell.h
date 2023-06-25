#pragma once

#include "MyString.h"

class DataCell {
public:

    virtual void print() const = 0;

    virtual double valueForFormula() const = 0;

    virtual void saveIn(std::ostream&) const = 0;

    virtual ~DataCell() = default;
};


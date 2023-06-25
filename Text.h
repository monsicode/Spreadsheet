#pragma once

#include "DataCell.h"
#include "MyString.h"

class Text : public DataCell{
protected:

    MyString data;

public:

    Text() {}

    Text(const MyString &data);

    Text(const Text &other);

    //int toInt() const ;

    void print() const override;

    double valueForFormula() const;

    friend std::ostream &operator<<(std::ostream &os, const Text &txt);

    void saveIn(std::ostream& file)const override;
};

std::ostream &operator<<(std::ostream &os, const Text &txt);

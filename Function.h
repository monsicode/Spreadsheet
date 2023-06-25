#pragma once

#include "Text.h"


class Function : public Text {

public:
    Function() {}

    Function(const MyString &data) {
        this->data = data;
    }

    bool chechIfFunction() const {
        return true;
    }

    const MyString &getFunction() const {
        return data;
    }
};


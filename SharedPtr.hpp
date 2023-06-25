#pragma once

#include <iostream>

template<typename T>
class SharedPtr {

    T *data;
    unsigned *countOfPointers;

    void free();

    void copyFrom(const SharedPtr<T> &other);

public:
    SharedPtr();

    SharedPtr(T *data);

    SharedPtr(const SharedPtr<T> &other);

    SharedPtr &operator=(const SharedPtr<T> &other);

    const T &operator*() const;

    T &operator*();

    const T *operator->() const;

    T *operator->();


    friend std::ostream &operator<<(std::ostream &os, const SharedPtr<T> &ptr) {
        if (ptr.data != nullptr)
            os << *ptr;
        else
            os << " ";
        return os;
    }

    ~SharedPtr();

};

template<typename T>
SharedPtr<T>::SharedPtr() {
    data = nullptr;
    countOfPointers = nullptr;
}

template<typename T>
void SharedPtr<T>::free() {
    if (countOfPointers && *countOfPointers == 1) {
        delete data;
        delete countOfPointers;
    } else if (countOfPointers) {
        (*countOfPointers)--;
    }

    data = nullptr;
    countOfPointers = nullptr;
//    if ((*countOfPointers) == 1)
//    {
//        delete data;
//        delete countOfPointers;
//    }
//    else {
//        (*countOfPointers)--;
//    }
}

template<typename T>
void SharedPtr<T>::copyFrom(const SharedPtr<T> &other) {
    data = other.data;
    countOfPointers = other.countOfPointers;
    (*countOfPointers)++;
}

template<typename T>
SharedPtr<T>::SharedPtr(T *data) {
    this->data = data;
    countOfPointers = new unsigned(1);
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other) {
    copyFrom(other);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
const T &SharedPtr<T>::operator*() const {
    return *data;
}

template<typename T>
T &SharedPtr<T>::operator*() {
    return *data;
}

template<typename T>
const T *SharedPtr<T>::operator->() const {
    return data;
}


template<typename T>
T *SharedPtr<T>::operator->() {
    return data;
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    free();
}







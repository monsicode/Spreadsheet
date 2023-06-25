#pragma once
#include <iostream>
#include <exception>

template<typename T>
class Stack {

    T* data;
    size_t capacity;
    size_t size;

    size_t put;

    void copyFrom(const Stack<T>& other) {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        put = other.put;
    }

    void free() {
        delete[] data;
    }

    void move(Stack<T>&& other) {
        size = other.size;
        capacity = other.capacity;

        data = other.data;

        put = other.put;
    }

    void resize() {
        T* newData = new T[capacity * 2];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        free();

        data = newData;
        capacity *= 2;
        newData = nullptr;
        put = size;

    }


public:

    bool isEmpty() const {
        return size == 0;
    }

    Stack() {
        capacity = 4;
        data = new T[capacity];
        size = 0;
        put = 0;
    }

    Stack(const Stack<T>& other) {
        copyFrom(other);
    }

    Stack(Stack<T>&& other) {
        move(std::move(other));
    }

    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    Stack<T>& operator=(Stack<T>&& other) {
        if (this != &other) {
            free();
            move(std::move(other));
        }
        return *this;
    }

    ~Stack() {
        free();
    }

    void push(const T& obj) {
        if (size == capacity)
            resize();

        data[put] = obj;
        (++put) %= capacity;
        size++;
    }


    void push(T&& obj) {
        if (size == capacity)
            resize();

        data[put] = std::move(obj);
        (++put) %= capacity;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            throw "error";
        }

        size--;
        put--;
    }

    const T& peek() const{
        if (isEmpty()) {
            throw "Error";
        }
        return data[size - 1];
    }

};
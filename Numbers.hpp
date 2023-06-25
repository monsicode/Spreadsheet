# pragma once

#include "DataCell.h"
#include "MyString.h"
#include "Stack.hpp"
#include "MyQueue.hpp"
#include <cmath>

template<typename T>
class Numbers : public DataCell {
    T data;

    bool isOperator(char op) {
        return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
    }

    int getPrecedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;

        return 0;
    }

    MyQueue<MyString> shuntingYard(const MyString &expression) {
        Stack<MyString> operatorStack;
        MyQueue<MyString> outputQueue;

        std::stringstream ss(expression.c_str());
        MyString token;
        while (!ss.eof()) {
            getLine(ss, token, 1024, ' ');

            if (isdigit(token[0])) {
                outputQueue.push(token);
            } else if (token[0] == '(') {
                operatorStack.push(token);
            } else if (token[0] == ')') {
                while (!operatorStack.isEmpty() && operatorStack.peek() != "(") {
                    outputQueue.push(operatorStack.peek());
                    operatorStack.pop();
                }

                if (!operatorStack.isEmpty() && operatorStack.peek() == "(") {
                    operatorStack.pop();
                }
            } else if (isOperator(token[0])) {
                while (!operatorStack.isEmpty() && getPrecedence(token[0]) <= getPrecedence(operatorStack.peek()[0])) {
                    outputQueue.push(operatorStack.peek());
                    operatorStack.pop();
                }

                operatorStack.push(token);
            }
        }
        while (!operatorStack.isEmpty()) {
            outputQueue.push(operatorStack.peek());
            operatorStack.pop();
        }

        return outputQueue;
    }

    double evaluateRPN(MyQueue<MyString> rpnExpression) {
        Stack<double> operandStack;

        while (!rpnExpression.isEmpty()) {
            MyString token = rpnExpression.peek();
            rpnExpression.pop();

            if (token.isDouble()) {
                double operand = token.stringToDouble();
                operandStack.push(operand);
            } else if (token.isInteger()) {
                int operand = token.stringToInt();
                operandStack.push(operand);
            } else if (isOperator(token[0])) {
                double operand2 = operandStack.peek();
                operandStack.pop();
                double operand1 = operandStack.peek();
                operandStack.pop();

                double result;

                if (token == "+") {
                    result = operand1 + operand2;

                } else if (token == "-") {
                    result = operand1 - operand2;
                } else if (token == "*") {
                    result = operand1 * operand2;
                } else if (token == "/") {
                    result = operand1 / operand2;
                } else if (token == "^") {
                    result = pow(operand1, operand2);
                } else {
                    throw std::logic_error("Invalid mathematical operation!");
                }

                operandStack.push(result);
            }
        }

        return operandStack.peek();
    }

public:
    Numbers() = default;

    Numbers(const T &num);

    Numbers(const MyString &function) {
       data = evaluateRPN(shuntingYard(function));
    }

    void print() const override;

    double valueForFormula() const override;

    void saveIn(std::ostream &file) const override {
        file << data;
    }

    const T &getData() const;

    friend const Numbers<T> &operator+(const Numbers<T> &obj1, const Numbers<T> &obj2) {
        return obj1.data + obj2.data;
    }

    friend const Numbers<T> &operator-(const Numbers<T> &obj1, const Numbers<T> &obj2) {
        return obj1.data - obj2.data;
    }

    friend const Numbers<T> &operator*(const Numbers<T> &obj1, const Numbers<T> &obj2) {
        return obj1.data * obj2.data;
    }

    friend const Numbers<T> &operator/(const Numbers<T> &obj1, const Numbers<T> &obj2) {
        return obj1.data / obj2.data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Numbers<T> num) {
        return os << num.data;
    }

};

template<typename T>
Numbers<T>::Numbers(const T &num) :data(num) {}

template<typename T>
void Numbers<T>::print() const {
    std::cout << data << " | ";
}

template<typename T>
double Numbers<T>::valueForFormula() const {
    return data;
}

template<typename T>
const T &Numbers<T>::getData() const {
    return data;
}



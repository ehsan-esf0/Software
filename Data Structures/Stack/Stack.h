#include <iostream>
#include "StackException.h"
using namespace std;

template <typename T>
class Stack
{
private:
    int capacity;
    int topIndex;
    T *data;

public:
    Stack(int size = 100)
    {
        capacity = size;
        topIndex = -1;
        data = new T[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    bool isFull()
    {
        return topIndex == capacity - 1;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    void push(const T &value)
    {
        if (isFull())
        {
            throw StackException("Stack is full");
        }
        topIndex++;
        data[topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw StackException("Stack is empty");
        }
        topIndex--;
    }

    T top() const {
        if (isEmpty()) {
            throw StackException("Stack is empty");
        }
        return data[topIndex];
    }

    int size() const
    {
        return topIndex + 1;
    }

    void print() const
    {
        for (int i = topIndex; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

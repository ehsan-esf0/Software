Circular Queue Implementation in C++
This document provides a detailed explanation of a Circular Queue implementation in C++ using a template-based class. The code supports key queue operations, manages memory efficiently, and aligns with the concepts presented in the "2-Queue.pdf" document.
Overview
The Queue class implements a circular queue using a dynamically allocated array. It supports generic types via templates (T), handles memory management with deep copying, and throws exceptions for error conditions like full or empty queues.

Class Definition
#include "QueueException.h"

template <typename T>
class Queue {
private:
    T *a;                // Dynamic array to store elements
    int front;           // Index of the first element
    int rear;            // Index of the last element
    int size;            // Current number of elements
    unsigned int capacity; // Total capacity of the array

public:
    // Constructors, destructor, and member functions
};

Explanation

Purpose: Defines a template class Queue for a circular queue with a generic type T.
Private Members:
a: A pointer to a dynamically allocated array storing queue elements.
front: Points to the first element (or one position before it when empty).
rear: Points to the last element.
size: Tracks the current number of elements.
capacity: Defines the maximum number of elements the queue can hold.


Dependency: Requires QueueException.h for exception handling.


Constructor
Queue(int c) {
    capacity = c;
    a = new T[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

Explanation

Purpose: Initializes a queue with a given capacity c.
Actions:
Allocates a dynamic array of size capacity.
Sets front to 0 (start of the queue).
Sets rear to -1 (no elements yet).
Initializes size to 0 (empty queue).


Usage: Creates an empty queue ready to store up to c elements.


Copy Constructor
Queue(const Queue &q) {
    capacity = q.capacity;
    a = new T[capacity];
    front = q.front;
    rear = q.rear;
    size = q.size;
    for (int i = 0; i < capacity; i++) {
        a[i] = q.a[i];
    }
}

Explanation

Purpose: Creates a deep copy of an existing queue q.
Actions:
Copies capacity, front, rear, and size from q.
Allocates a new array and copies all elements from q.a to ensure independent memory.


Usage: Ensures safe copying of queues without sharing memory.


Assignment Operator
Queue &operator=(const Queue &q) {
    if (this != &q) {
        delete[] a;
        capacity = q.capacity;
        front = q.front;
        rear = q.rear;
        size = q.size;
        a = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            a[i] = q.a[i];
        }
    }
    return *this;
}

Explanation

Purpose: Assigns one queue's contents to another with deep copying.
Actions:
Checks for self-assignment (this != &q).
Frees the current array to prevent memory leaks.
Copies capacity, front, rear, and size.
Allocates a new array and copies elements from q.a.


Usage: Enables safe assignment like queue1 = queue2.


Destructor
~Queue() {
    delete[] a;
}

Explanation

Purpose: Frees the dynamically allocated array to prevent memory leaks.
Actions: Deallocates the array pointed to by a.
Usage: Automatically called when a Queue object goes out of scope.


Check Full Status
bool isFull() const {
    return capacity == size;
}

Explanation

Purpose: Checks if the queue is full.
Logic: Returns true if size equals capacity, indicating no more elements can be added.
Usage: Used before adding elements to prevent overflow.


Check Empty Status
bool isEmpty() const {
    return size == 0;
}

Explanation

Purpose: Checks if the queue is empty.
Logic: Returns true if size is 0, indicating no elements are present.
Usage: Used before removing or accessing elements to prevent underflow.


Add Element (Push)
void add(T item) {
    if (isFull()) {
        throw QueueException("Queue is full");
    }
    rear = (rear + 1) % capacity;
    a[rear] = item;
    size += 1;
}

Explanation

Purpose: Adds an element to the rear of the queue.
Actions:
Checks if the queue is full; if so, throws a QueueException.
Updates rear using (rear + 1) % capacity to wrap around in a circular manner.
Places item at a[rear] and increments size.


Usage: Implements the push operation described in the PDF (page 7).


Remove Element (Pop)
void remove() {
    if (isEmpty()) {
        throw QueueException("Queue is empty");
    }
    front = (front + 1) % capacity;
    size--;
}

Explanation

Purpose: Removes the front element from the queue.
Actions:
Checks if the queue is empty; if so, throws a QueueException.
Updates front using (front + 1) % capacity to move to the next element.
Decrements size to reflect the removal.


Usage: Implements the pop operation described in the PDF (page 9).


Access Front Element
T frontValue() const {
    if (isEmpty()) {
        throw QueueException("Queue is empty");
    }
    return a[front];
}

Explanation

Purpose: Returns the value of the front element without removing it.
Actions:
Checks if the queue is empty; if so, throws a QueueException.
Returns the element at a[front].


Usage: Implements the front operation described in the PDF (page 4).


Get Size
int getSize() const {
    return size;
}

Explanation

Purpose: Returns the current number of elements in the queue.
Usage: Useful for checking the queue's occupancy, as described in the PDF (page 4).


Get Capacity
int getCapacity() const {
    return capacity;
}

Explanation

Purpose: Returns the maximum number of elements the queue can hold.
Usage: Provides information about the queue's fixed capacity.


Clear Queue
void clear() {
    front = 0;
    rear = -1;
    size = 0;
}

Explanation

Purpose: Resets the queue to an empty state.
Actions: Sets front to 0, rear to -1, and size to 0 without deallocating the array.
Usage: Implements the "Empty That Queue" concept from the PDF (page 10).


Print Queue
void print() const {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < size; ++i) {
        int index = (front + i) % capacity;
        cout << a[index] << ' ';
    }
    cout << '\n';
}

Explanation

Purpose: Prints all elements in the queue from front to rear.
Actions:
If the queue is empty, prints "Queue is empty".
Otherwise, iterates from front to rear using (front + i) % capacity to access elements in order.


Usage: Useful for debugging or displaying the queue's contents.


Equality Operator
bool operator==(const Queue &other) const {
    if (size != other.size || capacity != other.capacity)
        return false;
    for (int i = 0; i < size; ++i) {
        int index1 = (front + i) % capacity;
        int index2 = (other.front + i) % other.capacity;
        if (a[index1] != other.a[index2])
            return false;
    }
    return true;
}

Explanation

Purpose: Checks if two queues are equal.
Logic:
Returns false if size or capacity differ.
Compares elements from front to rear in both queues using circular indexing.
Returns true only if all elements match.


Usage: Allows comparison of queue contents.


Inequality Operator
bool operator!=(const Queue &other) const {
    return !(*this == other);
}

Explanation

Purpose: Checks if two queues are not equal.
Logic: Returns the opposite of the == operator.
Usage: Complements the equality operator for comparisons.


Alignment with "2-Queue.pdf"
This implementation aligns with the concepts in the provided PDF:

Circular Array Queue: Uses front and rear with modulo arithmetic (pages 3, 6, 8).
Queue ADT: Supports empty, size, front, push, and pop operations (page 4).
Push/Pop Mechanics: Matches the described rear and front updates (pages 7, 9).
Size-Based Management: Uses size to track occupancy, as suggested in the PDF's third strategy (page 12).


Potential Improvements

Dynamic Resizing: Add a method to increase capacity when the queue is full, as suggested in the PDF's first strategy (page 12).
Custom Exception Handling: Ensure QueueException.h is well-defined or provide a fallback mechanism.
Print Flexibility: Modify print to support types without << operator or allow custom formatting.


Conclusion
This Queue class provides a robust and efficient implementation of a circular queue in C++. It handles memory safely, supports generic types, and includes all standard queue operations with proper error handling. The code is well-suited for educational purposes or practical applications requiring a fixed-size queue.

# 📘 Copy Constructor in C++

## 🔹 What is a Copy Constructor?

A **Copy Constructor** in C++ is a special constructor that creates a new object as a copy of an existing object.

### 📌 Syntax
```cpp
ClassName(const ClassName& other);
```

---

## 🔹 When is the Copy Constructor Called?

The copy constructor is invoked when:

1. A new object is initialized from an existing object:
    ```cpp
    MyClass obj2 = obj1;
    ```

2. An object is passed by value to a function:
    ```cpp
    void func(MyClass obj);
    ```

3. An object is returned by value from a function:
    ```cpp
    MyClass createObject() {
        MyClass temp;
        return temp;
    }
    ```

---

## 🔹 Example

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;

    // Constructor
    Person(string n) : name(n) {}

    // Copy Constructor
    Person(const Person& other) {
        cout << "Copy Constructor Called!" << endl;
        name = other.name;
    }
};

int main() {
    Person p1("Ali");
    Person p2 = p1; // Copy constructor is called
    cout << p2.name << endl;
}
```

---

## 🔹 Default Copy Constructor

If you don’t define a copy constructor, C++ automatically provides one that performs a **shallow copy**.

---

## 🔹 Shallow Copy vs Deep Copy

| Feature         | Shallow Copy                  | Deep Copy                        |
|-----------------|-------------------------------|----------------------------------|
| Memory Handling | Copies only pointers           | Duplicates actual memory content |
| Safety          | Risk of double-delete issues   | Safer with dynamic memory        |

---

## 🔹 Deep Copy Example

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) {
        data = new int(val);
    }

    // Deep Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*(other.data));
    }

    ~MyClass() {
        delete data;
    }
};
```

---

## ✅ Best Practices

- Define your own copy constructor if your class handles dynamic memory (e.g., using `new`).
- Use `const ClassName&` as the parameter to avoid infinite recursion.

---

## 🔚 Summary

- Copy constructors are crucial for safe copying of objects.
- Default copy constructors perform shallow copy.
- Define your own for deep copy when using pointers or dynamic resources.

# 🏗️ Abstract Classes in C++

---

## What is an Abstract Class?

- A class that **cannot be instantiated**.
- Contains at least one **pure virtual function**.
- Can have implemented member functions.
- Acts as a base class for inheritance and polymorphism.

---

## Why Use Abstract Classes?

- To provide a **base implementation** for derived classes.
- To define a **common interface** and share code.
- To enforce derived classes to implement certain methods.

---

## Example

```cpp
class Animal {
public:
    virtual void speak() = 0;  // Pure virtual function

    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof!" << std::endl;
    }
};
```

---

## Features of Abstract Classes

- Can have data members.
- Can have constructors and destructors.
- Can implement some functions.
- Cannot create objects directly.

---

## Summary Table

| Feature               | Description                      |
|-----------------------|--------------------------------|
| Abstract               | Cannot instantiate             |
| Pure virtual functions | At least one required          |
| Can implement methods  | Yes                            |
| Can have data members  | Yes                            |

---

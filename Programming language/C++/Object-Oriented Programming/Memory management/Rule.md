# Rule of Three / Five / Zero in C++

---

## Introduction

In C++, when a class manages resources such as dynamic memory, file handles, or network connections, **special member functions** are needed to properly handle copying, moving, and destruction to avoid resource leaks or double-free errors.

---

## Rule of Three

If your class requires **any one** of these:

- Destructor (`~ClassName()`)
- Copy Constructor (`ClassName(const ClassName&)`)
- Copy Assignment Operator (`ClassName& operator=(const ClassName&)`)

Then you **usually need to explicitly define all three**.

### Why?

Because the compiler-generated versions might do **shallow copies**, leading to resource management bugs.

---

## Rule of Five (C++11 and later)

With move semantics introduced in C++11, two more special member functions were added:

- Move Constructor (`ClassName(ClassName&&)`)
- Move Assignment Operator (`ClassName& operator=(ClassName&&)`)

**Rule of Five** says:  
If you define **any one** of the five special member functions, you should probably define **all five**.

---

## Rule of Zero

An alternative approach to avoid defining these special members:

- Use **RAII (Resource Acquisition Is Initialization)** types (e.g., smart pointers like `std::unique_ptr`, `std::shared_ptr`)
- Let **compiler generate** default versions
- Write **no destructor, no copy/move constructors or assignment operators**

This simplifies resource management and avoids bugs.

---

## Summary Table

| Rule            | Members to Define                                  | When to Use                      |
|-----------------|--------------------------------------------------|---------------------------------|
| Rule of Three   | Destructor, Copy Constructor, Copy Assignment    | Managing resources without move semantics (pre-C++11) |
| Rule of Five    | Above + Move Constructor, Move Assignment        | Managing resources with move semantics (C++11 and later) |
| Rule of Zero    | None (use smart pointers & RAII)                  | Preferred modern C++ style      |

---

## Example: Rule of Three

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) { data = new int(val); }
    
    // Destructor
    ~MyClass() { delete data; }
    
    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
    }
    
    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
````

---

## Example: Rule of Five

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) { data = new int(val); }

    // Destructor
    ~MyClass() { delete data; }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
    }

    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // Move Assignment
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
```

---

## Example: Rule of Zero

```cpp
#include <memory>

class MyClass {
    std::unique_ptr<int> data;
public:
    MyClass(int val) : data(std::make_unique<int>(val)) {}
    // No destructor, copy/move needed — default generated versions are fine
};
```
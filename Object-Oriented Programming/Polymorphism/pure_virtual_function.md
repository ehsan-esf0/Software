# ⚡ Pure Virtual Functions in C++

---

## What is a Pure Virtual Function?

- A **pure virtual function** is a virtual function that has no implementation in the base class.
- Declared by assigning `= 0` in its declaration.
- Forces derived classes to provide their own implementation.
- Syntax:

```cpp
virtual void func() = 0;
```

---

## Abstract Class

- Any class with at least one pure virtual function becomes an **abstract class**.
- Abstract classes **cannot be instantiated**.
- They define an interface or contract for derived classes.

---

## Why Use Pure Virtual Functions?

- To create **interfaces** (contracts).
- To ensure derived classes implement certain functions.
- To enable polymorphic behavior with mandatory overrides.

---

## Example

```cpp
class Base {
public:
    virtual void doSomething() = 0;  // Pure virtual function
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void doSomething() override {
        std::cout << "Doing something!" << std::endl;
    }
};
```

---

## Can Pure Virtual Functions Have a Body?

- Yes, they can have a body.
- But the class remains abstract.
- Useful to provide common functionality callable from derived classes.

```cpp
class Base {
public:
    virtual void func() = 0;
};

void Base::func() {
    std::cout << "Common behavior" << std::endl;
}
```

---

## Summary

| Feature                   | Description                      |
|---------------------------|--------------------------------|
| Syntax                    | `virtual void func() = 0;`     |
| Class becomes abstract    | Yes, cannot instantiate         |
| Derived classes must override | Yes                        |
| Can have a body           | Yes, optional                  |

---

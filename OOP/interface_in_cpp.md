# 📋 Interface in C++

---

## What is an Interface?

- A **pure abstract class** with **only pure virtual functions**.
- Defines a **contract** for derived classes.
- Does **not provide any implementation**.
- Does **not contain data members**.

---

## How to Define an Interface?

- Declare a class with all methods as pure virtual.
- Provide a **virtual destructor**.

```cpp
class IShape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~IShape() {}
};
```

---

## Why Use Interfaces?

- To define **behavior contracts**.
- To enable **loose coupling** and **flexible designs**.
- To support **multiple inheritance** for behavior.

---

## Example Usage

```cpp
class Circle : public IShape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
    double area() override {
        return 3.14 * radius * radius;
    }
private:
    double radius = 5.0;
};
```

---

## Summary

| Feature                   | Description                      |
|---------------------------|--------------------------------|
| Contains only pure virtual | Yes                           |
| Contains data members     | No                             |
| Provides implementations  | No                             |
| Defines contract          | Yes                            |
| Enables multiple inheritance | Yes                         |

---

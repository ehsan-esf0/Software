# 📘 Initializer List in C++

## 📌 What is an Initializer List?
An initializer list is a special C++ syntax used in constructors to initialize class members **before** the constructor body runs.

It's especially useful (and sometimes necessary) for:
- `const` members
- references
- class types without default constructors

---

## 🎯 Syntax
```cpp
ClassName(parameter1, parameter2)
    : member1(value1), member2(value2) {
    // Constructor body
}
```

---

## 🛠 Why Use Initializer Lists?

### 1. Const Members
Const members must be initialized at the time of construction.
```cpp
class Test {
    const int id;
public:
    Test(int x) : id(x) {}  // Must use initializer list
};
```

### 2. References
References must be bound to a value at initialization.
```cpp
class Test {
    int& ref;
public:
    Test(int& r) : ref(r) {}
};
```

### 3. Objects Without Default Constructor
```cpp
class Engine {
    int power;
public:
    Engine(int p) : power(p) {}
};

class Car {
    Engine engine;
public:
    Car(int power) : engine(power) {}  // Required
};
```

### 4. Performance
Avoids creating an object with the default constructor and then assigning to it.

---

## ⚠️ Initialization Order Matters
Members are always initialized **in the order of their declaration**, not the order in the initializer list!

```cpp
class Demo {
    int x;
    int y;
public:
    Demo() : y(2), x(1) {}  // x is initialized first, even though y is listed first!
};
```

---

## 💡 Best Practices
- Always use initializer lists for `const`, references, and complex types.
- Use them for better performance and clarity.
- Avoid side effects in initializer expressions.

---

## 🧩 Final Example
```cpp
class Battery {
    int charge;
public:
    Battery(int c) : charge(c) {}
};

class Phone {
    Battery battery;
    const std::string model;
public:
    Phone(int charge, std::string m)
        : battery(charge), model(m) {}

    void info() {
        std::cout << "Model: " << model << std::endl;
    }
};
```

---

## 📝 Summary
- Initializer lists are critical for initializing members correctly and efficiently.
- Always prefer them over assignment in the constructor body when possible.
- Understand the order of declaration vs initialization to avoid subtle bugs.

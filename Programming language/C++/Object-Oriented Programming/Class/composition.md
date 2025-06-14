# 📘 Composition in C++

## 📌 What is Composition?
Composition is an Object-Oriented Programming (OOP) concept where one class contains objects of other classes as its members. It's often described as a **"has-a"** relationship.

In contrast to inheritance ("is-a" relationship), composition models the idea that a class can **use** the functionality of another class by containing it as a member.

---

## ✅ Why Use Composition?
- **Reusability**: Use existing classes as building blocks.
- **Flexibility**: You can change composed parts without changing the outer class.
- **Encapsulation**: Each class is responsible for its own data and behavior.
- **Better abstraction**: Represents natural relationships like a Car "has an" Engine.

---

## 🧩 Simple Example:
```cpp
class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine; // Car has-an Engine
public:
    void startCar() {
        engine.start();  // Reusing Engine functionality
        std::cout << "Car is ready to go!\n";
    }
};
```

---

## 🔧 Types of Composition

### 1. Value-Based Composition
Object is declared as a value type (not pointer):
```cpp
class Wheel {};

class Bike {
    Wheel wheel; // Automatically constructed/destructed
};
```

### 2. Pointer-Based Composition
Object is managed manually using raw or smart pointers:
```cpp
class Bike {
    Wheel* wheel;
public:
    Bike() { wheel = new Wheel(); }
    ~Bike() { delete wheel; }
};
```

🧠 Use smart pointers (e.g., `std::unique_ptr`) in modern C++ to manage memory safely.

---

## 🚀 Real-Life Example: Student and Address
```cpp
class Address {
    std::string city;
public:
    Address(std::string c) : city(c) {}
    void print() const { std::cout << city << std::endl; }
};

class Student {
    std::string name;
    Address address; // Student has-an Address
public:
    Student(std::string n, Address a) : name(n), address(a) {}
    void printInfo() {
        std::cout << name << " lives in ";
        address.print();
    }
};
```

---

## 📊 Composition vs Inheritance

| Feature         | Composition (has-a) | Inheritance (is-a) |
|-----------------|---------------------|---------------------|
| Relationship    | has-a               | is-a                |
| Coupling        | Loose               | Tight               |
| Change impact   | Isolated            | Cascading           |
| Reusability     | High                | Medium              |
| Flexibility     | More                | Less                |

---

## 📝 Summary
- Composition allows building complex types by combining simpler ones.
- Prefer composition over inheritance when possible.
- Use value types unless dynamic allocation is required.

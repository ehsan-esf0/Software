# 📘 Delegation in C++

## 1. 🧠 Introduction: What is delegation?

**Delegation** in programming means **assigning a task to another function or object**. Instead of doing everything by itself, an object or function passes part of the work to another.

---

## 2. 🧱 Delegating Constructors (from C++11)

### 🔹 Definition:

In C++11 and later, one constructor can delegate the task of object initialization to another constructor within the same class.

### 🔹 Simple example:

```cpp
class Point {
    int x, y;
public:
    Point() : Point(0, 0) {
        std::cout << "Default constructor\n";
    }

    Point(int x) : Point(x, 0) {
        std::cout << "Single parameter constructor\n";
    }

    Point(int x, int y) : x(x), y(y) {
        std::cout << "Two parameter constructor\n";
    }
};
````

### ✅ Advantages:

* Reduces code duplication
* Improves readability

### ⚠️ Rules:

* Delegation can only happen to other constructors in the same class.
* Delegation must not be circular (A delegates to B and B delegates back to A).

---

## 3. 🔁 Delegation in Member Functions

Here, one member function delegates part of its task to another member function.

### 🔹 Example:

```cpp
class Printer {
public:
    void print() {
        printMessage("Hello");
    }

private:
    void printMessage(const std::string& msg) {
        std::cout << msg << '\n';
    }
};
```

---

## 4. 🏗️ Delegation in Object-Oriented Design (Composition vs Inheritance)

### 🔹 Two main ways to implement delegation:

| Method          | Description                                   |
| --------------- | --------------------------------------------- |
| **Composition** | Using other objects to perform tasks          |
| **Inheritance** | Using base class functions in derived classes |

### 🔹 Composition example:

```cpp
class Logger {
public:
    void log(const std::string& msg) {
        std::cout << "Log: " << msg << '\n';
    }
};

class Application {
    Logger logger;
public:
    void run() {
        logger.log("App started");
    }
};
```

### ✅ Benefits of composition:

* **Reduces dependency on inheritance hierarchies**
* **More flexibility**

---

## 5. 🧩 Design Patterns related to Delegation

Some design patterns rely heavily on the concept of delegation:

| Pattern       | Purpose                                                      |
| ------------- | ------------------------------------------------------------ |
| **Proxy**     | Control access or add extra behavior to an object            |
| **Decorator** | Add features to an object without changing its base class    |
| **Strategy**  | Delegate algorithm implementation to interchangeable classes |

### 🔹 Simple Decorator example:

```cpp
class Notifier {
public:
    virtual void notify() {
        std::cout << "Base notification\n";
    }
};

class EmailNotifier : public Notifier {
    Notifier* wrapped;
public:
    EmailNotifier(Notifier* n) : wrapped(n) {}

    void notify() override {
        wrapped->notify(); // delegation
        std::cout << "Email notification\n";
    }
};
```

---

## 6. 📝 Exercises

### Exercise 1:

Design a class named `Config` with 3 constructors that use delegation to avoid code duplication.

### Exercise 2:

Implement the decorator pattern for sending notifications via SMS and Push as well.

---

## 7. 🎯 Final Summary

| Item                       | Description                                            |
| -------------------------- | ------------------------------------------------------ |
| Delegation                 | Assigning work to another function or class            |
| Delegating Constructor     | Delegating one constructor to another                  |
| Member Function Delegation | Dividing tasks inside a class                          |
| Composition Delegation     | Delegating work to member objects                      |
| Design Pattern Delegation  | Implementing advanced concepts like Proxy or Decorator |

# C++ Copy and Move Semantics

---

## 1. Copy Constructor

A **Copy Constructor** creates a new object by copying data from an existing object.

```cpp
class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int val) {
        data = new int(val);
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // Deep copy of data
    }

    ~MyClass() {
        delete data;
    }
};
````

* Copy Constructor creates a **new memory** and copies the content.
* It's **expensive** for large data.

---

## 2. Copy Assignment Operator vs Copy Constructor

| Aspect         | Copy Constructor                | Copy Assignment Operator            |
| -------------- | ------------------------------- | ----------------------------------- |
| When called    | At object initialization        | After object has been initialized   |
| Syntax example | `MyClass b = a;`                | `b = a;`                            |
| Purpose        | Creates a new object by copying | Copies data into an existing object |

---

## 3. Shallow Copy vs Deep Copy

* **Shallow Copy**: copies only pointer values (addresses). Both objects point to the same data (dangerous).
* **Deep Copy**: copies the actual data the pointer refers to (safe but costly).

---

## 4. Move Constructor (C++11 and later)

Instead of copying, **Move Constructor transfers ownership** of resources from a temporary (rvalue) object to a new object.

```cpp
class MyClass {
public:
    int* data;

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;       // Transfer pointer (ownership)
        other.data = nullptr;    // Nullify the old pointer
    }

    ~MyClass() {
        delete data;
    }
};
```

* No new memory allocation.
* Very efficient for temporary objects.
* `other` loses ownership by setting its pointer to `nullptr`.

---

## 5. What is `&&` in C++? (Rvalue Reference)

* `&` is an **lvalue reference**: refers to objects with names.
* `&&` is an **rvalue reference**: refers to temporary unnamed objects.

### Examples:

```cpp
int a = 5;
int& lref = a;       // lvalue reference to a
int&& rref = 10;     // rvalue reference to temporary value 10
```

---

## 6. Why use Rvalue References?

To implement **Move Semantics** and avoid costly deep copies when dealing with temporary objects.

Example:

```cpp
MyClass foo() {
    return MyClass(42);  // Returns a temporary object (rvalue)
}

int main() {
    MyClass obj = foo(); // Calls Move Constructor instead of Copy Constructor
}
```

---

## 7. `std::move`

`std::move` converts an lvalue to an rvalue to enable moving:

```cpp
MyClass a(5);
MyClass b = std::move(a);  // Forces move, transfers ownership
```

---

## 8. What exactly moves in Move Constructor?

* The **content of the pointer** (i.e., the address it points to) is moved.
* The pointer variable itself has its own address, but **we don’t move the pointer’s own address**, only the address it holds.

```cpp
data = other.data;      // Move the address stored in the pointer
other.data = nullptr;   // Remove ownership from other
```

---

## 9. Summary Table

| Concept                 | Description                              | Efficiency             |
| ----------------------- | ---------------------------------------- | ---------------------- |
| Copy Constructor        | Allocates new memory and copies data     | Slow for big data      |
| Move Constructor        | Transfers pointer ownership without copy | Very fast              |
| `&` (Lvalue Reference)  | Reference to named object                | Standard reference     |
| `&&` (Rvalue Reference) | Reference to temporary (unnamed) object  | Enables move semantics |

---

## 10. Full Example Code

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int val) {
        data = new int(val);
        cout << "Constructor\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        cout << "Copy Constructor\n";
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        cout << "Move Constructor\n";
    }

    ~MyClass() {
        delete data;
        cout << "Destructor\n";
    }
};

int main() {
    MyClass a(42);
    MyClass b = std::move(a);  // Move constructor called

    return 0;
}
```
## 🔷 Sample Class: `Person`

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;
    std::string job;

public:
    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
        job = "Unemployed";
        std::cout << "Default constructor called\n";
    }

    // Constructor with two parameters
    Person(std::string n, int a) : name(n), age(a), job("Unemployed") {
        std::cout << "Constructor with name & age called\n";
    }

    // Constructor with three parameters
    Person(std::string n, int a, std::string j) : name(n), age(a), job(j) {
        std::cout << "Constructor with name, age & job called\n";
    }

    void show() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Job: " << job << '\n';
    }
};
```

---

## 🔶 Different Ways to Create Objects

### ✅ 1. Direct Initialization

```cpp
Person p1("Ali", 25);                  // Calls the 2-parameter constructor
Person p2("Sara", 30, "Engineer");     // Calls the 3-parameter constructor
```

---

### ✅ 2. Copy Initialization

```cpp
Person p3 = Person("Reza", 22, "Artist");  // Calls the 3-parameter constructor
```

---

### ✅ 3. Uniform Initialization (C++11 and later)

```cpp
Person p4{"Mina", 28};                    // Calls the 2-parameter constructor
Person p5{"Javad", 35, "Doctor"};         // Calls the 3-parameter constructor
```

---

### ✅ 4. Default Constructor

```cpp
Person p6;  // Calls the default constructor
```

---

### ✅ 5. Creating Objects on Heap with `new`

```cpp
Person* p7 = new Person("Amir", 27, "Pilot");
p7->show();
delete p7;
```

---

### ✅ 6. Using Smart Pointers (C++11+)

```cpp
#include <memory>

auto sp1 = std::make_shared<Person>("Niloofar", 32, "Teacher");
sp1->show();

auto up1 = std::make_unique<Person>("Hassan", 40);
up1->show();
```

---

### ✅ 7. Using `auto`

```cpp
auto p8 = Person("Fatemeh", 29, "Programmer");
p8.show();
```

---

### ✅ 8. Array of Objects

```cpp
Person arr[] = {
    Person("Ali", 20, "Student"),
    Person("Maryam", 26, "Designer")
};

arr[0].show();
arr[1].show();
```

---

### ✅ 9. Creating Object Inside Another Class (Member Initialization)

```cpp
class Department {
    Person manager;
public:
    Department() : manager("Mostafa", 45, "Manager") {
        std::cout << "Department created with manager\n";
    }
};
```
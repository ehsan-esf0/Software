# 🚄 Dynamic Array of Objects 

---

## 🔹 What Is It?

A **dynamic array of objects** means creating an array of class instances at runtime using heap memory.

### 🔧 Syntax:

```cpp
ClassName* arr = new ClassName[n];
```

This creates `n` objects of type `ClassName` using the **default constructor** of the class.

---

## ✅ Example: Simple Class Array

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    Student() { cout << "Constructor called\n"; }
    void sayHi() { cout << "Hi!\n"; }
};

int main() {
    Student* group = new Student[3];  // Dynamically creates 3 Students

    group[0].sayHi();
    group[1].sayHi();

    delete[] group;  // Properly free memory
    return 0;
}
```

### 🧠 Output:

```
Constructor called
Constructor called
Constructor called
Hi!
Hi!
```

---

## ⚠️ Key Rules

### ✅ Always use `delete[]` for arrays:

```cpp
delete[] arr;  // ✔️ Correct
```

Using `delete` instead of `delete[]` will only destroy the first object — causing a memory leak.

---

## ❌ Problem: No Default Constructor?

If your class **doesn’t have a default constructor**, then you **can’t** use `new Class[n]`.

### ❌ Wrong:

```cpp
class Student {
public:
    Student(int id) {}  // No default constructor
};

Student* arr = new Student[3];  // ❌ Compilation Error
```

### ✅ Solution 1: Add a default constructor

```cpp
class Student {
public:
    Student() {}
    Student(int id) {}
};
```

### ✅ Solution 2: Use pointer to pointer

```cpp
Student** arr = new Student*[3];
for (int i = 0; i < 3; ++i)
    arr[i] = new Student(100 + i);

// Cleanup
for (int i = 0; i < 3; ++i)
    delete arr[i];
delete[] arr;
```

---

## 🧠 Modern Alternative: `std::vector<Class>`

```cpp
#include <vector>

std::vector<Student> students(3);
students[0].sayHi();
```

* Automatically calls default constructor
* No need for `delete`
* Safer and cleaner
* Can grow dynamically

---

## 📊 Comparison Table

| Method                      | Pros                    | Cons                             |
| --------------------------- | ----------------------- | -------------------------------- |
| `Class* arr = new Class[n]` | Simple, fast            | Requires default constructor     |
| `Class** arr + new Class()` | Can use any constructor | More complex memory management   |
| `std::vector<Class>`        | Modern, safe, resizable | Slight overhead, requires C++11+ |

---

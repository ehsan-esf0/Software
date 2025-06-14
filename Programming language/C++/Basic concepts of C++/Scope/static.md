# The `static` Keyword in C++

The keyword `static` in C++ has different meanings depending on the context.  
It usually relates to **persistence of value** and **scope control**.

---

## 1. Static Local Variables

- A local variable declared as `static` inside a function is initialized only once.  
- Its value persists across multiple function calls.

```cpp
void foo() {
    static int count = 0; // initialized once
    count++;
    std::cout << "count = " << count << std::endl;
}

int main() {
    foo(); // count = 1
    foo(); // count = 2
    foo(); // count = 3
}
````

---

## 2. Static Variables at File Scope

* A variable declared `static` outside all functions/classes limits its linkage to the current translation unit (file).
* It is **not visible** outside the file.

```cpp
static int x = 5; // visible only in this file

void printX() {
    std::cout << x << std::endl;
}
```

---

## 3. Static Data Members in Classes

* Static member variables belong to the class, **shared by all objects**.
* Only one copy exists, regardless of how many objects are created.

```cpp
class MyClass {
public:
    static int count;
    MyClass() { count++; }
};

int MyClass::count = 0;

int main() {
    MyClass a;
    MyClass b;
    std::cout << MyClass::count << std::endl; // 2
}
```

---

## 4. Static Member Functions

* Belong to the class, **not to any particular object**.
* Can be called without creating an object.
* Can only access static data members or other static member functions.

```cpp
class MyClass {
public:
    static int count;
    static void printCount() {
        std::cout << "Count = " << count << std::endl;
    }
};

int MyClass::count = 0;

int main() {
    MyClass::printCount(); // Count = 0
}
```

---

## 5. Memory Behavior of Static Members and Functions

| Feature                | Storage Location                | Notes                                    |
| ---------------------- | ------------------------------- | ---------------------------------------- |
| Static local variable  | Data segment (persistent)       | Initialized once, value persists         |
| Static global variable | Data segment (internal linkage) | Visible only within one translation unit |
| Static class variable  | Data segment                    | Shared by all objects of the class       |
| Static member function | Code segment                    | One copy, no `this` pointer              |

* Static member functions **do not receive a `this` pointer** because they are not tied to any instance.
* Static data members exist independently of any object lifetime.

---

## Summary Table

| Usage Context          | Meaning                                 |
| ---------------------- | --------------------------------------- |
| Static local variable  | Persistent local variable across calls  |
| Static global variable | File-level variable, internal linkage   |
| Static class member    | Shared variable for all instances       |
| Static member function | Class-level function, no `this` pointer |


# 📘 Complete Guide to `extern`, Global, and Static Variables

---

## 🔹 1. What is `extern`?

* `extern` is a keyword used to **declare** variables or functions that are **defined in another translation unit** (i.e., another `.cpp` file).
* It tells the compiler:
  *“Don’t allocate memory; this exists somewhere else.”*

### ✅ Syntax

```cpp
extern int x;  // x is defined elsewhere
```

---

## 🔹 2. Global Variables

* A **global variable** is declared **outside any function or class**, usually at the top of a `.cpp` file.
* It has **external linkage** by default, meaning it can be accessed from other files using `extern`.

### 🧩 Example

#### File: `globals.cpp`

```cpp
int counter = 0;  // Definition
```

#### File: `main.cpp`

```cpp
#include <iostream>
extern int counter;  // Declaration

int main() {
    std::cout << counter << std::endl;
}
```

---

## 🔹 3. Static Variables

### A. Function-Scope Static

* Maintains its value **between function calls**.
* Has **internal linkage** (visible only within that function).

```cpp
void f() {
    static int count = 0;
    count++;
}
```

### B. File-Scope Static (Global but `static`)

* If you write `static` at file level, the variable becomes **private to that file**.
* This means **no other file can access it**, even with `extern`.

```cpp
static int filePrivate = 42;  // Can't use extern from another file
```

---

## 🔹 4. `extern` and Header Files

To safely use a variable across multiple files:

* **Step 1:** Define the variable in **one .cpp file**.
* **Step 2:** Declare it with `extern` in a **header file**.
* **Step 3:** Include that header wherever the variable is needed.

### Example

#### `globals.h`

```cpp
#ifndef GLOBALS_H
#define GLOBALS_H
extern int sharedValue;
#endif
```

#### `globals.cpp`

```cpp
#include "globals.h"
int sharedValue = 5;  // Only one definition allowed
```

#### `main.cpp`

```cpp
#include "globals.h"
#include <iostream>

int main() {
    std::cout << sharedValue << std::endl;
}
```

---

## 🔹 5. `extern` in Namespaces

You can declare `extern` variables inside a **namespace**:

### Example

#### `mynamespace.h`

```cpp
namespace App {
    extern int version;
}
```

#### `mynamespace.cpp`

```cpp
namespace App {
    int version = 2;
}
```

#### `main.cpp`

```cpp
#include "mynamespace.h"
#include <iostream>

int main() {
    std::cout << App::version << std::endl;
}
```

---

## 🔹 6. `extern` and Static Class Members

### Rules:

* Only `static` data members of a class can be **defined outside the class**.
* You declare them in the class.
* Then define them in one `.cpp` file.
* `extern` is **optional** if you include the header.

### Example

#### `MyClass.h`

```cpp
class MyClass {
public:
    static int staticVar;  // Declaration only
};
```

#### `MyClass.cpp`

```cpp
#include "MyClass.h"
int MyClass::staticVar = 10;  // Definition
```

#### `main.cpp`

```cpp
#include "MyClass.h"
#include <iostream>

extern int MyClass::staticVar;  // Optional

int main() {
    std::cout << MyClass::staticVar << std::endl;
}
```

---

## 🔹 7. Summary Table

| Feature                  | Description                                                              |
| ------------------------ | ------------------------------------------------------------------------ |
| `extern` keyword         | Declares something that's defined elsewhere                              |
| Global variable          | Default external linkage; can be shared using `extern`                   |
| Static global variable   | Internal linkage; **cannot** be accessed using `extern` from other files |
| Static function variable | Remembers state across calls; local to the function                      |
| Static class member      | Shared across all instances; defined outside the class                   |
| `extern` in namespace    | Must be inside the same namespace as the definition                      |
| Use in header files      | Place `extern` declarations in headers; include them where needed        |


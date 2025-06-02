# 📘 C++ Macros and Inline Functions 

---

## 🧠 What is a Macro?

In C and C++, a **macro** is a preprocessor directive that defines how certain code fragments should be replaced **before compilation**.

### 🔹 Syntax

```cpp
#define NAME replacement_text
```

---

### 🧩 Types of Macros

#### 1. **Object-like Macro**

Defines constants or values:

```cpp
#define PI 3.14159
double area = PI * r * r;
```

#### 2. **Function-like Macro**

Mimics functions, but does **text replacement**:

```cpp
#define SQUARE(x) ((x) * (x))
int result = SQUARE(5);  // Becomes ((5) * (5))
```

**⚠ Danger Without Parentheses:**

```cpp
#define BAD_SQUARE(x) x * x
int result = BAD_SQUARE(1 + 2);  // Expands to 1 + 2 * 1 + 2 = 5 ❌
```

#### 3. **Conditional Macros**

Used for platform-specific or build-specific code:

```cpp
#ifdef _WIN32
#define OS "Windows"
#else
#define OS "Other"
#endif
```

---

## 🛠️ What is an Inline Function?

An **inline function** is a suggestion to the compiler to insert the **function code directly** at the point of call to **reduce function call overhead**.

### 🔹 Syntax

```cpp
inline int square(int x) {
    return x * x;
}
```

Or inside a class:

```cpp
class Math {
public:
    int square(int x) {
        return x * x; // Inline by default inside classes
    }
};
```

---

### ✅ Advantages of Inline Functions

* Faster execution (no function call overhead)
* Safe with type checking
* Easier to debug than macros

---

### ⚠ When Not to Use Inline

* Large or complex functions
* Recursive functions
* Functions that are rarely used

---

## 🆚 Macro vs Inline Function

| Feature        | Macro                   | Inline Function               |
| -------------- | ----------------------- | ----------------------------- |
| Processed by   | Preprocessor            | Compiler                      |
| Type checking  | ❌ No                    | ✅ Yes                         |
| Debug-friendly | ❌ No                    | ✅ Yes                         |
| Safe?          | ❌ Error-prone           | ✅ Safe                        |
| Example        | `#define SQUARE(x) ...` | `inline int square(int x) {}` |

---

## 📦 Include Guards

To prevent a header file from being included multiple times (causing redefinition errors), we use:

### 🔹 Classic Include Guards

```cpp
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    void doSomething();
};

#endif
```

* `#ifndef` checks if not defined.
* `#define` defines the macro to mark it included.
* `#endif` ends the conditional.

### 🔹 Modern Alternative: `#pragma once`

Simpler and safer (modern compilers support it):

```cpp
#pragma once

class MyClass {
public:
    void doSomething();
};
```

---

## 🚧 Why Use Macros in Header Files?

At the **top of header files**, macros are used:

* To **prevent multiple inclusions** (with include guards)
* To define **configuration constants** or platform-specific code

This is why you’ll often see:

```cpp
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// your class/function declarations

#endif
```

---

## 📚 Full Example

### 🔹 `MathUtils.h`

```cpp
#ifndef MATHUTILS_H
#define MATHUTILS_H

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

inline double circleArea(double r) {
    return PI * SQUARE(r);
}

#endif
```

### 🔹 `main.cpp`

```cpp
#include <iostream>
#include "MathUtils.h"

int main() {
    double area = circleArea(5);
    std::cout << "Area: " << area << std::endl;
    return 0;
}
```

---

## 🧠 Summary

| Concept          | Use Case                                       |
| ---------------- | ---------------------------------------------- |
| `#define`        | Define constants or macros (code substitution) |
| Inline functions | Lightweight functions with type safety         |
| Include guards   | Prevent multiple inclusion of headers          |
| `#pragma once`   | Cleaner alternative to include guards          |

---

📌 **Tips:**

* Prefer `const`, `constexpr`, and `inline` over `#define` in modern C++
* Use macros carefully — they can cause bugs if not handled properly
* Keep macros small and simple; avoid using them like real functions


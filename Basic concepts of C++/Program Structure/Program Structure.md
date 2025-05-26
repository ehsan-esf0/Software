# 🏗️ **C++ Program Structure** 🏗️

---

## 1️⃣ **Namespaces (`namespace`)** 🌐

* **Definition:** Logical containers to group related code elements (classes, functions, variables) and avoid naming conflicts.
* **Location:** Declared inside header (`.h`) or source (`.cpp`) files, can be nested.
* **Purpose:** Organize code and prevent name collisions in large projects.
* **Example:**

```cpp
namespace MathUtils {
    int add(int a, int b);
}

namespace Graphics {
    namespace Shapes {
        class Circle {
        public:
            void draw();
        };
    }
}
```

* **Usage:**

```cpp
int result = MathUtils::add(5, 3);
Graphics::Shapes::Circle c;
c.draw();

// Or bring namespace into scope:
using namespace MathUtils;
int x = add(10, 20);
```

* **Note:** Namespaces exist at **compile time only**, with no runtime overhead.

---

## 2️⃣ **`main` Function: Program Entry Point** 🚀

* **What:** The function where program execution begins.
* **Location:** Must be a **free function** in the **global namespace** (not inside any class or namespace).
* **Why:** The OS and runtime look for `main` in the global scope to start the program.
* **Valid signatures:**

```cpp
int main();
int main(int argc, char* argv[]);
```

* **Important:** Putting `main` inside a namespace or class breaks program startup.

---

## 3️⃣ **Entry Point Differences in Other Languages** 🌎

| Language   | Entry Point                         | Inside Class/Namespace?       |
| ---------- | ----------------------------------- | ----------------------------- |
| C++        | `main` function                     | No (global namespace)         |
| C          | `main` function                     | No                            |
| Java       | `public static void main(String[])` | Yes, inside a class           |
| C#         | `static void Main()`                | Yes, inside a class or struct |
| Python     | No special entry function needed    | Script runs top to bottom     |
| JavaScript | No special entry function needed    | Script runs line by line      |

---

## 4️⃣ **Libraries (`Library`) in C++** 📚

* **Definition:** Collections of pre-written reusable code (functions, classes) bundled together.

* **Types:**

  | Type            | Description                              | Extensions                                        |
  | --------------- | ---------------------------------------- | ------------------------------------------------- |
  | Static Library  | Linked into executable at compile time   | `.lib` (Windows), `.a` (Linux/macOS)              |
  | Dynamic Library | Linked at runtime, shared among programs | `.dll` (Windows), `.so` (Linux), `.dylib` (macOS) |

* **Usage:**
  Include headers with `#include` and link libraries during compilation.

* **Example:**

```cpp
#include <iostream>
#include <cmath>  // standard math library

int main() {
    double val = 9.0;
    double root = sqrt(val);  // sqrt from <cmath>
    std::cout << "Square root of 9 is: " << root << std::endl;
    return 0;
}
```

---

## 5️⃣ **Libraries vs Namespaces** ⚠️

| Aspect           | Library                              | Namespace                                            |
| ---------------- | ------------------------------------ | ---------------------------------------------------- |
| Purpose          | Provide reusable compiled code       | Organize code and prevent name collisions            |
| Form             | Binary files + header files          | Code blocks inside source/header files               |
| Usage            | Linked during compile/link time      | Used at compile-time via scope resolution or `using` |
| Runtime Presence | Code included/loaded into executable | No runtime impact, compile-time only                 |

---

## 6️⃣ **How to Build Your Own Library in C++** 🛠️

### Step 1: Write Code

```cpp
// MyLib.h
#ifndef MYLIB_H
#define MYLIB_H

namespace MyLib {
    void sayHello();
}

#endif
```

```cpp
// MyLib.cpp
#include "MyLib.h"
#include <iostream>

namespace MyLib {
    void sayHello() {
        std::cout << "Hello from MyLib! 👋" << std::endl;
    }
}
```

---

### Step 2: Create Static Library (Linux/macOS example)

```bash
g++ -c MyLib.cpp           # Compile to object file
ar rcs libMyLib.a MyLib.o  # Create static library
```

---

### Step 3: Use Your Library

```cpp
// main.cpp
#include "MyLib.h"

int main() {
    MyLib::sayHello();
    return 0;
}
```

Compile & link:

```bash
g++ main.cpp -L. -lMyLib -o myprogram
```

---

### Tips:

* `-L.` tells the linker where to find libraries (current folder).
* `-lMyLib` links `libMyLib.a`.
* For dynamic libraries, use `-shared` and other platform-specific flags.

---

## Summary Table 🎯

| Concept        | Purpose                            | Location/Scope                | Example                             |
| -------------- | ---------------------------------- | ----------------------------- | ----------------------------------- |
| Namespace      | Organize code & avoid name clashes | Inside `.h` or `.cpp` files   | `namespace Foo { ... }`             |
| `main`         | Program entry point                | Global namespace              | `int main() { ... }`                |
| Library        | Reusable compiled code collection  | Header + static/dynamic files | `#include <mylib.h>` + `libmylib.a` |
| Create library | Write code, compile, archive/link  | Separate files, then link     | See steps above                     |

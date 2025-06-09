## 🔷 Accessing Global Variables Across Files Using `#include`

### ✅ Proper Way (Recommended Practice)

If you want to use a global variable across multiple source files, the clean and correct way is to:

1. **Declare** the variable as `extern` in a header file.
2. **Define** the variable in one `.cpp` file.
3. **Include** the header wherever you need to access the variable.

---

### 📁 Example Structure

#### `globals.h`

```cpp
#ifndef GLOBALS_H
#define GLOBALS_H

extern int globalCounter;  // Declaration only

#endif
```

#### `globals.cpp`

```cpp
#include "globals.h"

int globalCounter = 0;  // Actual definition
```

#### `main.cpp`

```cpp
#include <iostream>
#include "globals.h"

int main() {
    std::cout << globalCounter << std::endl;  // Access the global variable
    return 0;
}
```

✅ This setup ensures:

* Only one definition exists (in `globals.cpp`)
* Other files can use the variable via the declaration from the header

---

## ❌ Incorrect Way — Defining in Header File

If you **define** the variable directly in a header and include it in multiple `.cpp` files:

#### `globals.h` (Incorrect)

```cpp
int globalCounter = 0;  // ❌ This is a definition!
```

Then including this in multiple `.cpp` files like this:

```cpp
#include "globals.h"
```

...will lead to:

```
Linker error: multiple definition of 'globalCounter'
```

💥 Because each `.cpp` file gets its own copy of the variable → multiple definitions.

---

## ✅ C++17 Solution: `inline` Global Variables

If you're using **C++17 or later**, you can safely define global variables in headers using the `inline` keyword:

#### `globals.h` (C++17+)

```cpp
inline int globalCounter = 0;  // OK in multiple translation units
```

This ensures **only one definition across all translation units**.

---

## 🔁 Summary Table

| Method                                      | Result            | Notes                        |
| ------------------------------------------- | ----------------- | ---------------------------- |
| `extern` in header + `int x;` in one `.cpp` | ✅ Works perfectly | Recommended classic approach |
| `int x = 0;` in header                      | ❌ Linker error    | Multiple definitions         |
| `inline int x = 0;` in header (C++17+)      | ✅ Works fine      | Modern and safe              |

---

## 🧠 Final Notes

* Global variables should be **declared, not defined** in headers (unless marked `inline`).
* Static global variables are **never visible outside their file** — so don't use them if you need cross-file access.
* Using `#include` alone is **not enough** unless the included header is set up correctly with `extern`.


## 🔷 Global Variables and Static 

### ✅ What is a global variable?

A **global variable** is declared **outside** of any function, class, or namespace, and is accessible from **any file** in your program—**if properly declared**.

```cpp
// file1.cpp
int myGlobal = 42;  // Definition

// file2.cpp
extern int myGlobal;  // Declaration

void doSomething() {
    myGlobal++;
}
```

### 📌 Key Characteristics:

| Property                | Value                          |
| ----------------------- | ------------------------------ |
| Scope                   | Entire program (all files)     |
| Linkage                 | External                       |
| Lifetime                | Entire duration of the program |
| Access from other files | ✅ Yes, via `extern`            |

---

## 🔷 Static Global Variables (File Scope Static)

### ✅ What is a static global variable?

A global variable with the `static` keyword becomes **file-local**, meaning it can only be accessed **within the same source file**. This is called **internal linkage**.

```cpp
// file1.cpp
static int myCounter = 0;  // File-local, cannot be used in other files

void increment() {
    myCounter++;
}
```

### ❌ Trying to access it from another file:

```cpp
// file2.cpp
extern int myCounter;  // ❌ Linker error: not found
```

### 📌 Key Characteristics:

| Property                | Value                               |
| ----------------------- | ----------------------------------- |
| Scope                   | Only within the file it is declared |
| Linkage                 | Internal                            |
| Lifetime                | Entire duration of the program      |
| Access from other files | ❌ No                                |

---

## 🔁 Comparison Table

| Feature                | Global Variable   | Static Global Variable |
| ---------------------- | ----------------- | ---------------------- |
| Location               | Outside functions | Outside functions      |
| Scope                  | All files         | Current file only      |
| Linkage                | External          | Internal               |
| Lifetime               | Whole program     | Whole program          |
| `extern` compatibility | ✅ Yes             | ❌ No                   |

---

## 🧠 Key Notes

* `static` does **not** affect **lifetime**, it only limits **visibility** (scope).
* A `static` global variable is great when you want to **hide implementation details** from other translation units.
* **You should not define a global variable in a header file** unless it's declared `inline` (from C++17 onward).

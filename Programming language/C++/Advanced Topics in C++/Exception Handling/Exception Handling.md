# 🌟 Advanced and Complete Guide to Exception Handling in C++

---

## ✅ 1. **Stack Unwinding & Destructors**

When an exception is thrown, **local variables go out of scope**, and their **destructors are automatically called**.

```cpp
struct Resource {
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

void func() {
    Resource r;
    throw 1;
}

int main() {
    try {
        func();
    } catch (...) {
        std::cout << "Exception caught\n";
    }
}
```

**Output:**

```
Resource destroyed  
Exception caught
```

👉 This ensures resources are properly cleaned up during exception propagation.

---

## ✅ 2. **Rethrowing Exceptions**

You can catch an exception and then rethrow it for higher-level handling.

```cpp
void lowLevel() {
    throw std::runtime_error("Low-level error");
}

void middle() {
    try {
        lowLevel();
    } catch (...) {
        std::cout << "Logging and rethrowing\n";
        throw;  // Rethrow current exception
    }
}
```

---

## ✅ 3. **Custom Exception Hierarchy**

Create your own exception classes by inheriting from `std::exception`:

```cpp
class BaseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Base error";
    }
};

class FileNotFound : public BaseException {
public:
    const char* what() const noexcept override {
        return "File not found";
    }
};
```

This allows catching a **group of related exceptions** polymorphically.

---

## ✅ 4. **`noexcept` Keyword**

Used to indicate that a function **won't throw exceptions**.

```cpp
void safeFunction() noexcept {
    // Must not throw anything
}
```

* If it **does throw**, `std::terminate()` will be called.
* Important for **performance** and **compiler optimizations**, especially in destructors and move operations.

---

## ✅ 5. **RAII (Resource Acquisition Is Initialization)**

Manages resources safely using object lifetime.

```cpp
class FileHandle {
    FILE* file;
public:
    FileHandle(const char* name) {
        file = fopen(name, "r");
        if (!file) throw std::runtime_error("Cannot open file");
    }
    ~FileHandle() {
        if (file) fclose(file);
    }
};
```

RAII ensures proper cleanup even when an exception is thrown.

---

## ✅ 6. **Nested Exceptions**

Wrap one exception inside another using `std::throw_with_nested`.

```cpp
void low() {
    throw std::runtime_error("Low-level error");
}

void high() {
    try {
        low();
    } catch (...) {
        std::throw_with_nested(std::runtime_error("High-level error"));
    }
}

void handle() {
    try {
        high();
    } catch (const std::exception& e) {
        try {
            std::rethrow_if_nested(e);
        } catch (const std::exception& nested) {
            std::cout << "Nested: " << nested.what() << "\n";
        }
        std::cout << "Outer: " << e.what() << "\n";
    }
}
```

---

## ✅ 7. **Exceptions in Destructors — Dangerous!**

Throwing inside destructors during stack unwinding will terminate the program.

```cpp
class Bad {
public:
    ~Bad() {
        throw std::runtime_error("Error in destructor"); // Risky!
    }
};
```

✅ **Best practice:** Never throw in destructors, or if you must, **catch the exception inside the destructor.**

---

## ✅ 8. **Performance Consideration**

* **Throwing/catching** exceptions is **expensive**.
* Use exceptions only for **unexpected, abnormal situations**, not for regular flow control.
* Avoid in tight loops or low-latency systems unless absolutely necessary.

---

## ✅ 9. **Delayed Exception Handling using `std::exception_ptr`**

Capture and store an exception to rethrow later.

```cpp
std::exception_ptr eptr;

try {
    throw std::runtime_error("Deferred error");
} catch (...) {
    eptr = std::current_exception();
}

if (eptr) std::rethrow_exception(eptr);
```

Useful in **multi-threading** or deferred error handling.

---

## ✅ 10. **Standard Exception Classes in STL**

C++ provides a rich set of standard exceptions:

| Exception Class         | Meaning                                    |
| ----------------------- | ------------------------------------------ |
| `std::exception`        | Base class                                 |
| `std::runtime_error`    | Runtime errors                             |
| `std::logic_error`      | Logic errors (violations of preconditions) |
| `std::invalid_argument` | Invalid arguments                          |
| `std::out_of_range`     | Index out of bounds                        |
| `std::overflow_error`   | Overflow occurred                          |
| `std::underflow_error`  | Underflow occurred                         |

All provide `.what()` method for error description.

---

## ✅ 11. **Flow Behavior After `throw`**

Once a `throw` occurs:

* No code after it in the same scope is executed.
* Control jumps to the nearest matching `catch`.
* All local objects go out of scope and destructors run (**stack unwinding**).

---

## 🧠 Summary

* Use exceptions sparingly and for exceptional events only.
* Always manage resources with RAII to prevent leaks.
* Understand stack unwinding and never throw from destructors without catching.
* Use `noexcept`, `std::exception_ptr`, and `throw_with_nested` in advanced designs.


## What is `explicit` in C++?

The `explicit` keyword in C++ is used to **prevent implicit type conversions** when:

* Calling a **constructor** with a single parameter.
* Defining a **conversion operator**.

It ensures that conversions must be done **explicitly by the programmer**, not automatically by the compiler.

---

## 🔷 1. Explicit Constructors

### 🧠 Why?

Without `explicit`, a constructor with one parameter can be used for implicit conversions.

### 🔽 Example without `explicit` (implicit conversion):

```cpp
class MyClass {
public:
    MyClass(int x) {
        std::cout << "Constructor called with x = " << x << std::endl;
    }
};

void print(MyClass obj) {}

int main() {
    print(42);  // Implicitly converts int → MyClass
}
```

### 🔽 Example with `explicit` (requires manual conversion):

```cpp
class MyClass {
public:
    explicit MyClass(int x) {
        std::cout << "Explicit constructor with x = " << x << std::endl;
    }
};

void print(MyClass obj) {}

int main() {
    print(MyClass(42)); // ✅ OK - explicit construction
    // print(42);       // ❌ Error - implicit conversion not allowed
}
```

---

## 🔷 2. Explicit Conversion Operators

You can also use `explicit` on conversion functions like `operator bool()`:

```cpp
class MyClass {
public:
    explicit operator bool() const {
        return true;
    }
};

int main() {
    MyClass obj;

    if (obj) {         // ✅ Allowed inside control flow
        std::cout << "True\n";
    }

    // bool b = obj;   // ❌ Error - implicit conversion blocked
}
```

---

## 🔷 3. Explicit Template Constructors (C++11+)

```cpp
template<typename T>
class MyTemplate {
public:
    explicit MyTemplate(T value) { /* ... */ }
};
```

This prevents unintended instantiations from other types.

---

## 🔷 4. Explicit with `constexpr` (C++20+)

You can combine `explicit` and `constexpr` in modern C++:

```cpp
class MyClass {
public:
    explicit constexpr MyClass(int x) : x_(x) {}
private:
    int x_;
};
```

---

## ❌ Where `explicit` Cannot Be Used

| Context              | Allowed? | Reason                                                         |
| -------------------- | -------- | -------------------------------------------------------------- |
| Non-member functions | ❌ No     | `explicit` only works with class members                       |
| Global variables     | ❌ No     | Not applicable to variables                                    |
| Class declarations   | ❌ No     | You can't declare an entire class as `explicit`                |
| Function parameters  | ❌ No     | `explicit` only modifies constructors and conversion operators |

---

## ✅ Summary Table

| Feature                           | Allowed with `explicit`? | Example                         |
| --------------------------------- | ------------------------ | ------------------------------- |
| Constructor                       | ✅ Yes                    | `explicit MyClass(int);`        |
| Conversion operator               | ✅ Yes                    | `explicit operator bool();`     |
| Template constructor (C++11+)     | ✅ Yes                    | `explicit MyClass(T);`          |
| `constexpr` + `explicit` (C++20+) | ✅ Yes                    | `explicit constexpr MyClass();` |
| Non-member function               | ❌ No                     | N/A                             |
| Global or local variable          | ❌ No                     | N/A                             |
| Class declaration                 | ❌ No                     | N/A                             |

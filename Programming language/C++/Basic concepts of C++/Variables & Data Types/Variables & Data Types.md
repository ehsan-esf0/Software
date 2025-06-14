# 🎉 Variables & Data Types in C++

---

## 1️⃣ What is a Variable? 🤔

A **variable** is a named storage in memory that holds data of a specific type.
You declare a variable with a type and name, and optionally assign an initial value.

```cpp
int age = 25;  // 'age' is a variable of type int with initial value 25
```

---

## 2️⃣ Primitive Data Types (Basic Types) ⚙️

### 🔢 Integer Types (Whole numbers)

| Type        | Size (bytes)  | Typical Range (Signed)                     | Description             |
| ----------- | ------------- | ------------------------------------------ | ----------------------- |
| `int`       | 4             | -2,147,483,648 to 2,147,483,647            | Standard integer        |
| `short`     | 2             | -32,768 to 32,767                          | Smaller integer         |
| `long`      | 4 or 8        | Larger range than int (platform-dependent) | Large integer           |
| `long long` | 8             | Very large range                           | Very large integer      |
| `unsigned`  | Same as above | Only positive values (0 and up)            | No sign (positive only) |

```cpp
unsigned int score = 4000000000;
long long bigNumber = 1234567890123;
```

---

### 💧 Floating-Point Types (Decimals)

| Type          | Size (bytes) | Approximate Range                    | Description                  |
| ------------- | ------------ | ------------------------------------ | ---------------------------- |
| `float`       | 4            | \~1.2e-38 to 3.4e+38                 | Single precision (7 digits)  |
| `double`      | 8            | \~2.3e-308 to 1.7e+308               | Double precision (15 digits) |
| `long double` | 8,12, or 16  | More precision (depends on compiler) | Extended precision           |

```cpp
float pi = 3.14f;
double e = 2.7182818284;
```

⚠️ Floating-point values are stored approximately (IEEE 754 standard), so small rounding errors are normal.

---

### ✅ Boolean Type

* `bool` can only be `true` or `false`.

```cpp
bool isReady = true;
if (isReady) {
    // do something
}
```

---

### 🔤 Character Types

* `char` stores one byte (ASCII character).
* `wchar_t`, `char16_t`, and `char32_t` are for Unicode and wider characters.

```cpp
char letter = 'A';
wchar_t persianLetter = L'ش';
```

---

## 3️⃣ Compound and Advanced Data Types 🏗️

### 🗂 Arrays

* Collection of elements of the same type in contiguous memory.
* Fixed size, determined at compile-time.

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
std::cout << numbers[0];  // Output: 1
```

---

### 📜 Strings

* C-Style Strings: null-terminated `char` arrays (`'\0'` at the end).
* C++ Strings: `std::string` from the Standard Library, safer and easier.

```cpp
char cstr[] = "Hello";
std::string cppstr = "Hello, World!";
```

---

### 👤 Structures (`struct`)

* Group related variables of different types under one name.

```cpp
struct Person {
    std::string name;
    int age;
};

Person p1 = {"Alice", 30};
```

---

### 🔄 Unions (`union`)

* Different members share the **same memory** location.
* Only one member can hold a value at a time.

```cpp
union Value {
    int i;
    float f;
};

Value v;
v.i = 10;  
v.f = 3.14f;  // Overwrites v.i!
```

---

### 🎨 Enumerations (`enum`)

* Define a list of named integral constants.

```cpp
enum Color { RED, GREEN, BLUE };
Color c = RED;
```

You can assign custom integer values:

```cpp
enum Status { SUCCESS = 1, FAIL = 0 };
```

---

## 4️⃣ Modern C++ Types and Keywords 🚀

### `auto`

* Compiler deduces the type from the initializer.

```cpp
auto x = 5;          // int
auto y = 3.14;       // double
auto name = std::string("Bob");
```

---

### `decltype`

* Get the exact type of an expression **without evaluating** it.

```cpp
int a = 10;
decltype(a) b = 20;  // b is int
```

---

### `void`

* Represents **no type**.
* Used for functions with no return value and generic pointers.

```cpp
void printHello() {
    std::cout << "Hello\n";
}

void* ptr;  // Generic pointer to any type
```

---

### Pointers (`*`) and References (`&`)

| Feature     | Syntax          | Explanation                             |
| ----------- | --------------- | --------------------------------------- |
| Pointer     | `int* p = &x;`  | Holds memory address of variable `x`.   |
| Dereference | `*p`            | Access the value at the memory address. |
| Reference   | `int& ref = x;` | Alias to existing variable `x`.         |

```cpp
int x = 10;
int* p = &x;
std::cout << *p;  // 10

int& ref = x;
ref = 20;         // x changes to 20
```

---

## 5️⃣ Advanced Modifiers and Features ⚙️

### `const` (constant)

* Variable that **cannot** be modified after initialization.

```cpp
const int MAX_USERS = 100;
```

---

### `volatile`

* Tells the compiler the variable can change at **any moment** (e.g., hardware registers).

```cpp
volatile int sensorValue;
```

---

### `constexpr`

* Value computed at **compile time**.

```cpp
constexpr int square(int x) { return x * x; }
int val = square(5);  // val is 25, computed at compile time
```

---

### `std::variant` (C++17)

* A **type-safe union** that can hold one of multiple types.

```cpp
#include <variant>
std::variant<int, std::string> var;
var = 42;
var = "Hello";
```

---

### `std::optional` (C++17)

* Represents a value that may or may not be present.

```cpp
#include <optional>
std::optional<int> opt;

if (!opt) {
    opt = 100;
}
```

---

# 🏁 Summary Table 🏁

| Category              | Examples                        | Description                          |
| --------------------- | ------------------------------- | ------------------------------------ |
| Primitive Types       | `int`, `float`, `bool`, `char`  | Basic data types                     |
| Compound Types        | `struct`, `union`, `enum`       | Combine multiple values              |
| Pointers & Refs       | `int*`, `int&`                  | Memory addresses and aliases         |
| Modern Types (C++11+) | `auto`, `decltype`, `constexpr` | Type inference and compile-time eval |
| Advanced C++17        | `std::variant`, `std::optional` | Safe unions and nullable values      |


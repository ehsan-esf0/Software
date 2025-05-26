# 📘 **C++ Pointers

---

## 🔹 What is a Pointer?

A **pointer** is a variable that **stores the memory address** of another variable.

```cpp
int x = 10;
int* ptr = &x; // ptr stores the address of x
```

* `&x` → gives the address of `x`
* `*ptr` → accesses the value at the address stored in `ptr`

---

## 🔸 Declaring Pointers

```cpp
type* pointerName;
```

### Examples:

```cpp
int* p;       // Pointer to int
float* fptr;  // Pointer to float
char* cptr;   // Pointer to char
```

---

## 🔹 Address-of (&) and Dereference (\*) Operators

| Operator | Meaning     | Example                                       |
| -------- | ----------- | --------------------------------------------- |
| `&`      | Address-of  | `&x` gives the memory address of `x`          |
| `*`      | Dereference | `*ptr` accesses the value pointed to by `ptr` |

---

## 🔸 Example Code:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in p: " << p << endl;
    cout << "Value pointed by p: " << *p << endl;
}
```

---

## 🔹 Types of Pointer Constants (`const` usage)

### 1. 🔒 `const int* p` – Cannot change value pointed to

```cpp
const int* p = &x;
*p = 10; // ❌ error
p = &y;  // ✅ allowed
```

### 2. 🔒 `int* const p` – Cannot change the address stored in pointer

```cpp
int* const p = &x;
*p = 10; // ✅ allowed
p = &y;  // ❌ error
```

### 3. 🔒 `const int* const p` – Totally constant

```cpp
const int* const p = &x;
*p = 10; // ❌
p = &y;  // ❌
```

---

## 🔹 Pointer to Pointer (📍📍)

```cpp
int x = 10;
int* p = &x;
int** pp = &p;

cout << **pp; // Output: 10
```

---

## 🔸 Null Pointer (`nullptr`)

```cpp
int* ptr = nullptr;

if (ptr == nullptr) {
    cout << "Pointer is null!" << endl;
}
```

> Use `nullptr` instead of `NULL` in modern C++.

---

## 🔹 Dynamic Memory Allocation (`new` and `delete`)

### 🆕 Allocating Single Variable:

```cpp
int* p = new int;
*p = 42;
```

### 🗑️ Freeing Memory:

```cpp
delete p;
```

### 🧱 Allocating Array:

```cpp
int* arr = new int[5];
```

### 🧹 Deleting Array:

```cpp
delete[] arr;
```

---

## ⚠️ Common Pointer Issues

| Problem                 | Description                             |
| ----------------------- | --------------------------------------- |
| 🧨 **Dangling Pointer** | Pointer to deallocated memory           |
| 🧭 **Wild Pointer**     | Uninitialized pointer (garbage address) |
| 🔥 **Memory Leak**      | Forgetting to `delete` allocated memory |
| 🚫 **Invalid Access**   | Dereferencing null or garbage pointer   |

---

## 🔹 Void Pointers (`void*`)

Generic pointer, can store address of any data type.

```cpp
void* vp;
int a = 10;
vp = &a;
cout << *(int*)vp;
```

---

## 🔸 Pointer Casting

### ✅ Safe Cast

```cpp
void* p = malloc(sizeof(int));
int* ip = static_cast<int*>(p);
```

### 🚨 Dangerous Cast

```cpp
int* p = reinterpret_cast<int*>(0x12345678); // risky!
```

---

## 📌 sizeof Pointer

```cpp
int* p;
cout << sizeof(p); // Usually 4 bytes (32-bit) or 8 bytes (64-bit)
```

---

## 🔹 Pointers and Arrays

```cpp
int arr[3] = {1, 2, 3};
int* p = arr;

cout << *(p + 1); // prints 2
```

> `arr[i]` is equivalent to `*(arr + i)`

---

## ✅ Summary Table

| Concept            | Example                           | Notes                          |
| ------------------ | --------------------------------- | ------------------------------ |
| Basic Pointer      | `int* p = &x;`                    | Stores address of `x`          |
| Dereferencing      | `*p`                              | Accesses value at address      |
| Null Pointer       | `nullptr`                         | Empty pointer                  |
| Dynamic Memory     | `new`, `delete`                   | Manual allocation/deallocation |
| `const` Usage      | `const int*`, `int* const`        | Control mutability             |
| Pointer to Pointer | `int** pp`                        | Multilevel indirection         |
| Void Pointer       | `void* vp`                        | Generic pointer                |
| Casting            | `static_cast`, `reinterpret_cast` | Type conversion                |
| Array with Pointer | `int* p = arr;`                   | Pointer arithmetic             |

---

## 🧠 Pro Tips

✅ Always initialize pointers (e.g. `nullptr`)
🚫 Never dereference uninitialized or null pointers
🔁 Always `delete` what you `new`
🧯 Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) in modern C++

---